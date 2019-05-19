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
#define pii pair <int,int>
#define pb push_back
#define in insert
#define llu unsigned long long
#define lld long long
#define U unsigned int
#define endl "\n"

const int MOD = 1000000007;
const int MAX = 1005;

bool prime[MAX];
vector <int> v;

void sieve ()
{
    int i,j;

    v.pb(2);
    prime[0] = prime[1] = true;

    for (i=3; i*i<=MAX; i+=2)
        if (!prime[i])
            for (j=i*i; j<MAX; j+=2*i)
                prime[j] = true;

    for (i=3; i<MAX; i+=2)
        if (!prime[i])
            v.pb(i);
}

int power (int n,int p)
{
    string bin;

    while (p)
    {
        if (p & 1)
            bin += "1";
        else
            bin += "0";

        p >>= 1;
    }

    reverse (bin.begin(),bin.end());

    int res=1,len=bin.size(),i;

    for (i=0; i<len; i++)
    {
        res *= res;

        if (bin[i] == '1')
            res *= n;
    }

    return res;
}

int main (void)
{
    /*
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    */
    sieve ();

    int tc,pos,n,i,sum,k,t;

    sf ("%d",&tc);

    for (pos=1; pos<=tc; pos++)
    {
        sf ("%d",&n);

        t = n;

        sum = 1;

        for (i=0; v[i]*v[i]<=n; i++)
        {
            if (n % v[i] == 0)
            {
                k = 1;

                while (n % v[i] == 0)
                {
                    ++k;
                    n /= v[i];
                }

                sum *= (power(v[i],k)-1)/(v[i]-1);
            }
        }

        if (n > 1)
            sum *= (power(n,2)-1)/(n-1);

        pf ("%d\n",sum-t);
    }

    return 0;
}
