#include "my_algorithm.h"

void copyValue(Employee src, Employee &dest)
{
	dest.id = src.id;
	dest.fullName = src.fullName;
	dest.gender = src.gender;
}

void merge(Employee employees[], int left, int mid, int right)
{
	int n_1 = mid - left + 1;
	int n_2 = right - mid;

	Employee *employees_1 = new Employee[n_1];
	Employee *employees_2 = new Employee[n_2];

	for (int i = 0; i < n_1; i++)
	{
		employees_1[i] = employees[left + i];
	}
	for (int i = 0; i < n_2; i++)
	{
		employees_2[i] = employees[mid + 1 + i];
	}

	int i = left;
	int i_1, i_2;
	i_1 = i_2 = 0;

	while (i_1 < n_1 && i_2 < n_2)
	{
		if (getName(employees_1[i_1].fullName) <= getName(employees_2[i_2].fullName))
		{
			copyValue(employees_1[i_1], employees[i]);
			i_1++;	
		}
		else
		{
			copyValue(employees_2[i_2], employees[i]);
			i_2++;
		}
		i++;
	}

	while (i_1 < n_1)
	{
		copyValue(employees_1[i_1], employees[i]);
		i_1++;
		i++;
	}
	while (i_2 < n_2)
	{
		copyValue(employees_2[i_2], employees[i]);
		i_2++;
		i++;
	}
}

void mergerSort(Employee employees[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		mergerSort(employees, left, mid);
		mergerSort(employees, mid + 1, right);

		merge(employees, left, mid, right);
	}
}