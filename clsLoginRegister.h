#pragma once
#include<iostream>
#include"clsSecrean.h"
#include"clsGlobal.h"
#include<fstream>
class clsLoginRegister : protected clsSecrean
{

    string _DateLogin;
    string _UserName;
    string _Password;
    string _Permiisions;



    static clsLoginRegister _ConvertRecordToOpject(vector<string>vDataString)
    {
         clsLoginRegister oLogin;
        oLogin.DateLogin  =  vDataString[0];
        oLogin.UserName   =  vDataString[1];
        oLogin.Password = clsUtil::Encript(vDataString[2]);
        oLogin.Permission =  vDataString[3];
          return oLogin;

    }

    


public:

    void setDateLogin(string Date)
    {
        _DateLogin = Date;
    }
    void setUserName(string User)
    {
        _UserName = User;
    }
    void setPassword(string Pass)
    {
        _Password = Pass;
    }
    void setPermission(string Permiss)
    {
        _Permiisions = Permiss;
    }

    string getDateLogin()
    {
        return _DateLogin;
    }
    string getUserName()
    {
        return _UserName;
    }
    string getPassword()
    {
        return _Password;
    }
    string getPermission()
    {
        return _Permiisions;
    }

    __declspec(property(get= getDateLogin, put = setDateLogin))string DateLogin;
    __declspec(property(get=getUserName, put = setUserName))string UserName;
    __declspec(property(get=getPassword, put =setPassword ))string Password;
    __declspec(property(get=getPermission, put =setPermission ))string Permission;


    static vector<clsLoginRegister> ReadDataLogin()
    {

        fstream MyFile;
        string Line;
        MyFile.open("LoginRegister.txt", ios::in);
        vector<clsLoginRegister> vDataLogin;

        if (MyFile.is_open())
        {
            while ((getline(MyFile, Line)))
            {
                vector<string>StringData = clsString::Split(Line, "#//#");
                
                clsLoginRegister V = _ConvertRecordToOpject(StringData);
                vDataLogin.push_back(V);
                
            }

            MyFile.close();
        }
        return vDataLogin;
    }










};

