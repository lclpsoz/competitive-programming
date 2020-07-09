#include<cstdio>
#include<set>
using namespace std;
const int N=400, N2=1e5+10;
const int M=5e6;
int n;
int o[N+10], prosti[N],p=0, a[N2], obidjen[M+100], niz[M];
set <int> S;

void sito ()
{
    for (int i=2;i<=N;i++) o[i]=0;

    for (int i=2;i<=N;i++)
        if (!o[i])
        {
            prosti[++p]=i;
            for (int j=i+i;j<=N;j+=i) o[j]=1;
        }
}

void radi(int g)
{
    for (int j=g;j<=M;j+=g) obidjen[j]=1;
    return;
}
int main ()
{
    sito();

    scanf ("%d",&n);
    for (int i=1;i<=n;i++) scanf ("%d",&a[i]);

    for (int i=2;i<=M;i++) obidjen[i]=0;

    int d=a[1];
        for (int i=1;i<=p;i++)
        {
            if (!(a[1]%prosti[i]))
            {
                int g=prosti[i];
                radi(g);
                while (!(d%prosti[i])) d/=prosti[i];
            }
        }
    if (d>1) radi(d);

    int z=0;
    for (int i=2;i<=n;i++)
    {
        int q=0;
        d=a[i];
        for (int j=1;j<=p;j++)
        {
            if ( (!(a[i]%prosti[j]))  )
            {
                if (!obidjen[prosti[j]]) niz[++q]=prosti[j];
                else
                {z=i; break;}

                while (!(d%prosti[j])) d/=prosti[j];
            }
        }
        if (!z && d>1)
            if (!obidjen[d]) niz[++q]=d;
            else z=i;

        if (z==i) break;

        for (int j=1;j<=q;j++)
        {
            int g=niz[j];
            radi(g);
        }
    }

    if (!z) {for (int i=1;i<=n;i++) printf ("%d ",a[i]); return 0;}

    int k=a[z];
    for (int i=k+1;i<=M;i++)
    {
        if (!obidjen[i])
        {
            d=i;
            for (int j=1;j<=p;j++)
            {
                if ( (!(i%prosti[j]))  )
                {
                    int g=prosti[j];
                    while (!(d%prosti[j])) d/=prosti[j];
                    radi(g);
                }
            }

            if (d>1) radi(d);

            a[z++]=i;
            break;
        }
    }

    for (int i=2;i<=M;i++)
    {
        if (z==n+1) break;
        if (!obidjen[i])
        {
            d=i;
            for (int j=1;j<=p;j++)
            {
                if ( (!(i%prosti[j]))  )
                {
                    int g=prosti[j];
                     while (!(d%prosti[j])) d/=prosti[j];
                    radi(g);
                }
            }
             if (d>1) radi(d);
            a[z++]=i;
        }
    }

    for (int i=1;i<=n;i++){ printf ("%d",a[i]); if (i < n) putchar (' '); }
	putchar ('\n');
    return 0;
}
