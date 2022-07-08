#include<iostream>
#include<stack>
#include<vector>
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

        string str = (root->left == NULL) ? " ." : "" + to_string(root->left->data);
        str += " <- [" + to_string(root->data) + "] -> ";
        str += (root->right == NULL) ? ". " : to_string(root->right->data);
        cout<<str<<endl;

        display(root->left);
        display(root->right);
    }

};


int main(){

    int n;  cin>>n;
    vector<int> v(n);

    for(int i=0; i<v.size(); i++){
    cin>>v[i];
    }

    Node* root = bst::construct(v, 0, v.size()-1);
    bst::display(root);
}