#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> oc[10];

bool divisible(int x)
{
  stack<int> s;
  s.push(x%10);
  int topo, ans = -1, numb = 0, mult;
  x /= 10;
  while(x) {
    s.push(x%10);
    x /= 10;
  }
  vector<int>::iterator it;
  mult = pow(10, s.size());
  mult /= 10;
  while(!s.empty()) {
    topo = s.top();
    s.pop();
    it = upper_bound(oc[topo].begin(), oc[topo].end(), ans);
    if (it == oc[topo].end()) return false;
    ans = *it;
    //break
    numb += mult*topo;
    mult /= 10;
  }
  return numb%8==0;
}

int main()
{
  char c;
  int i = 0;
  bool achou = false;
  while(c = getchar(), (c != '\n' && c != EOF)) {
    oc[c-'0'].pb(i++);
  }
  for (int i = 0; 8*i <= 999; ++i) {
    if (divisible(8*i)) {
      printf("YES\n%d\n",8*i);
      achou = true;
      break;
    }
  }
  if (!achou) printf("NO\n");
  return 0;
}
