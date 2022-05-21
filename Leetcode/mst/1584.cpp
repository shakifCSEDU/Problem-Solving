#include<bits/stdc++.h>
using namespace std;

int par[10009],Rank[1009];

struct point{
    int x,y;
}points[10009];



int Find(int n){
    if(par[n] <  0)return n;
    else return par[n] = Find(par[n]);
}

void Merge(int n,int m){
    
    int x = Find(n);
    int y = Find(m);

    if(x == y)return;
  
    if(Rank[x] < Rank[y]){
        Rank[y] += Rank[x];
        par[x] = y;
    }
    else{
        Rank[x] +=  Rank[y];
        par[y] = x;
    }
}


struct edge{
    int u,v,w;
    // bool operator < (const edge &l)const{
    //     return w<l.w;
    // }
}a[1009];

bool comp(edge l , edge m){
    return l.w < m.w;
}



int32_t main(){

    int i,j,n,m;

    scanf("%d",&n);
    
    for(i = 0 ; i < n ; i++){
        scanf("%d %d",&points[i].x,&points[i].y);
    }
    int in = 0;

    for(i = 0 ; i<n ; i++){

        for(j = i+1 ; j<n ; j++){
            
            int w = abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y);

            a[in].u = i;
            a[in].v = j;
            a[in++].w = w;
        }
    }
    
    sort(a , a+in,comp);
    

    int mst = 0;

    for(i = 0 ; i<in ; i++)
        par[i] = -1 , Rank[i] = 1;


    for(i = 0 ; i < in ; i++){
        
        int x = Find(a[i].u);
        int y = Find(a[i].v);
        //cout<<x<<" "<<y<<endl;
        int w = a[i].w;

        if(x != y){
          
            Merge(x , y);
            mst += w;
            
        }
 
    }    

    cout<<mst<<'\n';



    return 0;
}