#include<iostream>
#include<list>
#include<sstream>
using namespace std;

class LLToStackAdapter {
    //LinkedList<Integer> list;
    list<int> lst;

    public:
    
    LLToStackAdapter() {
    
    }


    int size() {
      // write your code here
      lst.size();
      
    }

    void push(int val) {
      // write your code here
      lst.push_back(val);
    }

    int pop() {
      // write your code here
      int val = lst.back();
      lst.pop_back();
      return val;
    }

    int top() {
      // write your code here
      return lst.back();
    }
};

int main(){
    
    string str;    getline(cin,str);
    LLToStackAdapter st;

    while(str!="quit")
    {
      if(str.find("push")==0){
        stringstream number(str.substr(5));
        int val = 0;  number >> val;
        st.push(val);
      } else if(str.find("pop")==0){
        int val = st.pop();
        if(val != -1){
          cout<<val<<endl;
        }
      } else if(str.find("top")==0){
        int val = st.top();
        if(val != -1){
          cout<<val<<endl;
        }
      } else if(str.find("size")==0){
        cout<<st.size()<<endl;
      } 
      getline(cin,str);
    }
}