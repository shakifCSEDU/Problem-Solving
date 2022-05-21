#include<bits/stdc++.h>
using namespace std; 

vector<string>dictionary;

map<string,int>dist;
map<string,bool>visited;

map<string,vector<string> >vec;

int check(string s1,string s2){
    
    int cnt = 0;

    for(int i = 0 ; i < s1.length() ; i++){
        if(s1[i] != s2[i])cnt++;
    }
    return cnt;
}


int bfs(string src,string dest){
    
    
    dist[src] = 0;
    visited[src] = true;
    
    queue<string>q;
    q.push(src);
    bool flag = false;

    while(!q.empty())
    {
        string u = q.front();
        q.pop();
        if(u == dest){
            flag = true;
            break;
        }
        for(int i = 0 ; i< vec[u].size() ;i++){
            string v = vec[u][i];

            if(!visited[v]){
                
                visited[v] = true;
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    int ans;
    if(flag)
        ans = dist[dest]+1;
    else
        ans = 0;
    return ans;
}

int32_t main(){
    int i,j,n;
    
    string word,src,dest;
    
    cin>>src>>dest;

    cin>>n;
    dictionary.push_back(src);
    for(i = 0 ; i < n ; i++){
        
        cin>>word;
        dictionary.push_back(word);
    
    }
    n++;
    int ans = 0;
    
    bool flag = false;

    for(i = 0 ; i < n ; i++){
        if(dictionary[i] == dest)flag = true;
    }
    
    if(!flag){
        cout<<ans;
        return 0;
    }

    for(i = 0 ; i < n ; i++){
        string s1 = dictionary[i];

        for(j = i+1 ; j<n ; j++){
            string s2 = dictionary[j];
            int cnt = check(s1,s2);
            if(cnt == 1){
                vec[s1].push_back(s2);
                vec[s2].push_back(s1);

            }
        }
    }

    // for(i = 0 ; i < n ; i++){
        
    //     string s1 = dictionary[i];
    //     cout<<s1<<" : ";
    //     for(j = 0 ; j<vec[s1].size() ; j++){
    //         cout<<vec[s1][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
      
      ans =  bfs(src,dest);
     cout<<ans<<"\n";

    return 0;
}
/*

        unordered_set<string>dict(wordList.begin(),wordList.end());
        if(dict.find(endWord)==dict.end())
        {
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        int steps=1;
        while(!q.empty())
        {
            int n=q.size();
            while(n)
            {
                string node=q.front();
                q.pop();
                if(node==endWord)
                {
                    return steps;
                }
                for(int i=0;i<node.length();i++)
                {
                    for(char c='a';c<='z';c++)
                    {
                        char x=node[i];
                        node[i]=c;
                        if(dict.find(node)!=dict.end())
                        {
                            dict.erase(node);
                            q.push(node);
                        }
                        node[i]=x;
                    }
                }
                n--;
            }
            steps++;
        }
        return 0;


*/

