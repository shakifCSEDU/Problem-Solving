#include<bits/stdc++.h>
using namespace std;

vector<string>ans;


void solve(int open , int close , string s){
    
    if(open == 0){

        if(close == 0){
            ans.push_back(s);
            return;
        }

        for(int i = 0; i < close ; i++)
            s.push_back(')');
        
        ans.push_back(s);
        return;
    }


    if(open == close){

        s.push_back('(');
        solve(open-1 , close , s);

    }

    else{
        s.push_back('(');
        solve(open-1 , close , s);
        
        s.erase(s.size()-1);
        s.push_back(')');
        solve(open , close -1 , s);
    }

}

int32_t main(){
    int i,j,n,m;

    cin>>n;
    
    string s;

    solve(n,n,s);
    
    for(i = 0 ; i < ans.size() ; i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}