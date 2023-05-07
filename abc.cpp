#include<bits/stdc++.h>
using namespace std;

const int N=12;
int n;
int graph[N][N];
int path[N];
int bpath[N];
int ccost;
int bcost;
bool vis[N];

void intialize(){
for(int i=0;i<n;i++){
    vis[i]=false;
    path[i]=-1;
    bpath[i]=-1;
    
}    
ccost=0;
bcost=INT_MAX;

}

void printp(int path[N]){
    for(int i=0;i<n;i++){
        cout<<path[i]<<" ";
        
    }
    cout<<path[0];
}

void tsp(int ccity){
    if(ccity=n){
        if(ccost+graph[path[n-1]][path[0]]<bcost){
            bcost=ccost+graph[path[n-1]][path[0]];
            memcpy(bpath,path,sizeof(path));
        }
        return ;
    }
    
    for(int ncity=0;ncity<n;ncity++){
        if(!vis[ncity]){
            int pcity=(ccity==0)?path[n-1]:path[ccity-1];
            ccost +=graph[pcity][ncity];
            if(ccost +(n-ccity)*2<bcost){
                vis[ncity]=true;
                path[ccity]=ncity;
                tsp(ccity+1);
                 vis[ncity]=false;
                path[ccity]=-1;
            }
            ccost-=graph[pcity][ncity];
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          cin>>graph[i][j];
        }
    }
    
    intialize();
    vis[0]=true;
    path[0]=0;
    tsp(1);
    
    cout << "Best tour: ";
    printp(bpath);
    cout << endl;
    cout << "Best cost: " << bcost << endl;
    return 0;
}