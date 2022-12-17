#include "material.h"

string createMaterialID()
{
	string materialID = "VT0000";
	for (int i = 2; i < materialID.length(); i++)
	{
		materialID[i] = rand() % (57 - 48 + 1) + 48;
	}
	return materialID;
}

int checkSameMaterialID(string materialID, Materials materials)
{
	for (int i = 0; i < materials.number; i++)
	{
		if (materialID == materials.material[i]->ID)
		{
			return i;
		}
	}
	return -1;
}
int checkSameMaterialName(string materialName, Materials materials)
{
	for (int i = 0; i < materials.number; i++)
	{
		if (materialName == materials.material[i]->name)
		{
			return i;
		}
	}
	return -1;
}

void addMaterial(Materials& materials, int x, int y)
{
	string materialID = "",
		name = "",
		unit = "",
		strNumberInStock = "",
		strUnitPrice = "";

	while (true)
	{
		materialID = createMaterialID();
		if (checkSameMaterialID(materialID, materials) == -1)
		{
			break;
		}
	}

	gotoXY(x + 14, y + 3);
	cout << materialID;

	//Nhập dữ liệu để thêm vật tư
	while (true)
	{
		menuAddMaterial(x, y);
		showCur(true);

		// Nhập dữ liệu
		if (name.empty())
		{
			gotoXY(x + 14, y + 8);
			getline(cin, name);
		}
		gotoXY(x + 14, y + 13);
		cout << unit;
		if (unit.empty())
		{
			gotoXY(x + 14, y + 13);
			getline(cin, unit);
		}
		if (strNumberInStock.empty())
		{
			gotoXY(x + 14, y + 18);
			edit_string(strNumberInStock);
		}
		if (strUnitPrice.empty())
		{
			gotoXY(x + 14, y + 23);
			edit_string(strUnitPrice);
		}

		//Kiểm tra toàn vẹn dữ liệu
		if (name.empty() || unit.empty() || strNumberInStock.empty() || strUnitPrice.empty()) //Đã nhập đủ dữ liệu hay chưa
		{
			showCur(false);
			message(x + 5, y + 12, 35, 4, 100, 0, " Khong duoc bo trong thong tin...");
			_getch();
			message(x + 5, y + 12, 35, 5, 0, 7, "                               ");
		}
		else if (!isOnlyDigits(strNumberInStock) || !isOnlyDigits(strUnitPrice)) // đầu vào 2 số có kí tự khác ngoài chữ số và dấu chấm hay không
		{
			showCur(false);
			message(x + 5, y + 12, 35, 4, 100, 0, " Du lieu dau vao khong chinh xac...");
			_getch();
			message(x + 5, y + 12, 35, 5, 0, 7, "                              ");
		}
		else // Đã toàn vẹn dữ liệu thì thoát không nhập nữa
		{
			break;
		}
	}

	showCur(false);

	/*
		Bắt sự kiện lựa chọn THÊM hoặc THOÁT
	*/
	int xThem = x - 5, yThem = y + 27;
	int xThoat = x + 38, yThoat = y + 27;
	char key_press;
	bool isKeyPress = true;
	bool isLeft = 1;
	box(xThem, yThem, 10, 1, 10, 10, "   THEM");
	while (true)
	{
		if (_kbhit())
		{
			key_press = _getch();
			if (key_press == 224 || key_press == -32)
			{
				key_press = _getch();
				if (key_press == 77) // phải
				{
					isLeft = 0;
					box(xThem, yThem, 10, 1, 9, 9, "   THEM");
					box(xThoat, yThoat, 10, 1, 10, 10, "  THOAT");
				}
				else if (key_press == 75) // trái
				{
					isLeft = 1;
					box(xThoat, yThoat, 10, 1, 9, 9, "  THOAT");
					box(xThem, yThem, 10, 1, 10, 10, "   THEM");
				}
			}
			else if (key_press == 13) // enter
			{
				if (isLeft)
				{
					normalizeString(name);
					normalizeString(unit);

					int number = materials.number;
					materials.material[number] = new Material;

					materials.material[number]->ID = materialID;
					materials.material[number]->name = name;
					materials.material[number]->unit = unit;
					materials.material[number]->numberInStock = stof(strNumberInStock);
					materials.material[number]->unitPrice = stof(strUnitPrice);
					materials.number++;

					showCur(false);
					message(x + 5, y + 12, 35, 5, 100, 0, " Them vat tu thanh cong...");
					_getch();
					message(x + 5, y + 12, 35, 5, 0, 7, "                              ");

					return;
				}
				return;
			}
		}
	}
}

