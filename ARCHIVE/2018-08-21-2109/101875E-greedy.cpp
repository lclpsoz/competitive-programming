#include <bits/stdc++.h>

using namespace std;

#define len(x) ((int)(x).size())
#define x first
#define y second

using ll = long long;
using llu = unsigned long long;
using ld = long double;

const int N = 500;

int n, k;
int en, total;
char str[N];

void del (int x) {
  int acu = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '1')
      ++acu;
    else if (acu == x) {
      str[i-1-(x/2)] = '0';
      //printf ("%d %s\n", i-1-x/2, str);
      return;
    }
    else
      acu = 0;
  }
  str[n-1-(x/2)] = '0';
  //printf ("%d %s\n", n-1-(x/2), str);
}

void upd () {
  int acu = 0;
  total = 0;
  en = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '1')
      ++acu;
    else
      acu = 0;
    //printf ("%d\n", acu);
    en = max (en, acu);
    total += acu;
  }
}
  
int main(){
  int ans = 0;
  int qnt;
  scanf ("%d", &qnt);
  while (qnt--) {
    ans = 0;
    scanf ("%d %d", &n, &k);
    scanf ("%s", str);
    upd();
    //printf ("%d %d\n", total, k);
    while (total > k) {
      ++ans;
      del(en);
      upd();
      //printf ("%d %d (%d)\n", total, k, en);
    }

    printf ("%d\n", ans);
  }
  
  return 0;
}
