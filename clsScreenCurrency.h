#pragma once
#include<iostream>
#include"clsSecrean.h"
#include"clsCrrunecy.h"
#include"clsInputValidate.h"
#include"clsCrruncyiesListSecreen.h"
#include"clsFindCrruncy.h"
#include"clsUpdateCrruency.h"
#include"clsCalculatCrruency.h"
 class clsScreenCurrency : protected clsSecrean
{


 

	enum enCrruency{List=1,Find=2,Update=3,Calculat=4,MainManui=5};

	static void PressAnyKayToGoCrruncyManui()
	{
 		cout << "Press any kay to go crruncy manui . ";
		system("pause>0");
		PrintCrruencySecreen();

	}
	static void _ListCrruenciesScreen()
	{
		//cout << "List Crruencies Screen will be here \n";
		clsCrruncyiesListSecreen::PrintCrruncysList();
		PressAnyKayToGoCrruncyManui();
	}
	static void _FindCrruencyScreen()
	{
		
		//cout << "Find Crruencies Screen will be here \n";
		clsFindCrruncy::ShowFindCrruncy();
		PressAnyKayToGoCrruncyManui();
	}
	static void _UpdateCrruenciesScreen()
	{
		//cout << "Update Crruencies Screen will be here \n";
		clsUpdateCrruency::PrintUpdateScreen();

		PressAnyKayToGoCrruncyManui();
	}
	static void _CalculateCrruenciesScreen()
	{
		//cout << "Calculat Crruencies Screen will be here \n";
		clsCalculatCrruency::ShowCalculatScreen();

		PressAnyKayToGoCrruncyManui();
	}
	static void _MainScreen()
	{
		//cout << "Main Screen will be here \n";
		//PressAnyKayToGoCrruncyManui();
	}


	static enCrruency _ReadOption()
	{
		cout << "Please choice form [1] to [5] ? ";
			short A;
			A = clsInputValidate::ReadIntNumberBetween(1, 5);
			return (enCrruency)A;
	}
	static void _PerformCrruency(enCrruency Choice)
	{
     
		switch (Choice)
		{

		case clsScreenCurrency::List: 
		{
			system("cls");
			_ListCrruenciesScreen();
			break;
		}
		case clsScreenCurrency::Find:
		{
			system("cls");
			_FindCrruencyScreen();
			break;
		}
		case clsScreenCurrency::Update:
		{
			system("cls");
			_UpdateCrruenciesScreen();
			break;
		}
		case clsScreenCurrency::Calculat:
		{
			system("cls");
			_CalculateCrruenciesScreen();
			break;
		}
		case clsScreenCurrency::MainManui:
		{
			system("cls");
			break;
		}
		default:
			break;
		}








    }

	

	public:



		static void PrintCrruencySecreen()
		{
			system("cls");
			_PrintHeader("Crruency Excahng");
			cout << "\n" << clsUtil::Tabs(5) <<"======================================== \n";
			cout << clsUtil::Tabs(3) << "  Crruency Exchang Manui";
			cout << "\n" << clsUtil::Tabs(5) <<"======================================== \n";
			cout << clsUtil::Tabs(3) << "[1]  List Crruencies\n";
			cout << clsUtil::Tabs(3) << "[2]  Find Crruency\n";
			cout << clsUtil::Tabs(3) << "[3]  UpDate Rate\n";
			cout << clsUtil::Tabs(3) << "[4]  Crruency Calculater\n ";
			cout << clsUtil::Tabs(3) << "[5]  Main Manui ";
			cout << "\n" << clsUtil::Tabs(5) << "======================================== \n";

			_PerformCrruency(_ReadOption());


		}

};

