#include "save_load_file.h"

void saveMaterialsDataToFile(Materials materials, string filePath)
{
	ofstream fileOut;
	fileOut.open(filePath, ios_base::out);

	int number = materials.number;
	for (int i = 0; i < number; i++)
	{
		Material *material = materials.material[i];
		string line = "";
		line = material->ID + "#" + material->name + "#" + material->unit + "#" + to_string(material->numberInStock) + "#" + to_string(material->unitPrice);
		fileOut << line << endl;
	}

	fileOut.close();
}
void loadMaterialsFromFile(Materials &materials, string filePath)
{
	ifstream fileIn;
	fileIn.open(filePath, ios_base::in);
	
	if (fileIn.fail())
	{
		return;
	}

	string *materialArray;
	string id, name, unit;
	float numberInStock;
	double unitPrice;
	string line;
	string ch;

	while (true)
	{
		getline(fileIn, line);

		if (fileIn.eof())
		{
			break;
		}

		materialArray = splitString(line, '#');
		id = materialArray[0];
		name = materialArray[1];
		unit = materialArray[2];
		numberInStock = stof(materialArray[3]);
		unitPrice = stod(materialArray[4]);

		materials.material[materials.number] = new Material;
		materials.material[materials.number]->ID = id;
		materials.material[materials.number]->name = name;
		materials.material[materials.number]->unit = unit;
		materials.material[materials.number]->numberInStock = numberInStock;
		materials.material[materials.number]->unitPrice= unitPrice;

		materials.number++;
	}

	fileIn.close();
}

void saveEmployeeNodeToFile(EmployeeNode *root, ofstream &fileOut)
{
	if (root != NULL)
	{
		string line = to_string(root->id) + "#" + root->fullName + "#" + root->gender;
		fileOut << line << endl;

		saveEmployeeNodeToFile(root->left, fileOut);
		saveEmployeeNodeToFile(root->right, fileOut);
	}
}

void saveEmployeesToFile(Employees employees, string filePath)
{
	ofstream fileOut;
	fileOut.open(filePath, ios_base::out);

	saveEmployeeNodeToFile(employees.root, fileOut);

	fileOut.close();
}

void loadEmployeesFromFile(Employees &employees, string filePath)
{
	ifstream fileIn;
	fileIn.open(filePath, ios_base::in);
	
	if (fileIn.fail())
	{
		return;
	}

	string *stringArray;
	int id;
	string fullName, gender;
	string line;

	while (true)
	{
		getline(fileIn, line);

		if (fileIn.eof())
		{
			break;
		}

		stringArray = splitString(line, '#');

		id = stoi(stringArray[0]);
		fullName = stringArray[1];
		gender = stringArray[2];

		EmployeeNode *employeeNode = createEmployeeNode(id, fullName, gender);
		addEmployeeNodeToTree(employees.root, employeeNode);
		employees.number++;
	}

	fileIn.close();
}

void saveInvoiceToFile(Invoices invoices, string filePath)
{
	ofstream fileOut;
	fileOut.open(filePath, ios_base::out);

	InvoiceNode *curInvoiceNode = invoices.head;
	while (curInvoiceNode != NULL)
	{
		InvoiceData &data = curInvoiceNode->data;

		string line = data.invoiceNo + "#" + data.date + "#" + data.type + "#" + to_string(data.invoiceDetails.number);
		for (int i = 0; i < data.invoiceDetails.number; i++)
		{
			InvoiceDetail &invoiceDetail_i = data.invoiceDetails.invoiceDetail[i];
			
			line = line + "#" + invoiceDetail_i.materialID + "#" + invoiceDetail_i.materialName + "#" + invoiceDetail_i.unit
				+ "#" + to_string(invoiceDetail_i.unitPrice) + "#" + to_string(invoiceDetail_i.number)
				+ "#" + to_string(invoiceDetail_i.vat) + "#" + to_string(invoiceDetail_i.status);
		}
		
		fileOut << line << endl;
		
		curInvoiceNode = curInvoiceNode->invoiceNodeNext;
	}

	fileOut.close();
}

void addInvoiceFromFile(Invoices &invoices, InvoiceNode *invoiceNode)
{
	if (invoiceNode == NULL)
	{
		return;
	}

	if (invoices.head == NULL)
	{
		invoices.head = invoiceNode;
	}
	else
	{
		InvoiceNode *curInvoiceNode = invoices.head;
		while (curInvoiceNode->invoiceNodeNext != NULL)
		{
			curInvoiceNode = curInvoiceNode->invoiceNodeNext;
		}
		curInvoiceNode->invoiceNodeNext = invoiceNode;
	}
	invoices.number++;
}

void loadInvoicesFromFile(Invoices &invoices, string filePath)
{
	ifstream fileIn;
	fileIn.open(filePath, ios_base::in);
	
	if (fileIn.fail())
	{
		return;
	}

	string line;

	while (true)
	{
		getline(fileIn, line);

		if (fileIn.eof())
		{
			break;
		}

		string *obj = splitString(line, '#');

		string no = obj[0],
			date = obj[1];
		char type = obj[2].at(0);

		InvoiceDetails invoiceDetails;
		invoiceDetails.number = stoi(obj[3]);
		
		int iInvoiceDetail = 0;
		int iObj = 4; // invoiceDetail start from index 4 of obj array
		while (iInvoiceDetail < invoiceDetails.number)
		{	
			
			invoiceDetails.invoiceDetail[iInvoiceDetail].materialID = obj[iInvoiceDetail + iObj];
			iObj++;

			invoiceDetails.invoiceDetail[iInvoiceDetail].materialName = obj[iInvoiceDetail + iObj];
			iObj++;

			invoiceDetails.invoiceDetail[iInvoiceDetail].unit = obj[iInvoiceDetail + iObj];
			iObj++;

			invoiceDetails.invoiceDetail[iInvoiceDetail].unitPrice = stod(obj[iInvoiceDetail + iObj]);
			iObj++;

			invoiceDetails.invoiceDetail[iInvoiceDetail].number = stoi(obj[iInvoiceDetail + iObj]);
			iObj++;

			invoiceDetails.invoiceDetail[iInvoiceDetail].vat = stof(obj[iInvoiceDetail + iObj]);
			iObj++;

			invoiceDetails.invoiceDetail[iInvoiceDetail].status = stoi(obj[iInvoiceDetail + iObj]);
			
			iInvoiceDetail++;
		}
		InvoiceNode *invoiceNode = createInvoiceNode(no, date, type, invoiceDetails);
		addInvoiceFromFile(invoices, invoiceNode);
	}

	fileIn.close();
}