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

    static void levelOrder(Node* root) {
        queue<Node*> qu;

        qu.push(root);

        while(qu.size() > 0) {
            // 1. get + remove
            Node* rem = qu.front();  qu.pop();
            // 2. print
            cout<<to_string(rem->data)<<" ";
            // 3. add children
            for(Node* child : rem->children) {
                qu.push(child);
            }
        }
        cout<<"."<<endl;
       
    }


    // level order using 2 queues
    static void levelOrderLinewise1(Node* node){
        queue<Node*> mainQ;
        queue<Node*> childQ;
        
        mainQ.push(node);
        int level = 1;
        while(mainQ.size() > 0) {
            Node* rem = mainQ.front();   mainQ.pop();
            cout<<to_string(rem->data)<<" ";

            for(Node* child : rem->children) {
                childQ.push(child);
            }

            if(mainQ.size() == 0) {
                // hit enter
                cout<<endl;
                level++;
                // swap mainQ and childQ
                queue<Node*> temp = mainQ;
                mainQ = childQ;
                childQ = temp;
            }
        }
    }

    // level order using delimiter
    static void levelOrderLinewise2(Node* node){
        // use linkedlist as a queue, because arrayDeque is not allow us to add null
        queue<Node*> qu;

        qu.push(node);
        qu.push(NULL);

        while(qu.size() > 0) {
            // 1. get + remove
            Node* rem = qu.front();     qu.pop();

            if(rem == NULL) {
                // 2. hit enter
                cout<<endl;
                // 3. if size is more than 0 then again add null
                if(qu.size() > 0)
                    qu.push(NULL);

            } else {
                // 2. print
                cout<<rem->data<<" ";
                // 3. add children
                for(Node* child : rem->children) {
                    qu.push(child);
                }
            }
        }
    }

    // level order line wise, using single que, count approach
    static void levelOrderLinewise3(Node* node){
        // use linkedlist as a queue, because arrayDeque is not allow us to add null
        queue<Node*> qu;
        qu.push(node);

        while(qu.size() > 0) {
            int sz = qu.size();
            while(sz-- > 0) {
                // 1. get + remove
                Node* rem = qu.front(); qu.pop();
                // 2. print
                cout<<rem->data<<" ";
                // 3. add children
                for(Node* child : rem->children) {
                    qu.push(child);
                }
            }
            cout<<endl;
        }
    }
    
    
    static void levelOrderLinewiseZZ2(Node* node){
        stack<Node*> mainS;
        stack<Node*> childS;
        mainS.push(node);
        int lvl = 1;
        while(mainS.size() > 0) {
            Node* rem = mainS.top(); mainS.pop();
            cout<<to_string(rem->data)<<" ";
            
            if(lvl % 2 == 1) {
                // odd level -> left to right
                for(int i = 0; i < rem->children.size(); i++) {
                    Node* child = rem->children[i];
                    childS.push(child);
                }
            } else {
                // even level -> right to left
                for(int i = rem->children.size() - 1; i >= 0; i--) {
                    Node* child = rem->children[i];
                    childS.push(child);
                }
            }

            if(mainS.size() == 0) {
                cout<<endl;
                lvl++;
                stack<Node*> temp = mainS;
                mainS = childS;
                childS = temp;
            }
        }
    }



       static void removeLeaves(Node* node) {
        
        vector<Node*> st;
        for(Node* child : node->children) {
            // Node child = node.children.get(i);
            if(child->children.size() != 0) {
                st.push_back(child);
            }
        }
        node->children = st;

        for(Node* child : node->children) {
            removeLeaves(child);
        }
        
    }


    static Node* getTail(Node* node) {
        Node* tail = node;

        while(tail->children.size() != 0) {
            tail = tail->children[0];
        }

        return tail;
    }

    static void linearize(Node* node){
        for(Node* child : node->children) {
            linearize(child);
        }

        for(int i = node->children.size() - 2; i >= 0; i--) {
            Node* last = node->children[i+1];  // last 
            Node* slast = node->children[i];     // second last

            node->children.erase(node->children.begin()+i+1);
            Node* tail = getTail(slast);

            tail->children.push_back(last);
        }
    }


    static bool find(Node* node, int data){

        if(node->data == data)  return true;

        bool res = false;

        for(Node* child : node->children){
            res = find(child, data);
            if(res==true) return true;
        }

        return res;
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
 

    static int lca(Node* node, int d1, int d2) {

        vector<int> n2rp1 = nodeToRoot(node, d1);
        vector<int> n2rp2 = nodeToRoot(node, d2);

        int i = n2rp1.size() - 1;
        int j = n2rp2.size() - 1;
        int res = -1;
        while(i >= 0 && j >= 0 && n2rp1.at(i) == n2rp2.at(j)) {
            res = n2rp1.at(i);
            i--;
            j--;
        }

        return res;
    
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

cout<<gtree::lca(root,d1,d2)<<endl;


}
