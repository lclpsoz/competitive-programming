#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;

#define x first
#define y second

const int N = 1e5+10;
const int INF = 1e9;


int main()
{
    int n, k, x;
    while(scanf("%d %d", &n, &k) != EOF) {
        vector <pii> m(n);
        vi v;
        
        for(int i = 0 ; i < n ; i++) {
            scanf("%d", &x);
            v.push_back(x);
        }
        m[0].x = v[0];
        m[0].y = v[0];
        if(k < n) {
            for(int i = 1 ; i < k ; i++) {
                m[i].x = m[i-1].x + v[i];
                m[i].y = m[i-1].x + v[i];
            }
            int pts = k;
            for(int i = k ; i < n ; i++) {
                
                if(pts == k) {
                    pts = 0;
                    m[i].x = m[i-1].x;
                    m[i].y = m[i-1].x + v[i];
                }
                else {
                    pts++;
                    m[i].x = min(m[i-1].x + v[i], m[i-1].y);
                    m[i].y = m[i-1].x + v[i];
                }
            }
        }
        else {
            for(int i = 1 ; i < n ; i++) {
                m[i].x = m[i-1].x + v[i];
            }
        }
        printf("%d\n", m[n-1].x);
    }

    return 0;
}
