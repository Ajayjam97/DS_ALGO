#include<bits/stdc++.h>

using namespace std;

struct Person{

        //Fields
        public: string name;
        public: int id;

        //Constructor
        public: Person(string _name, int _id){
            name=_name; id=_id;
        }

};

enum Shapes
{
    Circle,
    Square
};

int main(){
    cout<<"HELLO WORLD C++"<<endl;

    //User defined types
    //struct, union, enum, class
    Person* p = new Person("Ajay", 103);
    cout<<p->id<<" "<<p->name<<endl;
    cout<<Circle<<" "<<Square<<endl;

    //Built in types
    //int, char, void, float, double
    char c='A'; bool bl=true; short shrt=-16; unsigned short ushrt=16; int i=-32; unsigned int ui=32; long l=-64; unsigned long ul=64; 
    float f=3.38843884f; //float 6-digit precision
    double dbl=8.388438843884388438843884;  //double 18-digit precision
    cout<<sizeof(c)<<" "<<sizeof(bl)<<" "<<sizeof(shrt)<<" "<<sizeof(ushrt)<<" "<<sizeof(i)<<" "<<sizeof(ui)<<" "
    <<sizeof(l)<<" "<<sizeof(ul)<<" "<<sizeof(f)<<" "<<sizeof(dbl)<<endl;
    cout<<CHAR_MAX<<" "<<SHRT_MAX<<" "<<USHRT_MAX<<" "<<INT_MAX<<" "<<UINT_MAX<<" "<<LONG_MAX<<" "<<ULONG_MAX<<" "<<FLT_MAX<<" "<<DBL_MAX<<endl;

    //Derived type
    //array, pointer, reference


}