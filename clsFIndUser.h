#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include "clsSecrean.h"
#include "clsUser2.h"


class clsFIndUser :protected clsSecrean
{

	static void _PrintUserCard(clsUser2 User)
	{
		cout << "\n----------------------";
		cout << "\nUser Name  :  " << User.GetUserName();
		cout << "\nFull Name  :  " << User.getFullName();
		cout << "\nEmail      :  " << User.Email;
		cout << "\nPhone      :  " << User.Phone;
		cout << "\nPassword   :  " << User.Password;
		cout << "\nPermission :  " << User.Permissions;
		cout << "\n----------------------\n";
		User.Email;

	}


public:
	static void FindUser()
	{
		_PrintHeader("Delet User");
		vector<clsUser2> Users = clsUser2::GetUsersList();
		cout << "Please enter User Name . ";
		string UserToDelet = clsUtil::ReadString();
		while (!clsUser2::IsUserExist(UserToDelet))
		{
			cout << "This user is not found , please try again . ";
			UserToDelet = clsUtil::ReadString();
		}
		clsUser2 UserDelet = clsUser2::Find(UserToDelet);
		_PrintUserCard(UserDelet);


	}

};