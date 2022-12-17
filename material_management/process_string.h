#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <iostream>
#include <conio.h>

using namespace std;

void normalizeString(string &str);
string* splitString(string src, char delim);
string getName(string fullName);
bool isOnlyDigits(string str);

void edit_string(string& str);
void display_string(const string& str);
void delete_space(string& str);