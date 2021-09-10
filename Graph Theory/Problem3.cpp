#include<bits/stdc++.h>
using namespace std;
#define Infinity INT_MAX
int main()
{
    int tc;
    cin >> tc;
    for(int k=1 ; k<=tc ; k++)
    {
        int N,E,u,v,w,src,dstn;
        cin >> N >> E >> src >> dstn;
        vector <pair <int,int>> G[N];
        int dist[N];
        while(E--)
        {
            cin >> u >> v >> w;
            G[u].push_back({w,v});
            G[v].push_back({w,u});
        }
        for(int i=0 ; i<N ; i++)
        {
            dist[i]=Infinity;
        }
        priority_queue<pair<int,int>,vector<pair <int,int>>,greater<pair<int,int>>> PQ;
        dist[src]=0;
        PQ.push({0,src});
        while(PQ.size())
        {
            int Current_Node = PQ.top().second;
            int Node_Cost = PQ.top().first;
            PQ.pop();
            for(pair <int,int> i:G[Current_Node])
            {
                if(Node_Cost + i.first < dist[i.second])
                {
                    dist[i.second] = Node_Cost + i.first;
                    PQ.push({dist[i.second],i.second});
                }
            }
        }
        if(dist[dstn]!=Infinity)
            printf("Case #%d: %d\n",k,dist[dstn]);
        else
            printf("Case #%d: unreachable\n",k);
    }
}
