#include <bits/stdc++.h>
using namespace std;

struct graph{

    int u,v,w;

}Graph[2005];
int bellmanFord(int N, int E);
int Distance[1005];

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int Node,Edge;
        cin >> Node >> Edge;
        for(int i=0 ; i<Edge ; i++)
        {
            cin >> Graph[i].u >> Graph[i].v >> Graph[i].w;
        }
        int K = bellmanFord(Node,Edge);
        if(K) cout << "possible" << endl;
        else cout << "not possible" << endl;
    }
}
int bellmanFord(int N, int E)
{
    Distance[0] = 0;
    for(int i=1 ; i<N ; i++) Distance[i] = INT_MAX;


    for(int i=0 ; i<N-1 ; i++)
    {
        for(int j=0 ; j<E ; j++)
        {
            if(Graph[j].u!=INT_MAX && Distance[Graph[j].u] + Graph[j].w < Distance[Graph[j].v])
                Distance[Graph[j].v] = Distance[Graph[j].u] + Graph[j].w;
        }
    }

    for(int j=0 ; j<E ; j++)
        {
            if(Graph[j].u!=INT_MAX && Distance[Graph[j].u] + Graph[j].w < Distance[Graph[j].v])
                return 1;
        }
    return 0;

}

