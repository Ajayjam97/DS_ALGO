#include<bits/stdc++.h>
using namespace std;

class ListNode{

    public: 

    int data;
    ListNode* next;

    ListNode(): data(0), next(NULL){

    }

    ListNode(int x): data(x), next(NULL){

    }

    ListNode(int x, ListNode* nxt): data(x), next(nxt){

    } 


};

class List{

    private:

    ListNode* head;
    ListNode* tail;
    int size;

    public:

    List(): head(NULL), tail(NULL), size(0){

    } 

    List(int x){
        head = new ListNode(x);
        tail = head;
        size=1;
    }

    void InsertAtHead(int x){
        ListNode* temp = new ListNode(x);
        temp->next = head;
        head = temp;
        size++;
    }

    void InsertAtTail(int x){
        ListNode* temp = new ListNode(x);
        tail->next = temp;
        tail = temp;
        size++;
    }

    void InsertAt(int x, int indx){

    try{

        if(indx>size || indx<0){
            throw exception();
        }
        else if(indx==0){
            InsertAtHead(x);
        }
        else if(indx==size){
            InsertAtTail(x);
        }
        else{
            ListNode* temp = new ListNode(x);
            ListNode* itr = head;
            while(itr!=NULL){
                indx--;
                if(indx==0){
                    temp->next = itr->next;
                    itr->next = temp;
                    size++;
                    break;
                }
                itr=itr->next;
            }
        }
    }
    catch(exception e){
        cout<<"Index out of bound"<<endl;
    }

    }


    void DeleteAt(int indx){

        if(indx==0){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            size--;
        }
        else{
            ListNode* prev=NULL;
            ListNode* curr=NULL;
            int count=0;
            ListNode* itr=head;
            while(count!=indx){
                prev=itr;
                itr=itr->next;
                curr=itr;
                count++;                
            }

            prev->next=curr->next;
            delete curr;
            size--;
        }
    }

    void DisplayList(){
        ListNode* temp=this->head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void Size(){
        cout<<size<<endl;
    }

};


    
int main(){

    //ListNode* head=NULL;
    //head=new ListNode();
    //head->next = new ListNode(2);

    List* l = new List(10);
    l->InsertAtTail(20);
    l->InsertAtTail(30);
    l->InsertAtTail(40);
    l->InsertAtTail(50);
    l->InsertAt(0, 4);
    l->DisplayList();
    l->Size();
    l->InsertAtTail(60);
    l->DisplayList();
    l->Size();
    l->DeleteAt(6);
    l->DisplayList();
    l->Size();
    l->DeleteAt(0);
    l->DisplayList();
    l->Size();
    l->DeleteAt(3);
    l->DisplayList();
    l->Size();



}