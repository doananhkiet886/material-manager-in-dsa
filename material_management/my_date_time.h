#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>
#include "process_string.h"
using namespace std;

string getSystemDateTime();
string getDateFromDateTime(string dateTime);
bool is3Days(string date_1, string date_2);