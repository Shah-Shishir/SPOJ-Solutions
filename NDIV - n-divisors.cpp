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
#define llu unsigned long long
#define lld long long
#define U unsigned int

const int MAX = 31700;
bool prime[MAX];
vector <int> v;

void sieve ()
{
    int i,j;

    prime[0] = prime[1] = true;
    v.pb(2);

    for (i=4; i<MAX; i+=2)
        prime[i] = true;

    for (i=3; i*i<=MAX; i+=2)
        if (!prime[i])
            for (j=i*i; j<MAX; j+=2*i)
                prime[j] = true;

    for (i=3; i<MAX; i++)
        if (!prime[i])
            v.pb(i);
}

int countfact (int n)
{
    int i,sum=1,k;

    for (i=0; v[i]*v[i]<=n; i++)
    {
        if (n % v[i] == 0)
        {
            k = 1;

            while (n % v[i] == 0)
            {
                n /= v[i];
                k++;
            }

            sum *= k;
        }
    }

    if (n > 1)
        sum *= 2;

    return sum;
}

int main (void)
{
    /*freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);*/
    sieve ();

    int a,b,n,i,k=0;

    sf ("%d %d %d",&a,&b,&n);

    if (a > b)
    {
        a = a^b;
        b = a^b;
        a = a^b;
    }

    for (i=a; i<=b; i++)
        if (countfact(i) == n)
            k++;

    pf ("%d\n",k);

    return 0;
}
