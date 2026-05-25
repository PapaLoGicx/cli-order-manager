#include "customer.h"
#include <iostream>
#include <cstring> 

using namespace std;

Customer::Customer() {
    custNo = 0;
    strcpy(custName, "");
    strcpy(custEmail, "");
}

Customer::Customer(int custNo1, char custName1[], char custEmail1[]) {
    custNo = custNo1;
    strcpy(custName, custName1);
    strcpy(custEmail, custEmail1);
}

void Customer::readData() {
    cout << "Dose Customer No : "; 
    cin >> custNo;
    
    cin.ignore(); 
    
    cout << "Dose Customer Name: "; 
    cin.getline(custName, 21); 
    
    cout << "Dose Customer Email: "; 
    cin.getline(custEmail, 21);
}

void Customer::setData(int custNo1, char custName1[], char custEmail1[]) {
    custNo = custNo1;
    strcpy(custName, custName1);
    strcpy(custEmail, custEmail1);
}

void Customer::printData() {
    cout << "Customer No : " << custNo << endl; 
    cout << "Customer Name: " << custName << endl; 
    cout << "Customer Email: " << custEmail << endl; 
}

int Customer::getCustNo() {
    return custNo;
}

char* Customer::getCustName() {
    return custName;
}

char* Customer::getCustEmail() {
    return custEmail;
}