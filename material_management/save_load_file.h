#pragma once
#include <fstream>
#include "data_structure.h"
#include "process_string.h"
#include "employee.h"
#include "invoice.h"

void saveMaterialsDataToFile(Materials materials, string filePath);
void loadMaterialsFromFile(Materials &materials, string filePath);

void saveEmployeeNodeToFile(EmployeeNode *root, ofstream &fileOut);
void saveEmployeesToFile(Employees employees, string filePath);
void loadEmployeesFromFile(Employees &employees, string filePath);

void saveInvoiceToFile(Invoices invoices, string filePath);
void addInvoiceFromFile(Invoices &invoices, InvoiceNode *invoiceNode);
void loadInvoicesFromFile(Invoices &invoices, string filePath);