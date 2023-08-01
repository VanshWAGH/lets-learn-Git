#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:

    char data;
    vector<Node*> children;

    Node(char data){
        this->data = data;
    }
};

void preorderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    for(Node* child: root->children){
        preorderTraversal(child);
    }
    return;
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    int childNodes = root->children.size();
    for(int i = 0; i < childNodes-1; i++){
        inorderTraversal(root->children[i]);
    }

    cout<<root->data<<" ";
    if(childNodes > 0){
        inorderTraversal(root->children[childNodes-1]);
    }

    return;
}

void postorderTraversal(Node* root){

    if(root == NULL){
        return;
    }

    for(Node* child: root->children){
        postorderTraversal(child);
    }
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*>q;

    q.push(root);

    while(!q.empty()){
        int currentLevelNodes = q.size();
        while(currentLevelNodes--){
            Node* curr = q.front();
            q.pop();
            cout<<curr->data<<" ";
            for(Node* child : curr->children){
                q.push(child);
            }
        }
    }
    cout<<endl;
}

int main(){

    Node* root = new Node('A');
    root->children.push_back(new Node('B'));
    root->children.push_back(new Node('C'));
    root->children.push_back(new Node('d'));
    root->children.push_back(new Node('e'));
    root->children.push_back(new Node('f'));

    cout<<root->data<<endl;
    cout<<"children of root node are:";

    for(Node *child: root->children){
        cout<<child->data<<" ";
    }

    cout<<endl;

    cout<<"preorderTraversal :"<<endl;

    preorderTraversal(root);

    cout<<endl;

    cout<<"inorderTraversal :"<<endl;

    inorderTraversal(root);

    cout<<endl;

    cout<<"postorderTraversal :"<<endl;

    postorderTraversal(root);
    cout<<endl;

    cout<<"levelOrderTraversal :"<<endl;

    levelOrderTraversal(root);

    
    return 0;
}