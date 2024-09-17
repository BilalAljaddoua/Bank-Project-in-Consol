#pragma once
#include"clsSecrean.h"
#include"clsInputValidate.h"
#include"clsCrrunecy.h"
class clsCalculatCrruency : protected clsSecrean
{
	static float _ReadAmount()
	{
		float A;
		cout << "\nPlease enter amount . ";
		A=clsInputValidate::ReadDblNumber();
		return A;
	}
	static  void _PrintCrruencyCard(clsCurrency C)
	{
		
		{
			cout << "\n--------------------------------------------\n";
			cout << "Country Crruency     : " <<   C.Country();
			cout << "\nCod Crruency         : " << C.CurrencyCode();
			cout << "\nName Crruency        : " << C.getCurrencyName();
			cout << "\nRate Crruency (1$) = : " << C.Rate();
			cout << "\n--------------------------------------------\n";
		}
		 
	}
	static clsCurrency _ReadCrruency(string Masseg)
	{
		cout << Masseg << endl;
		string FromCrr;
		cin >> FromCrr;
		clsCurrency CrruncyFrom = clsCurrency::FindByCode(FromCrr); 
		while (CrruncyFrom.IsEmpty()) 
		{
			cout << "wrong Cod , please try again . ";
			cin >> FromCrr;
			CrruncyFrom = clsCurrency::FindByCode(FromCrr); 
		}
		return CrruncyFrom;
	}
	static float _Calculat(clsCurrency Crruncy1, clsCurrency Crruncy2,float Amount)
	{
		float InDolar = Crruncy1.ConvertToUSD(Amount);
		_PrintCrruencyCard(Crruncy1);
		if (Crruncy2.CurrencyCode() == "USA")
		{
			return InDolar;
		}
		float InAnotherCrr = Crruncy1.ConvertToAnotherCrruency(Crruncy2, Amount);
		return InAnotherCrr;


	}

public:

	static void ShowCalculatScreen()
	{
		_PrintHeader("Calculat Crruncy");
		 
		char A='y';
		while (A == 'Y' || A == 'y')
		{
 			clsCurrency Crruncy1 = _ReadCrruency("Pleae enter Crrucy 1");  
			clsCurrency Crruncy2 = _ReadCrruency("Pleae enter Crrucy 2");
			float Amount = _ReadAmount();
			float FinalAmount = _Calculat(Crruncy1, Crruncy2, Amount);

			cout << "Each " << Amount << Crruncy1.CurrencyCode() 
				 << " = " << FinalAmount << Crruncy2.CurrencyCode()<<endl;

			cout << "\n\nDo you want to another calculat ? y/n . ";
			cin >> A;

		}

	
	
	
	
	}

};

