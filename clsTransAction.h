#pragma once
#include<iostream>
#include"clsSecrean.h"
#include"clsMainSecren.h"
#include"clsClientBank.h"
#include"clsInputValidate.h"
 #include"clsWithDrow.h"
#include"clsTotalBalance.h"
#include"clsDeposit.h"
#include"clsTransFireSecreen.h"
#include"clsShowTransFers.h"

using namespace std;

class clsTransAction :protected clsSecrean
{
	static void PresAnyKaytoMange()
	{
		cout << "\n\n\t\t\t\t\t\tPlease peress any kay...";
		system("pause>0");
 

	}
	static enum enTransAcion { Deposit = 1, WithDrow = 2, ToralPalanc = 3,TransFer=4, ShowTransfers=5,MainManiu = 6 };
	static void _PresAnyKayToScrenTransAcion()
	{
		cout << "\nPlease pres any kay to maniu\n";
		system("pause>0");
		TransActionSecren();
	}
	static enTransAcion _ReadTypeTransFromUser()

	{
		short a;
		cout << "\nChoose what do you want to do ? [1->6].  ";
		a=clsInputValidate::ReadIntNumberBetween(1, 6);
return ((enTransAcion)(a));
	}
 	static void _PrintFormatOneClient(clsBankClient Clint)
	{
		cout << "\n\nThe follwing are client [" << Clint.AccountNumber() << "] ditails :\n";
		cout << setw(20) << "\nName Client    :" << Clint.getFullName();
		cout << setw(20) << "\nAccount Number :" << Clint.AccountNumber();
		cout << setw(20) << "\nPhone Number   :" << Clint.Phone;
		cout << setw(20) << "\nPIN cod        :" << Clint.PinCode;
		cout << setw(20) << "\nBalance         :" << Clint.AccountBalance;
	}
 	static void _GoToMainManui();
 
	




	static void _ChoiceTypeTransAcion(enTransAcion Trans )
	{
		switch (Trans)
		{
		case(enTransAcion::Deposit):
		{
			system("cls");
		
		 
			clsDepositScreen::ShowDepositScreen();
		
			_PresAnyKayToScrenTransAcion( );
			break;
		}
		case(enTransAcion::WithDrow):
		{
			system("cls");
 			clsWithdrawScreen::ShowWithdrawScreen();

 			_PresAnyKayToScrenTransAcion();
			break;
		}
 		case(enTransAcion::ToralPalanc):
		{
			system("cls");
			clsTotalBalance::TotalBalance();
 			_PresAnyKayToScrenTransAcion();
			break;
		}
		case(enTransAcion::TransFer):
		{
			system("cls");
			clsTransFireSecreen::ShowTransFer();
			_PresAnyKayToScrenTransAcion();
			break;
		}
		case(enTransAcion::ShowTransfers):
		{
			system("cls");
			clsShowTransFers::ShowTransFersScreen();
			_PresAnyKayToScrenTransAcion();
			break;
		}
		case(enTransAcion::MainManiu):
		{
			system("cls");
 			break;
		}
		}
	}


public:



	static void  TransActionSecren()
	{
		if (!CheekPermissionRight(clsUser2::pTranactions))
		{
			
			return;
		}
 	 
		system("cls");
		cout << "\t\t\t===============================\n";
		cout << "\t\t\t     TransAction secren     \n";
		cout << "\t\t\t===============================\n";
		cout << "\t\t\t[1] Deposit . \n";
		cout << "\t\t\t[2] With Drow . \n";
		cout << "\t\t\t[3] Total Palance . \n";
		cout << "\t\t\t[4] TransFire . \n";
		cout << "\t\t\t[5] Show Transfer . \n";
		cout << "\t\t\t[6] Main Maniu . \n";
		cout << "\t\t\t_________________________________\n";
		_ChoiceTypeTransAcion(_ReadTypeTransFromUser());
	}




};

