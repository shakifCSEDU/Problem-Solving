#include<bits/stdc++.h>
using namespace std;


vector<int>vec;

vector<int> solution1(int n){

        int cnt = 0 ;
        int prod = 1;
        int i,j;
        
       for(i = 0 ; i < n ; i++){
        
       int x = vec[i];
        
        if(x == 0 )
            cnt++;
        else
            prod *= x;
    }
        
         vector<int>ans;


    if(cnt >1){
        for(i = 0 ; i < n ; i++)ans.push_back(0);

    }
    else if(cnt == 1){

        for(i = 0 ; i < n ; i++)
        {
            if(vec[i] != 0)ans.push_back(0);
            else ans.push_back(prod);
        }
    }
    else{
        for(i = 0 ; i < n ; i++){
            
            if(vec[i] == 0)
                ans.push_back(0);
            
            else{
                ans.push_back(prod / vec[i]);
            }
        }
    }
        
        return ans;
}



vector<int> solution2(int n){
    int i,j;

    vector<int> pre_mul , post_mul;
    
    pre_mul.resize(n+1);
    post_mul.resize(n+1);


    pre_mul[0] = 1;
    post_mul[n-1] = 1;


    for(i = 1 ; i < n ; i++){

        pre_mul[i]  = pre_mul[i-1] * vec[i -1];
    }

    for(i = n-2 ; i>=0 ; i--){
        post_mul[i] = post_mul[i+1]* vec[i+1];
    }

    vector<int>ans;


    for(i = 0 ; i < n ; i++){
        int x = pre_mul[i] * post_mul[i];
        ans.push_back(x);
    }
    return ans;
}

int32_t main(){
    int i,j,n,x;

    cin>>n;

    for(i = 0 ; i < n ; i++){
        
        cin>>x;
        vec.push_back(x);
    }
    
    //solution1(n);

    vector<int>ans =  solution2(n);
    
    for(i = 0 ; i < ans.size() ; i++)
        cout<<ans[i]<<" ";
    
    return 0;
}