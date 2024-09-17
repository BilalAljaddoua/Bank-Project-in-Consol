#pragma once
#include<iostream>
#include"clsSecrean.h"
#include"clsInputValidate.h"
#include "clsClientBank.h"
#include"clsUser2.h";

using namespace std;



class clsAddUser : protected clsSecrean
{

	static void _ReadDataUser(clsUser2& User)
	{
		cout << "Please enter first name . ";
		User.FirstName = clsUtil::ReadString();

		cout << "Please enter last name  . ";
		User.LastName = clsUtil::ReadString();

		cout << "Please enter Email      . ";
		User.Email = clsUtil::ReadString();

		cout << "Please enter Phone      . ";
		User.Phone = clsUtil::ReadString();

		cout << "Please enter Password   . ";
		User.Password = clsUtil::Encript(clsUtil::ReadString(),5);
		cout << "Plase enter Permission  . \n";
		User.Permissions = _Permission();
	}
	static int _Permission()
	{
		char Answer = 'n';
		short Permission = 0;
		cout << "\nAre you get access all system ? y/n  ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			return -1;
		}
		cout << "\nAre you get access to show Clients ? y/n  ";	
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser2::pListClients;
		}
		cout << "\nAre you get access Delet client ? y/n  ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser2::pDeleteClient;

		}
		cout << "\nAre you get access Add new client ? y/n  ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser2::pAddNewClient;

		}
		cout << "\nAre you get access Find Client ? y/n  ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser2::pFindClient;

		}
	
		cout << "\nAre you get access Update Cient ? y/n  ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser2::pUpdateClients;

		}
		cout << "\nAre you get access TreansAction ? y/n  ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser2::pTranactions;

		}
		cout << "\nAre you get access ManegeUseer ? y/n  ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser2::pManageUsers;

		}
		cout << "\nAre you get access Rigerster Login ? y/n  ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser2::pRegister;

		}
		return Permission;

	}


public:


	static void AddNewUserSecren()
	{
		_PrintHeader("Add User Secren");
		cout << "Add New Client \nPlease enter AccountNumber. ";
		string  AccuontNumber = "";
		AccuontNumber = clsUtil::ReadString();
		while (clsUser2::IsUserExist(AccuontNumber))
		{
			cout << "\n The UserName is exist , please try again .";
			AccuontNumber = clsUtil::ReadString();
		}
		clsUser2 NewClient = clsUser2::GetAddNewUserObject(AccuontNumber);
		_ReadDataUser(NewClient);
		clsUser2::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsUser2::svFaildEmptyObject:
		{
			cout << "Empty User, you can not saved...";
			break;
		}
		case clsUser2::svSucceeded:
		{
			cout << "\nsave   successed ";

			break;
		}
		case clsUser2::svFaildUserExists:
		{
			cout << "\nsave not successed !";

			break;
		}
		default:
			break;
		}

	};

};