#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
typedef long long int ll;

void PrimeFactorization(ll n);
int main()
{
    ll n;
    while(cin >> n)
    {
        if(n==0) break;
        cout << n << " = ";
        PrimeFactorization(n);

    }
    return 0;
}
void PrimeFactorization(ll n)
{
    int PFact[MAX],k=0;
    if(n<0)
    {
        n*=-1;
        cout << "-1 x ";
    }
    while(n%2==0)
    {
        PFact[k++] = 2;
        n/=2;
    }

    for(ll i=3 ; i<=sqrt(n) ; i+=2)
    {
        while(n%i==0)
        {
            n/=i;
            PFact[k++] = i;
        }
    }
    if(n>2)
        PFact[k++] = n ;
    for(int j=0 ; j<k-1 ; j++)
        cout << PFact[j] << " x ";
    cout << PFact[k-1] << endl;
}
