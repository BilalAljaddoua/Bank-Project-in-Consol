#pragma once
#include<iostream>
#include"clsSecrean.h"
#include"clsClientBank.h"
#include"clsInputValidate.h"
#include"clsDeposit.h"
#include"clsMainSecren.h"
class clsTotalBalance : protected clsSecrean
{


	static void PrintshowTransAcionClints(clsBankClient Client)
	{
		
		cout << left << setw(35) << Client.getFullName() << " | ";
		cout << left << setw(35) << Client.AccountNumber() << " | ";
		cout << left << setw(35) << Client.AccountBalance << " | ";
		cout << endl;
	}

 

public :

	static void TotalBalance()
	{

		vector<clsBankClient> Clients = clsBankClient::GetClientsData();
		string Subtilte = "Clients [" + to_string(Clients.size()) + "]";
		clsSecrean::_PrintHeader("Total Balance",Subtilte);
		cout << "-----------------------------------------------------------------------------------------------------------------\n";
		for (clsBankClient C : Clients)
		{
			PrintshowTransAcionClints(C);
		}
		cout << "-----------------------------------------------------------------------------------------------------------------\n";
		double Total =clsBankClient::GetTotalBalance(Clients);

		cout << "Total Balance is : " << Total << endl;
		cout <<clsUtil::NumberToText(Total)<<endl;

	}

 
};

