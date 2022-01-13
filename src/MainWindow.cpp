#include <MainWindow.h>
#include "ui_MainWindow.h"
#include <Model.h>

#include <vtkXMLUnstructuredGridReader.h>
#include <vtkUnstructuredGrid.h>
#include <vtkActor.h>
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

    for (int k = 0;k < 4;k++) {
        mActor[k] = vtkSmartPointer<vtkActor>::New();
        mSelActor[k] = vtkSmartPointer<vtkActor>::New();
    }
    mSelFunActor = vtkSmartPointer<vtkActor>::New();

    // Set the background color
    mRenderer->SetBackground(0, 0, 0);

    // Set the UI connections
    QObject::connect(ui->loadMesh_button, &QPushButton::clicked, this, &MainWindow::onLoadMeshClick);
    QObject::connect(ui->displayCheckBox_bg, &QButtonGroup::buttonClicked, this, &MainWindow::updateView);
    QObject::connect(ui->displayVol_combo, &QComboBox::currentIndexChanged, this, &MainWindow::updateView);
    QObject::connect(ui->displayFac_combo, &QComboBox::currentIndexChanged, this, &MainWindow::updateView);
    QObject::connect(ui->displayEdg_combo, &QComboBox::currentIndexChanged, this, &MainWindow::updateView);
    QObject::connect(ui->displayNod_combo, &QComboBox::currentIndexChanged, this, &MainWindow::updateView);
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

    QObject::connect(ui->transpVol_slider, &QSlider::valueChanged, this, &MainWindow::onTranspVolSliderMoved);
    QObject::connect(ui->transpFac_slider, &QSlider::valueChanged, this, &MainWindow::onTranspFacSliderMoved);
    QObject::connect(ui->transpEdg_slider, &QSlider::valueChanged, this, &MainWindow::onTranspEdgSliderMoved);
    QObject::connect(ui->transpNod_slider, &QSlider::valueChanged, this, &MainWindow::onTranspNodSliderMoved);
    QObject::connect(ui->slideSelXm_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValueXm);
    QObject::connect(ui->slideSelXp_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValueXp);
    QObject::connect(ui->slideSelYm_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValueYm);
    QObject::connect(ui->slideSelYp_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValueYp);
    QObject::connect(ui->slideSelZm_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValueZm);
    QObject::connect(ui->slideSelZp_slider, &QSlider::valueChanged, this, &MainWindow::updateSpinValueZp);
    QObject::connect(ui->slideSelXm_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValueXm);
    QObject::connect(ui->slideSelXp_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValueXp);
    QObject::connect(ui->slideSelYm_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValueYm);
    QObject::connect(ui->slideSelYp_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValueYp);
    QObject::connect(ui->slideSelZm_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValueZm);
    QObject::connect(ui->slideSelZp_spin, &QDoubleSpinBox::valueChanged, this, &MainWindow::updateSlideValueZp);
}

MainWindow::~MainWindow(){
    delete ui;
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

void MainWindow::updateSpinValueXm(int val)
{
    double spinVal = ui->slideSelXm_spin->value();
    double dx = selBox[1] - selBox[0];
    int slideVal = static_cast<int>((spinVal - selBox[0]) / dx * 100);
    if (slideVal != ui->slideSelXm_slider->value()) {
        ui->slideSelXm_spin->setValue(selBox[0] + dx * val * 0.01);
        this->updateSelectionFunction();
    }
}

void MainWindow::updateSpinValueXp(int val)
{
    double spinVal = ui->slideSelXp_spin->value();
    double dx = selBox[1] - selBox[0];
    int slideVal = static_cast<int>((spinVal - selBox[0]) / dx * 100);
    if (slideVal != ui->slideSelXp_slider->value()){
        ui->slideSelXp_spin->setValue(selBox[0] + dx * val * 0.01);
        this->updateSelectionFunction();
    }
}

void MainWindow::updateSpinValueYm(int val)
{
    double spinVal = ui->slideSelYm_spin->value();
    double dx = selBox[3] - selBox[2];
    int slideVal = static_cast<int>((spinVal - selBox[2]) / dx * 100);
    if (slideVal != ui->slideSelYm_slider->value()){
        ui->slideSelYm_spin->setValue(selBox[2] + dx * val * 0.01);
        this->updateSelectionFunction();
    }
}

void MainWindow::updateSpinValueYp(int val)
{
    double spinVal = ui->slideSelYp_spin->value();
    double dx = selBox[3] - selBox[2];
    int slideVal = static_cast<int>((spinVal - selBox[2]) / dx * 100);
    if (slideVal != ui->slideSelYp_slider->value()){
        ui->slideSelYp_spin->setValue(selBox[2] + dx * val * 0.01);
        this->updateSelectionFunction();
    }
}

void MainWindow::updateSpinValueZm(int val)
{
    double spinVal = ui->slideSelZm_spin->value();
    double dx = selBox[5] - selBox[4];
    int slideVal = static_cast<int>((spinVal - selBox[4]) / dx * 100);
    if (slideVal != ui->slideSelZm_slider->value()){
        ui->slideSelZm_spin->setValue(selBox[4] + dx * val * 0.01);
        this->updateSelectionFunction();
    }
}

void MainWindow::updateSpinValueZp(int val)
{
    double spinVal = ui->slideSelZp_spin->value();
    double dx = selBox[5] - selBox[4];
    int slideVal = static_cast<int>((spinVal - selBox[4]) / dx*100);
    if (slideVal != ui->slideSelZp_slider->value()){
        ui->slideSelZp_spin->setValue(selBox[4] + dx * val * 0.01);
        this->updateSelectionFunction();
    }
}

void MainWindow::updateSlideValueXm(double val)
{
    int slideVal = ui->slideSelXm_slider->value();
    double dx = selBox[1] - selBox[0];
    double spinVal = slideVal + dx * slideVal * 0.01;
    if (slideVal != ui->slideSelXm_slider->value()){
        ui->slideSelXm_slider->setSliderPosition(static_cast<int>((spinVal - selBox[0]) / dx));
        this->updateSelectionFunction();
    }
}

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
}

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

