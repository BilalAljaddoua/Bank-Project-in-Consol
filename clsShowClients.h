#pragma once
#include <iostream>
#include <iomanip>
#include"clsMainSecren.h"
#include"clsClientBank.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsGlobal.h"



using namespace std;


class clsShowClients : protected clsSecrean
{
	static void _PrintClient(clsBankClient C)
	{
		cout << setw(20) << C.getFullName() << " | "
			<< setw(20) << C.Email << " | "
			<< setw(15) << C.Phone << " | "
			<< setw(10) << ( clsUtil::DeCreipte(C.PinCode ))<< " | "
			<< setw(10) << C.AccountNumber() << " | "
			<< setw(10) << C.AccountBalance << " | \n";
	}



public:
	static void ShowListClients()
	{
		if (!CheekPermissionRight(clsUser2::pListClients))
		{
			return;
		}
		vector<clsBankClient> Clients = clsBankClient::GetClientsData();
		cout << "_______________________________________________________________________________________________________\n";
		cout << "\t\t\t\t\t    Clients [" << Clients.size() << " ]\n";
		cout << "_______________________________________________________________________________________________________\n";
		cout << setw(20) << left << "Full Name " << " | "
			<< setw(20) << left << "Email" << " | "
			<< setw(15) << left << "Phone" << " | "
			<< setw(10) << left << "PIN cod" << " | "
			<< setw(10) << left << "AccNumber" << " | "
			<< setw(10) << left << "Balance" << " | ";
		cout << "\n_______________________________________________________________________________________________________\n";


		if (Clients.size() == 0)
			cout << "\n\t\t\t\t\tNo Clients in system  ! \n";
		else
		{
			for (clsBankClient C : Clients)
			{
				_PrintClient(C);
			}
		}
		cout << "_______________________________________________________________________________________________________\n";


 

	}


};

