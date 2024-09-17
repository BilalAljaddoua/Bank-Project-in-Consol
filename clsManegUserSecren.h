#pragma once
#include<iostream>
#include"clsSecrean.h"
#include"clsClientBank.h"
#include"clsAddUser.h"
#include"clsShowUsersSecren.h"
#include"clsDeletUser.h"
#include"clsUpdateUser.h"
#include"clsFIndUser.h"

using namespace std;


class clsManegUserSecren :protected clsSecrean
{
	static enum enManegUser { Showw = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, MainManue = 6 };
	static void PresAnyKaytoMange()
	{
		cout << "\nPlease pres any kay to maniu\n";
		system("pause>0");
		ShowMainManuiSecren();
	}
	static enManegUser ReadOptionUser()
	{
		short a = 0;
		cout << "Please choice from [1] to [6]";
		cin >> a;
		return (enManegUser)a;
	}
 
	static void ManegUsers()
	{
		
 		
		vector<clsBankClient> vClients = clsBankClient::GetClientsData();
		enManegUser ManegUser = ReadOptionUser();
		
		switch (ManegUser)
		{
		case enManegUser::AddUser:
		{
			system("cls");
			clsAddUser::AddNewUserSecren();
 				PresAnyKaytoMange();

			break;
		}
		case enManegUser::Showw:
		{

			system("cls");
			clsShowUsersSecren::ShowListUsers();
				PresAnyKaytoMange();
			break;
		}
		case enManegUser::DeleteUser:
		{
			system("cls");
			clsDeletUser::DeletUser();
				PresAnyKaytoMange();

			break;
		}
		case enManegUser::FindUser:
		{
			system("cls");
			clsFIndUser::FindUser();
				PresAnyKaytoMange();

			break;
		}
		case enManegUser::UpdateUser:
		{
			system("cls");
			clsUpdateUser::UodateUser();
			PresAnyKaytoMange();

			break;
		}
		case enManegUser::MainManue:
		{
			system("cls");
 
			break;
		}




		}
	}


public:


	static void ShowMainManuiSecren()
	{
		if (!CheekPermissionRight(clsUser2::pManageUsers))
		{
			return;
		}
		_PrintHeader("Manege User");

		system("cls");
		cout << "\t\t\t\t\t\==================================\n";
		cout << "\t\t\t\t\t\          Manege Clints screen       \n";
		cout << "\t\t\t\t\t\==================================\n";
		cout << "\t\t\t\t\t\ [1] Show Users. \n";
		cout << "\t\t\t\t\t\ [2] Add new User. \n";
		cout << "\t\t\t\t\t\ [3] Delete User. \n";
		cout << "\t\t\t\t\t\ [4] Update User. \n";
		cout << "\t\t\t\t\t\ [5] Find User. \n";
		cout << "\t\t\t\t\t\ [6]  Main Manue. \n";
		cout << "\t\t\t\t\t\==================================\n\n";

		ManegUsers();






	}

 

};

