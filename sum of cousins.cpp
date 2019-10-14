#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *left, *right;
};

// A utility function to create a new
// Binary Tree Node
struct Node* newNode(int item)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

int findCousinSum(struct Node* root,int k){
if(root == NULL)
    return -1;
if(root->data == k)
    return -1;
int curr_sum = 0;
int size;
queue<Node*> q;
q.push(root);
bool found = false;
while(!q.empty()){

    if(found == true)
        return curr_sum;
    size = q.size();
    curr_sum = 0 ; // sum of current level
    while(size){
        root = q.front();
        q.pop();
        if(root->left->data == k || root->right->data == k){
            found = true;
        }
        else{
            if(root->left){
                curr_sum += root->left->data;
                q.push(root->left);
            }
            if(root->right){
                curr_sum += root->right->data;
                q.push(root->right);
            }
        }
        size--;
    }
}
return -1;
}
int main()
{
    /*
                1
              /  \
             3    7
           /  \  / \
          6   5  4  13
             /  / \
            10 17 15
    */

    struct Node* root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(6);
    root->left->right = newNode(5);
    root->left->right->left = newNode(10);
    root->right->left = newNode(4);
    root->right->right = newNode(13);
    root->right->left->left = newNode(17);
    root->right->left->right = newNode(15);

    cout << findCousinSum(root, 13) << "\n";

    cout << findCousinSum(root, 7) << "\n";
    return 0;
}
