#include<bits/stdc++.h>
using namespace std;

vector<int>vec[2009];
int in[2009];


void kahn(int n){
    vector<int>res;
    queue<int>q;

    for(int i = 0; i < n; i++){
        if(in[i] == 0)
            q.push(i);
    }

    bool flag  = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        res.push_back(u);
        if(res.size() > n){
            flag  = false;
            break;
        }
        for(int i = 0 ; i<vec[u].size() ; i++){
            int v = vec[u][i];
            in[v]--;
            if(in[v] == 0){
                q.push(v);
            }
        }
    }
    if(flag && res.size() == n){
        reverse(res.begin(),res.end());
        for(int i = 0 ; i<res.size() ; i++)cout<<res[i]<<' ';
        cout<<"\n";
    }
    else cout<<"0\n";
}


int32_t main(){
    int i,j,n,m;

    cin>>n>>m;
    int u,v;
    memset(in,0,sizeof(in));

    for(i = 0 ; i < m ; i++){
        cin>>u>>v;    
        vec[u].push_back(v);    
        in[v]++;
    }

    kahn(n);
    return 0;
}