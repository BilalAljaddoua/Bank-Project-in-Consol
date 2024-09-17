 #pragma once
#include <iostream>
#include <iomanip>
#include"clsMainSecren.h"
#include"clsClientBank.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsGlobal.h"

class clsUpdateClient :protected clsSecrean
{
	static void _ReadDataClient(clsBankClient& Client)
	{

		cout << "Please Enter First Name  .";
		Client.FirstName = clsUtil::ReadString();

		cout << "Please Enter last Name   .";
		Client.LastName = clsUtil::ReadString();

		cout << "Please Enter Email       .";
		Client.Email = clsUtil::ReadString();

		cout << "Please Enter Phone       .";
		Client.Phone = clsUtil::ReadString();

		cout << "Please Enter PIN         .";
		Client.PinCode = clsUtil::Encript(clsUtil::ReadString());

		cout << "Please Enter Balanse     .";
		Client.AccountBalance = clsInputValidate::ReadIntNumber();


	}



public:
	static void UpDateClient()
	{
		if (!CheekPermissionRight(clsUser2:: pUpdateClients))
		{
			return;
		}
		clsSecrean::_PrintHeader("UpDate Users");
		 
		
			string AccountNumber = "";
			cout << "Please Enter Account Number . ";
			AccountNumber = clsUtil::ReadString();
			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				cout << "the AccountNumber is not exist , please try again . ";
				AccountNumber = clsUtil::ReadString();

			}
			clsBankClient Clint = clsBankClient::Find(AccountNumber);
			Clint.Print();

			cout << "\nUpDate Info client :\n";
			_ReadDataClient(Clint);

			clsBankClient::enSaveResult SaveResult = Clint.Save();

			if (SaveResult == clsBankClient::EmptyOpject)
			{
				cout << "Error ;-(\n";
			}
			else
			{
				cout << "successFully\n";
			}





		

	}


};

