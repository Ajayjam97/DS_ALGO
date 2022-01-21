#include<bits/stdc++.h>
using namespace std;

class Stack{

    private:  vector<int> st;
    private: int size;

    public:
    
    Stack(int capacity){
        st.reserve(capacity);
        this->size=-1;
    }

    void push(int num){
        if(st.capacity()==st.size()){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            st[++size]=num;
        }
    }

    int pop(){
        if(size==-1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            return st[size--];
        }
    }

    int peek(){
        if(size==-1){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            return st[size];
        }
    }

    bool IsEmpty(){
        return (st.size()==0);
    }

    int Size(){
        return st.size();
    }

    void display(){
        for(int i=size; i>=0; i--){
            cout<<" ["<<st[i]<<"] ";
        }
        cout<<endl;
    }

};



int main(){

    Stack st = Stack(5);

    st.push(4);
    st.push(7);
    st.push(23);
    st.push(5);
    st.push(56);

    cout<<st.peek()<<endl;
    st.display();
    st.pop();
    cout<<st.peek()<<endl;
    st.display();
    st.pop();
    st.pop();
    st.display();



}