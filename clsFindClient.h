#pragma once
#include<iostream>
#include<iomanip>
#include"clsSecrean.h"
 #include"clsClientBank.h";
#include"clsGlobal.h"

using namespace std;


class clsFindClient : protected clsSecrean
{

	static bool SearhAtVectorUserToUsername(string UserName, clsBankClient& Client)
	{
		  (Client = clsBankClient::Find(UserName));
		  return !Client.IsEmpty();
	}
	static void _PrintClient(clsBankClient C)
	{
		cout << setw(20) << C.getFullName() << " | "
			<< setw(20) << C.Email << " | "
			<< setw(15) << C.Phone << " | "
			<< setw(10) << C.PinCode << " | "
			<< setw(10) << C.AccountNumber() << " | "
			<< setw(10) << C.AccountBalance << " | \n";
	}



public:


	static void FindClient()
	{
		if (!CheekPermissionRight(clsUser2::pFindClient))
		{
			return;
		}
		string UserName;
		clsBankClient Client=clsBankClient::GetEmptyClientObject();
		cout << "Please enter Username ? ";
		cin >> UserName;
		if (SearhAtVectorUserToUsername(UserName, Client))
		{
			cout << "_______________________________________________________________________________________________________\n";
 			cout << setw(20) << left << "Full Name " << " | "
				<< setw(20) << left << "Email" << " | "
				<< setw(15) << left << "Phone" << " | "
				<< setw(10) << left << "PIN cod" << " | "
				<< setw(10) << left << "AccNumber" << " | "
				<< setw(10) << left << "Balance" << " | ";
			cout << "\n_______________________________________________________________________________________________________\n";

 
				_PrintClient(Client);
				cout << "_______________________________________________________________________________________________________\n";
		}
		else
		{
			cout << "\nThe username is not found \n";
		}

	}


 

};

