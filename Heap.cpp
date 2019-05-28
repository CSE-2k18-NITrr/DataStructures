/**********************************************
*Code By: pratibha_899 (Pratibha Shrivastav) *
***********************************************/

// Min heap implementation 

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//All the Loops and defines required
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

//All the declarations using typedef

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<long long int> VL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;

class BHeap{

    VL heap;
    ll leftchild(ll parent);
    ll rightchild(ll parent);
    ll parent(ll child);
    void heapify_up(ll index);
    void heapify_down(ll index);

    public:
        void size();
        void insert(ll element);
        void deleteMin();
        void extractMin();
        void show_heap();

};

int main()
{
    BHeap bh;
    while(1){
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Minimum Element"<<endl;
        cout<<"3.Extract Minimum Element"<<endl;
        cout<<"4.Show Heap"<<endl;
        cout<<"5.Exit"<<endl;

        ll choice,e;
        cout<<"Enter your choice :\n";
        cin>>choice;
        switch(choice){

            case 1: cout<<"Enter the element to insert :\n";
            cin>>e;
            bh.insert(e);
            break;

            case 2: bh.deleteMin();
            break;

            case 3: bh.extractMin();
            break;

            case 4: bh.show_heap();
            break;

            case 5: exit(0);
            break;

            default: cout<<"Enter a valid choice\n";
        }
    }
    return 0;
}

ll BHeap::leftchild(ll parent){
    ll l=2*parent + 1;
    if(l<heap.size())
        return l;
    else
    {
        return -1;
    }
    
}

ll BHeap::rightchild(ll parent){
    ll l=2*parent + 2;
    if(l<heap.size())
        return l;
    else
    {
        return -1;
    }
    
}

ll BHeap::parent(ll child){
    if(child==0)
        return -1;
    else
    {
        return ((child-1)/2);
    }
    
}

void BHeap::heapify_up(ll index){
    if (index >= 0 && parent(index) >= 0 && heap[parent(index)] > heap[index]) {
      ll temp = heap[index];
      heap[index] = heap[parent(index)];
      heap[parent(index)] = temp;
      heapify_up(parent(index));
   }
}

void BHeap::heapify_down(ll index){
    ll leftc=leftchild(index);
    ll rightc=rightchild(index);
    if(leftc>=0 && rightc>=0 && heap[leftc]>heap[rightc])
        leftc=rightc;
    if(leftc>0 && heap[index]>heap[leftc]){
      ll temp = heap[index];
      heap[index] = heap[leftc];
      heap[leftc] = temp;
      heapify_down(leftc);
    }
}

void BHeap::size(){
    if(heap.size()>0){
        cout<<heap.size();
    }
    else
    {
        cout<<"Heap is empty\n";
    }
    
}

void BHeap::insert(ll element){
    heap.PB(element);
    heapify_up(heap.size()-1);
    cout<<"Element inserted\n";
}

void BHeap::deleteMin(){
    if(heap.size()==0){
        cout<<"Heap is empty\n";
        return;
    }
    heap[0]=heap[heap.size()-1];
    heap.pop_back();
    heapify_down(0);
    cout<<"Element deleted\n";
}

void BHeap::extractMin(){
    if(heap.size()==0){
        cout<<"Heap is empty\n";
        return;
    }
    cout<<heap.front()<<"\n";
}

void BHeap::show_heap(){
    if(heap.size()==0){
        cout<<"Heap is empty\n";
        return;
    }
    cout<<"Elements of heap are :\n";
    FOREACH(it,heap){
        cout<<*it<<" ";
    }
    cout<<"\n";
}