#include <Model.h>
#include <Windows.h>

#include <vtkCellData.h>
#include <vtkPointData.h>
#include <vtkGeometryFilter.h>
#include <vtkExtractEdges.h>
#include <vtkAppendFilter.h>
#include <vtkVoxel.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkGlyph3D.h>
#include <vtkCubeSource.h>
#include <vtkExtractSelectionBase.h>
#include <vtkSelection.h>
#include <vtkMapper.h>
#include <vtkInformation.h>
#include <vtkShrinkFilter.h>


Model::Model(MainWindow* aWin) 
{
	mainWindow = aWin;

	for (int k = 0;k < 4;k++) {
		// Create a selection per entity type and initialize it with an empty selection node
		vtkSmartPointer<vtkIdTypeArray> Ids = vtkSmartPointer<vtkIdTypeArray>::New();
		Ids->SetName("Element numbers");

		vtkSelectionNode* selectionNode = vtkSelectionNode::New();
		selectionNode->Initialize();
		selectionNode->SetFieldType(vtkSelectionNode::CELL);
		selectionNode->SetContentType(vtkSelectionNode::GLOBALIDS);
		selectionNode->SetSelectionList(Ids);

		selection[k] = vtkSelection::New();
		selection[k]->AddNode(selectionNode);

		mSelection[k] = NULL;
		this->visModelGeneration[k] = 0;
	}
}

Model::~Model(){
}

int Model::SetModel(vtkSmartPointer<vtkUnstructuredGrid> aMesh) {
	mModel = aMesh;
	int k;

	// Set element and node number arrays
	vtkSmartPointer<vtkIdTypeArray> elenum = vtkSmartPointer<vtkIdTypeArray>::New();
	elenum->SetName("Element numbers");
	for (k = 0;k < mModel->GetNumberOfCells();k++) {
		elenum->InsertNextTuple1(k);
	}
	mModel->GetCellData()->AddArray(elenum);
	mModel->GetCellData()->SetActiveGlobalIds("Element numbers");

	vtkSmartPointer<vtkIdTypeArray> nnum = vtkSmartPointer<vtkIdTypeArray>::New();
	nnum->SetName("Node numbers");
	for (k = 0;k < mModel->GetNumberOfPoints();k++)
		nnum->InsertNextTuple1(k);
	mModel->GetPointData()->AddArray(nnum);
	mModel->GetPointData()->SetActiveGlobalIds("Node numbers");

	mModelVisible[0] = vtkSmartPointer<vtkUnstructuredGrid> ::New();
	mModelVisible[0]->DeepCopy(mModel);

	return 0;
}

vtkSmartPointer<vtkUnstructuredGrid> Model::GetModel() {
	if (mModel)
		return mModel;
	else
		// Error
		return NULL;
}

void Model::SetModelToSelection()
{
	// Volume model
	mModelVisible[0]->ShallowCopy(mSelection[0]);
	/*
	selection[0]->Initialize();
	vtkIdTypeArray* Ids = static_cast<vtkIdTypeArray*>(mModelVisible[0]->GetCellData()->GetArray("Element numbers"));
	vtkSelectionNode* selectionNode = vtkSelectionNode::New();
	selectionNode->Initialize();
	selectionNode->SetFieldType(vtkSelectionNode::CELL);
	selectionNode->SetContentType(vtkSelectionNode::GLOBALIDS);
	selectionNode->SetSelectionList(Ids);
	selection[0]->AddNode(selectionNode);*/
}

void Model::SetModelToInverseSelection()
{
	// Volume model
	mModelVisible[0]->DeepCopy(mInverseSelection[0]);

	this->SetSelectionToNone();
}

void Model::SetModelToFull()
{
	mModelVisible[0]->DeepCopy(mModel);
}

