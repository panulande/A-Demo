#include<stdio.h>
#include<stdlib.h>
#include <stdarg.h>
#include <time.h>

struct Node{
    struct Node* left;
    struct Node* right;
    int data;
};
int maxheight(struct Node* root){
    if(root==NULL){
        return 0;

    }
    else{
        int leftdep=maxheight(root->left);
        int rightdep=maxheight(root->right);

        if(leftdep>rightdep){
            return leftdep+1;
        }
        else{
            return rightdep+1;
        }

    }
    
}
int isBST(struct  Node* root){
    struct Node* prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev !=NULL && root->data<=prev->data){
            return 0;
        }
        root=prev;
        return isBST(root->right);
        }


    }
    else{
        return 1;
    }
}



struct Node* createNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
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


    
    
    

    
    return 0;
}