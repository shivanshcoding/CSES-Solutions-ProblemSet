#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int n = s.size();
    int ans = 0;
    int i = 0;
    int j = 0;
    while(j<n){
        if(s[j]==s[i]){
            j++;
        }else{
            ans = max(ans,j-i);
            i = j;
        }
    }
    ans = max(ans,j-i);
    cout<<ans;
    return 0;
}