void adjustMaterialAt(Materials& materials, int indexAdjust, int x, int y)
{
	Material* material = materials.material[indexAdjust];

	// Các biến sau khi nhập lại sẽ thực hiện gán lại vào material => hiệu chỉnh
	string name = material->name,
		unit = material->unit,
		strNumberInStock = to_string(material->numberInStock),
		strUnitPrice = to_string(material->unitPrice);

	gotoXY(x + 14, y + 3);
	cout << material->ID;
	while (true)
	{
		menuAdjustMaterial(x, y);

		// In ra toàn bộ dữ liệu
		gotoXY(x + 14, y + 8);
		cout << name;

		gotoXY(x + 14, y + 13);
		cout << unit;

		gotoXY(x + 14, y + 18);
		cout << strNumberInStock;

		gotoXY(x + 14, y + 23);
		cout << strUnitPrice;

		showCur(true);

		// Nhập dữ liệu
		gotoXY(x + 14, y + 8);
		edit_string(name);

		gotoXY(x + 14, y + 13);
		edit_string(unit);

		gotoXY(x + 14, y + 18);
		edit_string(strNumberInStock);

		gotoXY(x + 14, y + 23);
		edit_string(strUnitPrice);

		//Kiểm tra toàn vẹn dữ liệu
		if (material->name.empty() || material->unit.empty() || strNumberInStock.empty() || strUnitPrice.empty()) //Đã nhập đủ dữ liệu hay chưa
		{
			showCur(false);
			message(x + 5, y + 12, 35, 4, 100, 0, " Khong duoc bo trong thong tin...");
			_getch();
			message(x + 5, y + 12, 35, 5, 0, 7, "                               ");
		}
		else if (!isOnlyDigits(strNumberInStock) || !isOnlyDigits(strUnitPrice)) // đầu vào 2 số có kí tự khác ngoài chữ số và dấu chấm hay không
		{
			showCur(false);
			message(x + 5, y + 12, 35, 4, 100, 0, " Du lieu dau vao khong chinh xac...");
			_getch();
			message(x + 5, y + 12, 35, 5, 0, 7, "                              ");
		}
		else // Đã toàn vẹn dữ liệu thì thoát không nhập nữa
		{
			break;
		}
	}

	showCur(false);

	/*
		Bắt sự kiện lựa chọn HIEU CHINH hoặc THOÁT
	*/
	int xThem = x - 5, yThem = y + 27;
	int xThoat = x + 38, yThoat = y + 27;
	char key_press;
	bool isKeyPress = true;
	bool isLeft = 1;
	box(xThem, yThem, 14, 1, 10, 10, "  HIEU CHINH"); // ở vị trí mặc định là đang chọn
	while (true)
	{
		if (_kbhit())
		{
			key_press = _getch();
			if (key_press == 224 || key_press == -32)
			{
				key_press = _getch();
				if (key_press == 77) // phải
				{
					isLeft = 0;
					box(xThem, yThem, 14, 1, 9, 9, "  HIEU CHINH"); // trả lại màu không chọn
					box(xThoat, yThoat, 14, 1, 10, 10, "  THOAT"); // ở vị trí đang chọn
				}
				else if (key_press == 75) // trái
				{
					isLeft = 1;
					box(xThoat, yThoat, 14, 1, 9, 9, "  THOAT"); // trả lại màu không chọn
					box(xThem, yThem, 14, 1, 10, 10, "  HIEU CHINH"); // ở vị trí đang chọn
				}
			}
			else if (key_press == 13) // enter
			{
				if (isLeft)
				{
					normalizeString(name);
					normalizeString(unit);

					material->name = name;
					material->unit = unit;
					material->numberInStock = stof(strNumberInStock);
					material->unitPrice = stof(strUnitPrice);

					showCur(false);
					message(x + 5, y + 12, 35, 5, 47, 0, " Hieu chinh vat tu thanh cong...");
					_getch();

					return;
				}
				return;
			}
		}
	}
}
void findAndAdjustMaterial(Materials& materials, int x, int y)
{
	string materialID = "";

	while (true)
	{
		menuFindMaterial(x, y);

		// Nhập dữ liệu
		showCur(true);
		gotoXY(x + 14, y + 5);
		edit_string(materialID);
		showCur(false);

		// Xử lý bắt sự kiện
		int xTim = x, yTim = y + 10;
		int xThoat = x + 35, yThoat = y + 10;
		char key_press;
		bool isKeyPress = true;
		bool isLeft = 1;
		box(xTim, yTim, 9, 1, 10, 10, "  TIM"); // ở vị trí mặc định là đang chọn
		while (true)
		{
			if (_kbhit())
			{
				key_press = _getch();
				if (key_press == 224 || key_press == -32)
				{
					key_press = _getch();
					if (key_press == 77) // phải
					{
						isLeft = 0;
						box(xTim, yTim, 9, 1, 9, 9, "  TIM"); // trả lại màu không chọn
						box(xThoat, yThoat, 9, 1, 10, 10, "  THOAT"); // ở vị trí đang chọn
					}
					else if (key_press == 75) // trái
					{
						isLeft = 1;
						box(xThoat, yThoat, 9, 1, 9, 9, "  THOAT"); // trả lại màu không chọn
						box(xTim, yTim, 9, 1, 10, 10, "  TIM"); // ở vị trí đang chọn
					}
				}
				else if (key_press == 13) // enter - thực hiện chọn
				{
					// Bên trái - thực hiện tìm vật tư
					if (isLeft)
					{
						/*
							Xử lý tìm vật tư
						*/
						int indexAdjust = checkSameMaterialID(materialID, materials);
						//Tìm thấy vật tư
						if (indexAdjust >= 0)
						{
							message(x, y, 45, 13, 0, 0, ""); //Xoá bỏ menu tìm vật tư trên console
							adjustMaterialAt(materials, indexAdjust, x, y);
							return;
						}
						// Không tìm thấy vật tư
						message(x + 9, y + 4, 25, 4, 100, 0, " Khong tim thay vat tu!");
						_getch();
						message(x, y, 45, 13, 0, 0, ""); //Xoá bỏ menu tìm vật tư trên console để làm mới lại
						break;
					}

					// Bên phải - thực hiện thoát
					return;
				}
			}
		}
	}
}

