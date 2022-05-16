#include<bits/stdc++.h>
using namespace std;


int heights[1009];


int32_t main(){
    int i,j,n,m;
    
    cin>>n;
    for(i = 1 ; i <= n ; i++)cin>>heights[i];

    int pre[1009],post[1009];
    
    memset(post,0,sizeof(post));
    memset(pre,0,sizeof(pre));


    stack<pair<int,int> >st;  // value -- index

    
    for(i = 1 ; i <= n ; i++)
    {
        if(st.empty())st.push(make_pair(heights[i],i));

        while(!st.empty() && st.top().first > heights[i]){

            int top = st.top().first;
            int index = st.top().second;
            st.pop();
            post[index] = i-1;
        }
        st.push(make_pair(heights[i],i));
    }



    while(!st.empty()){
        int idx = st.top().second;
        st.pop();
        post[idx] = n; 
    }


    for(i = n ; i >= 1 ; i--){
        if(st.empty())st.push(make_pair(heights[i],i));

        while(!st.empty() && st.top().first > heights[i]){
            int index = st.top().second;
            st.pop();

            pre[index] = i+1; 
        }   
        st.push(make_pair(heights[i],i));
    }

    while(!st.empty()){
        int index = st.top().second;
        st.pop();
        pre[index] = 1;
    }
    
    int mx = -1;


    for(i = 1 ; i<=n ; i++){
        mx = max(mx , (heights[i]*(post[i]-i+1) + heights[i]*(i - pre[i])));
    }
    cout<<mx<<"\n";

return 0;
}