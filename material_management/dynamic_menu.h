#pragma once
#include <iostream>
#include <string>
#include "myLib.h"
#include <fstream>
using namespace std;

void printQuanLyVatTu(int x, int y);
void message(int x, int y, int width, int high, int backgroundColor, int contentColor, string content);
void lightBar(int x, int y, int w, int h, int backgroundColor, string content);
void box(int x, int y, int width, int high, int borderColor, char borderStyle);
void box(int x, int y, int width, int high, int borderColor, int contentColor, string content);
void templateMenu(int x, int y, int width, int high, int borderColor);
void homeMenu(int x, int y, int width, int high, int codeColor);
void menuShortcut(int x, int y);
void menuSelection(int x, int y);

void menuAddMaterial(int x, int y);
void menuAdjustMaterial(int x, int y);
void menuFindMaterial(int x, int y);
void menuFindMaterial(int x, int y);
void menuRemoveMaterial(int x, int y);
void menuPrintMaterial(int x, int y);

void menuAddEmployee(int x, int y);
void menuAdjustEmployee(int x, int y);
void menuFindEmployee(int x, int y);
void menuRemoveEmployee(int x, int y);
void menuPrintEmployee(int x, int y);

void menuSelectionInvoice(int x, int y);
void menuAddMaterialToInvoice(int x, int y);