bool removeMaterialByID(Materials& materials, string materialID)
{
	int indexRemove = checkSameMaterialID(materialID, materials);

	if (indexRemove >= 0)
	{
		removeMaterialAt(materials, indexRemove);
		return true;
	}
	return false;
}
void removeMaterialAt(Materials& materials, int indexRemove)
{
	if (indexRemove < 0)
	{
		return;
	}

	delete materials.material[indexRemove];
	for (int i = indexRemove; i < materials.number - 1; i++)
	{
		materials.material[i] = materials.material[i + 1];
	}
	materials.number--;
}
bool removeMaterialByName(Materials& materials, string materialName)
{
	int indexRemove = checkSameMaterialName(materialName, materials);

	if (indexRemove >= 0)
	{
		removeMaterialAt(materials, indexRemove);
		return true;
	}
	return false;
}
void removeMaterial(Materials& materials, int x, int y)
{
	string materialID = "";

	while (true)
	{
		menuFindMaterial(x, y);

		// Nhập dữ liệu
		showCur(true);
		gotoXY(x + 14, y + 5);
		edit_string(materialID);
		showCur(false);

		// Xử lý bắt sự kiện
		int xTim = x, yTim = y + 10;
		int xThoat = x + 35, yThoat = y + 10;
		char key_press;
		bool isKeyPress = true;
		bool isLeft = 1;
		box(xTim, yTim, 9, 1, 10, 10, "  TIM"); // ở vị trí mặc định là đang chọn
		while (true)
		{
			if (_kbhit())
			{
				key_press = _getch();
				if (key_press == 224 || key_press == -32)
				{
					key_press = _getch();
					if (key_press == 77) // phải
					{
						isLeft = 0;
						box(xTim, yTim, 9, 1, 9, 9, "  TIM"); // trả lại màu không chọn
						box(xThoat, yThoat, 9, 1, 10, 10, "  THOAT"); // ở vị trí đang chọn
					}
					else if (key_press == 75) // trái
					{
						isLeft = 1;
						box(xThoat, yThoat, 10, 1, 9, 9, "  THOAT"); // trả lại màu không chọn
						box(xTim, yTim, 9, 1, 10, 10, "  TIM"); // ở vị trí đang chọn
					}
				}
				else if (key_press == 13) // enter - thực hiện chọn
				{
					// Bên trái - thực hiện tìm vật tư
					if (isLeft)
					{
						/*
							Xử lý tìm vật tư
						*/
						int indexMaterial = checkSameMaterialID(materialID, materials);
						//Tìm thấy vật tư
						if (indexMaterial >= 0)
						{
							message(x, y, 45, 13, 0, 0, ""); //Xoá bỏ menu tìm vật tư trên console

							/*
								...........Xử lý tiếp theo tại đây......
							*/
							printMaterialAndRemove(materials, indexMaterial, x, y);
							return;
						}
						// Không tìm thấy vật tư
						message(x + 9, y + 4, 25, 4, 100, 0, " Khong tim thay vat tu!");
						_getch();
						message(x, y, 45, 13, 0, 0, ""); //Xoá bỏ menu tìm vật tư trên console để làm mới lại
						break;
					}

					// Bên phải - thực hiện thoát
					return;
				}
			}
		}
	}
}
void printMaterialAndRemove(Materials& materials, int indexMaterialToRemove, int x, int y)
{
	menuRemoveMaterial(x, y);
	gotoXY(x + 14, y + 3);
	cout << materials.material[indexMaterialToRemove]->ID;

	gotoXY(x + 14, y + 8);
	cout << materials.material[indexMaterialToRemove]->name;

	gotoXY(x + 14, y + 13);
	cout << materials.material[indexMaterialToRemove]->unit;

	gotoXY(x + 14, y + 18);
	cout << materials.material[indexMaterialToRemove]->numberInStock;

	gotoXY(x + 14, y + 23);
	cout << materials.material[indexMaterialToRemove]->unitPrice;

	// Xử lý bắt sự kiện
	int xXoa = x - 5, yXoa = y + 27;
	int xThoat = x + 38, yThoat = y + 27;
	char key_press;
	bool isKeyPress = true;
	bool isLeft = 1;
	box(xXoa, yXoa, 9, 1, 10, 10, "  XOA"); // ở vị trí mặc định là đang chọn
	while (true)
	{
		if (_kbhit())
		{
			key_press = _getch();
			if (key_press == 224 || key_press == -32) // mã ascii kép của 4 phím mũi tên
			{
				key_press = _getch();
				if (key_press == 77) // phải
				{
					isLeft = 0;
					box(xXoa, yXoa, 9, 1, 9, 9, "  XOA"); // trả lại màu không chọn
					box(xThoat, yThoat, 9, 1, 10, 10, "  THOAT"); // ở vị trí đang chọn
				}
				else if (key_press == 75) // trái
				{
					isLeft = 1;
					box(xThoat, yThoat, 9, 1, 9, 9, "  THOAT"); // trả lại màu không chọn
					box(xXoa, yXoa, 9, 1, 10, 10, "  XOA"); // ở vị trí đang chọn
				}
			}
			else if (key_press == 13) // enter - thực hiện chọn
			{
				// Bên trái - thực hiện tìm vật tư
				if (isLeft)
				{
					removeMaterialAt(materials, indexMaterialToRemove);
					message(x + 5, y + 12, 35, 4, 100, 0, " Xoa vat tu thanh cong...");
					_getch();
					return;
				}
				// Bên phải - thực hiện thoát
				return;
			}
		}
	}
}

