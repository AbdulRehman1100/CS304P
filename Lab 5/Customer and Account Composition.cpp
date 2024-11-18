#include <iostream>
#include <string.h>

using namespace std;

class Account{
    private:
        int accNo;
        float balance;
        char* bankName;
        int bankCode;
    public:
    Account(int aAccNo, float aBalance, char* aBankName, int aBankCode);
    void withdraw(float amount);
    void deposit(float amount);
    ~Account();
    void print();
    Account(const Account& rhs); // so we can directly pass account object to Customer Constructor
};

Account::Account(int aAccNo, float aBalance, char* aBankName, int aBankCode) : accNo{aAccNo},
    balance{aBalance}, bankName(nullptr), bankCode{aBankCode}
    {
        if(aBankName != nullptr)
        {
            bankName = new char[strlen(aBankName) + 1];
            strcpy(bankName, aBankName);
        }
    }
void Account::withdraw(float amount)
{
    balance -= amount;
}

void Account::deposit(float amount)
{
    balance -= amount;
}

Account::~Account()
{
    if(bankName != nullptr)
    {
        delete [] bankName;
        bankName = nullptr;
    }
}

void Account::print()
{
    cout << "Account No: " << accNo
    << "\nBank Name: " << ((bankName != nullptr) ? bankName : "Null")
    << "\nBranch Code: " << bankCode
    << "\nBalance: " << balance << endl;
}

Account::Account(const Account& rhs): accNo{rhs.accNo},
    balance{rhs.balance}, bankName(nullptr), bankCode{rhs.bankCode}
{
    if(rhs.bankName != nullptr)
    {
        bankName = new char[strlen(rhs.bankName) + 1];
        strcpy(bankName, rhs.bankName);
    }
}

class Customer {
    private:
        int cusId;
        char* cusName;
        char* cusCNIC;
        char* cusAddress;
        Account cusAccount;
    public:
    Customer(int aCusId, char* aCusName, char* aCusCNIC, char* aCusAdres, Account aCusAccount);
    void withdraw(float amount);
    void deposit(float amount);
    void print();
    ~Customer();
};

Customer::Customer(int aCusId, char* aCusName, char* aCusCNIC, char* aCusAdres, Account aCusAccount):
    cusId{aCusId}, cusName{nullptr}, cusCNIC{nullptr}, cusAddress{nullptr}, cusAccount{aCusAccount}
    {
        if(aCusName != nullptr)
        {
            cusName = new char [strlen(aCusName) + 1];
            strcpy(cusName, aCusName);
        }

        if(aCusCNIC != nullptr)
        {
            cusCNIC = new char[strlen(aCusCNIC) + 1];
            strcpy(cusCNIC, aCusCNIC);
        }
        if(aCusAdres != nullptr)
        {
            cusAddress = new char [strlen(aCusAdres) + 1];
            strcpy(cusAddress, aCusAdres);
        }
    }

void Customer::withdraw(float amount)
{
    cusAccount.withdraw(amount);
}

void Customer::deposit(float amount)
{
    cusAccount.deposit(amount);
}

void Customer::print()
{
    cout << "Customer Id: " << cusId
    << "\nCustomer Name: " << ((cusName != nullptr) ? cusName : "Null")
    << "\nCustomer CNIC: " << ((cusCNIC != nullptr) ? cusCNIC: "Null")
    << "\nCustomer Address: " << ((cusAddress != nullptr) ? cusAddress : "Null")
    << endl;
    cusAccount.print();
}

Customer::~Customer()
{
    if(cusName != nullptr)
    {
        delete []cusName;
        cusName = nullptr; 
    }

    if(cusCNIC != nullptr)
    {
        delete []cusCNIC;
        cusCNIC = nullptr; 
    }

    if(cusAddress != nullptr)
    {
        delete []cusAddress;
        cusAddress = nullptr; 
    }

}

int main()
{
    float amount = 50000;
    Account account1(1, amount, "HBL", 1924);
    Customer customer1(10, "abc", "35204-7458545-8", "Lahore", account1);
    
    cout << "Customer information having initial amount (" << amount << ") is given below:\n" << endl;
    customer1.print();
    amount = 10000;
    customer1.deposit(amount);
    cout << "\nCustomer information after deposting amount (" << amount << ") is given below:\n" << endl;
    customer1.print();
    amount = 20000;
    customer1.withdraw(amount);
    cout << "\nCustomer information after withdrawing amount (" << amount << ") is given below:\n" << endl;
    customer1.print();
}