/***

            Bismillahir Rahmanir Rahim
            Read the name of Allah, who created you!!!
            Author : Shah Newaj Rabbi Shishir
            Department of CSE, City University, Bangladesh.

***/

#include <bits/stdc++.h>
using namespace std;

#define sf scanf
#define pf printf
#define ssf sscanf
#define spf sprintf
#define fsf fscanf
#define fpf fprintf
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define scase sf ("%d",&tc)
#define sn sf ("%d",&n)
#define whilecase while (tc--)
#define eof while (cin >> n)
#define forloop for (pos=1; pos<=tc; pos++)
#define arrayloop (i=0; i<n; i++)
#define cinstr cin >> str
#define getstr getline (cin,str)
#define pcase pf ("Case %d: ",pos)
#define vi vector <int>
#define pii pair <int,int>
#define mii map <int,int>
#define pb push_back
#define in insert
#define llu unsigned long long
#define lld long long
#define U unsigned int
#define endl "\n"

const int MOD = 1000000007;
const int MAX = 1000005;

int SetBit (int n, int x) { return n | (1 << x); }
int ClearBit (int n, int x) { return n & ~(1 << x); }
int ToggleBit (int n, int x) { return n ^ (1 << x); }
int CheckBit (int n, int x) { return (bool)(n & (1 << x)); }

llu BIT[10001];
int n,u,i,l,r,val,k;

void update (int i, int val)
{
    for (; i<=n; i+=i&(-i))
        BIT[i] += val;
}

llu query (int i)
{
    llu sum = 0;

    for (; i>0; i-=i&(-i))
        sum += BIT[i];

    return sum;
}

void range_update (int i, int j, int val)
{
    update (i,val);
    update (j+1,-val);
}

int main (void)
{
    /*
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    */

    int tc;

    sf ("%d",&tc);

    while (tc--)
    {
        sf ("%d %d",&n,&u);

        memset (BIT,0,sizeof(llu)*(n+1));

        for (i=1; i<=u; i++)
        {
            sf ("%d %d %d",&l,&r,&val);
            range_update (l+1,r+1,val);
        }

        sf ("%d",&k);

        for (i=1; i<=k; i++)
        {
            sf ("%d",&val);
            pf ("%llu\n",query(val+1));
        }
    }

    return 0;
}
