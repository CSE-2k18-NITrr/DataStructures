/*
    Time Complexity [Binary Tree]:
    - Access : O(n)
    - Search : O(n)
    - Insertion : O(n)
    - Deletion : O(n)

    Space Complexity: O(n)

 */

#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* newNode(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class BinaryTree{
    public:
        node* root;
        BinaryTree()
        {
            root = NULL;
        }

        void insertNode(int data)
        {
            node* nodeInsert = newNode(data);
            queue <node*> nodeQueue;
            
            if(root==NULL)
            {
                root = nodeInsert;
                return;
            }
            
            nodeQueue.push(root);

            while(!nodeQueue.empty())
            {
                node* temp = nodeQueue.front();
                nodeQueue.pop();

                if(temp->left!=NULL)
                    nodeQueue.push(temp->left);
                else
                {
                    temp->left = nodeInsert;
                    return;
                }
                if(temp->right!=NULL)
                    nodeQueue.push(temp->right);
                else
                {
                    temp->right = nodeInsert;
                    return;
                }
            }
        }
};

int main()
{
    BinaryTree tree;
    
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        tree.insertNode(temp);
    }

    return 0;
}