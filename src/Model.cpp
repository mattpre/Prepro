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
#include <vtkUnstructuredGridGeometryFilter.h>
#include <vtkLinearExtrusionFilter.h>
#include <vtkPolyDataNormals.h>
#include <vtkMeshQuality.h>


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

void Model::GetDerivedModel(int entity)
{
	if (entity == 1) {
		// Face model
		mModelVisible[0]->GetCellData()->SetActiveGlobalIds("");
		vtkSmartPointer<vtkUnstructuredGridGeometryFilter> gf = vtkSmartPointer<vtkUnstructuredGridGeometryFilter>::New();
		gf->SetInputData(mModelVisible[0]);
		gf->Update();
		vtkSmartPointer<vtkShrinkFilter> sf = vtkSmartPointer<vtkShrinkFilter>::New();
		sf->SetInputConnection(gf->GetOutputPort());
		sf->SetShrinkFactor(0.8);
		sf->Update();
		vtkSmartPointer<vtkGeometryFilter> gf2 = vtkSmartPointer<vtkGeometryFilter>::New();
		gf2->SetInputConnection(sf->GetOutputPort());
		gf2->Update();
		vtkSmartPointer<vtkPolyDataNormals> pdn = vtkSmartPointer<vtkPolyDataNormals>::New();
		pdn->SetInputConnection(gf2->GetOutputPort());
		pdn->Update();
		//vtkSmartPointer<vtkPolyData> shrink = sf->GetOutput();
		vtkSmartPointer<vtkMeshQuality> mq = vtkSmartPointer<vtkMeshQuality>::New();
		mq->SetInputConnection(pdn->GetOutputPort());
		mq->SetTriangleQualityMeasureToRelativeSizeSquared();
		mq->Update();
		vtkDataArray* quality = mq->GetOutput()->GetCellData()->GetArray("Quality");
		std::vector<double> aa;
		for (int k = 0;k < quality->GetNumberOfTuples();k++)
			aa.push_back(quality->GetTuple1(k));
		double mean = std::accumulate(aa.begin(), aa.end(), 0.0) / aa.size();
		vtkSmartPointer<vtkLinearExtrusionFilter> extf = vtkSmartPointer<vtkLinearExtrusionFilter>::New();
		extf->SetInputConnection(pdn->GetOutputPort());
		extf->SetExtrusionTypeToNormalExtrusion();
		extf->SetCapping(TRUE);
		extf->SetScaleFactor(0.1*sqrt(mean));
		extf->Update();
		vtkSmartPointer<vtkAppendFilter> af1 = vtkSmartPointer<vtkAppendFilter>::New();
		af1->SetInputConnection(extf->GetOutputPort());
		af1->Update();
		mModelVisible[1] = af1->GetOutput();
		mModelVisible[0]->GetCellData()->SetActiveGlobalIds("Element numbers");
		// Create a new global Id Array for selection operations
		vtkIdTypeArray* Ids = vtkIdTypeArray::New();
		Ids->SetName("Face numbers");
		for (int k = 0;k < mModelVisible[1]->GetNumberOfCells();k++)
			Ids->InsertNextTuple1(k);
		mModelVisible[1]->GetCellData()->AddArray(Ids);
		mModelVisible[1]->GetCellData()->SetActiveGlobalIds("Face numbers");

		//this->renumberEntities(mModelVisible[1]);
	}
	else if (entity == 2) {
		// Edge model
		mModelVisible[0]->GetCellData()->SetActiveGlobalIds("");
		vtkSmartPointer<vtkUnstructuredGridGeometryFilter> gf = vtkSmartPointer<vtkUnstructuredGridGeometryFilter>::New();
		gf->SetInputData(mModelVisible[0]);
		gf->Update();
		vtkSmartPointer<vtkExtractEdges> ee2 = vtkSmartPointer<vtkExtractEdges>::New();
		ee2->SetInputConnection(gf->GetOutputPort());
		ee2->Update();
		vtkSmartPointer<vtkAppendFilter> af2 = vtkSmartPointer<vtkAppendFilter>::New();
		af2->SetInputConnection(ee2->GetOutputPort());
		af2->Update();
		mModelVisible[2] = af2->GetOutput();
		mModelVisible[0]->GetCellData()->SetActiveGlobalIds("Element numbers");
		// Create a new global Id Array for selection operations
		vtkIdTypeArray* Ids = vtkIdTypeArray::New();
		Ids->SetName("Edge numbers");
		for (int k = 0;k < mModelVisible[2]->GetNumberOfCells();k++)
			Ids->InsertNextTuple1(k);
		mModelVisible[2]->GetCellData()->AddArray(Ids);
		mModelVisible[2]->GetCellData()->SetActiveGlobalIds("Edge numbers");

		//this->renumberEntities(mModelVisible[2]);
	}
	else if (entity == 3) {
		// Node model
		mModelVisible[0]->GetPointData()->SetActiveGlobalIds("");
		vtkSmartPointer<vtkExtractEdges> ee3 = vtkSmartPointer<vtkExtractEdges>::New();
		ee3->SetInputData(mModelVisible[0]);
		ee3->Update();

		vtkSmartPointer<vtkMeshQuality> mq = vtkSmartPointer<vtkMeshQuality>::New();
		mq->SetInputData(mModelVisible[0]);
		mq->SetHexQualityMeasureToRelativeSizeSquared();
		mq->Update();
		vtkDataArray* quality = mq->GetOutput()->GetCellData()->GetArray("Quality");
		std::vector<double> aa;
		for (int k = 0;k < quality->GetNumberOfTuples();k++)
			aa.push_back(quality->GetTuple1(k));
		double dl = pow(std::accumulate(aa.begin(), aa.end(), 0.0) / aa.size(),1./3);

		vtkNew<vtkCubeSource> cubeSource;
		cubeSource->SetXLength(0.2*dl);
		cubeSource->SetYLength(0.2*dl);
		cubeSource->SetZLength(0.2*dl);
		vtkNew<vtkGlyph3D> glyph3D;
		glyph3D->SetInputConnection(ee3->GetOutputPort());
		glyph3D->SetSourceConnection(cubeSource->GetOutputPort());
		glyph3D->ScalingOff();
		glyph3D->Update();

		vtkSmartPointer<vtkAppendFilter> af3 = vtkSmartPointer<vtkAppendFilter>::New();
		af3->SetInputConnection(glyph3D->GetOutputPort());
		af3->Update();
		mModelVisible[3] = af3->GetOutput();
		mModelVisible[0]->GetPointData()->SetActiveGlobalIds("Node numbers");
		mModelVisible[3]->GetPointData()->SetActiveGlobalIds("Node numbers");
	}
	else {
		//Error
	}

}

