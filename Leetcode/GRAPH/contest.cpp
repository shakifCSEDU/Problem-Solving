#include<bits/stdc++.h>
using namespace std;
#define int long long int

#define si(x) scanf("%lld", &x)
#define sii(x,y) scanf("%lld %lld",&x,&y)
#define out(x) printf("%lld",x)
#define line printf("\n");
int a[1000009];

int solve(int pos , int n , int k , int sum){
    if(pos > n){
        return sum;
    }
    
    int mx = -1;


    for(int i = 1; i <= 1000009 ; i++){
        if(k-a[i] < 0)break;

        int ans = solve(pos+1, n ,k-a[i],sum+i );
        mx = max(mx,ans);
    }
    return mx;
}


int32_t main(){
    int i,j,n,m,k;
    int test;
    int x,y;

    si(test);
    while(test--){
       sii(n,k);
       int val = 2;
        a[0] = 0;
        a[1] = 1;

       for(i = 2;i<1000009 ; i++){
           
           a[i] = a[i-1] + val;
           val*=2;
       
       } 
       

       int ans = 2*solve(1,(n+1)/2,(k+1)/2,0);
       printf("%lld\n",ans); 

    }
   
    return 0;
}