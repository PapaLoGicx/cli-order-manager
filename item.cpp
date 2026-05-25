#include "item.h"
#include <iostream>
#include <cstring>

using namespace std;

Item::Item() {
    itemNo = 0;
    strcpy(itemDesc, "");
    itemPrice = 0.0;
}

Item::Item(int itemNo1, char itemDesc1[], float itemPrice1) {
    itemNo = itemNo1;
    strcpy(itemDesc, itemDesc1);
    itemPrice = itemPrice1;
}

void Item::readData() {
    cout << "Dose Item No: ";
    cin >> itemNo;
    
    cin.ignore();
    
    cout << "Dose Item Description: ";
    cin.getline(itemDesc, 21);
    
    cout << "Dose Item Price: ";
    cin >> itemPrice;
}

void Item::setData(int itemNo1, char itemDesc1[], float itemPrice1) {
    itemNo = itemNo1;
    strcpy(itemDesc, itemDesc1);
    itemPrice = itemPrice1;
}

void Item::printData() {
    cout << "Item No: " << itemNo << endl;
    cout << "Description: " << itemDesc << endl;
    cout << "Price: " << itemPrice << endl;
}

int Item::getItemNo() {
    return itemNo;
}

char* Item::getItemDesc() {
    return itemDesc;
}

float Item::getItemPrice() {
    return itemPrice;
}