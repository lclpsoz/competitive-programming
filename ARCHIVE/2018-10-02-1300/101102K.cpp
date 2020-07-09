#include <stdio.h>
#include <map>
#include <vector>
#include <set>
using namespace std;

int t;
int n, m;
int u, v;
map<int, set<int>> mp;
vector<int> vec;

int main () {
  scanf ("%d", &t);
  while (t--) {
    mp.clear ();
    vec.clear();
    scanf ("%d %d", &n, &m);
    while (m--) {
      scanf ("%d %d", &u, &v);
      mp[u].insert (v);
    }
    for (int i = 1; i <= n; i++)
      vec.push_back (i);
    bool test = true;
    while (test) {
      test = false;
      for (int i = n-1; i > 0; i--)
	if (vec[i-1] < vec[i] && mp.count (vec[i-1]) &&  mp[vec[i-1]].count (vec[i])) {
	  swap (vec[i-1], vec[i]);
	  test = true;
	}
    }
    for (int x : vec)
      printf ("%d ", x);
    putchar ('\n');
  }
  
  
  return 0;
}
