#include<bits/stdc++.h>
using namespace std; 



int32_t main(){
    int i,j,n,m;


    string s;
    
    getline(cin,s);

    int len = s.size();


    stack<char>st;
    
    bool flag = true;

    for(i = 0 ; i < len ; i++){
        
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(st.size() == 0){
                flag = false;
                break;
            }
            else if(s[i] == ')' && st.top() == '(')st.pop();
            else if(s[i] == '}' && st.top() == '{')st.pop();
            else if(s[i] == ']' && st.top() == '[')st.pop();
            else{
                flag = false;
                break;
            }
                
        }
    }
    if(!st.empty()){
        flag = false;
    }

    if(flag)cout<<"true\n";
    else cout<<"false\n";

    return 0;
}