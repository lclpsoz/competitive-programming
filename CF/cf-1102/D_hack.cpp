#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e5+5;

int n;
char s[N];
int cnt[500];

int main() {
  scanf("%d", &n);

  scanf("%s", s);
  for(int i = 0; i < n; i++) cnt[s[i]]++;

  for(int i = 0; i < n and cnt['0'] < n/3; i++) if(cnt[s[i]] > n/3) {
    cnt[s[i]]--;
    cnt['0']++;
    s[i] = '0';
  }

  for(int i = n-1; i >= 0 and cnt['2'] < n/3; i--) if(cnt[s[i]] > n/3) {
    cnt[s[i]]--;
    cnt['2']++;
    s[i] = '2';
  }

  for(int i = n-1; i >= 0 and cnt['0'] > n/3; i--) if(s[i] == '0') {
    cnt['0']--;
    cnt['1']++;
    s[i] = '1';
  }
  for(int i = 0; i < n and cnt['2'] > n/3; i++) if(s[i] == '2') {
    cnt['2']--;
    cnt['1']++;
    s[i] = '1';
  }

  printf("%s\n", s);

  return 0;
}