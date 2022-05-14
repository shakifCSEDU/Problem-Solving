#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define si(x) scanf("%lld",&x)
#define sii(x,y) scanf("%lld %lld",&x,&y)
#define out(x) printf("%lld\n",x)


int a[1009];
vector<int>subset_sum;

void solve(int index , int n,intt sum){
    if(index == n){
        subset_sum.push_back(sum);
    }
    solve(index + 1 , n , sum + a[index]);
    solve(index + 1 , n , sum);
}



int32_t main(){
    
    int i,j,n,m;
    
    si(n);
    
    for(i = 0 ; i<n ; i++)si(a[i]);

    solve(0,n,0);
    return 0;
}
