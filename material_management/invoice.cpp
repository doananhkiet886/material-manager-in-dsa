#include "invoice.h"

float defaultVat = 0.1;

int checkSameMaterialID(InvoiceDetails invoiceDetails, string materialID)
{
	for (int i = 0; i < invoiceDetails.number; i++)
	{
		if (invoiceDetails.invoiceDetail[i].materialID == materialID)
		{
			return i;
		}
	}
	return -1;
}

InvoiceNode* isSameInvoiceNo(Invoices invoices, string invoiceNo)
{
	InvoiceNode *curInvoiceNode = invoices.head;
	while (curInvoiceNode != NULL)
	{
		if (curInvoiceNode->data.invoiceNo == invoiceNo)
		{
			return curInvoiceNode;
		}
		curInvoiceNode = curInvoiceNode->invoiceNodeNext;
	}
	return NULL;
}

string createInvoiceNo(Invoices invoices)
{
	string invoiceNo = "HD00000";
	while (true)
	{
		for (int i = 2; i < invoiceNo.length(); i++)
		{
			invoiceNo[i] = rand() % 10 + 48;
		}
		if (!isSameInvoiceNo(invoices, invoiceNo))
		{
			break;
		}
	}
	
	return invoiceNo;
}

void addInvoiceDetailExport(InvoiceDetails &invoiceDetails, Materials materials, int x, int y)
{
	string materialID = "";
	while (true)
	{
		menuAddMaterialToInvoice(x, y);

		gotoXY(x + 13, y + 5);
		edit_string(materialID);

		showCur(false);

		/*
			Bắt sự kiện lựa chọn THEM hoặc THOAT hoặc XEM DANH SÁCH VAT TU
		*/
		int xThem = x, yThem = y + 10;
		int xThoat = x + 35, yThoat = y + 10;
		int xXemDSVT = x + 15, yXemDSVT = y + 12;

		char key_press;
		bool isKeyPress = true;
		int checkThemThoat = 1; // 1: them, 2: thoat, 0: khong them va khong thoat
		int checkXemDSVT = 1; // 1: xem danh sach vat tu, 0: khong xem danh sach vat tu

		box(xThem, yThem, 14, 1, 10, 10, "  THEM"); // ở vị trí mặc định là đang chọn
		while (true)
		{
			if (_kbhit())
			{
				key_press = _getch();
				if (key_press == 224 || key_press == -32)
				{
					key_press = _getch();
					if (key_press == 77 && checkXemDSVT == 0) // phải
					{
						checkThemThoat = 2;
						box(xThem, yThem, 14, 1, 9, 9, "  THEM"); // trả lại màu không chọn
						box(xThoat, yThoat, 14, 1, 10, 10, "  THOAT"); // ở vị trí đang chọn
					}
					else if (key_press == 75 && checkXemDSVT == 0) // trái
					{
						checkThemThoat = 1;
						box(xThoat, yThoat, 14, 1, 9, 9, "  THOAT"); // trả lại màu không chọn
						box(xThem, yThem, 14, 1, 10, 10, "  THEM"); // ở vị trí đang chọn
					}
					else if (key_press == 80 && checkXemDSVT == 0) // xuống
					{
						checkThemThoat = 0;
						checkXemDSVT = 1;
						box(xThem, yThem, 14, 1, 9, 9, "  THEM"); // trả lại màu không chọn
						box(xThoat, yThoat, 14, 1, 9, 9, "  THOAT"); // trả lại màu không chọn

						box(xXemDSVT, yXemDSVT, 25, 1, 10, 10, "  XEM DANH SACH VAT TU");
					}
					else if (key_press == 72 && checkXemDSVT == 1) // lên
					{
						checkThemThoat = 1;
						checkXemDSVT = 0;

						box(xXemDSVT, yXemDSVT, 25, 1, 9, 9, "  XEM DANH SACH VAT TU");

						box(xThem, yThem, 14, 1, 10, 10, "  THEM"); // trả lại màu không chọn
					}
				}
				else if (key_press == 13) // enter
				{
					// Them
					if (checkThemThoat == 1 && checkXemDSVT == 0)
					{
						int indexMaterial = checkSameMaterialID(materialID, materials);
						// Material for export found
						if (indexMaterial >= 0)
						{
							printMaterial(*materials.material[indexMaterial], x, y);
							int number;
							while (true)
							{
								cout << "So luong (" << materials.material[indexMaterial]->unit << "): ";
								cin >> number;
								cin.ignore();

								// Not enough quantity to export
								if (number > materials.material[indexMaterial]->numberInStock)
								{
									cout << "KHONG DU SO LUONG DE XUAT!" << endl;
									cout << "So luong ton: " << materials.material[indexMaterial]->numberInStock << endl;
									cout << "Ban co muon tiep tuc khong? (y/n): ";
									char yn;
									while (true)
									{
										yn = _getch();
										cout << endl;
										if (yn == 'y')
										{
											break;
										}
										else if (yn == 'n')
										{
											return; // No more implement and exit
										}
									}
								}
								else // Enough quantity to export, "break" to get the value of the material properties
								{
									break;
								}
							}

							// Get the value of the material properties
							invoiceDetails.invoiceDetail[invoiceDetails.number].materialID = materials.material[indexMaterial]->ID;
							invoiceDetails.invoiceDetail[invoiceDetails.number].materialName = materials.material[indexMaterial]->name;
							invoiceDetails.invoiceDetail[invoiceDetails.number].unitPrice = materials.material[indexMaterial]->unitPrice;
							invoiceDetails.invoiceDetail[invoiceDetails.number].unit = materials.material[indexMaterial]->unit;
							invoiceDetails.invoiceDetail[invoiceDetails.number].vat = defaultVat;
							invoiceDetails.invoiceDetail[invoiceDetails.number].status = 1;
							invoiceDetails.invoiceDetail[invoiceDetails.number].number = number;

							invoiceDetails.number++;
						}

						cout << "Ban co muon them vat tu vao hoa don nua khong? (y/n): ";
						char yn;
						yn = _getch();

						if (yn == 'n')
						{
							break;
						}
					}
					// Thoat
					if (checkThemThoat == 2 && checkXemDSVT == 0)
					{
						return;
					}
					// Xem danh sach vat tu
					if (checkThemThoat == 0 && checkXemDSVT == 1)
					{
						
					}
				}
			}
		}

		/* === */
		
	}
}

