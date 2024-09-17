#pragma once
#include"clsSecrean.h"
#include<iostream>
#include"clsClientBank.h"

using namespace std;

class clsTransFireSecreen :protected clsSecrean
{
	static void _PrintCard(clsBankClient Client)
	{
		cout << "\n----------------------------\n";
		cout << "Acc . Number :" << Client.AccountNumber() << endl;
		cout << "Name         :" << Client.getFullName() << endl;
		cout << "Balance      :" << Client.AccountBalance << endl;
		cout << "----------------------------\n";
	}
	static float _ReadAmount(clsBankClient Sourse)
	{
		cout << "Please enter Amount . ";
		float Amount;
		cin>> Amount;
		while (Amount > Sourse.AccountBalance)
		{
			cout << "\nPlease enter another amount , your balance is :" << Sourse.AccountBalance << endl;
			cin >> Amount;

		}
		return Amount;
	}
 
public:


	static void ShowTransFer()
	{
		_PrintHeader("TransFer");
		string From;

		cout << "\nPlease enter Source Account Number  \n";
		string AccSource = clsUtil::ReadString();
		clsBankClient SourceClient = clsBankClient::Find(AccSource);

		while (SourceClient.IsEmpty())
		{
			cout << "\nThe user is not found , please try againe . \n";
			  AccSource = clsUtil::ReadString();
			clsBankClient SourceClient = clsBankClient::Find(AccSource);

		}
		From = AccSource;
		_PrintCard(SourceClient);
		 
		cout << "\nPlease enter Destion Account Number  \n";
		string AccDestinos= clsUtil::ReadString();
		clsBankClient DestionClient = clsBankClient::Find(AccDestinos);


		while (DestionClient.IsEmpty()|| (From == AccDestinos))
		{
			if (From == AccDestinos)
			{
				cout << "\nYou cann't  chose the same account , Please chose another one . \n";

			}
			else
			{
		cout << "\nThe user is not found , please try againe . \n";
			}
			 AccDestinos = clsUtil::ReadString(); 
			clsBankClient SourceClient = clsBankClient::Find(AccDestinos);

		}
		  DestionClient = clsBankClient::Find(AccDestinos);
		_PrintCard(DestionClient);

		float Amount =_ReadAmount(SourceClient);
	
		cout << "are you want to do this transfer  ? y/n ";
		char A = 'n';
		cin >> A;
		if(A=='y'||A=='Y')
		{

			if (SourceClient.Transfere(Amount, DestionClient,CurrentUser.UserName))
			{
				//CurrentUser.RegisterTransfer(SourceClient, DestionClient,Amount);
				cout << "\nSuccses transfer . ";
			}
			else
			{
				cout << "\nFaild transfer .";
			}

		}
 		_PrintCard(DestionClient);

		_PrintCard(SourceClient); 

	}


};

