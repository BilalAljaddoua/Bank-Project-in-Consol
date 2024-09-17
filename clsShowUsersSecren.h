#pragma once
#include<iostream>
#include"clsClientBank.h"
#include"clsSecrean.h"
#include"clsUser2.h"
#include"clsInputValidate.h"
#include<vector>
#include<iomanip>



class clsShowUsersSecren : protected clsSecrean
{
	static void _PrintHiderList()
	{
		cout << "\n\n---------------------------------------------------------------------------------------------------\n";
		cout << "  UserName   |" <<"FulllName\t\t    |" << "  Email\t\t   |"<<"  Phone\t|"  << "  Password   |" << " Permissons |" << endl;
		cout << "---------------------------------------------------------------------------------------------------\n";

	}
	static void PrintDataUsers(clsUser2 User)
	{
		cout << left << setw(13) << User.GetUserName() << "|  ";
		cout << left << setw(20) << User.getFullName()      << "|  " ;
		cout << left << setw(20) << User.getEmail() << "|  ";
		cout << left << setw(10) << User.getPhone() << "|  ";
		cout << left << setw(11) << clsUtil::DeCreipte(User.GetPassword()) << "|  ";
		cout << left << setw(10) << User.GetPermissions() << "|  ";
		cout << endl;

	}
public:

	static void ShowListUsers()
	{
		vector<clsUser2> User = clsUser2::GetUsersList();
		string SubTitle = "Users[" + to_string(User.size()) + "]";
		_PrintHeader("User List", SubTitle);
		_PrintHiderList();
		if (User.size() == 0)
		{
			cout << "No Users In system ";
			return;
		}
		
		for (clsUser2 U : User)
		{
			PrintDataUsers(U);
		}
		cout << "--------------------------------------------------------------------------------------------------- \n";
	}


};

