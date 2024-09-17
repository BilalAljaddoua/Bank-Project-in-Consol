#pragma once
#include<iostream>
#include <iomanip>
#include"clsMainSecren.h"
#include"clsSecrean.h"
#include"clsClientBank.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

using namespace std;


class clsDeletUse : protected clsSecrean
{

	

public:
	


	static void DeletClient()
	{

		if (!CheekPermissionRight(clsUser2::pDeleteClient))
		{
	
			return;
		}
		_PrintHeader("Delet User");

		string AccountNumber = "";
		cout << "Please Enter Account Number . ";
		AccountNumber = clsUtil::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "the AccountNumber is not exist , please try again . ";
			AccountNumber = clsUtil::ReadString();

		}
		clsBankClient ClintToDelet = clsBankClient::Find(AccountNumber);
		ClintToDelet.Print();

		char Answer = 'n';
		cout << "\nAre you want to delelt it ? y/n :\n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			ClintToDelet.DeletClient();
			ClintToDelet.Print();
		}


	}



};