void printMaterial(Material material, int x, int y)
{
	menuPrintMaterial(x, y);
	gotoXY(x + 14, y + 3);
	cout << material.ID;

	gotoXY(x + 14, y + 8);
	cout << material.name;

	gotoXY(x + 14, y + 13);
	cout << material.unit;

	gotoXY(x + 14, y + 18);
	cout << material.numberInStock;

	gotoXY(x + 14, y + 23);
	cout << material.unitPrice;
}
void printMaterialTable(Material material, int x, int y)
{
	gotoXY(x, y);
	cout << left << setw(15) << material.ID;
	cout << left << setw(25) << material.name;
	cout << left << setw(15) << material.unit;
	cout << left << setw(16) << material.numberInStock;
	cout << left << setw(17) << material.unitPrice;
}
void printMaterialsTable(Materials materials, int x, int y)
{
	gotoXY(coordinateUsedToCenterAlign(x, 88, 16), y);
	cout << "DANH SACH VAT TU";

	y = y + 3;
	gotoXY(x, y);
	textColor(160);
	cout << left << setw(15) << "ID";
	cout << left << setw(25) << "Name";
	cout << left << setw(15) << "Unit";
	cout << left << setw(16) << "Quantity";
	cout << left << setw(17) << "Unit Price";

	textColor(240);
	for (int i = 0; i < materials.number; i++)
	{
		printMaterialTable(*materials.material[i], x, ++y);
	}
	textColor(0);
}