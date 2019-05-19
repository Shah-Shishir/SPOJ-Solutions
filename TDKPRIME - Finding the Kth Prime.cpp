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
#define scase sf ("%d",&tc)
#define sn sf ("%d",&n)
#define whilecase while (tc--)
#define eof while (cin >> n)
#define forloop for (pos=1; pos<=tc; pos++)
#define arrayloop (i=0; i<n; i++)
#define cinstr cin >> str
#define getstr getline (cin,str)
#define pcase pf ("Case %d: ",pos)
#define pb push_back
#define in insert
#define lld long long

const lld MAX = 86500001;
bool check[MAX];
vector <lld> v;

void sieve ()
{
    v.pb (2);

    lld i,j;

    check[0] = check[1] = true;

    for (i=4; i<=MAX; i+=2)
        check[i] = true;

    for (i=3; i*i<=MAX; i+=2)
    {
        if (check[i] == false)
        {
            v.pb(i);

            for (j=i*i; j<MAX; j+=2*i)
                check[j] = true;
        }
    }

    for (i*i==MAX; i<MAX; i+=2)
        if (check[i] == false)
            v.pb(i);
}

int main (void)
{
    sieve ();

    int tc,n;

    sf ("%d",&tc);

    while (tc--)
    {
        sf ("%d",&n);
        pf ("%lld\n",v[n-1]);
    }

    return 0;
}
