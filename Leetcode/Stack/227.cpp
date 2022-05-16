#include<bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if(ch == '+' || ch == '-')return 1;
    else return 2;
}


int32_t main(){
    int i,j,n;
    
    string s;
    getline(cin,s);

    int len = s.size();
    
    stack<char>opertr;
    stack<int>operand;


    int tmp = 0;

    for(i = 0 ; i < len ; i++){
        
        
        if(s[i] == ' ')continue;

        if( s[i] == '+' || s[i] == '-' || s[i] =='*' || s[i] == '/' ){
            
            operand.push(tmp);
            tmp = 0;

            while(!opertr.empty() && precedence(opertr.top())  >= precedence(s[i])){
                char ch = opertr.top();
                opertr.pop();
                
                int num2 = operand.top();
                operand.pop();
                
                int num1 = operand.top();
                operand.pop();

                if(ch == '+')operand.push(num1+num2);
                else if(ch  == '-')operand.push(num1 - num2);
                else if(ch == '*')operand.push(num1*num2);
                else operand.push(num1/num2); 
            }
        opertr.push(s[i]);


        }
        if(s[i] >= '0' && s[i] <= '9'){
            tmp = tmp *10 + (s[i] - '0');

        }
    }
    
    operand.push(tmp);


   while(!opertr.empty()){

       char ch = opertr.top();
       opertr.pop();
       
       int op2 = operand.top();
       operand.pop();

       int op1 = operand.top();
       operand.pop();

       if(ch == '+')operand.push(op1 + op2);
       else if(ch == '-')operand.push(op1 - op2);
       else if(ch == '*')operand.push(op1 * op2);
       else operand.push(op1/op2);
   }

   while(!operand.empty()){
       cout<<operand.top();
       operand.pop();
   } 

    return 0;
}