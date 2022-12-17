#include "dynamic_menu.h"

void lightBar(int x, int y, int w, int h, int backgroundColor, string content)
{
	textColor(backgroundColor);
	for (int iy = y; iy <= y + h - 1; iy++)
	{
		for (int ix = x; ix <= x + w; ix++)
		{
			gotoXY(ix, iy);
			cout << " ";
		}
	}

	setColor(7);
	gotoXY(x, y);
	cout << content;
	textColor(7);
}

void box(int x, int y, int width, int high, int borderColor, char borderStyle)
{
	setColor(borderColor);
	for (int ix = x; ix <= width + x; ix++)
	{
		//Sleep(5);
		gotoXY(ix, y);
		cout << borderStyle;

		gotoXY(ix, y + high);
		cout << borderStyle;
	}

	for (int iy = y; iy <= high + y; iy++)
	{
		//Sleep(5);
		gotoXY(x, iy);
		cout << borderStyle;

		gotoXY(x + width, iy);
		cout << borderStyle;
	}
}

void box(int x, int y, int width, int high, int borderColor, int contentColor,string content)
{
	setColor(borderColor);
	for (int ix = x; ix <= x + width + 1; ix++)
	{
		gotoXY(ix, y);
		cout << char(196);

		gotoXY(ix, y + high + 1);
		cout << char(196);
	}

	for (int iy = y; iy <= y + high + 1; iy++)
	{
		gotoXY(x, iy);
		cout << char(179);

		gotoXY(x + width + 1, iy);
		cout << char(179);
	}

	gotoXY(x, y);
	cout << char(218);

	gotoXY(x + width + 1, y);
	cout << char(191);

	gotoXY(x, y + high + 1);
	cout << char(192);

	gotoXY(x + width + 1, y + high + 1);
	cout << char(217);

	gotoXY(x + 1, y + 1);
	setColor(contentColor);
	cout << content;
	setColor(7);
}

void templateMenu(int x, int y, int width, int high, int borderColor)
{
	box(x, y, width, high, borderColor, 219);

	int xShortcutFrame = x, yShortcutFrame = y;
	int widthShortcutFrame = width / 4, highShortcutFrame = high / 4;
	box(xShortcutFrame, yShortcutFrame, widthShortcutFrame, highShortcutFrame, borderColor, 219);

	int xSelectionFrame = x, ySelectionFrame = y + high / 4;
	int widthSelectionFrame = width / 4, highSelectionFrame = high * 3 / 4;
	box(xSelectionFrame, ySelectionFrame, widthSelectionFrame, highSelectionFrame, borderColor, 219);

	setColor(7);
	menuShortcut(xShortcutFrame + 3, yShortcutFrame + 2);
	menuSelection(xSelectionFrame + 3, ySelectionFrame + 2);
}

void homeMenu(int x, int y, int width, int high, int borderColor)
{
	box(x, y, width, high, borderColor, 219);

	int xShortcutFrame = x, yShortcutFrame = y;
	int widthShortcutFrame = width / 4, highShortcutFrame = high / 4;
	box(xShortcutFrame, yShortcutFrame, widthShortcutFrame, highShortcutFrame, borderColor, 219);

	int xSelectionFrame = x, ySelectionFrame = y + high / 4;
	int widthSelectionFrame = width / 4, highSelectionFrame = high * 3 / 4;
	box(xSelectionFrame, ySelectionFrame, widthSelectionFrame, highSelectionFrame, borderColor, 219);

	setColor(7);
	menuShortcut(xShortcutFrame + 3, yShortcutFrame + 2);
	menuSelection(xSelectionFrame + 3, ySelectionFrame + 2);

	setColor(14);
	printQuanLyVatTu(x + widthShortcutFrame + 11, y + 9);
	setColor(7);
}

void menuShortcut(int x, int y)
{
	gotoXY(x, y);
	cout << "*ESC: quay lai";

	gotoXY(x, y + 2);
	cout << "*Enter: hoan tat nhap/chon";

	gotoXY(x, y + 4);
	cout << "*Len/Xuong: chon menu";
}

void menuSelection(int x, int y)
{
	gotoXY(x, y++);
	cout << "Them vat tu";

	gotoXY(x, y++);
	cout << "Hieu chinh vat tu";

	gotoXY(x, y++);
	cout << "Xoa vat tu";

	gotoXY(x, y++);
	cout << "In danh sach vat tu";

	gotoXY(x, y++);
	cout << "Them nhan vien";

	gotoXY(x, y++);
	cout << "Hieu chinh nhan vien";

	gotoXY(x, y++);
	cout << "Xoa nhan vien";

	gotoXY(x, y++);
	cout << "In danh sach nhan vien";

	gotoXY(x, y++);
	cout << "Lap hoa don";

	gotoXY(x, y++);
	cout << "In danh sach hoa don";

	gotoXY(x, y);
	cout << "Khach tra hang";
}

