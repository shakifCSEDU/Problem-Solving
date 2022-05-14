// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define si(x) scanf("%lld",&x)
#define sii(x,y) scanf("%lld %lld",&x,&y)
#define out(x) printf("%lld\n",x)


int a[100009];
vector<vector<int> >ans;



void solve(int index , int n , int sum , vector<int>res){
    ans.push_back(res);
    
    for(int i = index; i < n; i++){
        
        if(i != index && a[i] == a[i-1])continue;
        
        res.push_back(a[i]);
        res.pop_back();
    }

}

int32_t main(){
    
    
    int i,j,n,m;
    si(n);
    for(i = 0 ; i <n ; i++)si(a[i]);

    sort(a , a + n);
    vector<int>res;

    solve(0 , n , 0,res);
    return 0;
}