void addInvoiceDetailImport(InvoiceDetails &invoiceDetails, Materials materials)
{
	system("cls");
	cout << "\tTHEM SO LUONG TON CUA VAT TU CO SAN" << endl;
	string materialID;
	cout << "Ma Vat Tu: ";
	getline(cin, materialID);
	if (materialID.empty())
	{
		return;
	}
	int indexMaterial = checkSameMaterialID(materialID, materials);
	// Material already exist
	if (indexMaterial >= 0)
	{
		int number;
		cout << "So luong (" << materials.material[indexMaterial]->unit << "): ";
		cin >> number;
		cin.ignore();

		// Get the value of the material properties.
		// "number" of invoiceDetail then  take the input  number
		invoiceDetails.invoiceDetail[invoiceDetails.number].materialID = materials.material[indexMaterial]->ID;
		invoiceDetails.invoiceDetail[invoiceDetails.number].materialName = materials.material[indexMaterial]->name;
		invoiceDetails.invoiceDetail[invoiceDetails.number].unitPrice = materials.material[indexMaterial]->unitPrice;
		invoiceDetails.invoiceDetail[invoiceDetails.number].unit = materials.material[indexMaterial]->unit;
		invoiceDetails.invoiceDetail[invoiceDetails.number].vat = defaultVat;
		invoiceDetails.invoiceDetail[invoiceDetails.number].status = 1;
		invoiceDetails.invoiceDetail[invoiceDetails.number].number = number;

		invoiceDetails.number++;
	}
	else // Material not exist
	{
		system("cls");
		cout << "KHONG TIM THAY!" << endl;
		cout << "Nhan phim bat ky de quay lai...";
		_getch();
	}
}

void invoiceExport(InvoiceDetails &invoiceDetails, Materials materials)
{
	while (true)
	{
		system("cls");
		menuExportInvoice();
		cout << "Lua chon: ";
		char key_press = _getch();
		
		if (key_press == '1')
		{
			addInvoiceDetailExport(invoiceDetails, materials);
		}
		else if (key_press == '2')
		{
			system("cls");
			printInvoiceDetails(invoiceDetails);
			_getch();
		}
		else if (key_press == '3')
		{
			removeInvoiceDetail(invoiceDetails);
		}
		else if (key_press == 13) //enter
		{
			return;
		}
	}
}

