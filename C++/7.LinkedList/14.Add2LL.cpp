#include<iostream>
#include<sstream>
#include<vector>
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


    static Node* reversePointer(Node* node) {
        Node* prev = NULL;
        Node* curr = node;

        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }



        static linkedlist* addTwoLists(linkedlist* one, linkedlist* two) {
        // write your code here
        Node* head1 = one->head;
        Node* head2 = two->head;
        // don't change original list
        // 1. reverse
        head1 = reversePointer(head1);
        head2 = reversePointer(head2);

        // 2. add
        Node* i = head1;
        Node* j = head2;
        linkedlist* res = new linkedlist();
        int carry = 0;
        while(i != NULL || j != NULL || carry != 0) {
            int ival = i == NULL ? 0 : i->data;
            i = i == NULL ? NULL : i->next;

            int jval = j == NULL ? 0 : j->data;
            j = j == NULL ? NULL : j->next;

            int sum = ival + jval + carry;

            int val = sum % 10;
            carry = sum / 10;
            res->addFirst(val);
        }

        // 3. make original list again, reverse head1 and head2
        head1 = reversePointer(head1);
        head2 = reversePointer(head2);
        // 4. return result
        return res;
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


        linkedlist* sum = linkedlist::addTwoLists(l1, l2);

        int a; cin>>a;
        int b; cin>>b;

        l1->display();
        l2->display();
        sum->display();
        sum->addFirst(a);
        sum->addLast(b);
        sum->display();

    

    
    }











    
    
    
