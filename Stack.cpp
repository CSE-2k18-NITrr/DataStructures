/*
    Time Complexity [Stack]:
    - Access : O(n)
    - Search : O(n)
    - Insertion : O(1)
    - Deletion : O(1)

    Space Complexity: O(n)

 */
#include<bits/stdc++.h>

using namespace std;

template <class T>
struct node{
    T data;
    node* next;
};

class Stack
{
    public:
        node<int>  *top;
        
        Stack() { top = NULL; }

        node<int> *newNode(int data)
        {
            node<int> *temp = new node<int>;
            temp->data = data;
            temp->next = NULL;
            return temp;
        }

        void printStack()
        {
            node<int> *temp = top;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }

        void push(int data)
        {
            node<int> *topNode = newNode(data);
            topNode->next = top;
            top = topNode;
        }

        void pop()
        {
            node<int> *topNode = NULL;
            
            if(top == NULL)
            {
                cout<<"UNDERFLOW";
                return;
            }
            
            topNode = top;
            top = top->next;
            
            delete topNode;
        }

        int peekTop()
        {
            if(top == NULL)
                return -1;
            else
                return top->data;
        }
};

int main()
{
    int n,data;
    Stack stack;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        stack.push(data);
    }

    cout<<"Stack after each step of pop:\n";
    stack.printStack();
    
    do{
        cout<<"\nNow deleting first node:"<<stack.peekTop()<<"\n";
        stack.pop();
        stack.printStack();
    }while(stack.top!=NULL);

    return 0;
}