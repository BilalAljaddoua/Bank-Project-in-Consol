#include <iostream>
#include"clsLogInSecren.h"
#include"clsScreenLoginRegister.h"
#include"clsShowTransFers.h"
#include"clsUtil.h"
#include"clsCrrunecy.h"
#include"clsCalculatCrruency.h"

using namespace std;
 
int main()
{  
	 while (true)
	{

		if (!clsLogInSecren::PrintLoginSecren())
		{
			break;
		}
	} 
 //	clsCalculatCrruency::ShowCalculatScreen();
	system("pause>0");

	return 0;
}







