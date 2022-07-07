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

        string str = (root->left == NULL) ? " ." : "" + to_string(root->left->data);
        str += " <- [" + to_string(root->data) + "] -> ";
        str += (root->right == NULL) ? ". " : to_string(root->right->data);
        cout<<str<<endl;

        display(root->left);
        display(root->right);
    }

    

    static vector<Node*>  nodeToRootPath(Node* node, int data) {
        if(node == NULL){
            vector<Node*> bres;
            return bres;
        }

        if(node->data == data) {
            vector<Node*>  bres;
            bres.push_back(node);
            return bres;
        }

        vector<Node*>  lres = nodeToRootPath(node->left, data);
        if(lres.size() > 0) {
            lres.push_back(node);
            return lres;
        }

        vector<Node*>  rres = nodeToRootPath(node->right, data);
        if(rres.size() > 0) {
            rres.push_back(node);
            return rres;
        }

        vector<Node*> res;
        return res;
    }


    static void printKDown(Node* node, Node* blockage, int k) {
        if(node == NULL || node == blockage || k < 0) return;

        if(k == 0) {
            cout<<node->data;
            return;
        }
        
        printKDown(node->left, blockage, k - 1);
        printKDown(node->right, blockage, k - 1);
    }



    static void printKNodesFar(Node* root, int data, int k) {
        vector<Node*> n2rp = nodeToRootPath(root, data);

        Node* blockage = NULL;
        for(int i = 0; i < n2rp.size() && k >= 0; i++) {
            Node* node = n2rp.at(i);
            printKDown(node, blockage, k);
            k--;
            blockage = node;
        }
    }


 

};


int main(){

int n; cin>>n;
vector<string> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

int data; cin>>data;
int k; cin>>k;
Node* root = btree::construct(v);

btree::printKNodesFar(root, data, k);


}