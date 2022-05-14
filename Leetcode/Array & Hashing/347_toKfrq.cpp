#include<bits/stdc++.h>
using namespace std;


int32_t main(){
        int x,i,j,n,m,k;

        cin>>n>>k;
        vector<int>nums;



        for(i = 0 ; i < n ; i++){
            cin>>x;
            nums.push_back(x);
        }

       
        
        int len = nums.size();
        
        
        map<int,int>x;

        
        for(auto & i : nums)x[i]++;
        
        vector<pair<int,int>>vec;
        
        for(auto it = x.begin() ; it != x.end() ; ++it){
            vec.push_back({it->second,it->first});
        }
        
        sort(vec.begin(), vec.end() , greater<pair<int,int>>());
        
        vector<int>ans;
        
        for(int i = 0 ; i<k ; i++){
            ans.push_back(vec[i].second);    
        }
       
    for(i =0  ; i<ans.size() ; i++)cout<<ans[i]<<" ";
    return 0;
}