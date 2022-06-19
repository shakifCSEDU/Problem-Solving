#include<bits/stdc++.h>
using namespace std;
#define int long long int

#define si(x) scanf("%lld", &x)
#define sii(x,y) scanf("%lld %lld",&x,&y)
#define out(x) printf("%lld",x)
#define line printf("\n");



int32_t main(){
    int i,j,n,m,k,x;
    sii(n,k);

    vector<int>vec;

    for(i = 0 ; i < n ; i++){
        si(x);
        vec.push_back(x);
    }

    
    //priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    priority_queue<pair<int,int> > pq;

    for(i = 0 ; i<k-1 ; i++){
        pq.push(make_pair(vec[i] , i));
    }
    
    vector<int>res;

    for(i = k-1 ; i<n ; i++){
        
        pq.push(make_pair(vec[i] , i));
        
        while(pq.top().second  < i-k+1){
            //cout<<pq.top().second<<" "<<pq.top().first<<endl;
            pq.pop();

        }
        res.push_back(pq.top().first);
    }
    for(i = 0 ; i < res.size() ; i++){
        cout<<res[i]<<" ";
    }


    return 0;
}