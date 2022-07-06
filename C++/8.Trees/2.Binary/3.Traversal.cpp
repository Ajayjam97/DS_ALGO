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


    static void levelOrder(Node* node) {
        queue<Node*> que;

        que.push(node);

        while(que.size() > 0) {
            int sz = que.size();

            while(sz-- > 0) {
                // 1. get + remove
                Node* rem = que.front();    que.pop();
                // 2. print
                cout<<rem->data<<" ";
                // 3. add children
                if(rem->left != NULL)
                    que.push(rem->left);

                if(rem->right != NULL) 
                    que.push(rem->right);
            }
            cout<<endl;
        }
    }


    static void preOrder(Node* root) {
        if(root == NULL) return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    static void inOrder(Node* root) {
        if(root == NULL) return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    static void postOrder(Node* root) {
        if(root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }



        static void iterativePrePostInTraversal(Node* node) {
        stack<Pair*> st;

        vector<int> pre;
        vector<int> in;
        vector<int> post;

        st.push(new Pair(node, 0));

        while(st.size() > 0) {
            Pair* p = st.top();
            if(p->state == 0) {
                pre.push_back(p->node->data);
                p->state++;
                if(p->node->left != NULL) {
                    st.push(new Pair(p->node->left, 0));
                }
            } else if(p->state == 1) {
                in.push_back(p->node->data);
                p->state++;
                if(p->node->right != NULL) {
                    st.push(new Pair(p->node->right, 0));
                }
            } else {
                post.push_back(p->node->data);
                st.pop();
            }
        }

        for(int val : pre) {
            cout<<val<<" ";
        }
        cout<<endl;

        for(int val : in) {
            cout<<val<<" ";
        }
        cout<<endl;

        for(int val : post) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
 

};


int main(){

int n; cin>>n;
vector<string> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

Node* root = btree::construct(v);
//btree::preOrder(root);  cout<<endl;
//btree::inOrder(root);   cout<<endl;
//btree::postOrder(root); cout<<endl;
btree::iterativePrePostInTraversal(root);

}