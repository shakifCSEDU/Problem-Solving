#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define si(x) scanf("%lld",&x)
#define sii(x,y) scanf("%lld %lld",&x,&y)
#define out(x) printf("%lld\n",x)


int a[100009];

vector<vector<int> >ans;

void solve(int index , int n , vector<int>&res , int target){
    
    if(index == n)return;

        if(target == 0){
            ans.push_back(res);
            return;
        }
        
    if(a[index] <= target){

        res.push_back(a[index]);
        solve(index , n, res , target - a[index]);
        res.pop_back();
      
    }
    solve(index +1  , n , res , target);
}

int32_t main(){
    int i,j,n,m,target,cs,test;
    
    sii(n,target);
    
    for(i = 0 ; i < n ; i++){
        si(a[i]);
    }

    vector<int>res;
 
    solve(0,n,res,target);

    for(i = 0 ; i < ans.size() ; i++){

        for(j = 0 ; j < ans[i].size() ; j++){
        
            printf("%lld ",ans[i][j]);
        
        }
        printf("\n");
    }
    return 0;
}
