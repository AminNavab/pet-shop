#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "customers.h"
#include "products.h"
using namespace std;

class Orders {
private:
    int num_cus;
    int num_pro;
    char names_cus[30];
    char names_pro[30];
    char category[30];
    int Price;
public:
    void setOrder(int num_cus, int num_pro, const char* name_cus, const char* name_pro, const char* _category, int _price) ;
    void setNum_cus(int cn){num_cus=cn;}
    void setNum_pro(int pn){num_pro=pn;}
	void setPrice(int p){Price=p;}
	void setCategory(const string &c) { setCategory(c.c_str()); }
    void setNames_pro(const string &p) { setNames_pro(p.c_str()); }
    void setNames_cus(const string &c) { setNames_cus(c.c_str()); }
    const char* getNames_cus() { return names_cus; }
    const char* getNames_pro() { return names_pro; }
    const char* getcategory() { return category; }
    int getNum_cus() { return num_cus; }
    int getNum_pro() { return num_pro; }
    int getPrice(){return Price;}
};
void Orders::setOrder(int num_cus, int num_pro, const char* name_cus, const char* name_pro, const char* category_, int price_){
		num_cus = num_cus;
        num_pro = num_pro;
        strncpy(names_cus, name_cus, 29); names_cus[29] = '\0';
        strncpy(names_pro, name_pro, 29); names_pro[29] = '\0';
        strncpy(category, category_, 29); category[29] = '\0';
        Price = price_;
    }
//----------------------------------------------------------------------
int buy_products(int customerNum, int productNum) {
    Products p;
    Orders order;
    ofstream outputFile("ordon.dat", ios::binary | ios::app);
    ifstream inputFile("products.dat", ios::binary);

    Customers c;
    ifstream customerFile("Customer.dat", ios::binary);
    string cName ;
    int cDeposit = 0;
    bool foundC = false;
    
    while (customerFile.read((char*)&c, sizeof(Customers))) {
        if (c.getnum_cus() == customerNum) {
            cName = c.get_names_cus();
            cDeposit = c.getDeposit_cus();
            foundC = true;
            break;
        }
    }
    customerFile.close();
    int foundPrice = 0;
    string pName ;
    string pCategory ;
    bool foundP = false;
    
    while (inputFile.read((char*)&p, sizeof(Products))) {
        if (p.getNum_pro() == productNum) {
            foundPrice = p.getPrice_pro();
            pName = p.getNames_pro();
            pCategory = p.getCategory_pro();
            foundP = true;
            break;
        }
    }
    inputFile.close();

    if (foundP && foundC && cDeposit >= foundPrice) {
        order.setOrder(customerNum, productNum, cName.c_str(), pName.c_str(), pCategory.c_str(), foundPrice);
        outputFile.write((char*)&order, sizeof(Orders));
        cout << "\n\t[Order placed successfully]\n";
        outputFile.close();
        drawdep_amount(customerNum, foundPrice);
        return foundPrice;
    } else {
        outputFile.close();
        if (!foundC) 
			cout << "\n\t[Customer not found]\n";
        else if (!foundP) 
			cout << "\n\t[Product not found]\n";
        else 
			cout << "\n\t[you have not enough money]\n";
        return 0;
    }
}
