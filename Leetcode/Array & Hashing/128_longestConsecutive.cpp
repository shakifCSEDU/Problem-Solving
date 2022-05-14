#include<bits/stdc++.h>
using namespace std;



int32_t main(){
    int i,j,n,m;
    cin>>n;
    
    vector<int>vec;

    for(i = 0 ; i < n ; i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    int cnt = 1 ;
    int mx = -1;

    for(i = 0 ; i < n-1 ; i++){
        
        if(vec[i] == vec[i+1])continue;

        if(vec[i+1] - vec[i] == 1)cnt++;
        
        else cnt = 1;

        mx = max(mx,cnt);
    }
    cout<<mx<<"\n";

    return 0;
}