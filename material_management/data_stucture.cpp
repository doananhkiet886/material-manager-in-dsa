#include "data_structure.h"

EmployeeNode* createEmployeeNode(int id, string fullName, string gender)
{
	EmployeeNode *employeeNode = new EmployeeNode;
	employeeNode->id = id;
	employeeNode->fullName = fullName;
	employeeNode->gender = gender;
	employeeNode->left = NULL;
	employeeNode->right = NULL;
	return employeeNode;
}

void convertTreeToArray(EmployeeNode *root, Employee dest[], int &iDest)
{
	if (root != NULL)
	{
		dest[iDest].id = root->id;
		dest[iDest].fullName = root->fullName;
		dest[iDest].gender = root->gender;
		iDest++;
		convertTreeToArray(root->left, dest, iDest);
		convertTreeToArray(root->right, dest, iDest);
	}
}

InvoiceData createInvoiceData(string invoiceNo, string date, char type, InvoiceDetails invoiceDetails)
{
	InvoiceData invoiceData;
	invoiceData.invoiceNo = invoiceNo;
	invoiceData.date = date;
	invoiceData.type = type;
	invoiceData.invoiceDetails = invoiceDetails;

	return invoiceData;
}

InvoiceNode* createInvoiceNode(string no, string date, char type, InvoiceDetails invoiceDetails)
{
	InvoiceNode *invoiceNode = new InvoiceNode;
	invoiceNode->data.invoiceNo = no;
	invoiceNode->data.date = date;
	invoiceNode->data.type = type;
	invoiceNode->data.invoiceDetails = invoiceDetails;
	invoiceNode->invoiceNodeNext = NULL;
	return invoiceNode;
}

void addInvoiceNode(InvoiceNode *&head, InvoiceNode *invoiceNode)
{
	if (invoiceNode == NULL)
	{
		return;
	}

	if (head == NULL)
	{
		head = invoiceNode;
	}
	else
	{
		InvoiceNode *curNode = head;
		while (curNode->invoiceNodeNext != NULL)
		{
			curNode = curNode->invoiceNodeNext;
		}
		curNode->invoiceNodeNext = invoiceNode;
	}
	
}