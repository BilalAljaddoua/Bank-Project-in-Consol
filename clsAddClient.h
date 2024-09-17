#pragma once
#include<iostream>
 #include <iomanip>
#include"clsMainSecren.h"
#include"clsSecrean.h"
#include"clsClientBank.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

using namespace std;
class clsAddClient :protected clsSecrean
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
  
 	

	static	void AddNewClient()
	{

	if(!CheekPermissionRight(clsUser2::pAddNewClient))
    {
 		return;
	}

		clsSecrean::_PrintHeader("Add New Client");

		cout << "Add New Client \nPlease enter AccountNumber. ";
		string  AccuontNumber = "";
		AccuontNumber = clsUtil::ReadString();
		while (clsBankClient::IsClientExist(AccuontNumber))
		{
			cout << "\n The UserName is exist , please try again .";
			AccuontNumber = clsUtil::ReadString();
		}
		clsBankClient NewClient = clsBankClient::CreatNewClient(AccuontNumber);
		_ReadDataClient(NewClient);

		clsBankClient::enSaveResult SaveResult = NewClient.Save();

		if (SaveResult == clsBankClient::EmptyOpject)
		{
			cout << "Error , The Account Number is exist :-( \n";
		}
		else if (SaveResult == clsBankClient::SaveSucceessFully)
		{
			cout << "Succceesed Save Client \n";
		}

	}

};

