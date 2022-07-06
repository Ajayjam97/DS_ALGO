#include<iostream>
#include<stack>
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

        string str = (root->left == NULL) ? " ." : "" + to_string(root->left->data);
        str += " <- [" + to_string(root->data) + "] -> ";
        str += (root->right == NULL) ? ". " : to_string(root->right->data);
        cout<<str<<endl;

        display(root->left);
        display(root->right);
    }


 static int size(Node* node) {
    // write your code here
    if(node == NULL) return 0;

        int ls = size(node->left);
        int rs = size(node->right);

        return ls + rs + 1;
  }

 static int sum(Node* node) {
    // write your code here
    if(node == NULL) return 0;

        int lsum = sum(node->left);
        int rsum = sum(node->right);

        return lsum + rsum + node->data;
  }

  static int max(Node* node) {
    // write your code here
    int rvalue = INT8_MIN;
    if(node == NULL) return rvalue;

        int lmax = max(node->left);
        int rmax = max(node->right);

        return std::max(node->data, std::max(lmax, rmax));
  }

  static int height(Node* node) {
    // write your code here
    if(node == NULL) return -1;
        
        int lh = height(node->left);
        int rh = height(node->right);

        return std::max(lh, rh) + 1;
  }


 

};


int main(){

int n; cin>>n;
vector<string> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

Node* root = btree::construct(v);

cout<<btree::size(root)<<endl;
cout<<btree::sum(root)<<endl;
cout<<btree::max(root)<<endl;
cout<<btree::height(root)<<endl;

}