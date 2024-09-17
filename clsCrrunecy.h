#pragma once

#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;


class clsCurrency
{
	enum enMod { EmptyMod = 0, UpdateMod = 1 };

	string _Country;
	string _CurrencyCod;
	string _CurrencyName;
	float  _Rate;
	enMod  _Mod; 

   static clsCurrency _ConvertStringVectorToCurrencyObject(vector<string> vDataCurrency)
	{
		return clsCurrency(UpdateMod,vDataCurrency[0],vDataCurrency[1] ,vDataCurrency[2],stod(vDataCurrency[3]));
	 
	}
	static clsCurrency _ConvertLineToCurrencyObject(string Line)
	{
		vector<string> vDataCurrency = clsString::Split(Line,"#//#");
		return _ConvertStringVectorToCurrencyObject(vDataCurrency);
	}
	static vector<clsCurrency> _LoadCurrencysDataFromFile()
	{
		fstream MyFile;
		vector<clsCurrency> vDatacls;
		clsCurrency clsData=GetEmptyObject();
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;

			
			while (getline(MyFile,Line))
			{

				  clsData=_ConvertLineToCurrencyObject(Line);
				  vDatacls.push_back(clsData);
 

			}
			MyFile.close();
		
		}

		return vDatacls;
	}
	static string _ConvertObjectToREcord(clsCurrency Currency,string Seperator="#//#")
	{
		string Line = "";
		Line += Currency.Country() + Seperator;
		Line += Currency.CurrencyCode() + Seperator;
		Line += Currency.getCurrencyName() + Seperator;
		Line += to_string(Currency.Rate()) + Seperator;
		return Line;

	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency> vDatacls)
	{
		fstream MyFile;
		string Line;
		clsCurrency clsData = GetEmptyObject();
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsCurrency C : vDatacls)
			{
				Line = _ConvertObjectToREcord(C);
				MyFile << Line << endl;
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vCurrencys);

	}
	void _setRate(float Rate)
	{
		_Rate = Rate;
	}


public:

	clsCurrency(enMod Mod,string Country, string CurrencyCod, string CurrenceName, float Rate)
	{
		_CurrencyCod = CurrencyCod;
		_Country = Country;
		_CurrencyName = CurrenceName;
		_Rate = Rate;
		_Mod = Mod; 
	}
	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCod;
	}
	string getCurrencyName()
	{
		return _CurrencyName;
	}
    void PrintCrruencyCard()
	{
		if (!IsEmpty())
		{
			cout << "\n--------------------------------------------\n";
			cout << "Country Crruency     : "   << Country();
			cout << "\nCod Crruency         : " << CurrencyCode();
			cout << "\nName Crruency        : " << getCurrencyName();
			cout << "\nRate Crruency (1$) = : " << Rate();
			cout << "\n--------------------------------------------\n";
		}
		else
			cout << "Error .. is empty";

	}
	void setRate(float NewRate)
	{
		_Rate = NewRate;
	}
	float  Rate()
	{
		return _Rate;
	}
	bool   IsEmpty()
	{
		return _Mod == enMod::EmptyMod;
	}
	static clsCurrency GetEmptyObject()
	{
		return clsCurrency(EmptyMod,"", "", "", 0); 
	}
	static vector< clsCurrency> GetAllUSDCurrency()
	{
		return _LoadCurrencysDataFromFile();
	}
	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());

	}
	 void EditRate( float NewRate)
	{

		vector <clsCurrency> vCurrency = _LoadCurrencysDataFromFile();
		for (clsCurrency& C : vCurrency)
		{
			if (_CurrencyCod == C.CurrencyCode())
			{
				C._setRate(NewRate);
				_Rate = NewRate;
				_SaveCurrencyDataToFile(vCurrency);
				break;
			}
		}


	}
	static   clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return GetEmptyObject();

	}
	static   clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					
					return Currency;
				}

			}

			MyFile.close();

		}

		return GetEmptyObject();

	}
	void UpDate()
	{
		vector<clsCurrency> vCrruncy= clsCurrency::GetCurrenciesList();
		for (clsCurrency& C : vCrruncy)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C.setRate(_Rate);
			}

		}
		_SaveCurrencyDataToFile(vCrruncy);
	}
   

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}
	float ConvertToAnotherCrruency(clsCurrency Crruncey2,float Amount)
	{
		float InDolar = ConvertToUSD(Amount);

		return (float)(InDolar * Crruncey2.Rate());

	}



};

