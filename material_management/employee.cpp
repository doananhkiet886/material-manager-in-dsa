#include "employee.h"

int createEmployeeID()
{
	return rand() % (9876 - 1234 + 1) + 1234;
}

EmployeeNode* checkSameEmployeeID(EmployeeNode *root, int id)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (id == root->id)
	{
		return root;
	}

	if (id < root->id)
	{
		checkSameEmployeeID(root->left, id);
	}
	else if (id > root->id)
	{
		checkSameEmployeeID(root->right, id);
	}
}

void addEmployeeNodeToTree(EmployeeNode *&root, EmployeeNode *employeeNode)
{
	if (employeeNode == NULL)
	{
		return;
	}

	if (root == NULL)
	{
		root = employeeNode;
		return;
	}
	else if (employeeNode->id < root->id)
	{
		addEmployeeNodeToTree(root->left, employeeNode);
	}
	else if (employeeNode->id > root->id)
	{
		addEmployeeNodeToTree(root->right, employeeNode);
	}
}
void addEmployee(Employees &employees, int x, int y)
{
	int employeeID;
	string fullName = "";
	string gender = "";

	while (true)
	{
		employeeID = createEmployeeID();
		if (checkSameEmployeeID(employees.root, employeeID) == NULL);
		{
			break;
		}
	}

	gotoXY(x + 14, y + 3);
	cout << employeeID;

	//Nhập dữ liệu để thêm nhân viên
	while (true)
	{
		menuAddEmployee(x, y);
		showCur(true);

		// Nhập dữ liệu
		gotoXY(x + 14, y + 8);
		cout << fullName;
		if (fullName.empty())
		{
			gotoXY(x + 14, y + 8);
			edit_string(fullName);
		}
		if (gender.empty())
		{
			gotoXY(x + 14, y + 13);
			edit_string(gender);
		}

		//Kiểm tra toàn vẹn dữ liệu
		if (fullName.empty() || gender.empty()) // Còn rỗng thì nhập lại
		{
			showCur(false);
			message(x + 5, y + 7, 35, 4, 100, 0, " Khong duoc bo trong thong tin...");
			_getch();
			message(x + 5, y + 7, 35, 5, 0, 7, "                               ");
		}
		else // Không rỗng thì thoát không nhập nữa
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
	box(x - 5, y + 17, 10, 1, 10, 10, "   THEM");
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
					box(x - 5, y + 17, 10, 1, 9, 9, "   THEM");
					box(x + 38, y + 17, 10, 1, 10, 10, "  THOAT");
				}
				else if (key_press == 75) // trái
				{
					isLeft = 1;
					box(x + 38, y + 17, 10, 1, 9, 9, "  THOAT");
					box(x - 5, y + 17, 10, 1, 10, 10, "   THEM");
				}
			}
			else if (key_press == 13) // enter
			{
				if (isLeft)
				{
					normalizeString(fullName);
					normalizeString(gender);

					EmployeeNode *employeeNode = createEmployeeNode(employeeID, fullName, gender);
					addEmployeeNodeToTree(employees.root, employeeNode);
					employees.number++;

					showCur(false);
					message(x + 5, y + 7, 35, 5, 100, 0, " Them nhan vien thanh cong...");
					_getch();
					return;
				}
				return;
			}
		}
	}

}

