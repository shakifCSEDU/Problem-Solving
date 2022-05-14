// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define si(x) scanf("%lld",&x)
#define sii(x,y) scanf("%lld %lld",&x,&y)
#define out(x) printf("%lld\n",x)

int a[1000];
vector<vector<int> >ans;


void solve(int index,int n,map<int,bool>mark,vector<int>res)
{
    if(index == n)ans.push_back(res);

    for(int i = 0 ; i<n ; i++){
        int x = a[i];

        if(!mark[x]){
            mark[x] = true;
            res.push_back(x);
            solve(index + 1 , n , mark,res);
            mark[x] = false;
            res.pop_back();
        }
    }
}



int32_t main(){
    
    
    int i,j,n,m,cs,test;
    
    si(n);
    for(i = 0 ; i < n ; i++)si(a[i]);

    map<int,bool>mark;

    for(i = 0 ; i < n ; i++)
        mark[i] = false;

    vector<int>res;

    solve(0,n,  mark,res);

    for(i = 0 ; i < ans.size() ; i++)
    {
        for(j = 0 ; j<ans[i].size() ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }



    return 0;
}