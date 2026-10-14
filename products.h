
#include <iostream>
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