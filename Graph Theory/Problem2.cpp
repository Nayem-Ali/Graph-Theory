#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector <int> Graph[N];
map <string,int> MP;
int Visited[N],Distance[N];

void BFS(string src, string dstn,int n);

int main()
{
    ///freopen("TestCase.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int k=1 ; k<=tc ; k++)
    {
        int Node, Edge,Query,Frq;
       //cout << "Enter the node and edge quantity: ";
        cin >> Node >> Edge >> Query;
        string s,x,y,source,dest;

        for(int i=1 ; i<=Node ; i++)
        {
            cin >> s;
            MP[s]=i;
        }
        for(int i=1 ; i<=Edge ; i++)
        {
            cin >> x >> y;
            Graph[MP[x]].push_back(MP[y]);
            Graph[MP[y]].push_back(MP[x]);
        }
        if(k==1) cout << "SHIPPING ROUTES OUTPUT\n\n";
        cout << "DATA SET  " << k << endl << endl;
        for(int i=1 ; i<=Query ; i++)
        {
            cin >> Frq >> source >> dest;
            BFS(source,dest,Frq);
            if(Distance[MP[dest]]==0) cout << "NO SHIPMENT POSSIBLE\n";
            else cout << "$" << Frq*Distance[MP[dest]] << endl ;
        }
        cout << endl;
        for(int i=1 ; i<=Node ; i++)
        {
            Graph[i].clear();
        }
        MP.clear();

    }
    cout << "END OF OUTPUT\n";
    return 0;
}
void BFS(string src, string dstn,int n)
{
    memset(Distance,0,sizeof(Distance));
    memset(Visited,0,sizeof(Visited));
    queue <int> Q;
    Q.push(MP[src]);
    Visited[MP[src]] = 1;
    Distance[MP[src]] = 0;
    while(Q.size())
    {
        int u = Q.front();
        for(auto i:Graph[u])
        {
            if(Visited[i]==0)
            {
                Visited[i] = 1;
                Distance[i] = Distance[u]+100;
                Q.push(i);
            }
        }
        Q.pop();
    }
}

