// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
#include<bits/stdc++.h>
using namespace std;


int32_t main(){
    
    int i,j,n,m;
    string x;

    vector<string>vec;
    
    map<string,vector<string> > mp;
    map<string,vector<string> >:: iterator it;
    
    cin>>n;
    
    for(i = 0 ; i < n ; i++){
        cin>>x;
        vec.push_back(x);
        sort(x.begin(),x.end());
        mp[x].push_back(vec[i]);
    }

    vector<vector<string> >v;

     for(it=mp.begin() ; it != mp.end() ; it++){
            v.push_back(it->second);
    }

    for(i = 0 ; i < v.size() ; i++){
        for(j = 0 ; j< v[i].size() ; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }



    return 0;
}