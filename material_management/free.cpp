#include "free.h"

void freeMaterials(Materials &materials)
{
	for (int i = 0; i < materials.number; i++)
	{
		delete materials.material[i];
	}
	materials.number = 0;
}

void freeEmployeeTree(EmployeeNode *&root)
{
	if (root != NULL)
	{
		freeEmployeeTree(root->left);
		freeEmployeeTree(root->right);
		delete root;
		root = NULL;
	}
}

void freeEmployees(Employees &employees)
{
	freeEmployeeTree(employees.root);
	employees.number = 0;
}