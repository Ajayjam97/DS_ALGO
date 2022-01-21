#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

class CustomStack {
    int* data;
    int capacity;
    int tos;

public:
    CustomStack(int cap) {
      data = new int[cap];
      capacity = cap;
      tos = -1;
    }

    int size() {
      // write ur code here
      return tos+1;
    }

    void display() {
      // write ur code here
      for(int i=tos; i>=0; i--){
          cout<<data[i]<<" ";
      }
      cout<<endl;
    }

    void push(int val) {
      // write ur code here
        if(this->size()==capacity){
            cout<<"Stack overflow"<<endl;
            return;
        }
        data[++tos] = val;
    }

    int pop() {
      // write ur code here
      if(this->size()==0){
          cout<<"Stack underflow"<<endl;
          return -1;
        }
        return data[tos--];
    }

    int top() {
       // write ur code here
       if(this->size()!=0){
           return data[tos];
       }
       else{
           cout<<"Stack underflow"<<endl;
           return -1;
       }

    }

  };



int main(){

    CustomStack st = CustomStack(5);

    st.push(4);
    st.push(7);
    st.push(23);
    st.push(5);
    st.push(56);

    cout<<st.top()<<endl;
    st.display();
    st.pop();
    cout<<st.top()<<endl;
    st.display();
    st.pop();
    st.pop();
    st.display();



}