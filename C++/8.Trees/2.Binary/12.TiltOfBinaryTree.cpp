#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
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



    static int Tilt;

    static int sumForTilt(Node* node) {
        if(node == NULL) return 0;

        int lsum = sumForTilt(node->left);
        int rsum = sumForTilt(node->right);

        // add contribution of our level in tilt static variable
        Tilt += abs(lsum - rsum);

        return lsum + rsum + node->data;
    }
    
    static int tilt(Node* node){
        // write your code here to set the tilt data member
        Tilt = 0;
        sumForTilt(node);
        return Tilt;
    }

 

};

int btree::Tilt = 0;


int main(){

int n; cin>>n;
vector<string> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

Node* root = btree::construct(v);

cout<<btree::tilt(root);

}