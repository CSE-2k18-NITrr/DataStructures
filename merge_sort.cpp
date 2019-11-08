#include<bits/stdc++.h>
#define ll long long int
using namespace std;
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
ll merge(ll arr[], ll l, ll m, ll r)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 =  r - m;

    /* create temp arrays */
    ll L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    ll count = 0;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            count+=m-l;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count;
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
ll mergeSort(ll arr[], ll l, ll r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        ll m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        ll ans = merge(arr, l, m, r);
        return ans;
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */

/* Driver program to test above functions */
int main()
{   ll t;
    cin>>t;
    while(t--){
    ll  n;
    cin>>n;
    ll arr[n];
    for(ll i = 0 ; i < n ; i++)
        cin>>arr[i];
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout<<mergeSort(arr ,0, arr_size -1);
    }

    return 0;
}
