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


    static bool areMirror(Node* n1, Node* n2) {
        if(n1->children.size() != n2->children.size()) return false;

        int sz = n1->children.size();
        bool res = true;
        for(int i = 0; i < sz; i++) {
            Node* child1 = n1->children.at(i);
            Node* child2 = n2->children.at(sz - i - 1);

            res = areMirror(child1, child2);
            if(res == false) return false;
        }
        return res;
    }


};


int main(){

int n; cin>>n;
vector<int> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

int data; cin>>data;

Node* root = gtree::construct(v);

}
