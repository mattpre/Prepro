#ifndef MODEL_H
#define MODEL_H

#include <vtkUnstructuredGrid.h>
#include <vtkExtractSelectionBase.h>
#include <vtkSelectionNode.h>
#include <vtkSelection.h>
#include <vtkExtractSelection.h>

#include <MainWindow.h>

class Model
{

private:
    vtkSmartPointer<vtkUnstructuredGrid> mModel;
    vtkSmartPointer<vtkUnstructuredGrid> mModelVisible[4];
    int* visModelGeneration[4];

    vtkSmartPointer<vtkUnstructuredGrid> mSelection[4];
    vtkSmartPointer<vtkUnstructuredGrid> mInverseSelection[4];

    MainWindow* mainWindow;

    vtkSelection* selection[4];

public:
    explicit Model(MainWindow*);
    ~Model();

    int SetModel(vtkSmartPointer<vtkUnstructuredGrid>);

    vtkSmartPointer<vtkUnstructuredGrid> GetModel();
    vtkSmartPointer<vtkUnstructuredGrid> GetVisibleModel(int);
    vtkSmartPointer<vtkUnstructuredGrid> GetSelection(int);

    void UpdateSelection(int,vtkSmartPointer<vtkSelectionNode>,int);
    int SetSelection(int,vtkSmartPointer<vtkExtractSelectionBase>);
    void SetModelToSelection();
    void SetModelToInverseSelection();
    void SetModelToFull();
    void SetSelectionToVisible();
    void SetSelectionToNone();
    void SetSelectionToInverse();
    void GetDerivedModel(int);

};

#endif // MODEL_H
