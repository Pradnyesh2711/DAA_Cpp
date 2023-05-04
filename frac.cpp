#include <bits/stdc++.h>
using namespace std;

bool cmp (pair<float,int>p1,pair<float,int>p2){
    return p1.first>p2.first;
   
}
float frack(vector<int>weight,vector<int>profit,int cap,int n){
float grp=0;
vector<pair<float,int>>ratio(n,make_pair(0.0,0));
for(int i=0;i<n;i++){
    ratio[i]=make_pair(profit[i]/weight[i],i);
   
}
    sort(ratio.begin(),ratio.end(),cmp);
   
    for(int i=0;i<n;i++){
        int index=ratio[i].second;
        if(cap==0){
            break;
        }
       if(weight[i]<=cap){
           grp+=profit[i];
           cap-=weight[i];
           
       }
       else {
           float nep=profit[i]*float(cap/weight[i]);
           grp+=nep;
           cap=0;
       }
       cout<<(index+1)<<"\t"<<profit[index]<<"\t"<<weight[index]<<endl;
    }
    cout<<endl;
    return grp;
}

int main(){
   vector<int>weight={1,2,3,4,5};
   vector<int>profit={5,10,15,20,24};
   int max_profit=frack(weight,profit,15,5);
   cout<<max_profit;
   
}

