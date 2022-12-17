#pragma once
#include <iostream>
#include "data_structure.h"
#include "process_string.h"
#include "save_load_file.h"
#include "my_algorithm.h"

int createEmployeeID();

void addEmployeeNodeToTree(EmployeeNode *&root, EmployeeNode *employeeNode);
void addEmployee(Employees& employees, int x, int y);

void adjustEmployee(Employee& employee, int x, int y);
void findAndAdjustEmployee(Employees& employees, int x, int y);

void findLeftMostNodeToTakeOver(EmployeeNode *&nodeRemove, EmployeeNode *&nodeRight);
bool removeEmployeeNode(EmployeeNode *&root, int id);
void removeEmployee(Employees& employees, int x, int y);
void printEmployeeAndRemove(Employees& employees, EmployeeNode* employeeNode, int x, int y);

void printEmployeeTree(EmployeeNode* root, int x, int y);
void printEmployee(EmployeeNode* employeeNode, int x, int y);
void printEmployeeTable(EmployeeNode* employeeNode, int x, int y);
void printEmployeesTable(Employees employees, int x, int y);

