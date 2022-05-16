#include<bits/stdc++.h>
using namespace std;


int32_t main(){
    int i,j,n;
    
    string s;
    
    
    cin>>s;
    sort(s.begin() , s.end());
    int len = s.size();
    s.push_back('.');

    string res;

    for(int i = 0 ; i<len ; i++){
    
        if(s[i] == s[i+1])continue;
        
        res.push_back(s[i]);
    }
    cout<<res<<"\n";

    return 0;
}