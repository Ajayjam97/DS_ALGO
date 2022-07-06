#include<iostream>
#include<stack>
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
        
        string str = "[" + to_string(root->data) + "] -> ";
        for(Node* child : root->children) {
            str += to_string(child->data) + ", ";
        }
        cout<<str + " ."<<endl;

        for(int i = 0; i < root->children.size(); i++) {
            Node* child = root->children[i];
            display(child);
        }
    }

    static void constructanddisplay(vector<int> arr){
        Node* root = construct(arr);
        display(root);
    }
    
};


int main(){
vector<int> data = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
gtree::constructanddisplay(data);
}