void Model::SetSelectionToVisible()
{
	vtkSmartPointer<vtkIdTypeArray> Ids = static_cast<vtkIdTypeArray*>(mModelVisible[0]->GetCellData()->GetArray("Element numbers"));

	vtkSelectionNode* selectionNode = vtkSelectionNode::New();
	selectionNode->Initialize();
	selectionNode->SetFieldType(vtkSelectionNode::CELL);
	selectionNode->SetContentType(vtkSelectionNode::GLOBALIDS);
	selectionNode->SetSelectionList(Ids);

	this->UpdateSelection(0, selectionNode, 1);
}

void Model::SetSelectionToNone()
{
	vtkSmartPointer<vtkIdTypeArray> Ids = vtkSmartPointer<vtkIdTypeArray>::New();
	Ids->SetName("Element numbers");

	vtkSelectionNode* selectionNode = vtkSelectionNode::New();
	selectionNode->Initialize();
	selectionNode->SetFieldType(vtkSelectionNode::CELL);
	selectionNode->SetContentType(vtkSelectionNode::GLOBALIDS);
	selectionNode->SetSelectionList(Ids);

	this->UpdateSelection(0, selectionNode, 1);
}

void Model::SetSelectionToInverse()
{
	vtkIdTypeArray* Ids0 = static_cast<vtkIdTypeArray*>(mModelVisible[0]->GetCellData()->GetArray("Element numbers"));
	/*std::ofstream myfile;
	myfile.open("Ids0.txt");
	for (int k = 0;k < Ids0->GetNumberOfTuples();k++)
		myfile << Ids0->GetTuple1(k) << endl;
	myfile.close();*/
	vtkSmartPointer<vtkIdTypeArray> Ids2 = vtkSmartPointer<vtkIdTypeArray>::New();
	vtkIdTypeArray* Ids1;
	if (selection[0]->GetNumberOfNodes()) {
		Ids1 = static_cast<vtkIdTypeArray*>(selection[0]->GetNode(0)->GetSelectionList());
		for (int k = 0;k < mModelVisible[0]->GetNumberOfCells();k++)
			if (Ids1->LookupValue(Ids0->GetTuple1(k)) == -1)
				Ids2->InsertNextTuple1(Ids0->GetTuple1(k));
	}
	else
		for (int k = 0;k < mModelVisible[0]->GetNumberOfCells();k++)
				Ids2->InsertNextTuple1(Ids0->GetTuple1(k));
	/*myfile.open("Ids1.txt");
	for (int k = 0;k < Ids1->GetNumberOfTuples();k++)
		myfile << Ids1->GetTuple1(k) << endl;
	myfile.close();
	myfile.open("Ids2.txt");
	for (int k = 0;k < Ids2->GetNumberOfTuples();k++)
		myfile << Ids2->GetTuple1(k) << endl;
	myfile.close();*/

	vtkSelectionNode* selectionNode = vtkSelectionNode::New();
	selectionNode->Initialize();
	selectionNode->SetFieldType(vtkSelectionNode::CELL);
	selectionNode->SetContentType(vtkSelectionNode::GLOBALIDS);
	selectionNode->SetSelectionList(Ids2);

	this->UpdateSelection(0, selectionNode, 1);
	/*
	vtkSmartPointer<vtkUnstructuredGrid> temp = mSelection[0];
	mSelection[0] = mInverseSelection[0];
	mInverseSelection[0] = temp;

	vtkIdTypeArray* Ids0 = static_cast<vtkIdTypeArray*>(selection[0]->GetNode(0)->GetSelectionList());
	vtkSmartPointer<vtkIdTypeArray> Ids1 = vtkSmartPointer<vtkIdTypeArray>::New();
	for (int k = 0;k < mModelVisible[0]->GetNumberOfCells();k++)
		if (Ids0->LookupValue(k)==-1)
			Ids1->InsertNextTuple1(k);

	selection[0]->GetNode(0)->SetSelectionList(Ids1);*/
}
/*
void Model::UpdateDerivedModel(int entity)
{
	if (entity == 1) {
		// Face model
		vtkSmartPointer<vtkShrinkFilter> sf = vtkSmartPointer<vtkShrinkFilter>::New();
		sf->SetInputData(mModelVisible[0]);
		sf->SetShrinkFactor(0.8);
		sf->Update();
		vtkSmartPointer<vtkGeometryFilter> gf = vtkSmartPointer<vtkGeometryFilter>::New();
		gf->SetInputConnection(sf->GetOutputPort());
		gf->Update();
		vtkSmartPointer<vtkAppendFilter> af1 = vtkSmartPointer<vtkAppendFilter>::New();
		af1->SetInputConnection(gf->GetOutputPort());
		af1->Update();
		mModelVisible[1] = af1->GetOutput();

		this->renumberEntities(mModelVisible[1]);
	}
	else if (entity == 2) {
		// Edge model
		vtkSmartPointer<vtkExtractEdges> ee2 = vtkSmartPointer<vtkExtractEdges>::New();
		ee2->SetInputData(mModelVisible[0]);
		ee2->Update();
		vtkSmartPointer<vtkAppendFilter> af2 = vtkSmartPointer<vtkAppendFilter>::New();
		af2->SetInputConnection(ee2->GetOutputPort());
		af2->Update();
		mModelVisible[2] = af2->GetOutput();

		this->renumberEntities(mModelVisible[2]);
	}
	else if (entity == 3) {
		// Node model
		vtkSmartPointer<vtkExtractEdges> ee3 = vtkSmartPointer<vtkExtractEdges>::New();
		ee3->SetInputData(mModelVisible[0]);
		ee3->Update();

		vtkNew<vtkCubeSource> cubeSource;
		cubeSource->SetXLength(0.2);
		cubeSource->SetYLength(0.2);
		cubeSource->SetZLength(0.2);
		vtkNew<vtkGlyph3D> glyph3D;
		glyph3D->SetInputConnection(ee3->GetOutputPort());
		glyph3D->SetSourceConnection(cubeSource->GetOutputPort());
		glyph3D->ScalingOff();
		glyph3D->Update();

		vtkSmartPointer<vtkAppendFilter> af3 = vtkSmartPointer<vtkAppendFilter>::New();
		af3->SetInputConnection(glyph3D->GetOutputPort());
		af3->Update();
		mModelVisible[3] = af3->GetOutput();
	}
	else {
		//Error
	}

}*/

