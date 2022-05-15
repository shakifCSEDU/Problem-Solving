#include<bits/stdc++.h>
using namespace std;

int a[1009];

int32_t main(){


    int i,j,n,m;


    cin>>n;
    for(i = 0 ; i < n ; i++)cin>>a[i];


    vector<int>ans;

    ans.resize(n);
    ans.assign(n,0);

    stack<pair<int,int> >st;
    
    for(i = 0 ; i < n ; i++)    
    {
        if(st.empty())st.push(make_pair(a[i],i));

        else{

            int top = st.top().first; 
            int index = st.top().second;
            
            if(top < a[i]){
                st.pop();
                ans[index] = i-index;
                while(!st.empty()){
                    int top1 = st.top().first;
                    int index1 = st.top().second;
                    if(top1 < a[i]){
                        st.pop();
                        ans[index1] = i - index1;
                    }else break;
                }
            }
            st.push(make_pair(a[i] , i));
        }
    }
    for(i = 0 ; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}