#pragma once
#include"clsUser2.h"
#include<iostream>
#include"clsSecrean.h"


class clsUpdateUser : protected clsSecrean
{
	static void _UpDateUser(clsUser2& User)
	{
	
		cout << "Please enter First Name : ";
		User.FirstName = clsUtil::ReadString();
		cout << "Please enter Last Name : ";
		User.LastName = clsUtil::ReadString();
		cout << "Please enter Email : ";
		User.Email = clsUtil::ReadString();
		cout << "Please enter Phone  : ";
        User.Phone = clsUtil::ReadString();
		cout << "Please enter Password : ";
		User.Password = clsUtil::Encript(clsUtil::ReadString(), 5);
		cout << "Please enter Permission : ";
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

		return Permission;

	}
	static void _PrintUserCard(clsUser2 User)
	{
		cout << "\n----------------------";
		cout << "\nFull Name  :  " << User.getFullName();
		cout << "\nEmail      :  " << User.Email;
		cout << "\nPhone      :  " << User.Phone;
		cout << "\nPassword   :  " << User.Password;
		cout << "\nPermission :  " << User.Permissions;
		cout << "\n----------------------\n";

	}


public:

	static void UodateUser()
	{
		_PrintHeader("Update User ");
		string AccountNumber = "";
		cout << "Please Enter Account Number . ";
		AccountNumber = clsUtil::ReadString();
		while (!clsUser2::IsUserExist(AccountNumber))
		{
			cout << "the AccountNumber is not exist , please try again . ";
			AccountNumber = clsUtil::ReadString();

		}
		clsUser2 UserToUpdat = clsUser2::Find(AccountNumber);
		_PrintUserCard(UserToUpdat);
		char Answer = 'n';
		cout << "\nAre you want to Update it ? y/n :\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			_UpDateUser(UserToUpdat);
			clsUser2::enSaveResults Result;
			Result=UserToUpdat.Save();

			switch (Result)
			{
			case clsUser2::svFaildEmptyObject: 
			{
				cout << "The opject is empty ...Error save.";
				break;
			}
			case clsUser2::svSucceeded:
			{
				cout << " Save successfuly :-)";
				_PrintUserCard(UserToUpdat);
				break;
			}
			case clsUser2::svFaildUserExists:
			{
				cout << "Falid save updates";
				break;
			}
			default:
				break;
			}
		}
	}


};

