#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll countSetBits(ll n)
{
    // base case
    if (n == 0)
        return 0;

    else

        // if last bit set add 1 else add 0
        return (n & 1) + countSetBits(n >> 1);
}
int main(){
ll x;
cin>>x;
ll sum = countSetBits(x);
cout<<sum<<endl;
return 0;
}
