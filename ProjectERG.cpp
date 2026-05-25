#include "customer.h"
#include "item.h"
#include "order.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

//-----------------------------------------
//synartiseis pou xrisimopoiounte stin main
//-----------------------------------------

int fileToarr(ifstream &fin, Item p[]) {
    int count = 0;
    int id;
    char desc[21];
    float price;
    char diagrafi;

    while (fin >> id >> diagrafi) {
        fin.getline(desc, 21, ',');
        fin >> price;
        p[count].setData(id, desc, price);
        count++;
   }
   return count;
}

int itemMenu(Item p[], int n) {
    cout << "\n Lista diathesimon proionton:\n";
    for (int i=0; i<n; i++) {
        cout << p[i].getItemNo() << "," 
             << p[i].getItemDesc() << "\t" 
             << p[i].getItemPrice() << endl;
    }
    int choice;
    cout << "dwse kwdiko proiontos pou theleis na agoraseis:(bale 0 gia eksodo)";
    cin >> choice;
    return choice;
}

int searchItem(Item p[], int n, int searchCode) {
   for (int i=0; i<n; i++) {
        if (p[i].getItemNo() == searchCode) {
             return i; 
        }
   }
   return -1; 
}   

//-----------------
//Kurio programma 
//-----------------

int main(){
    Item itemArr[100];
    ifstream infile("items24105.txt");
    ofstream outfile("orders24105.txt");

    if (!infile.is_open()) {
       cout << "den anoikse to arxeio items" << endl;
        return 1;
    }
//1
    int TotalItems = fileToarr(infile,itemArr);
    infile.close();

//2
Order myOrder1;
myOrder1.readData();    

outfile << "Customer No : " << myOrder1.getCustNo() << endl;
outfile << "Customer Name: " << myOrder1.getCustName() << endl;
outfile << "Customer Email: " << myOrder1.getCustEmail() << endl;
outfile << "Order No : " << myOrder1.getOrderNo() << endl;
outfile << "Order Date: " << myOrder1.getOrderDate() << endl << endl;

outfile << "kwdikos\tperigrafi\tposotita\ttimi\naxia\n" << endl;
outfile << "---------------------------------------------\n" << endl;

//3
int selectedCode;
while (true) {
    selectedCode = itemMenu(itemArr, TotalItems);
    
    if (selectedCode == 0) {
        cout << "telos programmatos" << endl;
        break; 
    }
    int itemIndex = searchItem(itemArr, TotalItems, selectedCode);

    if (itemIndex != -1) {
        int qty;
        cout << "dwse posotita: ";
        cin >> qty;

        float price = itemArr[itemIndex].getItemPrice();
        myOrder1.buyItem(price, qty);

        cout << "egine agora, sinexise tis agores sou";

        outfile << itemArr[itemIndex].getItemNo() << "\t" 
                << itemArr[itemIndex].getItemDesc() << "\t" 
                << qty << "\t" 
                << price << "\t" 
                << price * qty << endl;
    } else {
        cout << "den vrethike to proion me ton kwdiko pou edwses" << endl;
    }
  }


 outfile << "\n synoliko poso : " << myOrder1.getTotalAmount() << endl;
 outfile << "metaforika : " << myOrder1.shippingCost() << endl;
 outfile << "teliki axia : " << myOrder1.getTotalAmount() + myOrder1.shippingCost() << endl;
 
 outfile.close();
 return 0;
}