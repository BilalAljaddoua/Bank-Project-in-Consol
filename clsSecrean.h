#pragma once
#include"clsUtil.h"
#include<iostream>
#include<iomanip>
#include"clsGlobal.h"
#include"clsDate.h"

using namespace std;
class clsSecrean

{

protected:
	static void _PrintHeader(string Massege,string SubTitle="")
	{
		clsDate Date = clsDate::GetSystemDate();
		cout << "\n\t----------------------------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t\t" << Massege;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t\t" << SubTitle;
		}
		cout << "\n\t---------------------------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t\t User : " << CurrentUser.UserName<<endl;
		cout << "\t\t\t\t\t\t Date : " << clsDate::DateToString(Date)<<"\n\n";

	}


	static bool CheekPermissionRight(clsUser2::enPermissions Permission)
	{
		if (CurrentUser.Permissions == clsUser2::enPermissions::eAll)
			return true;
		else if ((CurrentUser.Permissions & Permission) == Permission)
			return true;
		cout << "\n\t\t------------------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t Access Dinide , Please conect with Admin.";
		cout << "\n\t\t------------------------------------------------------------------------------------------\n";

		return false;
	}

};

