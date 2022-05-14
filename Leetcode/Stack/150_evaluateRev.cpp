#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int i,j,n;
    
    
    vector<string>s;
    
    cin>>n;
    string x;

    for(i = 0 ; i < n ; i++){
        cin>>x;
        s.push_back(x);
    }
    
    stack<int>st;
    int cal;

    for(int i=0; i<s.size(); ++i){
            if(s[i] != "+" && s[i] != "-" && s[i] != "*" && s[i] != "/"){
                st.push(stoi(s[i]));
            }
            else{
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                
                if(s[i] == "+"){
                    cal = op1 + op2;
                }
                else if(s[i] == "-"){
                    cal = op2 - op1;
                }
                else if(s[i] == "*"){
                    cal = op1 * op2;
                }
                else{
                    cal = op2/op1;
                }
                st.push(cal);
            } 
        }

cout<<st.top();

    
    

    return 0;
}