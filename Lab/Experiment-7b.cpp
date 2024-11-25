#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    
    node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};
    node* buildtree(node* root){
    cout << "enter the data for node " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data==-1){
        return NULL;
    } 

    cout <<"enter the data for inserting in left of  " <<data << endl;
    root->left=buildtree(root->left);

    cout <<"enter the data for inserting in right of  " <<data << endl;
    root->right=buildtree(root->right);
    return root;
    
}

void postorder(node* root){
    // base case
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}


int main()
{
    node* root = NULL;

    // creation of new tree
    root = buildtree(root);

    //leverl order
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout << "postorder traversal is " << endl;
    postorder(root);

    return 0;

}