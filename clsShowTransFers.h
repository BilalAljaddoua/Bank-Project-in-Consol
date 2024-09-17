#pragma once
#include"clsSecrean.h"
#include"clsClientBank.h"
class clsShowTransFers : protected clsSecrean
{

	static void _PrintHiderScreen()
	{
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		cout << left << setw(22) << " Date & Time " << "|";
		cout << left << setw(10) << " S.Client   " << "|";
		cout << left << setw(10) << " D.Client   " << "|";
		cout << left << setw(20) << " Amount " << "|";
		cout << left << setw(15) << " S.Balance   " << "|";
		cout << left << setw(15) << " D.Balance  " << "|";
		cout << left << setw(10) << " By User " << "|";
		cout << "\n------------------------------------------------------------------------------------------------------------------------\n";

	}
	static void _PrintData()
	{
		
		   vector<clsBankClient::DataTransfer>vDataTransfers = clsBankClient::GetTransferLog(); 
		   string SubTitle = "";
		   SubTitle = "[" + to_string(vDataTransfers.size()) + "] Records";
		   _PrintHeader("Transfers ", SubTitle);
		   _PrintHiderScreen();
		for(clsBankClient::DataTransfer D:vDataTransfers) 
		{
			cout << left <<  setw(22) << D.Date << "|";
			cout << left <<  setw(12) << D.Client1 << "|";
			cout << left <<  setw(12) << D.Client2 << "|";
			cout << left <<  setw(20) << D.Amount << "|";
			cout << left <<  setw(15) << D.AccBal1 << "|";
			cout << left <<  setw(15) << D.AccBal2 << "|";
			cout << left <<  setw(10) << D.User << "|";
			cout << endl;
		}
		cout << "------------------------------------------------------------------------------------------------------------------------\n";


	}


public:

	static void ShowTransFersScreen()
	{
	
		_PrintData();

	}



};

