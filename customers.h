
#include <iostream>
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