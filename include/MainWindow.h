#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <QVTKInteractor.h>
#include <vtkInteractorStyle.h>
#include <vtkColor.h>
#include <vtkPolyData.h>
#include <vtkInteractorStyleRubberBandPick.h>
#include <HighlightInteractorStyle.h>

class Model;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;

    vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow;
    vtkSmartPointer<vtkRenderer> mRenderer;
    vtkSmartPointer<QVTKInteractor> mInteractor;
    vtkSmartPointer<HighlightInteractorStyle> mInteractorStyle;

    vtkSmartPointer<vtkActor> mActor[4];
    vtkSmartPointer<vtkActor> mSelActor[4];
    vtkSmartPointer<vtkActor> mSelFunActor;

    double selBox[6];
    vtkSmartPointer<vtkPolyData> mSelFunRepresentation;

    Model* model;

    std::vector<vtkUnstructuredGrid*> collections;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Model* giveModel() { return model; };
    int ui_giveSelectionMode();
    int ui_giveSelectionEntity();
    vtkSmartPointer<vtkActor> giveActor(int);
    vtkSmartPointer<vtkActor> giveSelectionActor(int);
    double* getColors(vtkStdString);
    void initializeSelectionSlider();
    void initializeActors();
    void updateSelFunRepresentation();
    void updateSelectionFunction();
    void updateSelectionActors();

public slots:
    void onLoadMeshClick();
    void updateView();
    void onSelectionModeClick();
    void onMouseModeClick();
    void onSelectionMethodClick();
    void onTranspVolSliderMoved();
    void onTranspFacSliderMoved();
    void onTranspEdgSliderMoved();
    void onTranspNodSliderMoved();
    void onShowSelectionClick();
    void onHideSelectionClick();
    void onShowAllClick();
    void onSelectEntitiesClick();
    void onSelectAllClick();
    void onSelectionInvertClick();
    void onUnselectAllClick();
    void onExportAddClick();
    void onExportClick();
    void onParallelProjectionClick();
    void onViewDirectionClick();
    void onDisplayVolClick();
    void onDisplayFacClick();
    void onDisplayEdgClick();
    void onDisplayNodClick();

    void updateSpinValue(int);
    void updateSlideValue(double);
};

#endif // MAINWINDOW_H
