#pragma once
#include<iostream>
#include"clsUtil.h"
#include"clsUser2.h"
#include"clsMainSecren.h"
using namespace std;

class clsLogInSecren : protected clsSecrean
{
 
	static bool _Login()
	{
		bool LoginFaild = false;
		short CountFailed = 0;

		do
		{

			if (LoginFaild)
			{
				CountFailed++;
 				system("cls");
				_PrintHeader("Login Secren ");
  				cout << "\nUsername or password wrong  .";
				cout << "\nYou have " << 3- CountFailed << " Trial..";

			}
			if (CountFailed == 3)
			{
				return false;
			}

			string UserName = "", Password = "";

			cout << "\n\nPlase enter UserName ? ";
			UserName = clsUtil::ReadString();
			cout << "Plase enter Password ? ";
			Password = clsUtil::ReadString();
			CurrentUser = clsUser2::Find(UserName, clsUtil::Encript( Password));
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		CurrentUser.RegisterLogIn();  

 		clsMainSecren::PrintMainManui();

	}


public:


static bool PrintLoginSecren()
{
	system("cls");
 _PrintHeader("Login Secren ");
	return _Login();
}



};

