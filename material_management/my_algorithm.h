#pragma once
#include "data_structure.h"
#include "process_string.h"

void copyValue(Employee src, Employee &dest);
void merge(Employee employees[], int left, int mid, int right);
void mergerSort(Employee employees[], int left, int right);