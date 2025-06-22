#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;

    if(preorder[idx] == -1){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);   //LEFT
    root->right = buildTree(preorder);  //RIGHT
    // Time Complexity = O(n)
    return root;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    // Time Complexity = O(n)
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    // Time Complexity = O(n)
}


void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

    // Time Complexity = O(n)
}

int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    preOrder(root);                    //Pre-Order Traversal
    cout<<endl;   

    inOrder(root);                     //In-Order Traversal
    cout<<endl;  

    postOrder(root);                   //Post-Order Traversal
    cout<<endl;  
    return 0;
}
