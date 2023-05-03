#include <bits/stdc++.h>
using namespace std;
const int INF=numeric_limits<int>::max();

int main(){
    vector<vector<pair<int,int>>>adj_list={
        {{1,2},{3,4}},
        {{3,4},{5,6}}
    };
        int num_nodes=adj_list.size();
   vector<int>dis(num_nodes,INF);
    vector<bool>vis(num_nodes,false);
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     pq.push({0,0});
     dis[0]=0;
 
   
   
    while(!pq.empty()){
      int node=  pq.top().second;
        pq.pop();
        if(vis[node]){
            continue;
        }
        vis[node]=true;
        for(auto&ne:adj_list[node]){
            int nn=ne.first;
            int nw=ne.second;
            if(dis[node]+nw <dis[nn]){
                dis[nn]=dis[node]+nw ;
                pq.push({dis[nn],nn});
            }
        }
     
 }
    for (int i = 0; i < num_nodes; ++i) {
 cout << "Shortest path from node 0 to node " << i << ": " << dis[i] << endl;

    }
}

