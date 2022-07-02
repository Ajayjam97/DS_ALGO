#include<iostream>
#include<stack>
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

    static int size(Node* root){
    // write your code here
    int count=0;
    for(Node* child: root->children){
        count+=size(child);
    }
    if(root->data!=-1)
    return count+1;
    }

    static int max(Node* root){
    int mx=root->data;
    for(Node* child: root->children){
        int nmx = max(child);
        mx = (mx > nmx)? mx : nmx;
    }
    if(root->data!=-1)
    return mx;
    }

    static int height(Node *root){
        int ht =-1;
        for(Node* child: root->children){
        int nht = height(child);
        ht = (ht > nht)? ht : nht;
    }
    return ht+1;
    }

 

};

  

int main(){

int n; cin>>n;
vector<int> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

Node* root = gtree::construct(v);
int ht = gtree::height(root);
cout<<ht;

}
