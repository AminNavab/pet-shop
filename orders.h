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
    void setOrder(int customer_Name, int product_Name, const char* name_cus, const char* name_pro, const char* _category, int _price) ;
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
void Orders::setOrder(
    int customerNum,
    int productNum,
    const char* customerName,
    const char* productName,
    const char* categoryName,
    int price
) {
    num_cus = customerNum;
    num_pro = productNum;

    strncpy(names_cus, customerName, 29);
    names_cus[29] = '\0';

    strncpy(names_pro, productName, 29);
    names_pro[29] = '\0';

    strncpy(category, categoryName, 29);
    category[29] = '\0';

    Price = price;
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

void order_list(int CustomerNum) {
    ifstream inFile("ordon.dat", ios::binary);
    if (!inFile) {
        cout << "No orders found. Press Key";
        return;
    }
    Orders order;
    bool found = false;
    cout << "\n\t" << setw(45) << "Orders List for Customer: " << CustomerNum << endl;
    cout << "----------------------------------------------------------------\n";
    cout << left
        << setw(9) << "Num_cus"
        << setw(16) << "Customer" 
        << setw(16) << "Product"   
        << setw(16) << "Category"  
        << setw(8) << "Price" << endl;
    cout << "----------------------------------------------------------------\n";
    
    while (inFile.read((char*)&order, sizeof(Orders))) {
        if (order.getNum_cus() == CustomerNum) {  
            cout<< setw(9) << order.getNum_cus()
                << setw(16) << order.getNames_cus()  
                << setw(16) << order.getNames_pro()  
                << setw(16) << order.getcategory()  
                << setw(8) <<order.getPrice()  << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "\n\t[No orders found for this customer]\n";
    }
    inFile.close();
}

void Finder() {
	int n;
	Products p;
	do {
		ifstream inFile("products.dat",ios::in | ios::binary);
		if (!inFile) {
            cout << "File could not be opened." << endl;
            continue;
        }
		int t=0,r=0,v=0;
		int f=1,k=1,q=1;
		cout << "\nFinding by (1:Name / 2:Category / 3:Price / 4:exit) \n";
		cout << "Choice number: "; 
		cin >> n;
		switch(n)
		{
		case 1: {
    		string N;
    		cout << "Name of Product: ";
    		cin >> N;
    		while(inFile.read((char *) &p, sizeof(Products))){
        		if(string(p.getNames_pro()) == N){
            		if (f==1){
                		cout << "\n";
                		cout << "\t[Number" << setw(14)  << "Category" << setw(10) << "Name" << setw(23) << "Price]\n";
                		cout << "\n";
            		}
            		p.output_data_pro();
            		f++;
        		}
    		}
    	break;
    }
		case 2: {
    		string c;
    		cout << "Which category: ";
    		cin >> c;
    		while(inFile.read((char *) &p, sizeof(Products))){
        		if(string(p.getCategory_pro())==c){
            		if (k==1){
                		cout << "\n";
                		cout << "\t[Number" << setw(14)  << "Category" << setw(10) << "Name" << setw(23) << "Price]\n";
                		cout << "\n";
            		}
            		p.output_data_pro();
            		k++;
        		}
    		}
    	break;
    }
		case 3:
			cout << "Finding by Price from: ";
			cin >> r;
			cout << "until: ";
			cin >> v;
			while(inFile.read((char *) &p, sizeof(Products))){
				if((p.getPrice_pro() >= r) && (p.getPrice_pro() <= v)){
					if (q==1){
						cout<<"\n";
						cout<< "\t[Number" << setw(14)  << "Category" << setw(10) << "Name" << setw(23) << "Price]\n";
						cout<<"\n";
					}
					p.output_data_pro();
					q++;
				}
			}
			break;
		case 4:
			break;
		default:
			cout << "Choice number: ";
        	break;
		}
		inFile.close();
	}
	while (n!=4);
}