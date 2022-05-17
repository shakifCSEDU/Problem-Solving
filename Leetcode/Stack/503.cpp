#include<bits/stdc++.h>
using namespace std;


int main(){
    int x,i,j,n;
    cin>>n;

    vector<int>vec;
   
    for(i = 0 ; i < n ; i++){
        cin>>x;
        vec.push_back(x);
    }
    for(i = 0 ; i < n ; i++){
        vec.push_back(vec[i]);
    }
    
    vector<int>ans;
    
    ans.assign(n,-1);
    stack<pair<int,int> >st;


    for(i = 0 ; i < 2*n ; i++){


        if(st.empty())st.push(make_pair(vec[i],i));
        
        while(!st.empty() && st.top().first < vec[i]){
            
            int top = st.top().first;
            int index = st.top().second;
            st.pop();
            ans[index] = vec[i];
        }
        st.push(make_pair(vec[i],i));
    }

    for(i = 0 ; i < n ; i++)cout<<ans[i]<<" ";


    return 0;
}