void Model::UpdateSelection(int entity, vtkSmartPointer<vtkSelectionNode> selNode, int selection_mode)
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
		/*std::ofstream myfile;
		myfile.open("sel0.txt");
		for (std::vector<int>::iterator k = ids0.begin(); k < ids0.end(); k++)
			myfile << k[0] << endl;
		myfile.close();
		myfile.open("sub.txt");
		for (std::vector<int>::iterator k = ids1.begin(); k < ids1.end(); k++)
			myfile << k[0] << endl;
		myfile.close();
		myfile.open("res.txt");
		for (std::vector<int>::iterator k = bool_op.begin(); k < bool_op.end(); k++)
			myfile << k[0] << endl;
		myfile.close();*/
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
	}
	/*
	if (mSelection[entity]->GetNumberOfCells()) {
		vtkSmartPointer<vtkXMLUnstructuredGridWriter> w = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
		w->SetFileName("selection.vtu");
		w->SetInputData(mSelection[entity]);
		w->Write();
	}*/
	
}

vtkSmartPointer<vtkUnstructuredGrid> Model::GetVisibleModel(int entity)
{
	if (!mModelVisible[entity]) {
		if (entity == 0 || entity == 3)
			// Error
			return NULL;
		else
			this->GetDerivedModel(entity);
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

