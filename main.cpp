
#include <iostream>
#include "orders.h"
using namespace std;
int main() {
	string user;
	int t,h,a,b,c;
	cout << "Which user do you want use?(1:Customer / 2:Seller) ";
	cin >> user;
	if("Seller"==user||"seller"==user||"1"==user){
		do
		{
			cout<<endl;
			cout << "\n \t 1. New Product    ";
			cout << "\n \t 2. Products List  ";
			cout << "\n \t 3. Delete Product ";
			cout << "\n \t 4. Customers List ";
			cout << "\n \t 5. Exit           ";
			cout << "\n\n\tChoice Number: ";
			cin >> t;
			switch(t)
			{
			case 1:
				new_product();
				break;
			case 2:
				products_list();
				break;
			case 3:
				cout << "\n\n\tEnter The Product Number: ";
				cin >> h;
				Delete_product(h);
				break;
			case 4:
				customers_list();
				break;
			case 5:
				break;
			default:
		    	cout<<"\n\n\tChoice Number: ";
            	break;
			}
	    }
	    while(t!=5);
	    return 0;
    }
    else if(user=="Customer"||user=="customer"||user=="2"){
    	cout << "\n\tEnter your Customer number: ";
		cin >> h;
		add_customars(h);
    	do
		{
			cout << "\n \t 1. Products List                 ";
			cout << "\n \t 2. Finding Products              ";
			cout << "\n \t 3. increace Amount               ";
			cout << "\n \t 4. Product purchase & Orders List";
			cout << "\n \t 5. Exit                          ";
			cout << "\n\n\tChoice Number: ";
	        cin >> t;
			switch(t)
			{
			case 1:
				products_list();
				break;
			case 2:
				Finder();
				break;
			case 3:
				increase_amount(h);
				break;
			case 4: {
    			products_list();
    			cout << "\n\tEnter The Product Number to buy: ";
    			cin >> c;
   		 		int price = buy_products(h,c);
    			if (price > 0) {
        			drawdep_amount(h,price);
        			order_list(h);
    				}
    			break;
				}
			case 5:
				break;
			default:
		    	cout<<"\n\n\tChoice Number: ";
            	break;
		    }
        }
		while(t!=5);
	    return 0;
    }
	else{
		cout<<"Invalid user type"<<endl;
	}
}



