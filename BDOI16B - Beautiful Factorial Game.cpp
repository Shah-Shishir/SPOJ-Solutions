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
#define pii pair <int,int>
#define pb push_back
#define in insert
#define llu unsigned long long
#define lld long long
#define U unsigned int
#define endl "\n"

const int MOD = 1000000007;
const int MAX = 10005;
bool prime[MAX];
vector <int> v;

void sieve ()
{
    int i,j;

    v.pb(2);
    prime[0] = prime[1] = true;

    for (i=4; i<MAX; i+=2)
        prime[i] = true;

    for (i=3; i*i<=MAX; i+=2)
        if (!prime[i])
            for (j=i*i; j<MAX; j+=2*i)
                prime[j] = true;

    for (i=3; i<MAX; i+=2)
        if (!prime[i])
            v.pb(i);
}

int fun (int n, int p, int f)
{
    int sum = 0;

    while (n != 0)
    {
        n /= p;
        sum += n;
    }

    sum /= f;

    return sum;
}

int main (void)
{
    /*
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    fast;
    */
    sieve ();

    int tc,pos,m,n,t,l,i,j,val,mini;

    cin >> tc;

    for (pos=1; pos<=tc; pos++)
    {
        cin >> n >> m;

        cout << "Case " << pos << ": ";

        vector <int> P,F;
        t = m;

        int len = v.size();

        for (i=0; i<len; i++)
        {
            if (t % v[i] == 0)
            {
                P.pb(v[i]);
                j = 0;

                while (t % v[i] == 0)
                {
                    t /= v[i];
                    j++;
                }

                F.pb(j);
            }
        }

        if (t > 1)
        {
            P.pb(t);
            F.pb(1);
        }

        l = P.size(), mini = 1e9, val = 0;

        for (i=0; i<l; i++)
        {
            val = fun (n,P[i],F[i]);

            mini = min (val,mini);
        }

        cout << mini << endl;
    }

    return 0;
}