void menuAddMaterial(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "THEM VAT TU";

	gotoXY(x, y + 3);
	cout << "Ma Vat Tu";
	box(x + 12, y + 2, 30, 1, 4, 4, "");

	gotoXY(x, y + 8);
	cout << "Ten Vat tu";
	box(x + 12, y + 7, 30, 1, 7, 7, "");

	gotoXY(x, y + 13);
	cout << "Don Vi Tinh";
	box(x + 12, y + 12, 30, 1, 7, 7, "");

	gotoXY(x, y + 18);
	cout << "So Luong";
	box(x + 12, y + 17, 30, 1, 7, 7, "");

	gotoXY(x, y + 23);
	cout << "Don Gia";
	box(x + 12, y + 22, 30, 1, 7, 7, "");
	
	//setColor(4);
	box(x - 5, y + 27, 10, 1, 9, 9, "   THEM");
	box(x + 38, y + 27, 10, 1, 9, 9, "  THOAT");
}

void menuAdjustMaterial(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "HIEU CHINH VAT TU";

	gotoXY(x, y + 3);
	cout << "Ma Vat Tu";
	box(x + 12, y + 2, 30, 1, 4, 4, "");

	gotoXY(x, y + 8);
	cout << "Ten Vat tu";
	box(x + 12, y + 7, 30, 1, 7, 7, "");

	gotoXY(x, y + 13);
	cout << "Don Vi Tinh";
	box(x + 12, y + 12, 30, 1, 7, 7, "");

	gotoXY(x, y + 18);
	cout << "So Luong";
	box(x + 12, y + 17, 30, 1, 7, 7, "");

	gotoXY(x, y + 23);
	cout << "Don Gia";
	box(x + 12, y + 22, 30, 1, 7, 7, "");

	//setColor(4);
	box(x - 5, y + 27, 14, 1, 9, 9, "  HIEU CHINH");
	box(x + 38, y + 27, 14, 1, 9, 9, "  THOAT");
}

void menuFindMaterial(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "TIM VAT TU";

	gotoXY(x, y + 5);
	cout << "Ma Vat Tu";
	box(x + 12, y + 4, 30, 1, 7, 4, "");

	//setColor(4);
	box(x, y + 10, 9, 1, 9, 9, "  TIM");
	box(x + 35, y + 10, 9, 1, 9, 9, "  THOAT");
}

void menuFindMaterialByName(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "TIM VAT TU";

	gotoXY(x, y + 5);
	cout << "Ten Vat Tu";
	box(x + 12, y + 4, 30, 1, 7, 4, "");

	//setColor(4);
	box(x, y + 10, 9, 1, 9, 9, "  TIM");
	box(x + 35, y + 10, 9, 1, 9, 9, "  THOAT");
}

void menuRemoveMaterial(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "VAT TU";

	gotoXY(x, y + 3);
	cout << "Ma Vat Tu";
	box(x + 12, y + 2, 30, 1, 4, 4, "");

	gotoXY(x, y + 8);
	cout << "Ten Vat tu";
	box(x + 12, y + 7, 30, 1, 7, 7, "");

	gotoXY(x, y + 13);
	cout << "Don Vi Tinh";
	box(x + 12, y + 12, 30, 1, 7, 7, "");

	gotoXY(x, y + 18);
	cout << "So Luong";
	box(x + 12, y + 17, 30, 1, 7, 7, "");

	gotoXY(x, y + 23);
	cout << "Don Gia";
	box(x + 12, y + 22, 30, 1, 7, 7, "");

	//setColor(4);
	box(x - 5, y + 27, 9, 1, 9, 9, "  XOA");
	box(x + 38, y + 27, 9, 1, 9, 9, "  THOAT");
}

void menuPrintMaterial(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "THEM VAT TU";

	gotoXY(x, y + 3);
	cout << "Ma Vat Tu";
	box(x + 12, y + 2, 30, 1, 4, 4, "");

	gotoXY(x, y + 8);
	cout << "Ten Vat tu";
	box(x + 12, y + 7, 30, 1, 7, 7, "");

	gotoXY(x, y + 13);
	cout << "Don Vi Tinh";
	box(x + 12, y + 12, 30, 1, 7, 7, "");

	gotoXY(x, y + 18);
	cout << "So Luong";
	box(x + 12, y + 17, 30, 1, 7, 7, "");

	gotoXY(x, y + 23);
	cout << "Don Gia";
	box(x + 12, y + 22, 30, 1, 7, 7, "");
}

