#include<iostream>
  #include<vector>
  #include<bits/stdc++.h>
  using namespace std;
  
  // TreeNode class for a node of a Binary Search Tree
  class TreeNode {
      public:
  	  int val;
  	  TreeNode* left;
  	  TreeNode* right;
  
  	  TreeNode(int x) {
  	  	  val = x;
          left = NULL;
          right = NULL;
  	  }
  };
  
  // utility function to display a binary tree
  void display(TreeNode* node) {
      if (node == NULL) {
          return;
      }
      string str = "";
  
      str += node->left == NULL ? "." : to_string(node->left->val);
      str += " <= " + to_string(node->val) + " => ";
      str += node->right == NULL ? "." : to_string(node->right->val);
  
      cout<<str<<endl;
  
      display(node->left);
      display(node->right);
  }
  
  class BinaryTree {
      public: 
      static int heightForDiameter(TreeNode* root) {
          //Write your code here
          if(root == NULL) return -1;
        
        int lh = heightForDiameter(root->left);
        int rh = heightForDiameter(root->right);

        diameter = std::max(diameter, lh + rh + 2);

        return std::max(lh, rh) + 1;
  	  }
  	  
  	  
  	static int diameter;
  	
  	static int diameterOfBinaryTree(TreeNode* root) {

        heightForDiameter(root);
        return diameter;
    }

  };
  
  int BinaryTree::diameter = 0;
  
  //Don't change code of utility function.
  TreeNode* stringToTreeNode(string &input) {
      int first = input.find_first_not_of(' ');
      int last = input.find_last_not_of(' ');
      input = input.substr(first, (last - first + 1));
      if (!input.size()) {
          return nullptr;
      }
  
      string item;
      stringstream ss;
      ss.str(input);
  
      getline(ss, item, ' ');
      TreeNode* root = new TreeNode(stoi(item));
      queue<TreeNode*> nodeQueue;
      nodeQueue.push(root);
  
      while (true) {
          TreeNode* node = nodeQueue.front();
          nodeQueue.pop();
          if (!getline(ss, item, ' ')) {
              break;
          }
  
          if (item != "null") {
              int leftNumber = stoi(item);
              node->left = new TreeNode(leftNumber);
              nodeQueue.push(node->left);
          }
  
          if (!getline(ss, item, ' ')) {
              break;
          }
  
          if (item != "null") {
              int rightNumber = stoi(item);
              node->right = new TreeNode(rightNumber);
              nodeQueue.push(node->right);
          
          }
      }
      return root;
  }
  
  int main(int argc, char** argv){
      string line;
      getline(cin, line);
      TreeNode* root = stringToTreeNode(line);
      BinaryTree bt;
      cout<<(BinaryTree::diameterOfBinaryTree(root))<<endl;
  }