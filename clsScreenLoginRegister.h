#pragma once
#include"clsLoginRegister.h"
#include<iostream>
#include"clsSecrean.h"
#include"clsLoginRegister.h"
class clsScreenLoginRegister : protected clsSecrean
{
	
	
	static void _PrintHiderLoginRegister()
	{
		cout << "\n\t\t--------------------------------------------------------------------------\n";
		cout << "\t\t\tDate Login \t |  UserName   |  Password    | Permisssion   |\n";
		cout << "\t\t--------------------------------------------------------------------------\n";
	}
	static void vPrintLogInData(clsLoginRegister LoginReg)
	{
		cout << "\t\t"<<left << setw(25) << LoginReg.DateLogin <<"|";
		cout << left << setw(13)<<LoginReg.UserName << "|";
		cout << left << setw(14) << clsUtil::DeCreipte(clsUtil::DeCreipte(LoginReg.Password)) << "|";
		cout << left << setw(15)<<LoginReg.Permission << "|";

	}
public:


	static void ShowLoginRegister()
	{
		if (!CheekPermissionRight(clsUser2::pRegister))
		{

			return;
		}
		_PrintHeader("Login Regester");
		_PrintHiderLoginRegister();
		vector <clsLoginRegister> vLogInData = clsLoginRegister::ReadDataLogin();
		for (clsLoginRegister V : vLogInData)
		{
			vPrintLogInData(V);
			cout << endl;
 		}
		cout << "\t\t--------------------------------------------------------------------------\n";


	}



};