void adjustEmployee(EmployeeNode* employeeNode, int x, int y)
{
	// Các biến sau khi nhập lại sẽ thực hiện gán lại vào employee => hiệu chỉnh
	string fullName = employeeNode->fullName,
		gender = employeeNode->gender;

	gotoXY(x + 14, y + 3);
	cout << employeeNode->id;
	while (true)
	{
		menuAdjustEmployee(x, y);
		// In ra toàn bộ dữ liệu
		gotoXY(x + 14, y + 8);
		cout << fullName;

		gotoXY(x + 14, y + 13);
		cout << gender;

		showCur(true);

		// Nhập dữ liệu
		gotoXY(x + 14, y + 8);
		edit_string(fullName);

		gotoXY(x + 14, y + 13);
		edit_string(gender);

		//Kiểm tra đã nhập dữ liệu hay chưa
		if (fullName.empty() || gender.empty())
		{
			showCur(false);
			message(x + 5, y + 12, 35, 4, 100, 0, " Khong duoc bo trong thong tin...");
			_getch();
			message(x + 5, y + 12, 35, 5, 0, 7, "                               ");
		}
		else
		{
			break;
		}
	}

	showCur(false);

	/*
		Bắt sự kiện lựa chọn HIEU CHINH hoặc THOÁT
	*/
	int xThem = x - 5, yThem = y + 17;
	int xThoat = x + 38, yThoat = y + 17;
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
					normalizeString(fullName);
					normalizeString(gender);

					employeeNode->fullName = fullName;
					employeeNode->gender = gender;

					showCur(false);
					message(x + 5, y + 7, 35, 5, 47, 0, " Hieu chinh vat tu thanh cong...");
					_getch();
					return;
				}
				return;
			}
		}
	}
}
void findAndAdjustEmployee(Employees& employees, int x, int y)
{
	string strEmployeeID = "";

	while (true)
	{
		menuFindEmployee(x, y);

		// Nhập dữ liệu
		showCur(true);
		gotoXY(x + 14, y + 5);
		edit_string(strEmployeeID);
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
					// Bên trái - thực hiện tìm nhân viên
					if (isLeft)
					{
						/*
							Xử lý tìm nhân viên
						*/

						// Kiểm tra chỉ có chữ số không để thực hiện chuyển đổi strEmployee sang kiểu int
						if (strEmployeeID.empty())
						{
							message(x + 10, y + 4, 25, 4, 100, 0, " Khong duoc bo trong!");
							_getch();
							message(x + 6, y + 4, 35, 4, 0, 0, "                              ");
							break;
						}

						if (!isOnlyDigits(strEmployeeID))
						{
							message(x + 6, y + 4, 35, 4, 100, 0, " Ma nhan vien chi chua chu so!");
							_getch();
							message(x + 6, y + 4, 35, 4, 0, 0, "                              ");
							break;
						}

						int intEmployeeID = stoi(strEmployeeID);

						EmployeeNode* employeeNode = checkSameEmployeeID(employees.root, intEmployeeID);
						//Tìm thấy nhân viên
						if (employeeNode != NULL)
						{
							message(x, y, 45, 13, 0, 0, ""); //Xoá bỏ menu tìm nhân viên trên console
							adjustEmployee(employeeNode, x, y);
							return;
						}
						// Không tìm thấy vật tư
						message(x + 9, y + 4, 26, 4, 100, 0, " Khong tim thay nhan vien!");
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

void findLeftMostNodeToTakeOver(EmployeeNode *&nodeRemove, EmployeeNode *&nodeRight)
{
	if (nodeRight->left != NULL)
	{
		findLeftMostNodeToTakeOver(nodeRemove, nodeRight->left);
	}
	else
	{
		nodeRemove->id = nodeRight->id;
		nodeRemove->fullName = nodeRight->fullName;
		nodeRemove->gender = nodeRight->gender;

		nodeRemove = nodeRight;

		nodeRight = nodeRight->right;
	}
}
bool removeEmployeeNode(EmployeeNode *&root, int id)
{
	if (root == NULL)
	{
		return false;
	}

	if (id < root->id)
	{
		removeEmployeeNode(root->left, id);
	}
	else if (id > root->id)
	{
		removeEmployeeNode(root->right, id);
	}
	else if (id == root->id)
	{
		EmployeeNode *nodeRemove = root;
		if (root->left == NULL)
		{
			root = root->right;
		}
		else if (root->right == NULL)
		{
			root = root->left;
		}
		else
		{
			EmployeeNode *nodeRight = root->right;
			findLeftMostNodeToTakeOver(nodeRemove, nodeRight);
		}
		delete nodeRemove;
		return true;
	}
}
void removeEmployee(Employees &employees, int x, int y)
{
	string strEmployeeID = "";

	while (true)
	{
		menuFindEmployee(x, y);

		// Nhập dữ liệu
		showCur(true);
		gotoXY(x + 14, y + 5);
		edit_string(strEmployeeID);
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
							Xử lý tìm nhân viên
						*/
						if (strEmployeeID.empty())
						{
							message(x + 10, y + 4, 25, 4, 100, 0, " Khong duoc bo trong!");
							_getch();
							message(x + 6, y + 4, 35, 4, 0, 0, "                              ");
							break;
						}

						if (!isOnlyDigits(strEmployeeID))
						{
							message(x + 6, y + 4, 35, 4, 100, 0, " Ma nhan vien chi chua chu so!");
							_getch();
							message(x + 6, y + 4, 35, 4, 0, 0, "                              ");
							break;
						}

						int intEmployeeID = stoi(strEmployeeID);

						EmployeeNode* employeeNode = checkSameEmployeeID(employees.root, intEmployeeID);
						//Tìm thấy nhân viên
						if (employeeNode != NULL)
						{
							message(x, y, 45, 13, 0, 0, ""); //Xoá bỏ menu tìm nhân viên trên console
							printEmployeeAndRemove(employees, employeeNode, x, y);
							return;
						}
						// Không tìm thấy vật tư
						message(x + 9, y + 4, 26, 4, 100, 0, " Khong tim thay nhan vien!");
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
void printEmployeeAndRemove(Employees &employees, EmployeeNode *employeeNode, int x, int y)
{
	menuRemoveEmployee(x, y);
	printEmployee(employeeNode, x, y);

	// Xử lý bắt sự kiện
	int xXoa = x - 5, yXoa = y + 17;
	int xThoat = x + 38, yThoat = y + 17;
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
					removeEmployeeNode(employees.root, employeeNode->id);
					employees.number--;
					message(x + 5, y + 6, 35, 4, 100, 0, " Xoa nhan vien thanh cong...");
					_getch();
					return;
				}
				// Bên phải - thực hiện thoát
				return;
			}
		}
	}
}

void printEmployeeTree(EmployeeNode* root, int x, int y)
{
	if (root != NULL)
	{
		printEmployeeTree(root->left, x, y);

		printEmployeeTable(root, x, ++y);

		printEmployeeTree(root->right, x, y);
	}
}
void printEmployee(EmployeeNode* employeeNode, int x, int y)
{
	menuPrintEmployee(x, y);
	gotoXY(x + 14, y + 3);
	cout << employeeNode->id;

	gotoXY(x + 14, y + 8);
	cout << employeeNode->fullName;

	gotoXY(x + 14, y + 13);
	cout << employeeNode->gender;
}
void printEmployeeTable(EmployeeNode* employeeNode, int x, int y)
{
	gotoXY(x, y);
	cout << left << setw(15) << employeeNode->id;
	cout << left << setw(25) << employeeNode->fullName;
	cout << left << setw(15) << employeeNode->gender;
}
void printEmployeesTable(Employees employees, int x, int y)
{
	gotoXY(coordinateUsedToCenterAlign(x, 55, 16), y);
	cout << "DANH SACH NHAN VIEN";

	y = y + 3;
	gotoXY(x, y);
	textColor(160);
	cout << left << setw(15) << "ID";
	cout << left << setw(25) << "Name";
	cout << left << setw(15) << "Gender";

	textColor(240);
	printEmployeeTree(employees.root, x, y);
	textColor(0);
}
