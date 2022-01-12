#ifndef HighlightInteractorStyle_H
#define HighlightInteractorStyle_H

#pragma once
#include <vtkInteractorStyleRubberBandPick.h>

class vtkUnstructuredGrid, vtkDataSetMapper;

class HighlightInteractorStyle :
    public vtkInteractorStyleRubberBandPick
{
public:
    static HighlightInteractorStyle* New();
    vtkTypeMacro(HighlightInteractorStyle, vtkInteractorStyleRubberBandPick);

    void OnLeftButtonUp() override;

private:
    vtkSmartPointer<vtkUnstructuredGrid> PolyData;
    vtkSmartPointer<vtkActor> SelectedActor;
    vtkSmartPointer<vtkDataSetMapper> SelectedMapper;
};

#endif // HighlightInteractorStyle_H