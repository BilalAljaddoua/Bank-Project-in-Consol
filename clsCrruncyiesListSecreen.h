#pragma once
#include"clsSecrean.h"
#include"clsCrrunecy.h"
class clsCrruncyiesListSecreen : protected clsSecrean
{


	static void _PrintHiderSecreen()
	{
		cout << "\n----------------------------------------------------------------------------------------------------------\n";
		cout << left << setw(30) << " Country " << " | ";
		cout << left << setw(15) << " Currency Cod " << " | ";
		cout << left << setw(42) << " Currency Name " << " | ";
		cout << left << setw(10) << " Rate " << " | ";
		cout << "\n----------------------------------------------------------------------------------------------------------\n";
	}
	static void _PrintCrrunencies(clsCurrency Crru)
	{
 		cout << left << setw(30) << Crru.Country() << " | ";
		cout << left << setw(15) << Crru .CurrencyCode()<< " | ";
		cout << left << setw(42) << Crru .getCurrencyName()<< " | ";
		cout << left << setw(10) << Crru .Rate()<< " | ";
		cout << endl;
	}

public:

	static void PrintCrruncysList()
	{
		vector< clsCurrency>vData = clsCurrency::GetCurrenciesList();
		string Sub = " [" + to_string(vData.size()) + "] Crruencies .";
		_PrintHeader("Crruencies list ", Sub);

		_PrintHiderSecreen();
		for (clsCurrency C : vData)
		{
			_PrintCrrunencies(C);
		}
		cout << "\n----------------------------------------------------------------------------------------------------------\n";

	}

};

