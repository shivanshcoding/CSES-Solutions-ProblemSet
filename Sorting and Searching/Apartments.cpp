#include<bits/stdc++.h>
using namespace std;
vector<int> people;
vector<int> apart;
int main(){
    int n, m, k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int ch;
        cin>>ch;
        people.push_back(ch);
    }
    for(int i=0;i<m;i++){
        int ch;
        cin>>ch;
        apart.push_back(ch);
    }
    sort(people.begin(),people.end());
    sort(apart.begin(),apart.end());
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i<n and j<m){
        if(apart[j] >= people[i]-k and apart[j] <= people[i]+k){
            ans++;
            j++;
            i++;
        }else if(apart[j]<people[i]-k){
            j++;
        }else{
            i++;
        }
    }
    cout<<ans;
    return 0;
}