void invoiceImport(InvoiceDetails &invoiceDetails, Materials materials)
{

	while (true)
	{
		system("cls");
		menuImportInvoice();
		cout << "Lua chon: ";
		char key_press = _getch();

		if (key_press == '1')
		{
			addInvoiceDetailImport(invoiceDetails, materials);
		}
		else if (key_press == '2')
		{
			system("cls");
			addMaterial(materials, 0, 0);
		}
		else if (key_press == '3')
		{
			system("cls");
			printInvoiceDetails(invoiceDetails);
			_getch();
		}
		else if (key_press == '4')
		{
			removeInvoiceDetail(invoiceDetails);
		}
		else if (key_press == 13) // enter
		{
			return;
		}
	}
}

void invoice(Invoices &invoices, Materials &materials)
{
	while (true)
	{
		string no;
		string date;
		char type;
		InvoiceDetails invoiceDetails;

		no = createInvoiceNo(invoices);
		date = getSystemDateTime();

		system("cls");
		cout << "\tLAP HOA DON\n\n";
		cout << "Loai (N/X): ";
		type = _getch();

		if (type == 'N' || type == 'X')
		{
			type = type + 32;
		}
		int x = INT_MAX;
		if (type == 'n')
		{
			invoiceImport(invoiceDetails, materials);

			system("cls");
			cout << "Xac nhan lap hoa don? (y/n): ";
			char key_press = _getch();

			if (key_press == 'y')
			{
				InvoiceNode *invoiceNode = createInvoiceNode(no, date, type, invoiceDetails);
				addInvoiceNode(invoices.head, invoiceNode);
				invoices.number++;
				return;
			}
			else if (key_press == 'n')
			{
				return;
			}
		}
		else if (type == 'x')// type == 'X'
		{
			invoiceExport(invoiceDetails, materials);
			system("cls");
			cout << "Xac nhan lap hoa don? (y/n): ";
			char key_press = _getch();

			if (key_press == 'y')
			{
				InvoiceNode *invoiceNode = createInvoiceNode(no, date, type, invoiceDetails);
				addInvoiceNode(invoices.head, invoiceNode);
				invoices.number++;
				return;
			}
			else if (key_press == 'n')
			{
				return;
			}
		}
		else if (type == 13)
		{
			break;
		}
	}
}

void printInvoiceDetail(InvoiceDetail invoiceDetail)
{
	cout << "Ma Vat Tu: " << invoiceDetail.materialID << endl;
	cout << "Ten Vat Tu: " << invoiceDetail.materialName << endl;
	cout << "Don Vi Tinh: " << invoiceDetail.unit << endl;
	cout << "So Luong: " << invoiceDetail.number << endl;
	cout << "Don Gia: " << invoiceDetail.unitPrice << endl;
	cout << "Thue VAT: " << invoiceDetail.vat << " %" << endl;
	if (invoiceDetail.status == 1)
	{
		cout << "Trang thai: mua" << endl;
	}
	else
	{
		cout << "Trang thai: tra" << endl;
	}
}

void printInvoiceDetails(InvoiceDetails invoiceDetails)
{
	cout << "\n\t**** DANH SACH CHI TIET HOA DON ***\n\n";
	for (int i = 0; i < invoiceDetails.number; i++)
	{
		printInvoiceDetail(invoiceDetails.invoiceDetail[i]);
		if (i != invoiceDetails.number - 1)
		{
			cout << "....................................." << endl;
		}
	}
}

void printInvoice(InvoiceData invoiceData)
{
	cout << "So Hoa Don: " << invoiceData.invoiceNo << endl;
	cout << "Ngay Lap Hoa Don: " << invoiceData.date << endl;
	if (invoiceData.type == 'N')
	{
		cout << "Loai: Nhap kho" << endl;
	}
	else
	{
		cout << "Loai: Xuat kho" << endl;
	}
	printInvoiceDetails(invoiceData.invoiceDetails);
}

void printInvoices(Invoices invoices)
{
	InvoiceNode *curNode = invoices.head;
	cout << "\tDANH SACH HOA DON";
	while (curNode != NULL)
	{
		cout << "\n\n";
		printInvoice(curNode->data);
		curNode = curNode->invoiceNodeNext;
		cout << "______________________________________";
	}
}

