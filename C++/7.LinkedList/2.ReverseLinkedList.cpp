#include<iostream>
using namespace std;

class linkedlist{

private:

    class Node {

        public:
               int data;
               Node* next;
        
        public:
                Node(){
                data = 0;
                next = NULL;
                }

                Node(int data){
                this->data = data;
                next = NULL;
                }

                Node(int data, Node* next){
                this->data = data;
                this->next = next;
                } 

    };

    Node* head;
    Node* tail;
    int SIZE;


public:

    linkedlist(){
        this->head = this->tail = NULL;
        this->SIZE = 0;
    }

    Node* getnthnode(int indx){

        Node* temp = this->head;
        while(indx > 0){
            temp= temp->next;
            indx--;
        }
        return temp;
    }

    void addfirst(int val){
        if(this->SIZE==0){
        Node* newnode = new Node(val);
        this->head = this->tail = newnode;
        this->SIZE++;
        }
        else{
        Node* newnode = new Node(val);
        newnode->next = this->head;
        this->head = newnode;
        this->SIZE++;
        }
    }

    void addlast(int val){
        if(this->SIZE==0){
        Node* newnode = new Node(val);
        this->head = this->tail = newnode;
        this->SIZE++;
        }
        else{
        Node* newnode = new Node(val);
        tail->next = newnode;
        this->tail = newnode;
        this->SIZE++;
        }
    }

    void addat(int val, int indx){

        if(indx < 0 || indx >= this->SIZE){
            cout<<"Invalid position"<<endl;
            return;
        }
        else if(indx == 0){
            addfirst(val);
        }
        else if(indx == this->SIZE){
            addlast(val);
        }   
        else{

            Node* nnode = getnthnode(indx-1);
            Node* newnode = new Node(val);

            newnode->next = nnode->next;
            nnode->next = newnode;
            this->SIZE++;
        }

    }

    int getfirst(){

        if(this->SIZE == 0){
            return -1;
        }

        return this->head->data;

    }

    int getlast(){

        if(this->SIZE == 0){
            return -1;
        }

        return this->tail->data;
        
    }

    int getat(int indx){

        if(indx < 0 || indx >= this->SIZE){
            cout<<"Invalid position"<<endl;
            return -1;
        }
        else{        
        Node* res = getnthnode(indx);
        return res->data;
        }
    }

    int removefirst(){

        if(this->SIZE == 0) {
            return -1;
        } else if(this->SIZE == 1) {
            int val = this->head->data;
            this->head = this->tail = NULL;
            this->SIZE = 0;
            return val;
        } else {
            int val = this->head->data;
            this->head = this->head->next;
            this->SIZE--;
            return val;
        }

    }

     int removelast(){
        
        if(this->SIZE == 0) {
            return -1;
        } else if(this->SIZE == 1) {
            int val = this->head->data;
            this->head = this->tail = NULL;
            this->SIZE = 0;
            return val;
        } else {
            Node* nnode = getnthnode(this->SIZE - 2);
            int val = this->tail->data;

            nnode->next = NULL;
            this->tail = nnode;
            this->SIZE--;

            return val;
        }

    }

     int removeat(int indx){
        
         if(indx < 0 || indx >= this->SIZE) {
            return -1;
        } else if(indx == 0) {
            return removefirst();
        } else if(indx == this->SIZE - 1) {
            return removelast();
        } else {
            Node* nnode = getnthnode(indx - 1);
            int val = nnode->next->data;
            nnode->next = nnode->next->next;

            this->SIZE--;
            return val;
        }

    }

    int size(){
        return this->SIZE;
    }

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    //Reverse LinkedList
    void reverseDI() {
      // write your code here
      
      int left = 0;
      int right = this->SIZE-1;
      
      while(left<right){
          
          Node* lnode = getnthnode(left);
          Node* rnode = getnthnode(right);
          
          int temp = lnode->data;
          lnode->data = rnode->data;
          rnode->data = temp;
          
          left++;
          right--;
      }
    }


    //Reverse LinkedList using pointers
    void reversePI(){
      // write your code here
      
      Node* prev = NULL;
      Node* current = head;
      
      while(current!=NULL){
          Node* next = current->next;
          current->next = prev;
          prev = current;
          current = next;
      }
      
      Node* temp = head;
      head = tail;
      tail = temp;
    }



    void reversePRHelper(Node* node){
        // write your code here
        if(node->next == NULL) {
            this->head = node;
            return;
        }
        reversePRHelper(node->next);
        node->next->next = node;
    }

    
    void reversePR(){
        // write your code here
        Node* temp = this->head;
        reversePRHelper(temp);
        temp->next = NULL;
        this->tail = temp;
    }



};


int main(){

    linkedlist* lst = new linkedlist();
    

}