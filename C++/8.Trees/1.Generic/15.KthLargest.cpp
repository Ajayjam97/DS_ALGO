#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>
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


    static int ceil;  // qualified min
    static int floor; // qualified max
    static void ceilAndFloor(Node* node, int data) {
        if(node->data > data) {
            // ceil
            if(node->data < ceil) {
                ceil = node->data;
            }
        }

        if(node->data < data) {
            // floor
            if(node->data > floor) {
                floor = node->data;
            }
        }

        for(Node* child : node->children) {
            ceilAndFloor(child, data);
        }
    }


    static int kthLargest(Node* node, int k){
    // write your code here
     int data = INT_MAX;
        for(int i = 0; i < k; i++) {
            floor = INT_MIN;
            ceilAndFloor(node, data);
            data = floor;
        }
        return data;
    }


};

int gtree::ceil = INT_MAX; // qualified min
int gtree::floor = INT_MIN; // qualified max

  

int main(){

int n; cin>>n;
vector<int> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

Node* root = gtree::construct(v);



}
