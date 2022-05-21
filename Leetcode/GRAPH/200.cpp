// class Solution {
// public:
    
//     bool visited[399][399];
    
//     int dx[4] = {1 , -1 , 0 ,  0};
//     int dy[4] = {0 ,  0 , 1 , -1};

// bool isValid(vector<vector<char> >&graph , int i,int j){

//     int row = graph.size();
//     int col = graph[0].size();

//     if(i<row && i>=0 && j<col && j>=0 && graph[i][j] == '1')return true;
//     else return false;


// }

    
// void bfs(vector<vector<char> >&graph,int row,int col){

    
//     visited[row][col]  = true;

//     queue<pair<int,int> >q;
//     q.push({row,col});

//     while(!q.empty()){

//         int ux = q.front().first;
//         int uy = q.front().second;
//         q.pop();

//         for(int i = 0 ;i<4 ; i++){

//             int vx = ux + dx[i];
//             int vy = uy + dy[i];
//             if(isValid(graph,vx,vy) && !visited[vx][vy]){
//                 visited[vx][vy] = true;
//                 q.push({vx,vy});
//             }
//         }
//     }
// }
    
//     int numIslands(vector<vector<char>>& graph) {
//         int i,j;
//         int cnt = 0;
//         memset(visited,false,sizeof(visited));
        
//         for(i = 0 ; i < graph.size() ; i++){
//         for(j = 0 ; j<graph[i].size() ; j++){

//             if(!visited[i][j] && graph[i][j] == '1'){

//                 cnt++;
//                 bfs(graph,i,j);
//             }
//         }
//     }
        
//     return cnt;

//     }
// };