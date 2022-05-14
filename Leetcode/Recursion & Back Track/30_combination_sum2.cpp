#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define si(x) scanf("%lld",&x)
#define sii(x,y) scanf("%lld %lld",&x,&y)
#define out(x) printf("%lld\n",x)


int a[100009];

vector<vector<int> >ans;


void solve(int index , int n , int target , vector<int>res){
    
    if(target == 0){
        ans.push_back(res);
        return;
    }

    for(int i = index ; i < n ; i++){
        
        if(i>index && a[i] == a[i-1])continue;

        if(a[i] > target)break;

        res.push_back(a[i]);

        solve(index + 1 , n , target - a[i] , res);
        res.pop_back();
    }
}

int32_t main(){
    
    int i,j,n,m,target;
    
    sii(n,target);
    
    
    for(i = 0; i < n ; i++){
        si(a[i]);

    }
    
    sort(a , a + n);

    vector<int>res;
    
    solve(0 , n , target , res);
    
    for(i = 0 ; i< ans.size(); i++){
        
        for(j = 0 ; j < ans[i].size() ; j++){
            printf("%lld ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}