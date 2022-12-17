#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include "material.h"
#include "dynamic_menu.h"


int main()
{
	srand((int)time(NULL));
	Materials materials;
	Employees employees;
	Invoices invoices;

	loadMaterialsFromFile(materials, "data_materials.txt");
	loadInvoicesFromFile(invoices, "data_invoices.txt");
	loadEmployeesFromFile(employees, "data_employees.txt");

	int x = coordinateUsedToCenterAlign(0, 156, 130),
		y = 3,
		width = 130,
		high = 36,
		borderColor = 11;

	int xSelection = x + 3,
		ySelection = y + high / 4 + 2,
		backgroudColorSelect = 71;

	int xp = xSelection,
		yp = ySelection;

	int xOld = xp,
		yOld = yp;

	string selectContents[11] = { "" };
	selectContents[0] = "Them vat tu";
	selectContents[1] = "Hieu chinh vat tu";
	selectContents[2] = "Xoa vat tu";
	selectContents[3] = "In danh sach vat tu";
	selectContents[4] = "Them nhan vien";
	selectContents[5] = "Hieu chinh nhan vien";
	selectContents[6] = "Xoa nhan vien";
	selectContents[7] = "In danh sach nhan vien";
	selectContents[8] = "Lap hoa don";
	selectContents[9] = "In danh sach hoa don";
	selectContents[10] = "Khach tra hang";
	int iSelectContents = 0,
		iOldSelectContents = iSelectContents;

	bool isPressKey = true;
	
	homeMenu(x, y, width, high, borderColor);
	
	while (true)
	{
		showCur(false);
		if (isPressKey)
		{
			lightBar(xOld, yOld, 25, 1, 0, selectContents[iOldSelectContents]);
			lightBar(xp, yp, 25, 1, backgroudColorSelect, selectContents[iSelectContents]);
			isPressKey = false;
		}

		if (_kbhit())
		{
			int key_press = _getch();
			if (key_press == 224 || key_press == -32)
			{
				yOld = yp;
				iOldSelectContents = iSelectContents;
				isPressKey = true;
				key_press = _getch();
				if (key_press == 80 && (iSelectContents + 1 <= 10)) // xuong
				{
					yp++;
					iSelectContents++;
				}
				else if (key_press == 72 && (iSelectContents - 1 >= 0)) // len
				{
					yp--;
					iSelectContents--;
				}
			}
			else if (key_press == 13)
			{
				message(x + width / 4 + 11, y + 9, 74, 16, 0, 0, ""); // Xoá chữ quản lý vật tư
				if (iSelectContents == 0)
				{	
					addMaterial(materials, coordinateUsedToCenterAlign(x + width / 4, width * 3 / 4, 44), y + 3);
					message(x + width / 4 + 11, y + 9, 74, 16, 0, 0, "");
					saveMaterialsDataToFile(materials, "data_materials.txt");
				}
				else if (iSelectContents == 1)
				{
					findAndAdjustMaterial(materials, coordinateUsedToCenterAlign(x + width / 4, width * 3 / 4, 44), y + 3);
					saveMaterialsDataToFile(materials, "data_materials.txt");
				}
				else if (iSelectContents == 2)
				{
					removeMaterial(materials, coordinateUsedToCenterAlign(x + width / 4, width * 3 / 4, 44), y + 3);
					saveMaterialsDataToFile(materials, "data_materials.txt");
				}
				else if (iSelectContents == 3)
				{
					printMaterialsTable(materials, 51, y + 3);
					_getch();
				}
				else if (iSelectContents == 4)
				{
					addEmployee(employees, coordinateUsedToCenterAlign(x + width / 4, width * 3 / 4, 44), y + 3);
					saveEmployeesToFile(employees, "data_employees.txt");
				}
				else if (iSelectContents == 5)
				{
					findAndAdjustEmployee(employees, coordinateUsedToCenterAlign(x + width / 4, width * 3 / 4, 44), y + 3);
					saveEmployeesToFile(employees, "data_employees.txt");
				}
				else if (iSelectContents == 6)
				{
					removeEmployee(employees, coordinateUsedToCenterAlign(x + width / 4, width * 3 / 4, 44), y + 3);
					saveEmployeesToFile(employees, "data_employees.txt");
				}
				else if (iSelectContents == 7)
				{
					printEmployeesTable(employees, 65, y + 3);
					_getch();
				}
				else if (iSelectContents == 8)
				{
					system("cls");
					invoice(invoices, materials);
					saveInvoiceToFile(invoices, "data_invoices.txt");
				}
				else if (iSelectContents == 9)
				{
					system("cls");
					printInvoices(invoices);
					_getch();
				}
				else if (iSelectContents == 10)
				{
					customerReturnItem(invoices, materials);
					saveMaterialsDataToFile(materials, "data_materials.txt");
					saveInvoiceToFile(invoices, "data_invoices.txt");
				}

				message(x + width / 4 + 3, y + 2, 93, 32, 0, 0, ""); // xoá phần hiển thị xử lý
				homeMenu(x, y, width, high, borderColor);
				isPressKey = true;
			}
		}	
	}
	_getch();
	return 0;
}