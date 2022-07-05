#include<iostream>
#include<stack>
#include<queue>
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


    static vector<int> nodeToRoot(Node* node, int data){

        if(node->data == data){
            vector<int> bpath;
            bpath.push_back(data);
            return bpath; 
        }

        vector<int> respath;

        for(Node* child : node->children){
            respath = nodeToRoot(child, data);
            if(respath.size() > 0){
                respath.push_back(node->data);
                return respath;
            }
        }

        return respath;        

    }


    static int distance(Node* node, int d1, int d2){

        vector<int> n2rp1 = nodeToRoot(node, d1);
        vector<int> n2rp2 = nodeToRoot(node, d2);

        int i = n2rp1.size() - 1;
        int j = n2rp2.size() - 1;

        while(i >= 0 && j >= 0 && n2rp1.at(i) == n2rp2.at(j)) {
            i--;
            j--;
        }
        
        return i + j + 2;
    }

};

  

int main(){

int n; cin>>n;
vector<int> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

Node* root = gtree::construct(v);
int d1; cin>>d1;
int d2; cin>>d2;

cout<<gtree::distance(root,d1,d2)<<endl;


}
