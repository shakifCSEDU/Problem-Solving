#include<bits/stdc++.h>
using namespace std;
#define int long long int

#define si(x) scanf("%d", &x)
#define sii(x,y) scanf("%d %d", &x,&y)


int32_t main(){
    int i,j,n,m,target;

    vector<int>vec;

    sii(n,target);
    int x;

    for(i = 0 ; i<n ; i++){
        si(x);
        vec.push_back(x);
    }

    unordered_map<int, int> m;
for (int i = 0; i < vec.size(); ++i) {
    if (m.find(target - vec[i]) == m.end()) { 
        m[nums[i]] = i;
        } 
        else {
        return {m[target - nums[i]], i};
        }
}
return {-1, -1}



    return 0;
}