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


    static Node* predecessor;
    static Node* successor;
    static int state;


    static void predecessorAndSuccessor(Node* node, int data) {
        if(state == 0) {
            if(node->data == data) {
                state++;
            } else {
                predecessor = node;
            }
        } else if(state == 1) {
            successor = node;
            state++;
            return;
        }

        for(Node* child : node->children) {
            if(state < 2) {
                predecessorAndSuccessor(child, data);
            } else {
                return;
            }
        }
    }

};



Node* gtree::predecessor = NULL;
Node* gtree::successor = NULL;
int gtree::state = 0;

  

int main(){

int n; cin>>n;
vector<int> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

int data; cin>>data;

Node* root = gtree::construct(v);
gtree::predecessorAndSuccessor(root, data);

    if(gtree::predecessor == NULL){
      cout<<"Predecessor = Not found"<<endl;
    } else {
      cout<<"Predecessor = "<<gtree::predecessor->data<<endl;
    }

    if(gtree::successor == NULL){
      cout<<"Successor = Not found"<<endl;
    } else {
      cout<<"Successor = "<<gtree::successor->data<<endl;
    }

}
