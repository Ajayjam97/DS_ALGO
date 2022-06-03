#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

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

class linkedlist{

    


public:

    Node* head;
    Node* tail;
    int SIZE;

    linkedlist(){
        this->head = this->tail = NULL;
        this->SIZE = 0;
    }

    Node* getNthNode(int indx){

        Node* temp = this->head;
        while(indx > 0){
            temp= temp->next;
            indx--;
        }
        return temp;
    }

    void addFirst(int val){
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

    void addLast(int val){
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

    void addAt(int val, int indx){

        if(indx < 0 || indx >= this->SIZE){
            cout<<"Invalid position"<<endl;
            return;
        }
        else if(indx == 0){
            addFirst(val);
        }
        else if(indx == this->SIZE){
            addLast(val);
        }   
        else{

            Node* nnode = getNthNode(indx-1);
            Node* newnode = new Node(val);

            newnode->next = nnode->next;
            nnode->next = newnode;
            this->SIZE++;
        }

    }

    int getFirst(){

        if(this->SIZE == 0){
            cout<<"List is empty"<<endl;
            return -1;
        }

        return this->head->data;

    }

    int getLast(){

        if(this->SIZE == 0){
            cout<<"List is empty"<<endl;
            return -1;
        }

        return this->tail->data;
        
    }

    int getAt(int indx){

        if(indx < 0 || indx >= this->SIZE){
            cout<<"Invalid arguments"<<endl;
            return -1;
        }
        else{        
        Node* res = getNthNode(indx);
        return res->data;
        }
    }

    int removeFirst(){

        if(this->SIZE == 0) {
            cout<<"List is empty"<<endl;
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

     int removeLast(){
        
        if(this->SIZE == 0) {
            cout<<"List is empty"<<endl;
            return -1;
        } else if(this->SIZE == 1) {
            int val = this->head->data;
            this->head = this->tail = NULL;
            this->SIZE = 0;
            return val;
        } else {
            Node* nnode = getNthNode(this->SIZE - 2);
            int val = this->tail->data;

            nnode->next = NULL;
            this->tail = nnode;
            this->SIZE--;

            return val;
        }

    }

     int removeAt(int indx){
        
         if(indx < 0 || indx >= this->SIZE) {
            return -1;
        } else if(indx == 0) {
            return removeFirst();
        } else if(indx == this->SIZE - 1) {
            return removeLast();
        } else {
            Node* nnode = getNthNode(indx - 1);
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
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }


    static int findIntersection(linkedlist* one, linkedlist* two){
        // write your code here
        Node* t1 = one->head;
        Node* t2 = two->head;

        int s1 = one->size();
        int s2 = two->size();

        if(s1 > s2) {
            int diff = s1 - s2;
            for(int i = 0; i < diff; i++)
                t1 = t1->next;
        } else {
            int diff = s2 - s1;
            for(int i = 0; i < diff; i++)
                t2 = t2->next;
        }

        // while(t1 != null && t2 != null && t1 != t2) {
        //     t1 = t1.next;
        //     t2 = t2.next;
        // }
        // return t1 == null || t2 == null ? null : t1;

        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1->data;
    }
    

};



    int main() {
            
        linkedlist* l1 = new linkedlist();
        int n1; cin>>n1;        
        vector<int> v1(n1);

        for (int i = 0; i < n1; i++) {
            cin>>v1[i];
            l1->addLast(v1[i]);
        }


        linkedlist* l2 = new linkedlist();
        int n2; cin>>n2;        
        vector<int> v2(n1);

        for (int i = 0; i < n2; i++) {
            cin>>v2[i];
            l2->addLast(v2[i]);
        }

        int li; cin>>li;
        int di; cin>>di;

        if(li == 1){
            Node* n = l1->getNthNode(di);
            l2->tail->next = n;
            l2->tail = l1->tail;
            l2->SIZE += l1->size() - di;
        } else {
            Node* n = l2->getNthNode(di);
            l1->tail->next = n;
            l1->tail = l2->tail;
            l1->SIZE += l2->size() - di;
        }

        int inter = linkedlist::findIntersection(l1, l2);
        cout<<inter<<endl;

    

    
    }











    
    
    
