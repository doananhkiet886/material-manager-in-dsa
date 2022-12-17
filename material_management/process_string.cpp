#include "process_string.h"

void normalizeString(string &str)
{
	if (str.length() < 1)
	{
		return;
	}
	//delete first space
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}

	// delete middle space
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}

	// delete last space
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1);
	}

	//normalize letters
	if (str[0] >= 97 && str[0] <= 122)
	{
		str[0] -= 32;
	}

	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			i++;
			if (str[i] >= 97 && str[i] <= 122)
			{
				str[i] -= 32;
			}
		}
		else
		{
			if (str[i] >= 65 && str[i] <= 90)
			{
				str[i] += 32;
			}
		}
	}
}

string* splitString(string src, char delim)
{
	int numberDelim = 0;
	for (int isrc = 0; isrc < src.length(); isrc++)
	{
		if (src[isrc] == delim)
		{
			numberDelim++;
		}
	}

	if (numberDelim == 0)
	{
		return NULL;
	}

	string *strs = new string[numberDelim + 1];
	int i = 0;

	for (int isrc = 0; isrc < src.length(); isrc++)
	{
		if (src[isrc] != delim)
		{	
			strs[i].push_back(src[isrc]);
		}
		else
		{
			i++;
		}
	}
	return strs;
}

string getName(string fullName)
{
	string name = "";
	int i = fullName.length();
	while (fullName[i] != ' ')
	{
		i--;
	}
	name = fullName.substr(i + 1);
	return name;
}

bool isOnlyDigits(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
		{
			return false;
		}
	}
	return true;
}

void edit_string(string& str)
{
	cout << str;

	char ch;
	ch = _getch();
	while (ch != 13) //Nhan enter de ket thuc
	{
		if (ch == 8) //Khi nhan nut backspace
		{
			if (str.length() > 0) //Neu length > 0 thi moi xoa
			{
				cout << '\b'; //Xoa ki tu trong console
				cout << ' '; //Thay the ki tu do bang space
				cout << '\b'; //Xoa space vua moi them vao
				str.erase(str.length() - 1, 1); //Xoa ki tu luu trong string
			}
		}
		else
		{
			str.push_back(ch); // Them char vua nhap vao string
			cout << ch; //Hien thi char vua nhap
		}
		ch = _getch();
	} //End while
	//delete_space(str);
}

void delete_space(string& str)
{
	if (str.length() > 0)
	{
		unsigned short cnt = 0; //Bien dem khoang trang
		for (size_t i = 0; i < str.length(); i++) //Chay het chuoi
		{
			if (str[i] == 32) //Gap khoang trang tang bien dem len 1
				++cnt;
			else //Neu gap ki tu thuong thi khoi tao lai bien dem
				cnt = 0;

			if (cnt > 1)
			{
				str.erase(i, 1); //Xoa khoang trang
				--i; //Tra lai vi string da thay doi vi tri va length
			}
		}
		//Xoa khoang trang dau va cuoi
		if (str[str.length() - 1] == 32)
			str.erase(str.length() - 1, 1);
		if (str[0] == 32)
			str.erase(0, 1);
	}
}
