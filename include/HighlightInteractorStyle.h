#ifndef HighlightInteractorStyle_H
#define HighlightInteractorStyle_H

#include <vtkInteractorStyleRubberBandPick.h>
//#include <MainWindow.h>

class vtkDataSetMapper;
class vtkUnstructuredGrid;
class MainWindow;


class HighlightInteractorStyle :
    public vtkInteractorStyleRubberBandPick
{
public:
    static HighlightInteractorStyle* New();
    vtkTypeMacro(HighlightInteractorStyle, vtkInteractorStyleRubberBandPick);

    void OnLeftButtonUp();

    void setMainWindow(MainWindow* aWin) { this->mainWindow = aWin; };
    void setModeToSelect();
    void setModeToOrient();

protected:
    HighlightInteractorStyle();
    ~HighlightInteractorStyle();

private:
    MainWindow* mainWindow;

    vtkSmartPointer<vtkUnstructuredGrid> PolyData;
    vtkSmartPointer<vtkActor> SelectedActor;
    vtkSmartPointer<vtkDataSetMapper> SelectedMapper;
};

#endif // HighlightInteractorStyle_H