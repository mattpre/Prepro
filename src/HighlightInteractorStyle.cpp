
#include <vtkActor.h>
#include <vtkAreaPicker.h>
#include <vtkDataSetMapper.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkExtractSelectedFrustum.h>
#include <vtkIdFilter.h>
#include <vtkIdTypeArray.h>
#include <vtkInteractorStyleRubberBandPick.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>
#include <vtkPlanes.h>
#include <vtkPointData.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkRendererCollection.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkUnstructuredGrid.h>
#include <vtkVersion.h>
#include <vtkVertexGlyphFilter.h>

#include <vtksys/SystemTools.hxx>
#include <HighlightInteractorStyle.h>
#include <MainWindow.h>
#include <Model.h>
#include <vtkSelectionNode.h>
#include <vtkDoubleArray.h>
#include <vtkSignedCharArray.h>
#include <vtkCellData.h>
#include <vtkUnstructuredGrid.h>
#include <vtkXMLUnstructuredGridWriter.h>

#include <Windows.h>


#define VTKISRBP_ORIENT 0
#define VTKISRBP_SELECT 1

vtkStandardNewMacro(HighlightInteractorStyle);

HighlightInteractorStyle::HighlightInteractorStyle()
{
    //this->SelectedMapper = vtkSmartPointer<vtkDataSetMapper>::New();
    //this->SelectedActor = vtkSmartPointer<vtkActor>::New();
    //this->SelectedActor->SetMapper(SelectedMapper);
    //this->mainWindow = aWin;
}

HighlightInteractorStyle::~HighlightInteractorStyle()
{
}

void HighlightInteractorStyle::setModeToOrient()
{
    this->CurrentMode = VTKISRBP_ORIENT;
}

void HighlightInteractorStyle::setModeToSelect()
{
    this->CurrentMode = VTKISRBP_SELECT;
}

void HighlightInteractorStyle::OnLeftButtonUp()
{
    // Forward events
    vtkInteractorStyleRubberBandPick::OnLeftButtonUp();
    
    if (this->CurrentMode == VTKISRBP_SELECT)
    {
        vtkSmartPointer<vtkAreaPicker> picker = static_cast<vtkAreaPicker*>(this->GetInteractor()->GetPicker());
        vtkPlanes* frustum = picker->GetFrustum();

        int entity = mainWindow->ui_giveSelectionEntity();
        int mode = mainWindow->ui_giveSelectionMode();
        if (mainWindow->giveActor(entity)->GetVisibility() || (mode == 2 || mode == 3)) {
            vtkSmartPointer<vtkUnstructuredGrid> theModel;
            //if (mode == 2 || mode == 3)
            //    theModel = this->mainWindow->giveModel()->GetSelection(entity);
            //else
            theModel = this->mainWindow->giveModel()->GetVisibleModel(entity);
            vtkNew<vtkExtractSelectedFrustum> sel;
            sel->SetInputData(theModel);
            sel->SetFrustum(frustum);
            sel->PreserveTopologyOff();
            sel->Update();
            vtkUnstructuredGrid* UG = (static_cast<vtkUnstructuredGrid*>(sel->GetOutput()));

            if (UG->GetNumberOfCells() || mode == 3) {
                vtkIdTypeArray* Ids = static_cast<vtkIdTypeArray*>(UG->GetCellData()->GetArray("Element numbers"));

                //char msg[100];
                //sprintf_s(msg, "%d %d", Ids->GetTuple1(Ids->GetNumberOfTuples()-100), theModel->GetNumberOfCells());
                //MessageBoxA(NULL, msg, "Error", MB_ICONEXCLAMATION | MB_OK);

                vtkSelectionNode* selectionNode = vtkSelectionNode::New();
                selectionNode->Initialize();
                selectionNode->SetFieldType(vtkSelectionNode::CELL);
                selectionNode->SetContentType(vtkSelectionNode::GLOBALIDS);
                selectionNode->SetSelectionList(Ids);

                this->mainWindow->giveModel()->UpdateSelection(entity,selectionNode,mode);
            }
        }
    }

    mainWindow->updateView();
}


