#include "menu.h"

void menuMainSelection(int x, int y)
{
	
	cout << "Them vat tu" << endl;
	cout << "Hieu chinh vat tu" << endl;
	cout << "Xoa vat tu" << endl;
	cout << "In danh sach vat tu" << endl;
	cout << "Them nhan vien" << endl;
	cout << "Hieu chinh nhan vien" << endl;
	cout << "Xoa nhan vien" << endl;
	cout << "In danh sach nhan vien" << endl;
	cout << "Lap hoa don" << endl;
	cout << "In danh sach hoa don" << endl;
	cout << "Khach tra hang" << endl;
}

void menuImportInvoice()
{
	cout << "\tHOA DON NHAP\n\n";
	cout << "1. Them so luong ton cua vat tu da co" << endl;
	cout << "2. Them vat tu moi" << endl;
	cout << "3. Hien thi danh sach chi tiet hoa don" << endl;
	cout << "4. Xoa vat tu" << endl;
}

void menuExportInvoice()
{
	cout << "\tHOA DON XUAT\n\n";
	cout << "1. Them vat tu vao hoa don" << endl;
	cout << "2. Hien thi danh sach chi tiet hoa don" << endl;
	cout << "3. Xoa vat tu ra khoi hoa don" << endl;
}