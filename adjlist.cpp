#include<iostream>
#include<vector>
#define M (10<<3)
using namespace std;

int main(){
    vector <pair<int,int> > G[M+1];
    int ne;
    cout<<"Enter number of edges:"<<endl;
    cin>>ne;
    for (int i=1;i<=ne;i++){
        int u,v,w;
    cout<<"Enter u, v and w:"<<endl;
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    for(int u=0;u<=M;u++){
        int l=G[u].size();
        for(int i=0;i<=l-1;i++){

        cout<<"("<<G[u][i].first;
        cout<<",";
        cout<<G[u][i].second<<")";
        cout<<",";
        }

    }
    int source,destination;
    cin>>source>>destination;

    int ans=djikstra(G, source, destination);
    cout<<"The shortest path distance = "<<ans<<endl;
}

