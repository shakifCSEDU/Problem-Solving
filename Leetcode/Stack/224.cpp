#include<bits/stdc++.h>
using namespace std;


int32_t main(){
    int i,j,n,m;
    string s;
    
    getline(cin,s);
    int len = s.length();
    
    stack<char>st;


    for(i = 0 ; i < len ; i++){
        if(s[i] == ' ')continue;
        if(!st.empty() && s[i] == ')'){
           
            while(!st.empty()){
                
                char ch = st.top();
                st.pop();

                if(ch == '(')break;
                
                int operand2 = ch - '0';
                
                ch = st.top();
                char operatr = ch;
                st.pop();

                ch = st.top();
                int operand1 = ch-'0';
                st.pop();
                
                if(operatr == '+'){
                    int ans = operand1 + operand2;
                    st.push(ans);
                }
                else if(operatr == '-'){
                    int ans = operand1 - operand2;
                    st.push(ans);
                }

            }
        }
        else{
            st.push(s[i]);
        }
    }
    
    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }

    return 0;
}