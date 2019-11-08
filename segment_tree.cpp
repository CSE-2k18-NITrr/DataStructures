#include<bits/stdc++.h>
using namespace std;
int getSumUtil(int *, int , int ,int , int , int );
void updateValueUtil(int *, int , int , int, int , int );
int getMid(int s, int e) { return s + (e -s)/2; }

int constructSTUtil(int arr[], int ss, int se, int *st, int si){
if(ss==se){
    st[si] = arr[ss];
    return arr[ss];
}
int mid = getMid(ss, se);
st[si] = constructSTUtil(arr , ss ,mid , st , 2*si + 1) + constructSTUtil(arr , mid+1 , se ,st ,2*si+2);
return st[si];
}
int *constructST(int arr[] , int n){
int height = (int)(ceil(log2(n)));
int max_size  = 2*(int)pow(2 ,  height) - 1;
int *st = new int[max_size];
constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}
int getSum(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input";
        return -1;
    }

    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
int getSumUtil(int *st, int ss, int se,int qs, int qe, int si){
if(qs <= ss && qe >= se)
    return st[si];
if (se < qs || ss > qe)
    return 0;
int mid = getMid(ss, se);
return getSumUtil(st, ss, mid, qs, qe, 2*si+1) ^
     getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        cout<<"Invalid Input";
        return;
    }

    // Get the difference between new value and old value
    int diff = new_val - arr[i];

    // Update the value in array
    arr[i] = new_val;

    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
    // Base Case: If the input index lies outside the range of
    // this segment
    if (i < ss || i > se)
        return;

    // If the input index is in range of this node, then update
    // the value of the node and its children
    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
    }
}

int main(){
 int arr[] = {1, 3, 5, 7, 9, 11};
  int n = sizeof(arr)/sizeof(arr[0]);
int *st = constructST(arr, n);
 cout<<"Sum of values in given range = "<<getSum(st, n, 1, 3)<<endl;

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    updateValue(arr, st, n, 1, 10);

    // Find sum after the value is updated
    cout<<"Updated sum of values in given range = "
            <<getSum(st, n, 1, 3)<<endl;
    return 0;
}
