#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    int i,j,n,m;
    int n1,n2;

    scanf("%d %d",&n1,&n2);
    int x;
    vector<int>vec1,vec2;

    for(i = 0 ; i < n1 ; i++){
        scanf("%d",&x);
        vec1.push_back(x);
    }

    for(i = 0 ; i < n2 ; i++){
        scanf("%d",&x);
        vec2.push_back(x);
    }

    int low = 0 , high =n1 ;
    int l1,l2,r1,r2;
    double ans = 0.0;

    while(low <= high){
        
        int cut1 = (low+high)/2;
        
        int cut2 = (n1+n2+1)/2 - cut1 ;

        l1 = (cut1 == 0 )? INT_MIN : vec1[cut1-1];
        l2 = (cut2 == 0)? INT_MIN : vec2[cut2-1];

        r1 = (cut1 == n1)?INT_MAX:vec1[cut1];
        r2 = (cut2 == n2)?INT_MAX:vec2[cut2];

        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2 == 0)
            {
                ans = (max(l1,l2)+min(r1,r2))/2.0;
            }else{
                ans = max(l1,l2);
            }
            break;
        }

        else if(l1 > r2){
            high = cut1-1;
        }
        else{
            low = cut1+1;
        }
    }

    cout<<ans<<"\n";

    return 0;
}