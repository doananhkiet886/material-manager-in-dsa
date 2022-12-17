#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Material
{
	string ID;
	string name;
	string unit;
	float numberInStock;
	double unitPrice;
};
typedef struct Material Material;

struct Materials
{
	Material *material[100];
	int number = 0;
};
typedef struct Materials Materials;

/***************************/
struct InvoiceDetail
{
	string materialID;
	string materialName;
	string unit;
	float number;
	double unitPrice;

	float vat;
	int status;
};
typedef struct InvoiceDetail InvoiceDetail;

struct InvoiceDetails
{
	InvoiceDetail invoiceDetail[20];
	int number = 0;
};

/***************************/
struct InvoiceData
{
	string invoiceNo;
	string date;
	char type;
	InvoiceDetails invoiceDetails;
};

struct InvoiceNode
{
	InvoiceData data;
	InvoiceNode *invoiceNodeNext;
};
typedef struct InvoiceNode InvoiceNode;

struct Invoices
{
	InvoiceNode *head = NULL;
	int number = 0;
};

/***************************/
struct Employee
{
	int id;
	string fullName;
	string gender;
};
typedef struct Employee Employee;

struct EmployeeNode
{
	int id;
	string fullName;
	string gender;
	EmployeeNode *left;
	EmployeeNode *right;
};
typedef struct EmployeeNode EmployeeNode;

struct Employees
{
	EmployeeNode *root = NULL;
	int number = 0;
};
typedef struct Employees Employees;

EmployeeNode* createEmployeeNode(int id, string fullName, string gender);
void convertTreeToArray(EmployeeNode *root, Employee dest[], int &iDest);

InvoiceData createInvoiceData(string invoiceNo, string date, char type, InvoiceDetails invoiceDetails);
InvoiceNode* createInvoiceNode(string no, string date, char type, InvoiceDetails invoiceDetails);
void addInvoiceNode(InvoiceNode *&head, InvoiceNode *invoiceNode);