#include <iostream>
#include <iomanip>
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