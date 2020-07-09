#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const int S = 1e5+10;

int n;
char s[S];

int main () {
  scanf ("%d", &n);
  scanf ("%s", s);
  int a, d;
  a = d = 0;
  for (int i = 0; s[i] != '\0'; i++)
    s[i] == 'A' ? ++a : ++d;
  if (a == d)
    printf ("Friendship\n");
  else if (a > d)
    printf ("Anton\n");
  else
    printf ("Danik\n");
    

  return 0;
}
