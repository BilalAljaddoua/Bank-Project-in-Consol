#pragma once

#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>
#include <iomanip>
#include"clsSecrean.h"
#include"clsInputValidate.h"
#include"clsCrrunecy.h"
using namespace std;

class clsFindCrruncy : protected clsSecrean
{
	enum enFindBy{Cod=1,Country=2};
	static enFindBy _ReadChoise()
	{
		short A=clsInputValidate::ReadShortNumberBetween(1, 2);
		return (enFindBy)A;
	}
	
	static void _PrintCrruencyCard(clsCurrency  Curr)
	{
		cout << "\n--------------------------------------------\n";
		cout << "Country Crruency     : " << Curr.Country();
		cout << "\nCod Crruency         : " << Curr.CurrencyCode();
		cout << "\nName Crruency        : " << Curr.getCurrencyName();
		cout << "\nRate Crruency (1$) = : " << Curr.Rate();
		cout << "\n--------------------------------------------\n";

	}

	static clsCurrency _FindByCod()
	{
		cout << "Please enter Cod crruency .  ";

		string Cod=clsUtil::ReadString();
		clsCurrency Crrruency = clsCurrency::FindByCode((Cod));
		if (!Crrruency.IsEmpty())
		{
			_PrintCrruencyCard(Crrruency);
			return Crrruency;
        }
		else
		{
			cout << "the crruency is not found \n";
		}
	}
	static clsCurrency _FindByCountry()
	{
		cout << "Please enter name country .  ";
		string Country = clsUtil::ReadString();
		clsCurrency Crrruency =clsCurrency::FindByCountry(clsString::UpperAllString(Country));
		if (!Crrruency.IsEmpty())
		{
			_PrintCrruencyCard(Crrruency);
			return Crrruency;

		}
		else
		{
			cout << "the crruency is not found \n";
		}
	}
	
	static clsCurrency _PerformFind(enFindBy Choice)
	{
		switch (Choice)
		{
		case clsFindCrruncy::Cod: 
		{
			return _FindByCod();
			break;
		}
		case clsFindCrruncy::Country:
		{
			return _FindByCountry();
			break;
		}
		default:
			break;
		}
	}
public:

	static clsCurrency ShowFindCrruncy()
	{
		_PrintHeader("Find Crruency");
		cout << " Find by [1] Cod , [2] By Country ? ";
		return _PerformFind(_ReadChoise());

	}



};

