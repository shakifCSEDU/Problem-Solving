// Given an integer array nums of unique elements, return all possible subsets (the power set).

//The solution set must not contain duplicate subsets. Return the solution in any order.
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define si(x) scanf("%lld",&x)
#define sii(x,y) scanf("%lld %lld",&x,&y)
#define out(x) printf("%lld\n",x)


int a[100009];

vector<vector<int> >ans;

void solve(int index , int n , vector<int>res){
    
    if(index >= n){
        ans.push_back(res);
        return;
    }

    res.push_back(a[index]);
    solve(index +1 , n , res);
    
    
    res.pop_back();
    solve(index + 1 , n , res);

}


int32_t main(){
    int i,j,n,m,q,test;
    si(n);


    for(i = 0 ; i < n ; i++){
        si(a[i]);
    }    

    vector<int>res;


    solve(0 , n, res);

    for(i = 0  ; i < ans.size()  ; i++){
        
        for(j = 0 ; j<ans[i].size() ; j++){
            printf("%lld ",ans[i][j]);

        }
        printf("\n");
    }

    out(ans.size());


    return 0;
}