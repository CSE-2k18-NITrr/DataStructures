#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    string str;
    cin>>str;
    if(str[0]=='1' || str[n-1]=='1'){
        cout<<2*n<<"\n";
    }
    else{
    bool flag = true;
    size_t found = str.find_first_of("1");
    int temp1 = 0 , temp2 = 0 , temp3 = 0 ,  temp4 = 0;
    if(found != string::npos){
       temp1 = found+1;
       temp2 = n - found ;
    }
    else{
        flag = false;
    }
     size_t found1 = str.find_last_of("1");
     if(found1 != string::npos){
        temp3 = found1 + 1;
        temp4 = n - found1  ;
     }
         temp1 = max(temp1 , temp2);
         temp3 = max(temp3 , temp4);
         temp1 = max(temp1 , temp3);
         if(!flag){
            cout<<n<<endl;
         }
         else{
            cout<<2*temp1<<endl;
         }
    }

}

return 0;
}
