#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

    using namespace std;
    class clsBankClient : public clsPerson
    {
    private:
        
        enum enMode { EmptyMode = 0, UpdateMode = 1 ,AddNewMod=2};
        enMode _Mode;
        string _AccountNumber;
        string _PinCode;
        float _AccountBalance;
        bool _MarkToDelet = false;
        static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
        {
            vector<string> vClientData;
            vClientData = clsString::Split(Line, Seperator);

            return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
                vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

        }
         struct DataTransfer;

       static vector<clsBankClient>_OpenDataFromFile()
        {
             
            vector<clsBankClient>vDataClient;
            fstream MyFile;
            MyFile.open("Clients.txt", ios::in);
            if (MyFile.is_open())
            {
                 string Line;
                while (getline(MyFile, Line))
                {                            
                    clsBankClient Ob= clsBankClient::_ConvertLinetoClientObject(Line, "#//#");                                                               //ﬁ—«¡Â „‰ „·› À„ «· ﬁÿÌ⁄ À„  Œ“Ì‰Â« ›Ì «Ê»ÃÌﬂ 
                      vDataClient.push_back(Ob);
                }
                MyFile.close();
            
            }
            return vDataClient;
        }
        void    _UpDate(string AccountNumber) 
          {               

            vector < clsBankClient > Clients= _OpenDataFromFile(); 

            for (clsBankClient& C : Clients)
            {
                if (C.AccountNumber() == AccountNumber)
                {         
                     C = *this;
                    _ReRwite(Clients);
                }
            }

          

          }
        void    _AddNew()
        {
            _SaveRecordToFile(_ConvertClassToString(*this)); 
        }
        void    _Delet()
        {
            vector<clsBankClient> vDataClient = _OpenDataFromFile();

            for (clsBankClient& C : vDataClient)
            {
                if (C.AccountNumber() == _AccountNumber)
                {
                    C._MarkToDelet = true;
                    break;
                }
            }
            _ReRwite(vDataClient);
            *this = GetEmptyClientObject();

        }
        void    _SaveRecordToFile(string Line)
        {
            fstream MyFile;
            MyFile.open("Clients.txt", ios::out|ios::app);
            if (MyFile.is_open())
            {
                MyFile << Line << endl;

            }
            MyFile.close();
        }
        static   string  _ConvertClassToString(clsBankClient Client)
        {
            string Cl = "";
            Cl = Client.FirstName + "#//#" +
                Client.LastName + "#//#" +
                Client.Email + "#//#" +
                Client.Phone + "#//#" +
                Client.AccountNumber() + "#//#" +
                Client.PinCode + "#//#" +
                to_string(Client.AccountBalance);

            return Cl;
        }
         
        static void _ReRwite(vector<clsBankClient> Clients)
        {
             fstream MyFile; 
             string Line;
             MyFile.open("Clients.txt", ios::out); 
             if (MyFile.is_open()) 
             {                
                 for (clsBankClient C : Clients)
                 {
                    if(C._MarkToDelet==false)
                     {
                         Line = _ConvertClassToString(C);
                         MyFile << Line << endl;
                     }
                 }
                 MyFile.close();


             }

         }

        string _PrepareTranferRecord(clsBankClient Destinaion, float Amount, string User, string Seperator = "#//#")
        {

            string TransferRecord = "";
            TransferRecord += clsDate::GetSystemDateTimeString() + Seperator;
            TransferRecord += AccountNumber() + Seperator;
            TransferRecord += Destinaion.AccountNumber() + Seperator;
            TransferRecord += to_string(Amount) + Seperator;
            TransferRecord += to_string(AccountBalance) + Seperator;
            TransferRecord += to_string(Destinaion.AccountBalance) + Seperator;
            TransferRecord += User;

            return TransferRecord;
        }
        void _RegisterTransFer(clsBankClient Destinaion, float Amount, string User)
        {

            string stDataLine = _PrepareTranferRecord(Destinaion, Amount, User);

            fstream MyFile;
            MyFile.open("RegisterTransFer.txt", ios::out | ios::app);

            if (MyFile.is_open())
            {

                MyFile << stDataLine << endl;

                MyFile.close();
            }

        }

       
        static DataTransfer _SplitAndConvert(string Line)
        {
            vector<string> stDataTransfer = clsString::Split(Line, "#//#");

            DataTransfer stData;

            stData.Date = stDataTransfer[0];
            stData.Client1 = stDataTransfer[1];
            stData.Client2 = stDataTransfer[2];
            stData.Amount = stDataTransfer[3];
            stData.AccBal1 = stDataTransfer[4];
            stData.AccBal2 = stDataTransfer[5];
            stData.User = stDataTransfer[6];

            return stData;
        }


    public:

        static struct DataTransfer
        {
            string Date;
            string Client1;
            string Client2;
            string  Amount;
            string  AccBal1;
            string  AccBal2;
            string User;
        };
        clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
        {
            _Mode = Mode;
            _AccountNumber = AccountNumber;
            _PinCode = PinCode;
            _AccountBalance = AccountBalance;
        }
        bool WithDrow(double Number)
        {
             if (Number <= AccountBalance)
                {
                    AccountBalance -= Number;
                    Save();

                    return true;
                }
                else
                {
                    return false;
                }

        }
        void Deposit(double Number)
        {
            
            AccountBalance += Number;
            Save();
        }
        bool   IsEmpty()
        {
            return (_Mode == enMode::EmptyMode);
        }
        string AccountNumber()
        {
            return _AccountNumber;
        }
        void   SetPinCode(string PinCode)
        {
            _PinCode = PinCode;
        }
        string GetPinCode()
        {
            return _PinCode;
        }
        void   SetAccountBalance(float AccountBalance)
        {
            _AccountBalance = AccountBalance;
        }
        float  GetAccountBalance()
        {
            return _AccountBalance;
        }
        void   Print()
        {
            cout << "\nClient Card:";
            cout << "\n___________________";
            cout << "\nFirstName   : " << FirstName;
            cout << "\nLastName    : " << LastName;
            cout << "\nFull Name   : " << getFullName();
            cout << "\nEmail       : " << Email;
            cout << "\nPhone       : " << Phone;
            cout << "\nAcc. Number : " << _AccountNumber;
            cout << "\nPassword    : " << _PinCode;
            cout << "\nBalance     : " << _AccountBalance;
            cout << "\n___________________\n";

        }
        __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
        __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
        static clsBankClient GetEmptyClientObject()
        {
            return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
        }
        void DeletClient()
        {
            _Delet();
        }  
        bool Transfere(float Amount ,clsBankClient& Destinaion,string User)
        {
            if (Amount > AccountBalance)
            {
               
                return false;
            }
            else
            {
                WithDrow(Amount);
                _RegisterTransFer(Destinaion, Amount,User); 
                Destinaion.Deposit(Amount);
                return true
                    ;
            }
        }       
        static vector<DataTransfer> GetTransferLog()
        {
            fstream MyFile;
            vector<DataTransfer> vDataTransfer;
            MyFile.open("RegisterTransFer.txt", ios::in);
            if (MyFile.is_open())
            {
                string Line;
                DataTransfer stData;
                while (getline(MyFile, Line))
                {
                    stData = _SplitAndConvert(Line);
                    vDataTransfer.push_back(stData);
                }
                MyFile.close();
            }
            return vDataTransfer;
        }
        static  clsBankClient Find(string AccountNumber)
        {


            fstream MyFile;
            MyFile.open("Clients.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    clsBankClient Client = _ConvertLinetoClientObject(Line);
                    if (Client.AccountNumber() == AccountNumber)
                    {
                        MyFile.close();
                        return Client;
                    }

                }

                MyFile.close();

            }

            return GetEmptyClientObject();
        }
        static  clsBankClient Find(string AccountNumber, string PinCode)
        {



            fstream MyFile;
            MyFile.open("Clients.txt", ios::in);//read Mode

            if (MyFile.is_open())
            {
                string Line;
                while (getline(MyFile, Line))
                {
                    clsBankClient Client = _ConvertLinetoClientObject(Line);
                    if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                    {
                        MyFile.close();
                        return Client;
                    }

                }

                MyFile.close();

            }
            return GetEmptyClientObject();
        }
        enum    enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 };
        static  bool IsClientExist(string AccountNumber)
        {

            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            return (!Client1.IsEmpty());
        }
        static  clsBankClient CreatNewClient(string AccountNumber)
        {
            return clsBankClient(enMode::AddNewMod, "", "", "", "", AccountNumber, "", 0);
        }
        static vector <clsBankClient> GetClientsData()
        {
            return _OpenDataFromFile();
        }
        static double GetTotalBalance(vector <clsBankClient> vClient)
        {
            double Balance = 0;
            for (clsBankClient C : vClient)
            {
                Balance += C.AccountBalance;
            }
            return Balance;
        }
        enum enSaveResult{SaveSucceessFully=0,EmptyOpject=1};
        enSaveResult Save()
        {
            switch (_Mode)
            {
            case clsBankClient::EmptyMode:
            {
                return enSaveResult::EmptyOpject;
                break;
            }
            case clsBankClient::UpdateMode:
            {
                _UpDate(AccountNumber());
                return enSaveResult::SaveSucceessFully;

                break;
            }
            case clsBankClient::AddNewMod:
            {
                _AddNew();
                _Mode = clsBankClient::UpdateMode;
                return enSaveResult::SaveSucceessFully; 

                break;
            }
            }
        }
        
 

    };


 

