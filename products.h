
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Products{
	private:
		int num_pro=0;
		int Price=0;
		char category_pro[30];
		char names_pro[30];
	public:
		void input_data_pro(int pn);
		void setNum_pro(int pn){num_pro=pn;}
		void setPrice_pro(int p){Price=p;}
		int getNum_pro(){return num_pro;}
		int getPrice_pro(){return Price;}
		void output_data_pro();
		void setCategory_pro(const string &c) { setCategory_pro(c.c_str()); }
		void setNames_pro(const string &p) { setNames_pro(p.c_str()); }
		const char* getNames_pro() { return names_pro; }
		const char* getCategory_pro() { return category_pro; }
};
void Products::input_data_pro(int z){
	num_pro = z;
	cout<<"Enter Name Product: ";
	cin>> num_pro;
	cout << "Enter Category Product: ";
	cin >> category_pro;
	cout << "Enter Price Product: ";
	cin >> Price;
	cout <<"\n\t       [The Product entered]   \n";
}
void Products::output_data_pro(){
	cout << left << setw(12) << getNum_pro() << setw(14) << getCategory_pro() << setw(15) << getNames_pro() << right << setw(12) <<  getPrice_pro() << endl;
}
//-----------------------------------------------------------------------
void new_product(){
	Products p;
	bool flag = true;
	int P_num;
	ifstream inFile("products.dat",ios::in | ios::binary );

	cout << "Enter Your product Number: ";
	cin >> P_num;
	while(inFile.read((char *) &p, sizeof(Products))){
		if(p.getNum_pro() == P_num)
			flag = false;
	}
	inFile.close();
	ofstream outFile("products.dat",ios::binary | ios::out | ios::app );

	if(flag){
		Products newp;
		newp.input_data_pro(P_num);
		outFile.write((char *) &newp, sizeof(Products));
	}
	else
		cout << "\n\t[Product entered]\n" << endl;

	outFile.close();
}
void Delete_product(int n){
	Products p;
	ofstream outFile("newproducts.dat",ios::binary);
	ifstream inFile("products.dat",ios::binary);
	if(!inFile){
		cout<<"File could not be open . Press Key";
		return;
	}
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &p, sizeof(Products))){
		if(p.getNum_pro() != n){
			outFile.write((char *) &p, sizeof(Products));
		}
	}
	inFile.close();
	outFile.close();
	remove("products.dat");
	rename("newproducts.dat","products.dat");
	cout<<"\n\t[product Deleted]";
}