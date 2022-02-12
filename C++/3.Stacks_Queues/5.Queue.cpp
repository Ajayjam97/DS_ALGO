#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

class CustomQueue {
    int* data;
    int capacity;
    int front, rear, size;

public:
    CustomQueue(int cap) {
    //   data = new int[cap];
    //   capacity = cap;
    //   tos = -1;
    data = new int[cap];
    capacity = cap;
    front = size = 0;
    rear = -1;
    }

    void display() {
    // write ur code here
    //   for(int i=tos; i>=0; i--){
    //       cout<<data[i]<<" ";
    //   }
    //   cout<<endl;
      for(int i=rear; i>=front; i--){
          cout<<data[i]<<" ";
      }
      cout<<endl;
    }

    void enqueue(int val) {
    // write ur code here

    // if(this->size()==capacity){
    //     cout<<"Stack overflow"<<endl;
    //     return;
    // }
    // data[++tos] = val;
        if(size==capacity) return;

        rear = (rear+1)%capacity;
        data[rear] = val;
        size+=1;
    }

    int dequeue() {
    // write ur code here
    // if(this->size()==0){
    //       cout<<"Stack underflow"<<endl;
    //       return -1;
    // }
    // return data[tos--];
        if(size==0) return -1;

        int val = data[front];
        front = (front+1)%capacity;
        size-=1;
        return val;
    }

    int Front() {
       // write ur code here
    //    if(this->size()!=0){
    //        return data[tos];
    //    }
    //    else{
    //        cout<<"Stack underflow"<<endl;
    //        return -1;
    //    }
        if(size==0) return -1;
        return data[front];

    }

    int Fear(){

        if(size==0) return -1;
        return data[rear];

    }

  };



int main(){

    CustomQueue qu = CustomQueue(4);
    queue<string> qu;

    qu.enqueue();

    qu.enqueue(4); qu.enqueue(7);   qu.enqueue(3);    qu.enqueue(5);

    qu.display();   qu.dequeue();    qu.display();    cout<<qu.Front()<<endl;    qu.dequeue();    qu.display();



}