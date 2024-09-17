#pragma once
#include"clsSecrean.h"
#include"clsUtil.h";
#include"clsAddClient.h";
#include"clsUpdateClient.h";
#include"clsDeletUse.h";
#include"clsShowClients.h"
#include"clsFindClient.h"
#include"clsInputValidate.h";
#include"clsTransAction.h";
#include"clsManegUserSecren.h";
#include"clsLogInSecren.h";
#include<iostream>
#include<iomanip>
#include"clsScreenLoginRegister.h";
 #include"clsScreenCurrency.h";

using namespace std;

bool Login = false;

class clsMainSecren :protected clsSecrean
{
	static void _GoToMainManui()
	{
	
 		cout << "\n\n\t\t\t\t\t\tPlease peress any kay...";
		system("pause>0");
		PrintMainManui();

	
	}
	
	static void PrintAddClientSecrean()
	{
		system("cls");
		clsAddClient::AddNewClient();
		_GoToMainManui();
 	}

	static void PrintUpdateClientSecrean()
	{
		system("cls");
		clsUpdateClient::UpDateClient();
		_GoToMainManui();
	}

	static void PrintFindClientSecrean()
	{
		system("cls");
		clsFindClient::FindClient();
		_GoToMainManui();
 	}

	static void PrintShowClientsSecrean()
	{
		system("cls");
		clsShowClients::ShowListClients();
		_GoToMainManui();
 	}
 
	static void PrintDeleteClientsSecrean()
	{
		system("cls");
		clsDeletUse::DeletClient();
 		_GoToMainManui();
	}

	static void PrintTransAcionClientsSecrean()
	{
		system("cls");
		clsTransAction::TransActionSecren();
		_GoToMainManui();
	}

	static void PrintManegUsersSecrean()
	{
		system("cls");
		clsManegUserSecren::ShowMainManuiSecren();
		_GoToMainManui();
	}
	
	static void PrintLogInRegisterSecrean()
	{
		system("cls");
		clsScreenLoginRegister::ShowLoginRegister();
			_GoToMainManui();
	}

	static void _Logout()
	{
		CurrentUser = clsUser2::Find("", "");
    }

	static enum _Options{Show=1,Add=2,Update=3,Delet=4,Trans=5,Maneg=6,Find=7,Rigester=8,Crruncychang=9, LogOut=10	};

	static void _PerformOption(_Options Num)
	{
		switch (Num)
		{
		case clsMainSecren::Show:
		{
			system("cls");
			PrintShowClientsSecrean();

			break;
		}
		case clsMainSecren::Add:
		{
			system("cls");
			PrintAddClientSecrean();
 
			break;
		}
		case clsMainSecren::Update:
		{
			system("cls");
			PrintUpdateClientSecrean();
 
			break;
		}
		case clsMainSecren::Delet:
		{
			system("cls");
			PrintDeleteClientsSecrean();
			_GoToMainManui();
			break;
		}
		case clsMainSecren::Trans:
		{
			system("cls");
			PrintTransAcionClientsSecrean();
			_GoToMainManui();
			break;
		}
		case clsMainSecren::Maneg:
		{
			system("cls");
			PrintManegUsersSecrean();
			_GoToMainManui();

			break;
		}
		case clsMainSecren::Find:
		{
			system("cls");

			PrintFindClientSecrean();
 
			break;
		}
		case clsMainSecren::Rigester: 
		{
			system("cls");

			PrintLogInRegisterSecrean();
 
			break;
		}
		
		case clsMainSecren::LogOut:
		{
			system("cls");
			_Logout();
			break;
		}
		case clsMainSecren::Crruncychang:
		{
			system("cls");
			clsScreenCurrency::PrintCrruencySecreen();
			_GoToMainManui();

			_Logout();
 			break;
		}
		default:
		{
 		}
		}
 
	}


public:
	static void PrintMainManui()
	{
		system("cls");
		 	clsSecrean::_PrintHeader("   Main Manui");

		cout << "\n"<< clsUtil::Tabs(5)<<"================================================= \n";
		cout << clsUtil::Tabs(3)<< "[1]  Show list clients .\n";
		cout << clsUtil::Tabs(3)<< "[2]  Add  new  client .\n";
		cout << clsUtil::Tabs(3)<< "[3]  UpDate client .\n";
		cout << clsUtil::Tabs(3)<< "[4]  Delet Client .\n";
		cout << clsUtil::Tabs(3)<< "[5]  Transpher action .\n";
		cout << clsUtil::Tabs(3)<< "[6]  Manege users .\n";
		cout << clsUtil::Tabs(3)<< "[7]  Find Client .\n";
		cout << clsUtil::Tabs(3)<< "[8]  Rigester Login.\n";
		cout << clsUtil::Tabs(3)<< "[9]  Crrency Exchange.\n";
		cout << clsUtil::Tabs(3)<< "[10] Logout.\n";

		cout << "\n" << clsUtil::Tabs(5) << "=================================================\n";
		cout << endl<<  clsUtil::Tabs(5) << "Please choice from 1 to 10 ? .";
		short Num=clsInputValidate::ReadShortNumberBetween(1,10, "InValid Number , Please enter Number betwen 1 to 10 .");
		_PerformOption((_Options)Num);

	}


};

