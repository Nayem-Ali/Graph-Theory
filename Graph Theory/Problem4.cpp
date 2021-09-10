#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for(int p=1 ; p<=tc ; p++)
    {
        int N,R,s,d,u,v;
        cin >> N >> R;
        int Graph[N][N];
        for(int i=0 ; i<N ; i++)
        {
            for(int j=0 ; j<N ; j++)
                if(i!=j)
                {
                    Graph[i][j] = 100000;
                }
                else
                {
                    Graph[i][j] = 0;
                }

        }
        while(R--)
        {
            cin >> u >> v;
            Graph[u][v] = 1;
            Graph[v][u] = 1;
        }
        cin >> s >> d;
        for(int k=0 ; k<N ; k++)
        {
            for(int i=0 ; i<N ; i++)
            {
                for(int j=0 ; j<N ; j++)
                {
                    Graph[i][j] =  min(Graph[i][j],Graph[i][k]+Graph[j][k]);
                }
            }
        }

        int mAx=-100000;
        for(int i=0 ; i<N ; i++)
        {
            mAx = max(Graph[s][i]+Graph[i][d],mAx);
        }
        cout <<  "Case " << p << ": " <<  mAx << endl;
    }
    return 0;
}
