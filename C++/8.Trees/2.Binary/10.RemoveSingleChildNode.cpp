#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Node {

public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = this->right = NULL;
        }

        Node(int data, Node* left, Node* right) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
};

class btree{

public:

    class Pair {
    public:
        Node* node;
        int state;

        Pair(Node* node, int state) {
            this->node = node;
            this->state = state;
        }
    };

    static Node* construct(vector<string> arr) {
        Node* root = new Node(stoi(arr[0]));
        stack<Pair*> st;
        st.push(new Pair(root, 0));

        int indx = 0;
        while (st.size() > 0) {
            Pair* p = st.top();
            if (p->state == 0) {
                // left child processing
                indx++;
                if (arr[indx] != "n") {
                    Node* nn = new Node(stoi(arr[indx]));
                    p->node->left = nn;
                    st.push(new Pair(nn, 0));
                }
                p->state++;
            } else if (p->state == 1) {
                // right child processing
                indx++;
                if (arr[indx] != "n") {
                    Node* nn = new Node(stoi(arr[indx]));
                    p->node->right = nn;
                    st.push(new Pair(nn, 0));
                }
                p->state++;
            } else {
                // pop out node-pair from stack
                st.pop();
            }
        }
        return root;
    }

    static void display(Node* root) {
        
       if (root == NULL)
            return;

        string str = (root->left == NULL) ? "." : "" + to_string(root->left->data);
        str += " <- " + to_string(root->data) + " -> ";
        str += (root->right == NULL) ? "." : to_string(root->right->data);
        cout<<str<<endl;

        display(root->left);
        display(root->right);
    }


    static void printSingleChildNodes(Node* node, Node* parent){
        if(node == NULL) return;

        if(parent != NULL && parent->left == node && parent->right == NULL) {
            //Single left child
            cout<<node->data<<endl;
        }

        if(parent != NULL && parent->right == node && parent->left == NULL) {
            //Single right child
            cout<<node->data<<endl;
        }

        printSingleChildNodes(node->left, node);
        printSingleChildNodes(node->right, node);
    }
 

};


int main(){

int n; cin>>n;
vector<string> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

Node* root = btree::construct(v);
btree::printSingleChildNodes(root,root);

}