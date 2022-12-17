#pragma once
#include <iostream>
#include <iomanip>
#include "data_structure.h"
#include "process_string.h"
#include "save_load_file.h"
#include "myLib.h"
#include "dynamic_menu.h"
#include "string"

string createMaterialID();

int checkSameMaterialID(string materialID, Materials materials);
int checkSameMaterialName(string materialName, Materials materials);

void addMaterial(Materials& materials, int x, int y);

void printMaterial(Material material, int x, int y);
void printMaterialTable(Material material, int x, int y);
void printMaterialsTable(Materials materials, int x, int y);
void printMaterialAndRemove(Materials& materials, int indexMaterialToRemove, int x, int y);

void adjustMaterialAt(Materials& materials, int indexAdjust);
void findAndAdjustMaterial(Materials& materials, int x, int y);

void removeMaterialAt(Materials &materials, int indexRemove);
bool removeMaterialByID(Materials &materials, string materialID);
bool removeMaterialByName(Materials &materials, string materialName);
void removeMaterial(Materials& materials, int x, int y);

