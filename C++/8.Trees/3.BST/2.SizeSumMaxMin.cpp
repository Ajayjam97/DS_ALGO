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

        string str = (root->left == NULL) ? " ." : "" + to_string(root->left->data);
        str += " <- [" + to_string(root->data) + "] -> ";
        str += (root->right == NULL) ? ". " : to_string(root->right->data);
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

};


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
    
    int data; cin>>data;
    
    int Size = bst::size(root);
    int Sum = bst::sum(root);
    int Max = bst::max(root);
    int Min = bst::min(root);
    bool Found = bst::find(root, data);

    cout<<Size<<endl;
    cout<<Sum<<endl;
    cout<<Max<<endl;
    cout<<Min<<endl;
    if(Found)
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
    
    
    
}