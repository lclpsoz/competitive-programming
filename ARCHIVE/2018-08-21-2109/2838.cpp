#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
#define len(x) (int)x.size()
#define X real()
#define Y imag()
#define mp make_pair
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const int INF = 1e9;
  
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 202;

int adj[4][2] = {{0, 1},
		 {1, 0},
		 {-1, 0},
		 {0, -1}};
char mat[N][N];
bool vis[N][N][16][32];
queue<pair<pii, pair<pii, int>>> q;

int main ()
{
  int n, m;
  scanf ("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf (" %c", &mat[i][j]);
      if (mat[i][j] == 'T')
	q.push ({{i, j}, {{0, 0}, 0}});
    }
  
  while (!q.empty()) {
    int x = q.front().x.x, y = q.front().x.y;
    int lvl = q.front().y.x.x;
    int keys = q.front().y.x.y;
    int jow = q.front().y.y;
    q.pop();
    if (vis[x][y][keys][jow]) continue;
    vis[x][y][keys][jow] = true;
    char c = mat[x][y];
    if (c >= 'a' && c <= 'd')
	keys |= 1<<(c-'a');
    if (c == 'p')
      jow |= 1;
    else if (c == 't')
      jow |= 1<<1;
    else if (c == 'm')
      jow |= 1<<2;
    else if (c == 'e')
      jow |= 1<<3;
    else if (c == 'r')
      jow |= 1<<4;
	
    //printf ("%2d: %2d %2d %2d %2d\n", lvl, x, y, keys, jow);
    if (jow == 31) {
      printf ("%d\n", lvl);
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      char &cc = mat[x+adj[i][0]][y+adj[i][1]];
      if (cc != '#' && cc != '\0' && (cc < 'A' || cc > 'D' || (keys & 1<<(cc-'A'))))
	  q.push ({{x+adj[i][0], y+adj[i][1]}, {{lvl+1, keys}, jow}});
    }
  }
  printf ("Gamora\n");

  return 0;
}
