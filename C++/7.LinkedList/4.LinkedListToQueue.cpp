#include<iostream>
#include<list>
#include<sstream>
using namespace std;

class LLToQueueAdapter {
    list<int> lst;

    public:
    
    LLToQueueAdapter() {
      
    }

    int size() {
      // write your code here
      return lst.size();
    }

    void add(int val) {
      // write your code here
      lst.push_front(val);
    }

    int remove() {
      // write your code here
      if(lst.size()==0){
          cout<<"Queue underflow"<<endl;
          return -1;
      }
      int val = lst.back(); lst.pop_back();
      return val;
    }

    int peek() {
      // write your code here
      if(lst.size()==0){
          cout<<"Queue underflow"<<endl;
          return -1;
      }
      return lst.back();
    }
  };


int main(){
    
    string str;    getline(cin,str);
    LLToQueueAdapter qu = LLToQueueAdapter();

   while(str!="quit")
    {
      if(str.find("add")==0){
        stringstream number(str.substr(4));
        int val = 0;  number >> val;
        qu.add(val);
      } else if(str.find("remove")==0){
        int val = qu.remove();
        if(val != -1){
          cout<<val<<endl;
        }
      } else if(str.find("peek")==0){
        int val = qu.peek();
        if(val != -1){
          cout<<val<<endl;
        }
      } else if(str.find("size")==0){
        cout<<qu.size()<<endl;
      } 
      getline(cin,str);
    }
}
