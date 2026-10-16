
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Customers {
	private:
		int num_cus=0,
		Deposit_cus=0;
	protected:
		char names_cus[30];
	public:
		void input_data_cus(int num);
		void increasedep(int x);
		void drawdep(int x);
		void setnum_cus(int num){num_cus=num;}
		void setDeposit_cus(int d){Deposit_cus=d;}
		int getnum_cus(){return num_cus;}
		int getDeposit_cus(){return Deposit_cus;}
		void output_data_cus();
		void set_names_cus(const string &c) { set_names_cus(c.c_str()); }
		const char* get_names_cus() { return names_cus; }
	
};
void Customers::input_data_cus(int num){
		num_cus = num;
		cout<<"Enter Customer Name: " ;
		cin>>names_cus;
		cout<<"Enter Amount: ";
	
		cin>>Deposit_cus;
		cout<<"\n\t       [The Customer entered]   \n";
	}
void Customers::increasedep(int x){
		Deposit_cus = Deposit_cus + x;
	}
void Customers::drawdep(int x){
		Deposit_cus = Deposit_cus - x;
	}
void Customers::output_data_cus(){
		cout << left << setw(10) << num_cus << setw(11) << names_cus << right << setw(7)<< Deposit_cus << endl;
	}
//-----------------------------------------------------------------------------------
void add_customars(int c_num){
	Customers c;
	bool flag = true;
	ifstream inFile("Customer.dat",ios::in | ios::binary );

	while(inFile.read((char *) &c, sizeof(Customers))){
		if(c.getnum_cus() == c_num)
			flag =false;
	}
	inFile.close();
	ofstream outFile("Customer.dat",ios::binary | ios::out | ios::app );
	
	if(flag){
		Customers newc;
		newc.input_data_cus(c_num);
		outFile.write((char *) &newc, sizeof(Customers));
	}
	else
		cout << "\n\t   [Customer entered]" << endl;	
	outFile.close();
	ifstream lnFile("Customer.dat",ios::in | ios::binary );
	cout<<"\n";
	cout<< "\t[Number" << setw(8) << "Name" << setw(15) << "Amount]\n";
	cout<<"\n";
	while(lnFile.read((char *) &c, sizeof(Customers))){
		if (c.getnum_cus()==c_num)
			c.output_data_cus();
	}
	lnFile.close();
}

