#include<bits/stdc++.h>
using namespace std;

class Human{

public:
    int height;
    int weight;
    int age;

public:
    Human(int height=60, int weight=45, int age=27){
        this->height=height;
        this->weight=weight;
        this->age=age;
    }
};


class Male: public Human{
    
    public: 

    Male(int height=90, int weight=65, int age=30){
        this->height=height;
        this->weight=weight;
        this->age=age;
    }
};

class Female: public Human{

    public: 
    Female(){}
    Female(int h, int w, int a): Human(h,w,a){}
    
};


//Multiple Inheritance
class LGBTQ: public Male, public Female{

};

class A{
    public:
    void abc(){
        cout<<"A";
    }
};

class B{
    public:
    void abc(){
        cout<<"B";
    }
};

class C: public A, public B{
    
};


int main(){

    //Inheritance
    //Male is inheriting from Human class, so it can use properties of Human
    Male m;
    cout<<"Male object:"<<endl;
    cout<<m.height<<endl;
    cout<<m.weight<<endl;
    cout<<m.age<<endl;
    
    Female f(70,50,24);
    cout<<"Female object:"<<endl;
    cout<<f.height<<endl;
    cout<<f.weight<<endl;
    cout<<f.age<<endl;

    //Access Modifiers: 
    //public properties inherited as public will be public
    //public properties inherited as protected will be protected
    //public properties inherited as private will be private

    //protected properties inherited as public will be protected
    //protected properties inherited as protected will be protected
    //protected properties inherited as private will be private

    //private properties inherited as public will not be accessible
    //private properties inherited as protected will not be accessible
    //private properties inherited as private will not be accessible

    //Types of Inheritance:
    //Single
    //Multilevel
    //Multiple
    //Hierarchical
    //Hybrid

    //Inheritance ambiguity
    //Ambiguity resolved using scope resolution operator
    C c;
    c.B::abc();
}