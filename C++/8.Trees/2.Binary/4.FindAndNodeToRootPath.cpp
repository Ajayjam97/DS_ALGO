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


    static bool find(Node* node, int data) {
        if(node == NULL) return 0;

        if(node->data == data) return 1;

        bool lres = find(node->left, data);
        if(lres == 1) return 1;

        bool rres = find(node->right, data);
        if(rres == 1) return 1;

        return 0;
    }

    static vector<int>  nodeToRootPath(Node* node, int data) {
        if(node == NULL){
            vector<int> bres;
            return bres;
        }

        if(node->data == data) {
            vector<int>  bres;
            bres.push_back(node->data);
            return bres;
        }

        vector<int>  lres = nodeToRootPath(node->left, data);
        if(lres.size() > 0) {
            lres.push_back(node->data);
            return lres;
        }

        vector<int>  rres = nodeToRootPath(node->right, data);
        if(rres.size() > 0) {
            rres.push_back(node->data);
            return rres;
        }

        vector<int> res;
        return res;
    }
 

};


int main(){

int n; cin>>n;
vector<string> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

int data; cin>>data;
Node* root = btree::construct(v);
//btree::preOrder(root);  cout<<endl;
//btree::inOrder(root);   cout<<endl;
//btree::postOrder(root); cout<<endl;
if(btree::find(root,data)){
    cout<<"true"<<endl;
}
else{
    cout<<"false"<<endl;
}

vector<int> res = btree::nodeToRootPath(root,data);

if(btree::find(root,data)){
cout<<"[";

for(int i=0; i<res.size()-1; i++){
    cout<<res[i]<<", ";
}

cout<<res[res.size()-1]<<"]"<<endl;
}
else{
    cout<<"[]"<<endl;
}

}