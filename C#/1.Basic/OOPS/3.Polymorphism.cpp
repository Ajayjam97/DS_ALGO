#include<bits/stdc++.h>
using namespace std;

class A{

    public:
    int val;
    void func(){cout<<"a"<<endl;}
    void func(int a){cout<<a<<endl;}
    int func(char c){return c;}
    A operator+ (A &a){
        int value1=this->val;
        int value2=a.val;
        A na; na.val = value1+value2;
        return na;
    }
};


class Animal{
    public:
    void sound(){
        cout<<"Animal sound"<<endl;
    }
};

class Dog: public Animal{
    public:
    Dog(){
        cout<<"Dog"<<endl;
    }
    void sound(){
        cout<<"Barking sound"<<endl;
    }
};

int main(){

    //Polymorphism
    //Existing in multiple forms.

    //Types of polymorphism:

    //Compile time
    //Method Overloading
    A a;
    a.func();
    a.func(20);
    cout<<a.func('a')<<endl;
    //Operator Overloading
    A b;
    A c;
    a.val=20; b.val=20;
    c=a+b;
    cout<<c.val<<endl;

    //Run time
    //Method Overriding
    Dog d;
    d.sound();


}