void menuAddEmployee(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "THEM NHAN VIEN";

	gotoXY(x, y + 3);
	cout << "Ma Nhan Vien";
	box(x + 12, y + 2, 30, 1, 4, 4, "");

	gotoXY(x, y + 8);
	cout << "Ho ten";
	box(x + 12, y + 7, 30, 1, 7, 7, "");

	gotoXY(x, y + 13);
	cout << "Gioi Tinh";
	box(x + 12, y + 12, 30, 1, 7, 7, "");

	//setColor(4);
	box(x - 5, y + 17, 10, 1, 9, 9, "   THEM");
	box(x + 38, y + 17, 10, 1, 9, 9, "  THOAT");
}

void menuAdjustEmployee(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "HIEU CHINH NHAN VIEN";

	gotoXY(x, y + 3);
	cout << "Ma Nhan Vien";
	box(x + 12, y + 2, 30, 1, 4, 4, "");

	gotoXY(x, y + 8);
	cout << "Ho ten";
	box(x + 12, y + 7, 30, 1, 7, 7, "");

	gotoXY(x, y + 13);
	cout << "Gioi Tinh";
	box(x + 12, y + 12, 30, 1, 7, 7, "");

	//setColor(4);
	box(x - 5, y + 17, 14, 1, 9, 9, "  HIEU CHINH");
	box(x + 38, y + 17, 14, 1, 9, 9, "  THOAT");
}

void menuFindEmployee(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "TIM NHAN VIEN";

	gotoXY(x, y + 5);
	cout << "Ma nhan vien";
	box(x + 12, y + 4, 30, 1, 7, 4, "");

	//setColor(4);
	box(x, y + 10, 9, 1, 9, 9, "  TIM");
	box(x + 35, y + 10, 9, 1, 9, 9, "  THOAT");
}

void menuRemoveEmployee(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "NHAN VIEN";

	gotoXY(x, y + 3);
	cout << "Ma nhan vien:";
	box(x + 12, y + 2, 30, 1, 4, 4, "");

	gotoXY(x, y + 8);
	cout << "Ho ten";
	box(x + 12, y + 7, 30, 1, 7, 7, "");

	gotoXY(x, y + 13);
	cout << "Gioi tinh";
	box(x + 12, y + 12, 30, 1, 7, 7, "");

	//setColor(4);
	box(x - 5, y + 17, 9, 1, 9, 9, "  XOA");
	box(x + 38, y + 17, 9, 1, 9, 9, "  THOAT");
}

void menuPrintEmployee(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "NHAN VIEN";

	gotoXY(x, y + 3);
	cout << "Ma Nhan Vien";
	box(x + 12, y + 2, 30, 1, 4, 4, "");

	gotoXY(x, y + 8);
	cout << "Ho ten";
	box(x + 12, y + 7, 30, 1, 7, 7, "");

	gotoXY(x, y + 13);
	cout << "Gioi Tinh";
	box(x + 12, y + 12, 30, 1, 7, 7, "");
}

//invoice export
void menuSelectionInvoiceExport(int x, int y)
{
	gotoXY(x, y++);
	cout << "Them vat tu vao hoa don";

	gotoXY(x, y++);
	cout << "Hien thi danh sach chi tiet hoa don";

	gotoXY(x, y++);
	cout << "Xoa vat tu ra khoi hoa don";

	gotoXY(x, y++);
	cout << "Quay lai";
}

void menuAddMaterialToInvoice(int x, int y)
{
	gotoXY(x + 17, y);
	cout << "THEM VAT TU VAO HOA DON";

	gotoXY(x, y + 5);
	cout << "Ma Vat Tu";
	box(x + 12, y + 4, 30, 1, 7, 4, "");

	//setColor(4);
	box(x, y + 10, 9, 1, 9, 9, "  THEM");
	box(x + 35, y + 10, 9, 1, 9, 9, "  THOAT");
	box(x + 15, y + 12, 25, 1, 9, 9, "  XEM DANH SACH VAT TU");
}

void printQuanLyVatTu(int x, int y)
{
	//showCur(false);
	ifstream file;
	file.open("chu_quan_ly_vat_tu.txt", ios_base::in);

	string line = "";
	while (!file.eof())
	{
		gotoXY(x, y++);
		getline(file, line);
		cout << line;
		//Sleep(50);
	}
	file.close();
}

void message(int x, int y, int width, int high, int backgroundColor, int contentColor, string content)
{
	textColor(backgroundColor);
	for (int iy = y; iy <= y + high; iy++)
	{
		for (int ix = x; ix <= x + width; ix++)
		{
			gotoXY(ix, iy);
			cout << " ";
		}
	}
	
	gotoXY(coordinateUsedToCenterAlign(x, width, content.length()), coordinateUsedToCenterAlign(y, high, 1));
	setColor(contentColor);
	cout << content;
	textColor(7);
	setColor(7);
}