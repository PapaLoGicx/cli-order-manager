#include "order.h"
#include <iostream>
#include <cstring> 

using namespace std;


Order::Order() : Customer(), Item() {
    orderNo = 0;
    strcpy(orderDate, "");
    totalAmount = 0.0;
}


Order::Order(int orderNo1, char orderDate1[], float totalAmount1,
             int custNo1, char custName1[], char custEmail1[],
             int itemNo1, char itemDesc1[], float itemPrice1) 
    : Customer(custNo1, custName1, custEmail1), 
      Item(itemNo1, itemDesc1, itemPrice1) 
{
    orderNo = orderNo1;
    strcpy(orderDate, orderDate1);
    totalAmount = totalAmount1;
}


void Order::readData() {
    Customer::readData(); 
    
    cout << "Dose Order No : "; 
    cin >> orderNo;
    
    cout << "Dose Order Date: "; 
    cin >> orderDate;
    
    totalAmount = 0.0;
}


void Order::setData(int orderNo1, char orderDate1[], float totalAmount1,
                    int custNo1, char custName1[], char custEmail1[],
                    int itemNo1, char itemDesc1[], float itemPrice1) {

    Customer::setData(custNo1, custName1, custEmail1);
    Item::setData(itemNo1, itemDesc1, itemPrice1);
    
    orderNo = orderNo1;
    strcpy(orderDate, orderDate1);
    totalAmount = totalAmount1;
}

void Order::printData() {
    Customer::printData(); 
    cout << "Order No : " << orderNo << endl;
    cout << "Order Date: " << orderDate << endl;
    cout << "Total Amount: " << totalAmount << endl;
}

int Order::getOrderNo() {
    return orderNo;
}

char* Order::getOrderDate() {
    return orderDate;
}

float Order::getTotalAmount() {
    return totalAmount;
}

void Order::buyItem(float price, int qty) {
    totalAmount += (price * qty); 
}

int Order::shippingCost() {
    if (totalAmount > 200.0) { 
        return 0; 
    }
    return 20; 
}
