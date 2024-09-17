#pragma once
#include"clsSecrean.h"
#include"clsCrrunecy.h"
#include"clsFindCrruncy.h"
class clsUpdateCrruency : protected clsSecrean
{
	static float _ReadRate()
	{
		float A;
		A = clsInputValidate::ReadDblNumber();
			return A;
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


public:
	static void PrintUpdateScreen()
	{
		_PrintHeader("UpDate Screen");
     
		string CodCrruency = "";
		cout << "Please enter Crruency cod . ";
		cin >> CodCrruency;
		clsCurrency Crruency = clsCurrency::FindByCode(CodCrruency);
		while (Crruency.IsEmpty())
		{
			cout << "wornog crruncy cod , please try again . ";
			cin >> CodCrruency;
			  Crruency = clsCurrency::FindByCode(CodCrruency); 
		}
		 
		_PrintCrruencyCard(Crruency);
		
		cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

		char Answer = 'n'; 
		cin >> Answer; 

		if (Answer == 'y' || Answer == 'Y') 
		{

			cout << "\n\nUpdate Currency Rate:"; 
			cout << "\n____________________\n"; 

			Crruency.EditRate(_ReadRate()); 

			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCrruencyCard(Crruency); 


		}

	}

};

