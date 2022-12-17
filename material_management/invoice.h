#pragma once
#include "data_structure.h"
#include "my_date_time.h"
#include "material.h"
#include "menu.h"
#include <conio.h>
#include <ctime>

InvoiceNode* isSameInvoiceNo(Invoices invoices, string invoiceNo);
string createInvoiceNo(Invoices invoices);
void addInvoiceDetailExport(InvoiceDetails &invoiceDetails, Materials materials);
void addInvoiceDetailImport(InvoiceDetails &invoiceDetails, Materials materials);
void invoiceExport(InvoiceDetails &invoiceDetails, Materials materials);
void invoiceImport(InvoiceDetails &invoiceDetails, Materials materials);
void invoice(Invoices &invoices, Materials &materials);
void printInvoiceDetail(InvoiceDetail invoiceDetail);
void printInvoiceDetails(InvoiceDetails invoiceDetails);
void printInvoice(InvoiceData invoiceData);
void printInvoices(Invoices invoices);
void updateNumberInStock(Materials &materials, InvoiceData invoiceData);
void removeInvoiceDetail(InvoiceDetails &invoiceDetails);
void customerReturnItem(Invoices &invoices, Materials &materials);