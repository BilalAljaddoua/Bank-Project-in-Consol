#pragma once
#include <iostream>
#include<fstream>
#include"clsDate.h"
using namespace std;
class clsPerson
{

private:
	
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string First, string Last, string Email, string Phone)
	{
		_FirstName = First;
		_LastName = Last;
		_Email = Email;
		_Phone = Phone;
	}


	void setFirstName(string FirstName)
	{
		_FirstName=FirstName;
	}
	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	void setEmail(string Email)
	{
		_Email = Email;
	}
	void setPhone(string Phone)
	{
		_Phone = Phone;
	}

	string getFirstName()
	{
		return _FirstName;
	}
	string getLastName()
	{
		return _LastName;
	}
    string getEmail()
	{
		return _Email;
	}
    string getPhone()
	{
		return _Phone;
	}
	string getFullName()
	{
		return FirstName+" " + LastName;
	}

	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;
	__declspec(property(get = getLastName, put = setLastName)) string LastName;
	__declspec(property(get = getEmail, put = setEmail)) string Email;
	__declspec(property(get = getPhone, put = setPhone)) string Phone;




};

