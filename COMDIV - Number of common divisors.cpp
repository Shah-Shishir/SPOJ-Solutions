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

int gcd (int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a%b);
}

int main (void)
{
    /*freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);*/
    int tc,a,b,g,i,k;

    sf ("%d",&tc);

    while (tc--)
    {
        sf ("%d %d",&a,&b);

        g = gcd (a,b);
        k = 0;

        for (i=1; i*i<=g; i++)
        {
            if (g % i == 0)
            {
                if (i*i == g)
                    k++;
                else
                    k += 2;
            }
        }

        pf ("%d\n",k);
    }

    return 0;
}