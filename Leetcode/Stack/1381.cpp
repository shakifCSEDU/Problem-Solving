#include<bits/stdc++.h>
using namespace std;

class CustomStack{
    int sz,top;
    vector<int> st;
    
    CustomStack(int maxSize){
        sz = maxSize;
        st.resize(sz);
        top = -1;
    }
    void Push(int x){
        if(top < sz-1){
            top++;
            st[top] = x;
        }
    }
    int pop(){
        if(top <= -1)
        return -1;
        int temp = top;
        top--;
        return st[temp];
    }

    void increment(int k , int val){
        int mn = min(k-1 , top);
        
        for(int i = 0; i < mn; i++){
            st[i] += val;
        }
    }
};

int main(){

    int i,j,n,m;
    
    return 0;
}