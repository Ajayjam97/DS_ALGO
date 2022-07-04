#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

  class Node {

    public:
               int data;
               vector<Node*> children;
        
                Node(){
                data = 0;
                children.reserve(100);
                }

                Node(int data){
                this->data = data;
                this->children.reserve(100);
                }

    };

    class gtree{

public:

    static Node* construct(vector<int> arr) {
        Node* root = NULL;
        stack<Node*> st;

        for(int i = 0; i < arr.size(); i++) {
            int data = arr[i];
            if(data != -1) {
                Node* nn = new Node(data);
                if(st.size() == 0) {
                    root = nn;
                    st.push(nn);
                } else {
                    st.top()->children.push_back(nn);
                    st.push(nn);
                }
            } else {
                st.pop();
            }
        }

        
        return root;
    }

    static void display(Node* root) {
        
        string str = to_string(root->data) + " -> ";
        for(Node* child : root->children) {
            str += to_string(child->data) + ", ";
        }
        cout<<str + "."<<endl;

        for(int i = 0; i < root->children.size(); i++) {
            Node* child = root->children[i];
            display(child);
        }
    }


    static Node* getTail(Node* node) {
        Node* tail = node;

        while(tail->children.size() != 0) {
            tail = tail->children[0];
        }
        return tail;
    }


    static void linearize(Node* node){
        for(Node* child : node->children) {
            linearize(child);
        }

        for(int i = node->children.size() - 2; i >= 0; i--) {
            Node* last = node->children[i+1];  // last 
            Node* slast = node->children[i];     // second last

            node->children.erase(node->children.begin()+i+1);
            Node* tail = getTail(slast);

            tail->children.push_back(last);
        }
    }



 

};

  

int main(){

int n; cin>>n;
vector<int> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

Node* root = gtree::construct(v);
gtree::linearize(root);
gtree::display(root);





}
