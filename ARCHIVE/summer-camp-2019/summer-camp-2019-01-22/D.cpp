#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

ll gcd(ll a, ll b, ll&x, ll& y)
{
    if(a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    
    x = y1 - (b / a) * x1;
    y = x1;
    
    return d;
}

ll diop(ll a, ll b, ll c, ll& x, ll& y)
{
    ll g = gcd(abs(a), abs(b), x, y);
    
    if(c % g)
        return -1;
    
    x *= c / g;
    y *= c / g;
    
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    
    return g;
}
int main()
{
    int n;
    cin >> n;
    
    while(n--)
    {
        ll n1, f1, d1;
        ll n2, f2, d2;
        
        cin >> n1 >> f1 >> d1;
        cin >> n2 >> f2 >> d2;
        
        ll k1, k2, g;
        
        g = diop(d1, -d2, f2 - f1, k1, k2);
        
        if(g == -1)
        {
            cout << 0 << endl;
            continue;
        }
        
        ll ans = 1;
        
        if(k1 < 0 || k2 < 0)    
        {
            ll cnt1 = (-k1 + (d2 / g) - 1) / (d2 / g);
            ll cnt2 = (-k2 + (d1 / g) - 1) / (d1 / g);
            
            ll cnt = max(cnt1, cnt2);
            
            k1 += cnt * (d2 / g);
            k2 += cnt * (d1 / g);
        }
    
        if(k1 < n1 && k2 < n2)    
        {
            ll cnt1 = (n1 - k1) / (d2 / g);
            ll cnt2 = (n2 - k2) / (d1 / g);

            ll cnt = min(cnt1, cnt2);
            
            k1 += cnt * (d2 / g);
            k2 += cnt * (d1 / g);
             
            ans += cnt;
        }
                 
        if(k1 >= n1 || k2 >= n2)
        {
            k1 -= (d2 / g);
            k2 -= (d1 / g);
             
            ans--;
        }
        
        cout << ans << endl;
        
    }

    return 0;
}
