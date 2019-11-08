#include<bits/stdc++.h>
using namespace std;
int height(struct node*);
int getWidth(struct node*  , int );
struct node {
int data;
struct node* left, *right ;
node(int data){
this->data = data;
left = right = NULL;
}
};
int getMaxWidth(struct node* root){
int maxWidth = 0;
int width;
int h = height(root);
for(int i=1;i<=h;i++){
    width = getWidth(root , i);
    if(width > maxWidth)
        maxWidth = width;
}
return maxWidth;
}
int getWidth(struct node* root , int l){
if(root == NULL)
    return 0;
if(l == 1)
{
    return 1;
}
else if(l > 1)
return getWidth(root->left , l-1)+getWidth(root->right,l-1);
}
int height(struct node* node){
if(node == NULL)
    return 0;
int lheight , rheigth ;
lheight = height(node->left);
rheigth = height(node->right);

return max(lheight +1 , rheigth + 1);

}
int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(8);
    root->right->right->left = new node(6);
    root->right->right->right = new node(7);

    /*
    Constructed bunary tree is:
            1
            / \
         2        3
        / \        \
        4 5          8
                    / \
                    6 7

            width means max no of elements in any given level
    */
    cout<<"Maximum width is "<< getMaxWidth(root)<<endl;
    return 0;
}
