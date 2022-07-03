#include<bits/stdc++.h>
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


    

    static void Traversal(Node* root) {
        
        string str = "Node Pre " + to_string(root->data);
        cout<<str<<endl;
        for(Node* child: root->children){
            cout<<"Edge Pre "<<to_string(root->data)<<"--"<<to_string(child->data)<<endl;
            Traversal(child);
            cout<<"Edge Post "<<to_string(root->data)<<"--"<<to_string(child->data)<<endl;
        }
        str = "Node Post " + to_string(root->data);
        cout<<str<<endl;
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
    
    
    static void levelOrderLinewiseZZ(Node* node){
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



    static void IterativePreandPostOrder(Node* node) {
    // write your code here
    stack<pair<Node*, int>> st;

        st.push({node,0});

        vector<int> pre;
        vector<int> post;

        while(st.size()>0) {
            pair<Node*, int> p = st.top();
            if(p.second == 0) {
                pre.push_back(p.first->data);
                p.second++;
            } else if(p.second <= p.first->children.size()) {
                Node* child = p.first->children[p.second - 1];
                p.second++;
                st.push(make_pair(child,0));
            } else {
                post.push_back(p.first->data);
                st.pop();
            }
        }

        for(int val : pre) {
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
vector<int> v(n);

for(int i=0; i<v.size(); i++){
    cin>>v[i];
}

Node* root = gtree::construct(v);
gtree::levelOrderLinewiseZZ(root);


}