void Model::UpdateSelection(int entity,vtkSmartPointer<vtkSelectionNode> selNode,int selection_mode)
{
	// Update the selection according to the selected boolean selection mode
	vtkExtractSelection* ext = vtkExtractSelection::New();
	ext->SetInputData(0, mModelVisible[entity]);
	ext->SetInputData(1, selection[entity]);

	vtkSmartPointer<vtkUnstructuredGrid> emptyUG = vtkSmartPointer<vtkUnstructuredGrid>::New();
	vtkSmartPointer<vtkIdTypeArray> Ids = vtkSmartPointer<vtkIdTypeArray>::New();
	Ids->SetName("Element numbers");
	emptyUG->GetCellData()->AddArray(Ids);
	emptyUG->GetCellData()->SetActiveGlobalIds("Element numbers");

	bool emptySelection = FALSE;

	// Intersection of two selection nodes is computed manually
	if (selection[entity]->GetNumberOfNodes() == 0) {
		vtkSelectionNode* emptyNode = vtkSelectionNode::New();
		emptyNode->Initialize();
		emptyNode->SetFieldType(vtkSelectionNode::CELL);
		emptyNode->SetContentType(vtkSelectionNode::GLOBALIDS);
		emptyNode->SetSelectionList(Ids);
		selection[entity]->AddNode(emptyNode);
	}

	vtkIdTypeArray* Ids0 = static_cast<vtkIdTypeArray*>(selection[entity]->GetNode(0)->GetSelectionList());
	vtkIdTypeArray* Ids1 = static_cast<vtkIdTypeArray*>(selNode->GetSelectionList());
	std::vector<int> ids0;
	for (int k = 0;k < Ids0->GetNumberOfTuples();k++)
		ids0.push_back(Ids0->GetTuple1(k));
	std::vector<int> ids1;
	for (int k = 0;k < Ids1->GetNumberOfTuples();k++)
		ids1.push_back(Ids1->GetTuple1(k));
	std::vector<int> bool_op;

	if (selection_mode == 0) {
		std::set_union(ids0.begin(), ids0.end(), ids1.begin(), ids1.end(), std::back_inserter(bool_op));
	}
	else if (selection_mode == 1) {
		ids0.clear();
		std::set_union(ids0.begin(), ids0.end(), ids1.begin(), ids1.end(), std::back_inserter(bool_op));
	}
	else if (selection_mode == 2) {
		std::set_difference(ids0.begin(), ids0.end(), ids1.begin(), ids1.end(), std::back_inserter(bool_op));
	}
	else if (selection_mode == 3) {
		std::set_intersection(ids0.begin(), ids0.end(), ids1.begin(), ids1.end(), std::back_inserter(bool_op));

	}

	vtkSmartPointer<vtkIdTypeArray> BooleanResult = vtkSmartPointer<vtkIdTypeArray>::New();
	for (int k = 0;k < bool_op.size();k++)
		BooleanResult->InsertNextTuple1(bool_op[k]);
	vtkSelectionNode* selectionNode = vtkSelectionNode::New();
	selectionNode->Initialize();
	selectionNode->SetFieldType(vtkSelectionNode::CELL);
	selectionNode->SetContentType(vtkSelectionNode::GLOBALIDS);
	selectionNode->SetSelectionList(BooleanResult);

	selection[entity]->Initialize();
	selection[entity]->AddNode(selectionNode);

	if (emptySelection)
		mSelection[entity] = emptyUG;
	else {
		ext->Update();
		mSelection[entity]->ShallowCopy(ext->GetOutput());
//		std::cout << mSelection[entity]->GetNumberOfCells() << endl;

		selection[entity]->GetNode(0)->GetProperties()->Set(vtkSelectionNode::INVERSE(), 1);
		ext->Update();
		mInverseSelection[entity]->ShallowCopy(ext->GetOutput());
		//std::cout << mSelection[entity]->GetNumberOfCells() << endl;

		//this->renumberEntities(mSelection[entity]);
		//this->renumberEntities(mInverseSelection[entity]);
	}

	/*vtkSmartPointer<vtkXMLUnstructuredGridWriter> w = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
	w->SetFileName("selection.vtu");
	w->SetInputConnection(ext->GetOutputPort());
	w->Write();*/
	
}

