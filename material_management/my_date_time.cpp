#include "my_date_time.h"

string getSystemDateTime()
{
	time_t now = time(NULL);
	tm *ltime = localtime(&now);
	return to_string(ltime->tm_year + 1900) + "/" + to_string(ltime->tm_mon + 1)
		+ "/" + to_string(ltime->tm_mday) + " " + to_string(ltime->tm_hour)
		+ ":" + to_string(ltime->tm_min) + ":" + to_string(ltime->tm_sec);
}

string getDateFromDateTime(string dateTime)
{
	string *dateTimeArray = splitString(dateTime, ' ');
	return dateTimeArray[0];
}

bool is3Days(string date_1, string date_2)
{
	string *dateArray1 = splitString(getDateFromDateTime(date_1), '/');
	string *dateArray2 = splitString(getDateFromDateTime(date_2), '/');
	if (dateArray1[0] == dateArray2[0] && dateArray1[1] == dateArray2[1])
	{
		int distance = stoi(dateArray1[2]) - stoi(dateArray2[2]);
		if (distance <= 3)
		{
			return true;
		}
	}
	return false;
}