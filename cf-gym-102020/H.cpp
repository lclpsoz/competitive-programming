#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

template<class base_t, const int M, const int N>
struct matrix
{
    base_t **t;

    matrix(base_t c = 0)
    {
        t = new base_t*[M];
        for(int i = 0; i < M; i++)
        {
            t[i] = new base_t[N];
            for(int j = 0; j < N; j++)
                t[i][j] = 0;
        }
        for(int i = 0; i < min(M, N); i++)
            t[i][i] = c;
    }

    base_t* & operator [] (const int i) { return t[i];}

    matrix<base_t, M, N> operator + (const matrix<base_t, M, N>& o)
    {
        matrix<base_t, M, N> ans;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                ans[i][j] = t[i][j] + o.t[i][j];
        return ans;
    }
    matrix<base_t, M, N> operator - (const matrix<base_t, M, N>& o)
    {
        matrix<base_t, M, N> ans;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                ans[i][j] = t[i][j] - o.t[i][j];
        return ans;
    }
    template<const int U>
    matrix<base_t, M, U> operator * (const matrix<base_t, N, U>& o)
    {
        matrix<base_t, M, U> ans;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < U; j++)
                for(int k = 0; k < N; k++)
                {
                    if(is_same<base_t, int>::value)
                        ans[i][j] = int((ans[i][j] + ((t[i][k] * 1LL * o.t[k][j]) % MOD)) % MOD);
                    else
                        ans[i][j] = ans[i][j] || (t[i][k] && o.t[k][j]);
                }
        return ans;
    }

    matrix<base_t, M, N>& operator += (const matrix<base_t, M, N>& o)
    {
        return *this = *this + o;
    }
    matrix<base_t, M, N>& operator -= (const matrix<base_t, M, N>& o)
    {
        return *this = *this - o;
    }
    template<const int U>
    matrix<base_t, M, U>& operator *= (const matrix<base_t, N, U>& o)
    {
        return *this = *this * o;
    }

    matrix<base_t, M, N> operator + (const base_t& o)
    {
        matrix<base_t, M, N> ans;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                ans[i][j] = t[i][j] + o;
        return ans;
    }
    matrix<base_t, M, N> operator - (const base_t& o)
    {
        matrix<base_t, M, N> ans;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                ans[i][j] = t[i][j] - o;
        return ans;
    }
    matrix<base_t, M, N> operator * (const base_t* o)
    {
        matrix<base_t, M, N> ans;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                ans[i][j] = t[i][j] * o;
        return ans;
    }
    matrix<base_t, M, N> operator / (const base_t& o)
    {
        matrix<base_t, M, N> ans;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                ans[i][j] = t[i][j] / o;
        return ans;
    }

    matrix<base_t, M, N>& operator += (const base_t& o)
    {
        return *this = *this + o;
    }
    matrix<base_t, M, N>& operator -= (const base_t& o)
    {
        return *this = *this - o;
    }
    matrix<base_t, M, N>& operator *= (const base_t& o)
    {
        return *this = *this * o;
    }
    matrix<base_t, M, N>& operator /= (const base_t& o)
    {
        return *this = *this / o;
    }

    matrix<base_t, N, M> tranpose()
    {
        matrix<base_t, N, M> ans;
        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
                ans[j][i] = t[i][j];
        return ans;
    }

    base_t trace()
    {
        base_t sum = base_t(0);
        for(int i = 0; i < min(M, N); i++)
            sum += t[i][i];
        return sum;
    }
};

template<class base_t>
base_t fexp(base_t b, ll x)
{
    base_t ans(1);
    while(x)
    {
        if(x & 1LL) ans = ans * b;
        b = b * b;
        x >>= 1LL;
    }
    return ans;
}

const int N = 104;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int n, m;
    cin >> n >> m >> MOD;
    long long k;
    int u, v;
    cin >> k >> u >> v;

    matrix<int, N, N> mat;
    matrix<bool, N, N> mat2;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = mat[b][a] = 1;
        mat2[a][b] = mat2[b][a] = 1;
    }

    mat2 = fexp(mat2, k);

    if(!mat2[u][v])
    {
        cout << "Mendes will sleep in peace." << endl;
        return 0;
    }

    mat = fexp(mat, k);

    cout << mat[u][v] << endl;

	return 0;
}
