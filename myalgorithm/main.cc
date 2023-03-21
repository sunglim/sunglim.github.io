#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = nullptr;
            right = nullptr;
        }
};

class Solution {
public:
Node* insert(Node* root, int data) {
            if(root == nullptr) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
void levelOrder(Node * root) {
  std::vector<Node*> frontier;
  frontier.push_back(root);
  while(!frontier.empty()) {
    std::vector<Node*> next;
    for (auto* node : frontier) {
        std::cout << node->data << " ";
      if (node->left)
        next.push_back(node->left);
      if (node->right)
        next.push_back(node->right);
    }
    frontier = next;
  }
}
};

int main() {
  
    Solution myTree;
    Node* root = nullptr;

    root = new Node(1);
    root->left = new Node(2);
    root->right= new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.levelOrder(root);
    return 0;
}

*/

int main() {
  std::string aa = "fa";
  std::string aaa = "aabasdlkfjadsfljk";
  std::cout << aa.compare(aaa) << std::endl;
  std::cout << aaa.compare(aa) << std::endl;
  return 0;
}
