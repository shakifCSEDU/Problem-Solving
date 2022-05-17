#include<bits/stdc++.h>
using namespace std;


int32_t main(){
    int i,j,n;

    stack<char>st;
    
    string s;
    
    cin>>s;
    int len = s.size();

  stack<char> st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(st.empty())
                    count++;
                else if(st.top()=='(')
                      st.pop();
                else
                    st.push(s[i]);
            }
            else if(s[i]=='(')
                st.push(s[i]);
        }

    cout<<st.size() + count;

    
}