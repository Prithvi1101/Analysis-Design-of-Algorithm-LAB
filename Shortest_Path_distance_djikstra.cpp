#include<bits/stdc++.h>
#define M (10<<7)
#define inf (1<<30)
using namespace std;

struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second>b.second;
    }
};

int dijktra(vector< pair<int,int> > G[] ,int src, int dest){
    int dist[M+1];
    for(int i=0;i<=M;i++){
        dist[i]=inf;
        dist[src]=0;
    }
    priority_queue< pair<int,int>, vector< pair<int,int> >, compare > q; //learn how to sort in ascending order
    q.push(make_pair(src,dist[src]));
    while(!q.empty()){
        pair< int,int > u=q.top();
        q.pop();
        int l=G[u.first].size();
        for(int i=0;i<l;i++){
            pair< int,int > v=G[u.first][i];
            if(dist[u.first]+v.second<dist[v.first]){
                dist[v.first]=dist[u.first]+v.second;
                q.push(make_pair(v.first,dist[v.first]));
            }
        }
    }
    return dist[src,dest];
}

int main(){
    vector< pair<int,int> > G[M+1];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    /*for(int u=0;u<=M;u++){
        int l=G[u].size();
        for(int i=0;i<l;i++){
            cout<<G[u][i].first<<","<<G[u][i].second<<" ";
        }
        cout<<endl;
    }
*/
    int src,dest;
    cin>>src>>dest;
    int ans=dijktra(G,src,dest);

    cout<<"The shortest path distance: "<<ans<<endl;
    return 0;
}