void Model::renumberEntities(vtkSmartPointer<vtkUnstructuredGrid> model)
{
	if (model->GetNumberOfCells()) {
		vtkSmartPointer<vtkIdTypeArray> Ids = vtkSmartPointer<vtkIdTypeArray>::New();
		Ids->SetName("Ids");
		for (int k = 0;k < model->GetNumberOfCells();k++) {
			Ids->InsertNextTuple1(k);
		}
		model->GetCellData()->GetAbstractArray("Ids")->DeepCopy(Ids);
	}
}

vtkSmartPointer<vtkUnstructuredGrid> Model::GetVisibleModel(int entity)
{
	if (!mModelVisible[entity]) {
		if (entity == 0)
			// Error
			return NULL;
		else
			return NULL;
			//this->UpdateDerivedModels();
	}

	return mModelVisible[entity];
}

vtkSmartPointer<vtkUnstructuredGrid> Model::GetSelection(int entity)
{
	if (!mSelection[entity]) {
		mSelection[entity] = vtkSmartPointer<vtkUnstructuredGrid>::New();
		mInverseSelection[entity] = vtkSmartPointer<vtkUnstructuredGrid>::New();
	}
	return mSelection[entity];
}

void Model::shrinkFaceModel(double fac)
{
	vtkSmartPointer<vtkShrinkFilter> sf = vtkSmartPointer<vtkShrinkFilter>::New();
	sf->SetInputData(mModelVisible[1]);
	sf->SetShrinkFactor(fac);
	sf->Update();

	mModelVisible[1] = sf->GetOutput();
}

