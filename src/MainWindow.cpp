#include <MainWindow.h>
#include "ui_MainWindow.h"
#include <Model.h>

#include <vtkXMLUnstructuredGridReader.h>
#include <vtkUnstructuredGrid.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkProperty.h>
#include <vtkPolyDataMapper.h>
#include <vtkDataSetMapper.h>
#include <vtkGeometryFilter.h>
#include <vtkAreaPicker.h>
#include <vtkCallbackCommand.h>
#include <vtkProp3DCollection.h>
#include <vtkExtractSelectedFrustum.h>
#include <HighlightInteractorStyle.h>
#include <vtkNamedColors.h>
#include <vtkExtractGeometry.h>
#include <vtkBox.h>
#include <vtkCubeSource.h>
#include <vtkCellData.h>
#include <vtkXMLUnstructuredGridWriter.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mRenderWindow(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New()),
    mRenderer(vtkSmartPointer<vtkRenderer>::New()),
    mInteractor(vtkSmartPointer<QVTKInteractor>::New()),
    mInteractorStyle(vtkSmartPointer<HighlightInteractorStyle>::New())
{
    ui->setupUi(this);

    // Initialize model
    model = new Model(this);

    // Set up the rendering
    mRenderWindow->AddRenderer(mRenderer);
    mRenderWindow->SetInteractor(mInteractor);
    ui->openGLWidget->setRenderWindow(mRenderWindow);
    mInteractor->SetInteractorStyle(mInteractorStyle);
    mInteractorStyle->setMainWindow(this);

    // Set up the Picker
    vtkSmartPointer<vtkAreaPicker> areaPicker = vtkSmartPointer<vtkAreaPicker>::New();
    mInteractor->SetPicker(areaPicker);
    mInteractor->Initialize();

    this->initializeActors();

    // Set the background color
    mRenderer->SetBackground(0, 0, 0);

    // Set the UI connections
    QObject::connect(ui->loadMesh_button, &QPushButton::clicked, this, &MainWindow::onLoadMeshClick);
    QObject::connect(ui->displayVol_combo, &QComboBox::currentIndexChanged, this, &MainWindow::onDisplayVolClick);
    QObject::connect(ui->displayFac_combo, &QComboBox::currentIndexChanged, this, &MainWindow::onDisplayFacClick);
    QObject::connect(ui->displayEdg_combo, &QComboBox::currentIndexChanged, this, &MainWindow::onDisplayEdgClick);
    QObject::connect(ui->displayNod_combo, &QComboBox::currentIndexChanged, this, &MainWindow::onDisplayNodClick);
    QObject::connect(ui->add_rb, &QRadioButton::clicked, this, &MainWindow::onSelectionModeClick);
    QObject::connect(ui->replace_rb, &QRadioButton::clicked, this, &MainWindow::onSelectionModeClick);
    QObject::connect(ui->subtract_rb, &QRadioButton::clicked, this, &MainWindow::onSelectionModeClick);
    QObject::connect(ui->reselect_rb, &QRadioButton::clicked, this, &MainWindow::onSelectionModeClick);
    QObject::connect(ui->mouseModeOrient_rb, &QRadioButton::clicked, this, &MainWindow::onMouseModeClick);
    QObject::connect(ui->mouseModeSel_rb, &QRadioButton::clicked, this, &MainWindow::onMouseModeClick);
    QObject::connect(ui->selMethodBox_rb, &QRadioButton::clicked, this, &MainWindow::onSelectionMethodClick);
    QObject::connect(ui->selMethodSlider_rb, &QRadioButton::clicked, this, &MainWindow::onSelectionMethodClick);
    QObject::connect(ui->showSelection_pb, &QPushButton::clicked, this, &MainWindow::onShowSelectionClick);
    QObject::connect(ui->hideSelection_pb, &QPushButton::clicked, this, &MainWindow::onHideSelectionClick);
    QObject::connect(ui->showAll_pb, &QPushButton::clicked, this, &MainWindow::onShowAllClick);
    QObject::connect(ui->selectAll_pb, &QPushButton::clicked, this, &MainWindow::onSelectAllClick);
    QObject::connect(ui->selectInvert_pb, &QPushButton::clicked, this, &MainWindow::onSelectionInvertClick);
    QObject::connect(ui->unselectAll_pb, &QPushButton::clicked, this, &MainWindow::onUnselectAllClick);
    QObject::connect(ui->selBoxInside_cb, &QCheckBox::clicked, this, &MainWindow::updateSelectionFunction);
    QObject::connect(ui->selBoxBoundary_cb, &QCheckBox::clicked, this, &MainWindow::updateSelectionFunction);

    // Display page
    QObject::connect(ui->displayVol_cb, &QCheckBox::clicked, this, &MainWindow::onDisplayVolClick);
    QObject::connect(ui->displayVolSel_cb, &QCheckBox::clicked, this, &MainWindow::onDisplayVolClick);
    QObject::connect(ui->displayFac_cb, &QCheckBox::clicked, this, &MainWindow::onDisplayFacClick);
    QObject::connect(ui->displayFacSel_cb, &QCheckBox::clicked, this, &MainWindow::onDisplayFacClick);
    QObject::connect(ui->displayEdg_cb, &QCheckBox::clicked, this, &MainWindow::onDisplayEdgClick);
    QObject::connect(ui->displayEdgSel_cb, &QCheckBox::clicked, this, &MainWindow::onDisplayEdgClick);
    QObject::connect(ui->displayNod_cb, &QCheckBox::clicked, this, &MainWindow::onDisplayNodClick);
    QObject::connect(ui->displayNodSel_cb, &QCheckBox::clicked, this, &MainWindow::onDisplayNodClick);

    // View page
    QObject::connect(ui->viewParallelProjection_cb, &QPushButton::clicked, this, &MainWindow::onParallelProjectionClick);
    QObject::connect(ui->viewXm_pb, &QPushButton::clicked, this, &MainWindow::onViewDirectionClick);
    QObject::connect(ui->viewXp_pb, &QPushButton::clicked, this, &MainWindow::onViewDirectionClick);
    QObject::connect(ui->viewYm_pb, &QPushButton::clicked, this, &MainWindow::onViewDirectionClick);
    QObject::connect(ui->viewYp_pb, &QPushButton::clicked, this, &MainWindow::onViewDirectionClick);
    QObject::connect(ui->viewZm_pb, &QPushButton::clicked, this, &MainWindow::onViewDirectionClick);
    QObject::connect(ui->viewZp_pb, &QPushButton::clicked, this, &MainWindow::onViewDirectionClick);

    QObject::connect(ui->transpVol_slider, &QSlider::valueChanged, this, &MainWindow::onTranspVolSliderMoved);
    QObject::connect(ui->transpFac_slider, &QSlider::valueChanged, this, &MainWindow::onTranspFacSliderMoved);
    QObject::connect(ui->transpEdg_slider, &QSlider::valueChanged, this, &MainWindow::onTranspEdgSliderMoved);
    QObject::connect(ui->transpNod_slider, &QSlider::valueChanged, this, &MainWindow::onTranspNodSliderMoved);
    QObject::connect(ui->slideSelXm_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValue);
    QObject::connect(ui->slideSelXp_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValue);
    QObject::connect(ui->slideSelYm_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValue);
    QObject::connect(ui->slideSelYp_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValue);
    QObject::connect(ui->slideSelZm_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValue);
    QObject::connect(ui->slideSelZp_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValue);
    QObject::connect(ui->slideSelXm_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValue);
    QObject::connect(ui->slideSelXp_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValue);
    QObject::connect(ui->slideSelYm_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValue);
    QObject::connect(ui->slideSelYp_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValue);
    QObject::connect(ui->slideSelZm_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValue);
    QObject::connect(ui->slideSelZp_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValue);

    // Export collections
    QObject::connect(ui->expAddVol_pb, &QPushButton::clicked, this, &MainWindow::onExportAddClick);
    QObject::connect(ui->expAddFac_pb, &QPushButton::clicked, this, &MainWindow::onExportAddClick);
    QObject::connect(ui->expAddEdg_pb, &QPushButton::clicked, this, &MainWindow::onExportAddClick);
    QObject::connect(ui->expAddNod_pb, &QPushButton::clicked, this, &MainWindow::onExportAddClick);
    QObject::connect(ui->exportCollections_pb, &QPushButton::clicked, this, &MainWindow::onExportClick);

    // Initialize widgets
    ui->collections_table->setColumnWidth(0, 20);
    ui->collections_table->setColumnWidth(1, 140);
    ui->collections_table->setColumnWidth(2, 60);
    ui->collections_table->setColumnWidth(3, 60);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::initializeActors()
{
    for (int k = 0;k < 4;k++) {
        mActor[k] = vtkSmartPointer<vtkActor>::New();
        mSelActor[k] = vtkSmartPointer<vtkActor>::New();
    }
    mSelFunActor = vtkSmartPointer<vtkActor>::New();

    mActor[0]->GetProperty()->SetColor(this->getColors("Volumes"));
    mActor[1]->GetProperty()->SetColor(this->getColors("Faces"));
    mActor[2]->GetProperty()->SetColor(this->getColors("Edges"));
    mActor[2]->GetProperty()->SetRenderLinesAsTubes(1);
    mActor[2]->GetProperty()->SetLineWidth(2);
    mActor[3]->GetProperty()->SetColor(this->getColors("Nodes"));
    mActor[3]->GetProperty()->SetRenderPointsAsSpheres(1);
    mActor[3]->GetProperty()->SetVertexVisibility(1);
    mActor[3]->GetProperty()->SetPointSize(400);
    mActor[3]->GetProperty()->SetColor(this->getColors("Nodes"));

    mSelActor[0]->GetProperty()->SetColor(this->getColors("Volumes selected"));
    mSelActor[0]->GetProperty()->SetEdgeVisibility(1);
    mSelActor[1]->GetProperty()->SetColor(this->getColors("Faces selected"));
    mSelActor[1]->GetProperty()->SetEdgeVisibility(1);
    mSelActor[2]->GetProperty()->SetColor(this->getColors("Edges selected"));
    mSelActor[2]->GetProperty()->SetRenderLinesAsTubes(1);
    mSelActor[2]->GetProperty()->SetLineWidth(3);
    mSelActor[3]->GetProperty()->SetColor(this->getColors("Nodes selected"));
    mSelActor[3]->GetProperty()->SetRenderPointsAsSpheres(1);
    mSelActor[3]->GetProperty()->SetVertexVisibility(1);
    mSelActor[3]->GetProperty()->SetPointSize(400);
}

int MainWindow::ui_giveSelectionMode()
{
    if (ui->add_rb->isChecked())
        return 0;
    else if (ui->replace_rb->isChecked())
        return 1;
    else if (ui->subtract_rb->isChecked())
        return 2;
    else if (ui->reselect_rb->isChecked())
        return 3;
    else
        return -1;
}

int MainWindow::ui_giveSelectionEntity()
{
    if (ui->selVolumes_rb->isChecked())
        return 0;
    else if (ui->selFaces_rb->isChecked())
        return 1;
    else if (ui->selEdges_rb->isChecked())
        return 2;
    else if (ui->selNodes_rb->isChecked())
        return 3;
    else
        return -1;
}

void MainWindow::onMouseModeClick()
{
    if (ui->mouseModeSel_rb->isChecked()) {
        mInteractorStyle->setModeToSelect();
        ui->selMode_gb->setEnabled(TRUE);
        ui->selMethod_gb->setEnabled(TRUE);
        ui->selEntity_gb->setEnabled(TRUE);
    }
    else {
        mInteractorStyle->setModeToOrient();
        ui->selMode_gb->setEnabled(FALSE);
        ui->selMethod_gb->setEnabled(FALSE);
        ui->selEntity_gb->setEnabled(FALSE);
    }
}

void MainWindow::onSelectionMethodClick()
{
    if (ui->selMethodBox_rb->isChecked()) {
        mInteractorStyle->setModeToSelect();
        ui->selSlide_gb->setEnabled(FALSE);
        mSelFunActor->SetVisibility(0);
        this->updateView();
    }
    else {
        mInteractorStyle->setModeToOrient();
        ui->selSlide_gb->setEnabled(TRUE);
        mSelFunActor->SetVisibility(1);
        this->updateSelFunRepresentation();
        this->updateView();
    }
}

void MainWindow::onSelectionModeClick()
{
//    if (ui->reselect_rb->isChecked())
//        model->SetModelToSelection();
//    else
//        model->SetModelToFull();
}

void MainWindow::initializeSelectionSlider()
{
    double* bounds = this->model->GetVisibleModel(0)->GetBounds();
    for (int k=0;k<6;k++)
        selBox[k] = bounds[k];

    ui->slideSelXm_spin->blockSignals(TRUE);
    ui->slideSelXp_spin->blockSignals(TRUE);
    ui->slideSelYm_spin->blockSignals(TRUE);
    ui->slideSelYp_spin->blockSignals(TRUE);
    ui->slideSelZm_spin->blockSignals(TRUE);
    ui->slideSelZp_spin->blockSignals(TRUE);
    ui->slideSelXm_slider->blockSignals(TRUE);
    ui->slideSelXp_slider->blockSignals(TRUE);
    ui->slideSelYm_slider->blockSignals(TRUE);
    ui->slideSelYp_slider->blockSignals(TRUE);
    ui->slideSelZm_slider->blockSignals(TRUE);
    ui->slideSelZp_slider->blockSignals(TRUE);

    ui->slideSelXm_spin->setMinimum(bounds[0]);
    ui->slideSelXm_spin->setMaximum(bounds[1]);
    ui->slideSelXm_spin->setValue(bounds[0]);
    ui->slideSelXp_spin->setMinimum(bounds[0]);
    ui->slideSelXp_spin->setMaximum(bounds[1]);
    ui->slideSelXp_spin->setValue(bounds[1]);
    ui->slideSelYm_spin->setMinimum(bounds[2]);
    ui->slideSelYm_spin->setMaximum(bounds[3]);
    ui->slideSelYm_spin->setValue(bounds[2]);
    ui->slideSelYp_spin->setMinimum(bounds[2]);
    ui->slideSelYp_spin->setMaximum(bounds[3]);
    ui->slideSelYp_spin->setValue(bounds[3]);
    ui->slideSelZm_spin->setMinimum(bounds[4]);
    ui->slideSelZm_spin->setMaximum(bounds[5]);
    ui->slideSelZm_spin->setValue(bounds[4]);
    ui->slideSelZp_spin->setMinimum(bounds[4]);
    ui->slideSelZp_spin->setMaximum(bounds[5]);
    ui->slideSelZp_spin->setValue(bounds[5]);

    ui->slideSelXm_slider->setValue(0);
    ui->slideSelXp_slider->setValue(100);
    ui->slideSelYm_slider->setValue(0);
    ui->slideSelYp_slider->setValue(100);
    ui->slideSelZm_slider->setValue(0);
    ui->slideSelZp_slider->setValue(100);

    ui->slideSelXm_spin->blockSignals(FALSE);
    ui->slideSelXp_spin->blockSignals(FALSE);
    ui->slideSelYm_spin->blockSignals(FALSE);
    ui->slideSelYp_spin->blockSignals(FALSE);
    ui->slideSelZm_spin->blockSignals(FALSE);
    ui->slideSelZp_spin->blockSignals(FALSE);
    ui->slideSelXm_slider->blockSignals(FALSE);
    ui->slideSelXp_slider->blockSignals(FALSE);
    ui->slideSelYm_slider->blockSignals(FALSE);
    ui->slideSelYp_slider->blockSignals(FALSE);
    ui->slideSelZm_slider->blockSignals(FALSE);
    ui->slideSelZp_slider->blockSignals(FALSE);

    this->updateView();
}

void MainWindow::updateSelFunRepresentation()
{
    vtkSmartPointer<vtkCubeSource> box = vtkSmartPointer<vtkCubeSource>::New();
    double xm = ui->slideSelXm_spin->value();
    double xp = ui->slideSelXp_spin->value();
    double ym = ui->slideSelYm_spin->value();
    double yp = ui->slideSelYp_spin->value();
    double zm = ui->slideSelZm_spin->value();
    double zp = ui->slideSelZp_spin->value();
    box->SetBounds(xm, xp, ym, yp, zm, zp);
    box->Update();

    vtkPolyData* aPD = vtkPolyData::SafeDownCast(box->GetOutput());
    mSelFunRepresentation->ShallowCopy(aPD);
}

void MainWindow::updateSelectionFunction()
{
    this->updateSelFunRepresentation();

    int entity = this->ui_giveSelectionEntity();

    vtkNew<vtkExtractGeometry> sel;
    sel->SetInputData(this->giveModel()->GetVisibleModel(entity));
    vtkSmartPointer<vtkBox> boxFunction = vtkSmartPointer<vtkBox>::New();
    double xm = ui->slideSelXm_spin->value();
    double xp = ui->slideSelXp_spin->value();
    double ym = ui->slideSelYm_spin->value();
    double yp = ui->slideSelYp_spin->value();
    double zm = ui->slideSelZm_spin->value();
    double zp = ui->slideSelZp_spin->value();
    boxFunction->SetBounds(xm, xp, ym, yp, zm, zp);
    sel->SetImplicitFunction(boxFunction);
    if (ui->selBoxInside_cb->isChecked())
        sel->SetExtractInside(TRUE);
    else
        sel->SetExtractInside(FALSE);
    if (ui->selBoxBoundary_cb->isChecked())
        sel->SetExtractBoundaryCells(TRUE);
    else
        sel->SetExtractBoundaryCells(FALSE);
    sel->Update();
    vtkUnstructuredGrid* UG = (static_cast<vtkUnstructuredGrid*>(sel->GetOutput()));

    int mode = 1;//this->ui_giveSelectionMode();

    if (UG->GetNumberOfCells()) {
        vtkIdTypeArray* Ids;
        if (entity == 0)
            Ids = static_cast<vtkIdTypeArray*>(UG->GetCellData()->GetArray("Element numbers"));
        else if (entity == 1)
            Ids = static_cast<vtkIdTypeArray*>(UG->GetCellData()->GetArray("Face numbers"));
        else if (entity == 2)
            Ids = static_cast<vtkIdTypeArray*>(UG->GetCellData()->GetArray("Edge numbers"));

        vtkSelectionNode* selectionNode = vtkSelectionNode::New();
        selectionNode->Initialize();
        selectionNode->SetFieldType(vtkSelectionNode::CELL);
        selectionNode->SetContentType(vtkSelectionNode::GLOBALIDS);
        selectionNode->SetSelectionList(Ids);

        this->giveModel()->UpdateSelection(entity, selectionNode, mode);

    }

    this->updateView();
}

void MainWindow::onLoadMeshClick() {
    // Read vtu mesh
    vtkSmartPointer<vtkXMLUnstructuredGridReader> reader = vtkSmartPointer<vtkXMLUnstructuredGridReader>::New();
    //reader->SetFileName("C:/Mandats/M100/dev/vtkQt/prepro/data/Schacht_vo_13_0.vtu");
    //reader->SetFileName("C:/Mandats/M100/dev/vtkQt/prepro/data/BFH_003_00-002_00_vol.vtu");
    reader->SetFileName("C:/Mandats/M100/dev/vtkQt/prepro/data/Biopole_013_00_vol.vtu");
    reader->Update();
    model->SetModel(reader->GetOutput());

    // Create the actor where the sphere is rendered
    vtkSmartPointer<vtkDataSetMapper> volMapper = vtkSmartPointer<vtkDataSetMapper>::New();
    volMapper->SetInputData(model->GetVisibleModel(0));

    vtkSmartPointer<vtkDataSetMapper> facMapper = vtkSmartPointer<vtkDataSetMapper>::New();
    facMapper->SetInputData(model->GetVisibleModel(1));

    vtkSmartPointer<vtkDataSetMapper> edgMapper = vtkSmartPointer<vtkDataSetMapper>::New();
    edgMapper->SetInputData(model->GetVisibleModel(2));

    vtkSmartPointer<vtkDataSetMapper> nodMapper = vtkSmartPointer<vtkDataSetMapper>::New();
    nodMapper->SetInputData(model->GetVisibleModel(3));

    mActor[0]->SetMapper(volMapper);
    mActor[1]->SetMapper(facMapper);
    mActor[1]->SetVisibility(0);
    mActor[2]->SetMapper(edgMapper);
    mActor[2]->SetVisibility(0);
    mActor[3]->SetMapper(nodMapper);
    mActor[3]->SetVisibility(0);


    vtkSmartPointer<vtkDataSetMapper> selVolMapper = vtkSmartPointer<vtkDataSetMapper>::New();
    selVolMapper->SetInputData(model->GetSelection(0));

    mSelActor[0]->SetMapper(selVolMapper);
    mSelActor[0]->SetVisibility(1);
    mSelActor[0]->GetProperty()->SetColor(this->getColors("Volumes selected"));

    vtkSmartPointer<vtkDataSetMapper> selFacMapper = vtkSmartPointer<vtkDataSetMapper>::New();
    selFacMapper->SetInputData(model->GetSelection(1));

    mSelActor[1]->SetMapper(selFacMapper);
    mSelActor[1]->SetVisibility(1);
    mSelActor[1]->GetProperty()->SetColor(this->getColors("Faces selected"));

    vtkSmartPointer<vtkDataSetMapper> selEdgMapper = vtkSmartPointer<vtkDataSetMapper>::New();
    selEdgMapper->SetInputData(model->GetSelection(2));

    mSelActor[2]->SetMapper(selEdgMapper);
    mSelActor[2]->SetVisibility(1);
    mSelActor[2]->GetProperty()->SetColor(this->getColors("Edges selected"));

    vtkSmartPointer<vtkDataSetMapper> selNodMapper = vtkSmartPointer<vtkDataSetMapper>::New();
    selNodMapper->SetInputData(model->GetSelection(3));

    mSelActor[3]->SetMapper(selNodMapper);
    mSelActor[3]->SetVisibility(1);
    mSelActor[3]->GetProperty()->SetColor(this->getColors("Nodes selected"));

    // Create a selection function actor
    vtkSmartPointer<vtkPolyDataMapper> selFunMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mSelFunRepresentation = vtkSmartPointer<vtkPolyData>::New();
    this->initializeSelectionSlider();
    selFunMapper->SetInputData(mSelFunRepresentation);
    mSelFunActor->SetMapper(selFunMapper);
    mSelFunActor->SetVisibility(0);
    mSelFunActor->GetProperty()->SetOpacity(0.5);
    mSelFunActor->GetProperty()->SetEdgeVisibility(1);
    mSelFunActor->GetProperty()->SetRenderLinesAsTubes(1);
    mSelFunActor->GetProperty()->SetLineWidth(2);
    mSelFunActor->GetProperty()->SetEdgeColor(1,0,0);

    mRenderer->AddActor(mSelFunActor);

    // Add the sphere to the OpenGL
    for (int k = 0;k < 4;k++) {
        mRenderer->AddViewProp(mActor[k]);
        mRenderer->AddViewProp(mSelActor[k]);
    }
    mRenderer->ResetCamera();

    this->updateView();
}

void MainWindow::onTranspVolSliderMoved()
{
    int pos = ui->transpVol_slider->value();
    //char msg[100];
    //sprintf_s(msg, "%d", pos);
    //MessageBoxA(NULL,msg, "Error", MB_ICONEXCLAMATION | MB_OK);
    mActor[0]->GetProperty()->SetOpacity((100. - pos) * 0.01);
    mSelActor[0]->GetProperty()->SetOpacity((100. - pos) * 0.01);

    this->updateView();
}

void MainWindow::onTranspFacSliderMoved()
{
    int pos = ui->transpFac_slider->value();
    mActor[1]->GetProperty()->SetOpacity((100. - pos) * 0.01);
    mSelActor[1]->GetProperty()->SetOpacity((100. - pos) * 0.01);

    this->updateView();
}

void MainWindow::onTranspEdgSliderMoved()
{
    int pos = ui->transpEdg_slider->value();
    mActor[2]->GetProperty()->SetOpacity((100. - pos) * 0.01);
    mSelActor[2]->GetProperty()->SetOpacity((100. - pos) * 0.01);

    this->updateView();
}

void MainWindow::onTranspNodSliderMoved()
{
    int pos = ui->transpNod_slider->value();
    mActor[3]->GetProperty()->SetOpacity((100. - pos) * 0.01);
    mSelActor[3]->GetProperty()->SetOpacity((100. - pos) * 0.01);

    this->updateView();
}

void MainWindow::updateSpinValue(int val)
{
    QSlider* obj = static_cast<QSlider*>(sender());
    int ind;
    QDoubleSpinBox* spin;
    if (obj == ui->slideSelXm_slider) {
        ind = 0;
        spin = ui->slideSelXm_spin;
    }
    else if (obj == ui->slideSelXp_slider) {
        ind = 0;
        spin = ui->slideSelXp_spin;
    }
    else if (obj == ui->slideSelYm_slider) {
        ind = 2;
        spin = ui->slideSelYm_spin;
    }
    else if (obj == ui->slideSelYp_slider) {
        ind = 2;
        spin = ui->slideSelYp_spin;
    }
    else if (obj == ui->slideSelZm_slider) {
        ind = 4;
        spin = ui->slideSelZm_spin;
    }
    else if (obj == ui->slideSelZp_slider) {
        ind = 4;
        spin = ui->slideSelZp_spin;
    }

    double spinVal = spin->value();
    double dx = selBox[ind+1] - selBox[ind];
    int slideVal = static_cast<int>((spinVal - selBox[ind]) / dx * 100);
    if (slideVal != obj->value()) {
        spin->setValue(selBox[ind] + dx * val * 0.01);
        this->updateSelectionFunction();
    }
}

void MainWindow::updateSlideValue(double val)
{
    QDoubleSpinBox* obj = static_cast<QDoubleSpinBox*>(sender());
    int ind;
    QSlider* slider;
    if (obj == ui->slideSelXm_spin) {
        ind = 0;
        slider = ui->slideSelXm_slider;
    }
    else if (obj == ui->slideSelXp_spin) {
        ind = 0;
        slider = ui->slideSelXp_slider;
    }
    else if (obj == ui->slideSelYm_spin) {
        ind = 2;
        slider = ui->slideSelYm_slider;
    }
    else if (obj == ui->slideSelYp_spin) {
        ind = 2;
        slider = ui->slideSelYp_slider;
    }
    else if (obj == ui->slideSelZm_spin) {
        ind = 4;
        slider = ui->slideSelZm_slider;
    }
    else if (obj == ui->slideSelZp_spin) {
        ind = 4;
        slider = ui->slideSelZp_slider;
    }
//    int currentSliderVal = slider->value();
    double newSpinVal = val;
    double dx = selBox[ind+1] - selBox[ind];
//    double oldSpinVal = selBox[ind] + dx * currentSliderVal * 0.01;
    int newSliderVal = static_cast<int>((newSpinVal - selBox[ind]) / dx * 100);
    slider->setSliderPosition(newSliderVal);
    this->updateSelectionFunction();
}
/*
void MainWindow::updateSlideValueXp(double val)
{
    int slideVal = ui->slideSelXp_slider->value();
    double dx = selBox[1] - selBox[0];
    double spinVal = slideVal + dx * slideVal * 0.01;
    if (slideVal != ui->slideSelXp_slider->value()){
        ui->slideSelXp_slider->setSliderPosition(static_cast<int>((spinVal - selBox[0]) / dx));
        this->updateSelectionFunction();
    }
}

void MainWindow::updateSlideValueYm(double val)
{
    int slideVal = ui->slideSelYm_slider->value();
    double dx = selBox[3] - selBox[2];
    double spinVal = slideVal + dx * slideVal * 0.01;
    if (slideVal != ui->slideSelYm_slider->value()){
        ui->slideSelYm_slider->setValue(static_cast<int>(spinVal - selBox[2]) / dx);
        this->updateSelectionFunction();
    }
}

void MainWindow::updateSlideValueYp(double val)
{
    int slideVal = ui->slideSelYp_slider->value();
    double dx = selBox[3] - selBox[2];
    double spinVal = slideVal + dx * slideVal * 0.01;
    if (slideVal != ui->slideSelYp_slider->value()){
        ui->slideSelYp_slider->setValue(static_cast<int>(spinVal - selBox[2]) / dx);
        this->updateSelectionFunction();
    }
}

void MainWindow::updateSlideValueZm(double val)
{
    int slideVal = ui->slideSelZm_slider->value();
    double dx = selBox[5] - selBox[4];
    double spinVal = slideVal + dx * slideVal * 0.01;
    if (slideVal != ui->slideSelZm_slider->value()){
        ui->slideSelZm_slider->setValue(static_cast<int>(spinVal - selBox[4]) / dx);
        this->updateSelectionFunction();
    }
}

void MainWindow::updateSlideValueZp(double val)
{
    int slideVal = ui->slideSelZp_slider->value();
    double dx = selBox[5] - selBox[4];
    double spinVal = slideVal + dx * slideVal * 0.01;
    if (slideVal != ui->slideSelZp_slider->value())
        ui->slideSelZp_slider->setValue(static_cast<int>(spinVal - selBox[4]) / dx);
}*/

void MainWindow::onShowSelectionClick()
{
    model->SetModelToSelection();
    for (int k = 1;k < 3;k++)
        model->GetDerivedModel(k);

    vtkSmartPointer<vtkDataSetMapper> mapper;
    for (int k = 0;k < 3;k++) {
        mapper = vtkSmartPointer<vtkDataSetMapper>::New();
        mapper->SetInputData(model->GetVisibleModel(k));

        this->mActor[k]->SetMapper(mapper);
    }
    this->updateView();
}

void MainWindow::onHideSelectionClick()
{
    model->SetModelToInverseSelection();
    for (int k = 1;k < 3;k++)
        model->GetDerivedModel(k);

    vtkSmartPointer<vtkDataSetMapper> mapper;
    for (int k = 0;k < 3;k++) {
        mapper = vtkSmartPointer<vtkDataSetMapper>::New();
        mapper->SetInputData(model->GetVisibleModel(k));

        this->mActor[k]->SetMapper(mapper);
    }
    this->updateView();
}

void MainWindow::onShowAllClick()
{
    model->SetModelToFull();
    for (int k = 1;k < 3;k++)
        model->GetDerivedModel(k);

    vtkSmartPointer<vtkDataSetMapper> mapper;
    for (int k = 0;k < 3;k++) {
        mapper = vtkSmartPointer<vtkDataSetMapper>::New();
        mapper->SetInputData(model->GetVisibleModel(k));

        this->mActor[k]->SetMapper(mapper);
    }
    this->updateView();
}

void MainWindow::onSelectEntitiesClick()
{/*
    if (ui->selVolumes_rb->isChecked())
        int a = 0;
    else if (ui->selFaces_rb->isChecked())
        model->UpdateDerivedModel(1);
    else if (ui->selEdges_rb->isChecked())
        model->UpdateDerivedModel(2);
    else if (ui->selNodes_rb->isChecked())
        model->UpdateDerivedModel(3);
    else
        int a = 0;*/
}

void MainWindow::onSelectAllClick()
{
    model->SetSelectionToVisible();

    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputData(model->GetSelection(0));

    this->mSelActor[0]->SetMapper(mapper);
    this->updateView();
}

void MainWindow::onSelectionInvertClick()
{
    model->SetSelectionToInverse();

    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputData(model->GetSelection(0));

    this->mSelActor[0]->SetMapper(mapper);
    this->updateView();
}

void MainWindow::onUnselectAllClick()
{
    model->SetSelectionToNone();

    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputData(model->GetSelection(0));

    this->mSelActor[0]->SetMapper(mapper);
    this->updateView();
}

void MainWindow::onExportAddClick()
{
    QPushButton* obj = static_cast<QPushButton*>(sender());
    vtkUnstructuredGrid* aMesh = vtkUnstructuredGrid::New();

    int row = ui->collections_table->rowCount();
    ui->collections_table->insertRow(row);
    ui->collections_table->setCellWidget(row,0,(new QCheckBox("")));
    QTableWidgetItem* newItem0;
    QTableWidgetItem* newItem1;
    if (obj == ui->expAddVol_pb) {
        newItem0 = new QTableWidgetItem(tr("Volumes"));
        newItem1 = new QTableWidgetItem(tr("Volumes"));
        aMesh->DeepCopy(model->GetSelection(0));
    }
    else if (obj == ui->expAddFac_pb) {
        newItem0 = new QTableWidgetItem(tr("Faces"));
        newItem1 = new QTableWidgetItem(tr("Faces"));
        aMesh->DeepCopy(model->GetSelection(1));
    }
    else if (obj == ui->expAddEdg_pb) {
        newItem0 = new QTableWidgetItem(tr("Edges"));
        newItem1 = new QTableWidgetItem(tr("Edges"));
        aMesh->DeepCopy(model->GetSelection(2));
    }
    else if (obj == ui->expAddNod_pb) {
        newItem0 = new QTableWidgetItem(tr("Nodes"));
        newItem1 = new QTableWidgetItem(tr("Nodes"));
        aMesh->DeepCopy(model->GetSelection(3));
    }
    collections.push_back(aMesh);
    ui->collections_table->setItem(row, 1, newItem0);
    ui->collections_table->setItem(row, 2, newItem1);
    QTableWidgetItem* newItem2 = new QTableWidgetItem(std::to_string(aMesh->GetNumberOfCells()).c_str());
    newItem2->setTextAlignment(Qt::AlignRight);
    ui->collections_table->setItem(row, 3, newItem2);

}

void MainWindow::onExportClick()
{
    vtkSmartPointer<vtkXMLUnstructuredGridWriter> w;
    for (int row = 0;row < ui->collections_table->rowCount();row++)
        if ((static_cast<QCheckBox*>(ui->collections_table->cellWidget(row, 0)))->isChecked()) {
            w = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
            std::string fname = (ui->collections_table->item(row, 1)->text().toStdString() +std::string(".vtu"));
            w->SetFileName(fname.c_str());
            w->SetInputData(collections[row]);
            w->Write();
        }
}

void MainWindow::onParallelProjectionClick()
{
    if (ui->viewParallelProjection_cb->isChecked())
        this->mRenderer->GetActiveCamera()->ParallelProjectionOn();
    else
        this->mRenderer->GetActiveCamera()->ParallelProjectionOff();
    this->updateView();
}

void MainWindow::onViewDirectionClick()
{
    QPushButton* obj = static_cast<QPushButton*>(sender());

    double* center = model->GetModel()->GetCenter();
    double* bounds = model->GetModel()->GetBounds();
    double dx = bounds[1] - bounds[0];
    double dy = bounds[3] - bounds[2];
    double dz = bounds[5] - bounds[4];

    //cout << this->mRenderer->GetActiveCamera()->GetClippingRange()[0] << "   " << this->mRenderer->GetActiveCamera()->GetClippingRange()[1] << endl;
    if (obj == ui->viewXm_pb) {
        this->mRenderer->GetActiveCamera()->SetPosition(center[0] - 5 * dx, center[1], center[2]);
        this->mRenderer->GetActiveCamera()->SetFocalPoint(bounds[0], center[1], center[2]);
        this->mRenderer->GetActiveCamera()->SetViewUp(0, 1, 0);
    }
    else if (obj == ui->viewXp_pb) {
        this->mRenderer->GetActiveCamera()->SetPosition(center[0] + 5 * dx, center[1], center[2]);
        this->mRenderer->GetActiveCamera()->SetFocalPoint(bounds[1], center[1], center[2]);
        this->mRenderer->GetActiveCamera()->SetViewUp(0, 1, 0);
    }
    else if (obj == ui->viewYm_pb) {
        this->mRenderer->GetActiveCamera()->SetPosition(center[0], center[1] - 5 * dy, center[2]);
        this->mRenderer->GetActiveCamera()->SetFocalPoint(center[0], bounds[2], center[2]);
        this->mRenderer->GetActiveCamera()->SetViewUp(0, 0, 1);
    }
    else if (obj == ui->viewYp_pb) {
        this->mRenderer->GetActiveCamera()->SetPosition(center[0], center[1] + 5 * dy, center[2]);
        this->mRenderer->GetActiveCamera()->SetFocalPoint(center[0], bounds[3], center[2]);
        this->mRenderer->GetActiveCamera()->SetViewUp(0, 0, 1);
    }
    else if (obj == ui->viewZm_pb) {
        this->mRenderer->GetActiveCamera()->SetPosition(center[0], center[1], center[2] - 5 * dz);
        this->mRenderer->GetActiveCamera()->SetFocalPoint(center[0], center[1], bounds[4]);
        this->mRenderer->GetActiveCamera()->SetViewUp(0, 1, 0);
    }
    else if (obj == ui->viewZp_pb) {
        this->mRenderer->GetActiveCamera()->SetPosition(center[0], center[1], center[2] + 5 * dz);
        this->mRenderer->GetActiveCamera()->SetFocalPoint(center[0], center[1], bounds[5]);
        this->mRenderer->GetActiveCamera()->SetViewUp(0, 1, 0);
    }
    this->mRenderer->ResetCamera();
    this->updateView();
}

void MainWindow::onDisplayVolClick()
{
    // Update visibility settings for volumes
    int disp_ind = ui->displayVol_combo->currentIndex();
    if (disp_ind == 0) {
        mActor[0]->GetProperty()->SetRepresentationToSurface();
        mActor[0]->GetProperty()->SetEdgeVisibility(0);
    }
    else if (disp_ind == 1) {
        mActor[0]->GetProperty()->SetRepresentationToSurface();
        mActor[0]->GetProperty()->SetEdgeVisibility(1);
    }
    else if (disp_ind == 2) {
        mActor[0]->GetProperty()->SetRepresentationToWireframe();
        mActor[0]->GetProperty()->SetEdgeVisibility(1);
    }

    if (ui->displayVol_cb->isChecked()) {
        mActor[0]->SetVisibility(1);
    }
    else
        mActor[0]->SetVisibility(0);
    if (ui->displayVolSel_cb->isChecked()) {
        mSelActor[0]->SetVisibility(1);
    }
    else
        mSelActor[0]->SetVisibility(0);

    this->updateView();
}

void MainWindow::onDisplayFacClick()
{
    // Update visibility settings for faces
    int fac_ind = ui->displayFac_combo->currentIndex();
    if (fac_ind == 0) {
        mActor[1]->GetProperty()->SetRepresentationToSurface();
        mActor[1]->GetProperty()->SetEdgeVisibility(0);
    }
    else if (fac_ind == 1) {
        mActor[1]->GetProperty()->SetRepresentationToSurface();
        mActor[1]->GetProperty()->SetEdgeVisibility(1);
    }
    else if (fac_ind == 2) {
        mActor[1]->GetProperty()->SetRepresentationToWireframe();
        mActor[1]->GetProperty()->SetEdgeVisibility(1);
    }

    if (ui->displayFac_cb->isChecked()) {
        mActor[1]->SetVisibility(1);
    }
    else
        mActor[1]->SetVisibility(0);
    if (ui->displayFacSel_cb->isChecked()) {
        mSelActor[1]->SetVisibility(1);
    }
    else
        mSelActor[1]->SetVisibility(0);

    this->updateView();
}

void MainWindow::onDisplayEdgClick()
{
    if (ui->displayEdg_cb->isChecked()) {
        mActor[2]->SetVisibility(1);
    }
    else
        mActor[2]->SetVisibility(0);
    if (ui->displayEdgSel_cb->isChecked()) {
        mSelActor[2]->SetVisibility(1);
    }
    else
        mSelActor[2]->SetVisibility(0);

    this->updateView();
}

void MainWindow::onDisplayNodClick()
{
    if (ui->displayNod_cb->isChecked()) {
        mActor[3]->SetVisibility(1);
    }
    else
        mActor[3]->SetVisibility(0);
    if (ui->displayNodSel_cb->isChecked()) {
        mSelActor[3]->SetVisibility(1);
    }
    else
        mSelActor[3]->SetVisibility(0);

    this->updateView();
}


void MainWindow::updateView()
{
    this->updateSelectionActors();
    mRenderWindow->Render();
}

void MainWindow::updateSelectionActors()
{
    for (int k = 0;k < 4;k++) {
        vtkSmartPointer<vtkDataSetMapper> selMapper = vtkSmartPointer<vtkDataSetMapper>::New();
        selMapper->SetInputData(model->GetSelection(k));

        mSelActor[k]->SetMapper(selMapper);
    }
}

vtkSmartPointer<vtkActor> MainWindow::giveActor(int obj_type)
{
    return mActor[obj_type];
}

vtkSmartPointer<vtkActor> MainWindow::giveSelectionActor(int obj_type)
{
    return mSelActor[obj_type];
}

double* MainWindow::getColors(vtkStdString aStr)
{
    double* a;
    vtkNew<vtkNamedColors> colors;
    if (!strcmp(aStr, "Volumes"))
        a = colors->GetColor3d("Pink").GetData();
    else if (!strcmp(aStr, "Volumes selected"))
        a = colors->GetColor3d("DeepPink").GetData();
    else if (!strcmp(aStr, "Edges"))
        a = colors->GetColor3d("Gold").GetData();
    else if (!strcmp(aStr, "Edges selected"))
        a = colors->GetColor3d("GreenYellow").GetData();
    else if (!strcmp(aStr, "Faces"))
        a = colors->GetColor3d("DodgerBlue").GetData();
    else if (!strcmp(aStr, "Faces selected"))
        a = colors->GetColor3d("Cyan").GetData();
    else if (!strcmp(aStr, "Nodes"))
        a = colors->GetColor3d("Red").GetData();
    else if (!strcmp(aStr, "Nodes selected"))
        a = colors->GetColor3d("IndianRed").GetData();
    else
        a = NULL;

    return a;
}

