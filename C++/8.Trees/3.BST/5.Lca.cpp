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


    class bst {
    public:

    static Node* construct(vector<int> arr, int lo, int hi) {
        if (lo > hi)
            return NULL;

        int mid = lo + (hi - lo) / 2;

        Node* nn = new Node(arr[mid]);

        nn->left = construct(arr, lo, mid - 1);
        nn->right = construct(arr, mid + 1, hi);

        return nn;
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

    static int size(Node* node) {
        if(node == NULL) return 0;

        int lsize = size(node->left);
        int rsize = size(node->right);
        return lsize + rsize + 1;
    }

    static int sum(Node* node) {
        if(node == NULL) return 0;

        int lsum = sum(node->left);
        int rsum = sum(node->right);
        return lsum + rsum + node->data;
    }

    static int max(Node* node) {
        if(node == NULL) {
            return INT16_MIN;
        } else if(node->right == NULL) {
            return node->data;
        } else {
            return max(node->right);
        }
    }

    static int min(Node* node) {
        if(node == NULL) {
            return INT16_MAX;
        } else if(node->left == NULL) {
            return node->data;
        } else {
            return min(node->left);
        }
    }

    static bool find(Node* node, int data) {
        if(node == NULL) return false;

        if(data > node->data) {
            return find(node->right, data);
        } else if(data < node->data) {
            return find(node->left, data);
        } else {
            // data found
            return true;
        }
    }



    static Node* add(Node* node, int data) {
        if(node == NULL){
            Node* nn = new Node(data, NULL, NULL);
            return nn;
        }

        if(data > node->data) {
            node->right = add(node->right, data);
        } else if(data < node->data) {
            node->left = add(node->left, data);
        } else {
        }
        return node;
    }


    static int Sum;

    static void rwsol(Node* node){
        if(node == NULL) return;
        // right
        rwsol(node->right);
        // inorder is area of work
        int data = node->data;
        node->data = Sum;
        Sum += data;
        // left
        rwsol(node->left);
    }

    static int lca(Node* node, int d1, int d2) {
        if(d1 > node->data && d2 > node->data) { // right side
            return lca(node->right, d1, d2);
        } else if(d1 < node->data && d2 < node->data) { // left side
            return lca(node->left, d1, d2);
        } else { // answer
            return node->data;
        }
    }

};

int bst::Sum = 0;


int main(){

    int n;  cin>>n;
    vector<string> s(n);
    vector<int> v;

    for(int i=0; i<s.size(); i++){
        cin>>s[i];
        if(s[i]!="n"){
            v.push_back(stoi(s[i]));
        }
    }

    sort(v.begin(), v.begin() + v.size());
    Node* root = bst::construct(v, 0, v.size()-1);
    
    int d1; cin>>d1;
    int d2; cin>>d2;
    
    int lca = bst::lca(root,d1,d2);

    cout<<lca;
    
    
    
}