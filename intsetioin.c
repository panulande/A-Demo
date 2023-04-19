#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node{
    struct Node* left;
    struct Node* right;
    int data;

};

int searchNode(struct Node* root, int key){
    if(root==NULL){
        return 0;
    }
    if(root->data==key){
        return 1;
    }
    else if(key<root->data){
        searchNode(root->left,key);
    }
    else{
        searchNode(root->right,key);

    }



    

}
int insertion(struct Node* root, int data){
    
}

struct Node* createNode( int data){
    struct Node* node=(struct Node* )malloc(sizeof(struct Node));
    node->left=NULL;
    node->right=NULL;
    node->data=data;
    return node;

}
int main(){
    struct Node* root=createNode(20);
    struct Node* p1=createNode(10);
    struct  Node* p2=createNode(35);
    struct  Node* p3=createNode(5);
    struct Node* p4=createNode(15);
    struct Node* p5=createNode(25);
    struct Node* p6=createNode(40);

    root->left=p1;
    root->right=p2;
    root->left->left=p3;
    root->left->right=p4;
    root->right->left=p5;
    root->right->right=p6;

    printf("%d",searchNode(root,1));

    return 0;
}