void MainWindow::updateView()
{
    //   char msg[100];
    //   sprintf_s(msg, "%d", ui->display_combo->currentIndex());
    //   MessageBoxA(NULL,msg, "Error", MB_ICONEXCLAMATION | MB_OK);

    //this->updateModelForReselection();

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
        mActor[0]->GetProperty()->SetColor(this->getColors("Volumes"));
    }
    else
        mActor[0]->SetVisibility(0);
    if (ui->displayVolSel_cb->isChecked()) {
        mSelActor[0]->SetVisibility(1);
        mSelActor[0]->GetProperty()->SetColor(this->getColors("Volumes selected"));
    }
    else
        mSelActor[0]->SetVisibility(0);

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
        mActor[1]->GetProperty()->SetRepresentationToSurface();
        mActor[1]->GetProperty()->SetEdgeVisibility(0);
        vtkSmartPointer<vtkDataSet> mm = mActor[1]->GetMapper()->GetInput();
    }

    if (ui->displayFac_cb->isChecked()) {
        mActor[1]->SetVisibility(1);
        mActor[1]->GetProperty()->SetColor(this->getColors("Faces"));
    }
    else
        mActor[1]->SetVisibility(0);
    if (ui->displayFacSel_cb->isChecked()) {
        mSelActor[1]->SetVisibility(1);
        mSelActor[1]->GetProperty()->SetColor(this->getColors("Faces selected"));
    }
    else
        mSelActor[1]->SetVisibility(0);

    if (ui->displayEdg_cb->isChecked()) {
        mActor[2]->SetVisibility(1);
        mActor[2]->GetProperty()->SetRenderLinesAsTubes(1);
        mActor[2]->GetProperty()->SetLineWidth(2);
        mActor[2]->GetProperty()->SetColor(this->getColors("Edges"));
    }
    else
        mActor[2]->SetVisibility(0);
    if (ui->displayEdgSel_cb->isChecked()) {
        mSelActor[2]->SetVisibility(1);
        mSelActor[2]->GetProperty()->SetRenderLinesAsTubes(1);
        mSelActor[2]->GetProperty()->SetLineWidth(2);
        mSelActor[2]->GetProperty()->SetColor(this->getColors("Edges selected"));
    }
    else
        mSelActor[2]->SetVisibility(0);

    if (ui->displayNod_cb->isChecked()) {
        mActor[3]->SetVisibility(1);
        mActor[3]->GetProperty()->SetRenderLinesAsTubes(1);
        mActor[3]->GetProperty()->SetRenderPointsAsSpheres(1);
        mActor[3]->GetProperty()->SetVertexVisibility(1);
        mActor[3]->GetProperty()->SetPointSize(400);
        mActor[3]->GetProperty()->SetColor(this->getColors("Nodes"));
    }
    else
        mActor[3]->SetVisibility(0);
    if (ui->displayNodSel_cb->isChecked()) {
        mSelActor[3]->SetVisibility(1);
        mSelActor[3]->GetProperty()->SetRenderLinesAsTubes(1);
        mSelActor[3]->GetProperty()->SetRenderPointsAsSpheres(1);
        mSelActor[3]->GetProperty()->SetVertexVisibility(1);
        mSelActor[3]->GetProperty()->SetPointSize(400);
        mSelActor[3]->GetProperty()->SetColor(this->getColors("Nodes selected"));
    }
    else
        mSelActor[3]->SetVisibility(0);

    this->updateSelection();

    mRenderWindow->Render();

    //char msg[100];
    //sprintf_s(msg, "%d", model->GetVisibleFaceModel());
    //MessageBoxA(NULL,msg, "Error", MB_ICONEXCLAMATION | MB_OK);
}

void MainWindow::updateSelection()
{
    for (int k = 0;k < 4;k++) {
        vtkSmartPointer<vtkDataSetMapper> selMapper = vtkSmartPointer<vtkDataSetMapper>::New();
        selMapper->SetInputData(model->GetSelection(k));

        mSelActor[k]->SetMapper(selMapper);
        //mSelActor[k]->SetVisibility(1);
    }
    mSelActor[0]->GetProperty()->SetColor(this->getColors("Volumes selected"));
    mSelActor[0]->GetProperty()->SetEdgeVisibility(1);
    mSelActor[1]->GetProperty()->SetColor(this->getColors("Faces selected"));
    mSelActor[1]->GetProperty()->SetEdgeVisibility(1);
    mSelActor[2]->GetProperty()->SetColor(this->getColors("Edges selected"));
    mSelActor[2]->GetProperty()->SetRenderLinesAsTubes(1);
    mSelActor[2]->GetProperty()->SetLineWidth(3);
    mSelActor[3]->GetProperty()->SetColor(this->getColors("Nodes selected"));
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

