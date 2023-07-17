#include<bits/stdc++.h>
using namespace std;

const int n = 6;
bool bfs(int **rgraph, int s, int t, int parent[n]){
   int vis[n] = {0};
   queue<int>que;
   que.push(s);
   vis[s] = 1;
   parent[s] = -1;
   while(!que.empty()) {
       int u = que.front();
       que.pop();
       for(int v=0;v<n;v++) {
           if(vis[v] == 0 && rgraph[u][v] > 0) {
               if(v == t) {
                   parent[v] = u;
                   return true;
               }else {
                   que.push(v);
                   vis[v] = 1;
                   parent[v] = u;
               }


           }
       }


   }
   return false;
  


}
int ford_fulkerson(int G[n][n], int n) {
   int **rgraph = new int*[n];
   for(int i=0;i<n;i++){
       rgraph[i] = new int[n];
   }
   int max_flow = 0;;
   for(int u=0;u<n;u++){
       for(int v=0; v<n; v++){
           rgraph[u][v] = G[u][v];
       }
   }
   int s = 0;
   int t = 5;
   int parent[n];
   while(bfs(rgraph, s, t, parent)) {
       int path_flow = INT_MAX;
       for(int v=t; v!=s; v = parent[v]) {
           int u = parent[v];
           path_flow = min(path_flow, rgraph[u][v]);
       }
       for(int v=t; v!=s; v = parent[v]) {
           int u = parent[v];
           path_flow = min(path_flow, rgraph[u][v]);
       }
       for(int v=t; v!=s; v = parent[v]) {
           int u = parent[v];
           rgraph[u][v] -= path_flow;
           rgraph[v][u] += path_flow;
       }
       max_flow += path_flow;
   }
   return max_flow;
}




int main() {
   int G[n][n] = {
       {0,16,13,0,0,0},
       {0,0,10,12,0,0},
       {0,4,0,0,14,0},
       {0,0,9,0,0,20},
       {0,0,0,7,0,4},
       {0,16,13,0,0,0}
   };
   int max_flow = ford_fulkerson(G, n);
   cout << max_flow;
   return 0;


}