void updateNumberInStock(Materials &materials, InvoiceData invoiceData)
{
	for (int i = 0; i < invoiceData.invoiceDetails.number; i++)
	{
		int indexMaterial = checkSameMaterialID(invoiceData.invoiceDetails.invoiceDetail[i].materialID, materials);
		if (indexMaterial >= 0)
		{
			if (invoiceData.type == 'X')
			{
				materials.material[indexMaterial]->numberInStock -= invoiceData.invoiceDetails.invoiceDetail[i].number;
			}
			else
			{
				materials.material[indexMaterial]->numberInStock += invoiceData.invoiceDetails.invoiceDetail[i].number;
			}
		}
	}
}

void removeInvoiceDetail(InvoiceDetails &invoiceDetails)
{
	if (invoiceDetails.number == 0)
	{
		cout << "\nDanh sach chi tiet hoa don rong!" << endl;
		cout << "Nhan phim bat ky de quay lai...";
		_getch();
		return;
	}

	system("cls");
	cout << "\tXOA VAT TU RA KHOI HOA DON\n\n";
	cout << "Ma Vat Tu: ";
	string materialID;
	getline(cin, materialID);

	if (materialID.empty())
	{
		return;
	}

	bool isDeleted = false;
	int iToDelete = 0;
	int iCur = 0;
	while (iCur < invoiceDetails.number)
	{
		if (invoiceDetails.invoiceDetail[iCur].materialID != materialID)
		{
			invoiceDetails.invoiceDetail[iToDelete] = invoiceDetails.invoiceDetail[iCur];
			iToDelete++;
		}
		else
		{
			isDeleted = true;
		}
		iCur++;
	}
	invoiceDetails.number = iToDelete;

	if (isDeleted)
	{
		cout << "Da xoa thanh cong!" << endl;
		_getch();
		return;
	}

	cout << "Khong tim thay vat tu!" << endl;
	cout << "Nhan phim bat ky de quay lai...";
	_getch();
}

void customerReturnItem(Invoices &invoices, Materials &materials)
{
	while (true)
	{
		system("cls");
		cout << "\t\tKHACH TRA HANG\n\n" << endl;

		cout << "So Hoa Don: ";
		string invoiceNo;
		getline(cin, invoiceNo);
		if (invoiceNo.empty())
		{
			return;
		}

		InvoiceNode *invoiceFound = isSameInvoiceNo(invoices, invoiceNo);

		if (invoiceFound == NULL)
		{
			cout << "Khong tim thay..." << endl;
			_getch();
		}
		else
		{
			while (true)
			{
				system("cls");
				printInvoice(invoiceFound->data);
				cout << "------------------------------------------\n\n";
				cout << "Ma Vat Tu ma khach tra: ";
				string materialID;
				getline(cin, materialID);
				if (materialID.empty())
				{
					break;
				}

				int indexMaterialOfInvoiceDetails = checkSameMaterialID(invoiceFound->data.invoiceDetails, materialID);
				if (indexMaterialOfInvoiceDetails >= 0)
				{
					if (is3Days(getSystemDateTime(), invoiceFound->data.date))
					{
						invoiceFound->data.invoiceDetails.invoiceDetail[indexMaterialOfInvoiceDetails].status = 0;
						//Cập nhật lại số lượng tồn của vật tư trả
						int indexMaterialOfMaterials = checkSameMaterialID(materialID, materials);
						if (indexMaterialOfMaterials >= 0)
						{
							if (invoiceFound->data.type == 'X')
							{
								materials.material[indexMaterialOfMaterials]->numberInStock += invoiceFound->data.invoiceDetails.invoiceDetail[indexMaterialOfInvoiceDetails].number;
							}
							else if (invoiceFound->data.type == 'N')
							{
								materials.material[indexMaterialOfMaterials]->numberInStock -= invoiceFound->data.invoiceDetails.invoiceDetail[indexMaterialOfInvoiceDetails].number;
							}
						}
						
						cout << "Da thay doi trang thai hang..." << endl;
					}
					else
					{
						cout << "Hang da mua qua 3 ngay. Khong the tra hang..." << endl;
					}
				}
				else
				{
					cout << "Khong tim thay vat tu..." << endl;
				}
				_getch();
			}
			
		}
	}
	
}
