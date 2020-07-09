// URI 2559 - Sexta-Feira 13
// Segment Tree w/ lazy propagation
// Tree stores amount of 13, 7 and
// total of others values.
#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5+10;

struct node {
  int qnt7, qnt13, sum;
};

struct nodeLazy {
  int upd7, upd13;
};

int arr[N];
node tree[4*N];
nodeLazy lazy[4*N];

// Build tree
void build (int p, int tl, int tr);

// Propagates Lazy acumulated
void applyLazy (int p, int tl, int tr);

// Update position pos to val
void updPos (int p, int tl, int tr, int pos, int val);

// Update from {7, 13} to val
void updRange (int p, int tl, int tr, int l, int r, int valOld, int valNew);

// Sum in range
int sumRange (int p, int tl, int tr, int l, int r);

int main () {
  int n, m;
  int opt, pos, l, r, newVal, oldVal;
  while (scanf ("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++)
      scanf ("%d", &arr[i]);
    build (1, 1, n);
    scanf ("%d", &m);
    while (m--) {
      scanf ("%d", &opt);
      if (opt == 1) {
	scanf ("%d %d", &pos, &newVal);
	//printf ("updPos: %d %d\n\n", pos, newVal);
	updPos (1, 1, n, pos, newVal);
      } else if (opt == 2) {
	scanf ("%d %d %d %d", &l, &r, &oldVal, &newVal);
	//printf ("[%d, %d] %d -> %d\n\n", l, r, oldVal, newVal);
	if (oldVal != newVal)
	  updRange (1, 1, n, l, r, oldVal, newVal);
      } else {
	scanf ("%d %d", &l, &r);
	//printf ("sumRange [%d, %d]: %d\n", l, r, sumRange (1, 1, n, l, r));
	printf ("%d\n", sumRange (1, 1, n, l, r));
      }
    }
  }
  
  return 0;
}

// Build tree
void build (int p, int tl, int tr) {
  lazy[p] = {-1, -1};
  if (tl == tr) {
    if (arr[tl] == 13)
      tree[p].qnt13 = 1;
    else if (arr[tl] == 7)
      tree[p].qnt7 = 1;
    else
      tree[p].sum = arr[tl];
    return;
  }
  
  int md = (tl+tr)/2;
  build (2*p, tl, md);
  build (2*p+1, md+1, tr);

  tree[p].qnt13 = tree[2*p].qnt13 + tree[2*p+1].qnt13;
  tree[p].qnt7 = tree[2*p].qnt7 + tree[2*p+1].qnt7;
  tree[p].sum = tree[2*p].sum + tree[2*p+1].sum;
}

// Propagates Lazy acumulated
void applyLazy (int p, int tl, int tr) {
  //printf ("\napplyLazy: %d %d %d\n", p, tl, tr);
  
  if (tl != tr) {
    int md = (tl+tr)/2;
    applyLazy (2*p, tl, md);
    applyLazy (2*p+1, md+1, tr);
  }
  

  // Single position
  if (tl == tr) {
    //printf ("\n  [%d, %d]\n", tl, tr);
    //printf ("  here: %d %d\n", lazy[p].upd7, lazy[p].upd13);
    assert (lazy[p].upd7 == -1 || lazy[p].upd13 == -1);
    if (lazy[p].upd7 != -1 && tree[p].qnt7) {
      if (lazy[p].upd7 == 13)
	tree[p].qnt13 = 1;
      else
	tree[p].sum = lazy[p].upd7;
      tree[p].qnt7 = 0;
    } else if (lazy[p].upd13 != -1 && tree[p].qnt13) {
      if (lazy[p].upd13 == 7)
	tree[p].qnt7 = 1;
      else
	tree[p].sum = lazy[p].upd13;
      tree[p].qnt13 = 0;
    }
    lazy[p] = {-1, -1};
    return;
  }

  // Range
  if (lazy[p].upd7 != -1) {
    int &val = lazy[p].upd7;
    
    if (val == 13)
      tree[p].qnt13 += tree[p].qnt7;
    else
      tree[p].sum += val * tree[p].qnt7;
    tree[p].qnt7 = 0;
    
    lazy[2*p].upd7 = val;
    lazy[2*p+1].upd7 = val;
  }
  if (lazy[p].upd13 != -1) {
    int &val = lazy[p].upd13;
    
    if (val == 7)
      tree[p].qnt7 += tree[p].qnt13;
    else
      tree[p].sum += val * tree[p].qnt13;
    tree[p].qnt13 = 0;
    
    lazy[2*p].upd13 = val;
    lazy[2*p+1].upd13 = val;
  }
  
  lazy[p] = {-1, -1};
}

// Update position pos to val
void updPos (int p, int tl, int tr, int pos, int val) {
  applyLazy (p, tl, tr);
  
  if (tl == tr) {
    tree[p] = {0, 0, 0};
    if (val == 13)
      tree[p].qnt13 = 1;
    else if (val == 7)
      tree[p].qnt7 = 1;
    else
      tree[p].sum = val;
    //printf ("up: %d %d %d\n", tree[p].qnt7, tree[p].qnt13, tree[p].sum);
    return;
  }
  
  int md = (tl+tr)/2;
  if (pos <= md)
    updPos (2*p, tl, md, pos, val);
  else
    updPos (2*p+1, md+1, tr,  pos, val);

  tree[p].qnt13 = tree[2*p].qnt13 + tree[2*p+1].qnt13;
  tree[p].qnt7 = tree[2*p].qnt7 + tree[2*p+1].qnt7;
  tree[p].sum = tree[2*p].sum + tree[2*p+1].sum;
}

// Update from {7, 13} to val
void updRange (int p, int tl, int tr, int l, int r, int valOld, int valNew) {
  applyLazy (p, tl, tr);
  
  if (l <= tl && tr <= r) {
    //printf ("IN HERE\n");
    if (valOld == 13)
      lazy[p].upd13 = valNew;
    else if (valOld == 7)
      lazy[p].upd7 = valNew;
    applyLazy(p, tl, tr);
    return;
  }

  int md = (tl+tr)/2;
  if (l <= md)
    updRange (2*p, tl, md, l, r, valOld, valNew);
  if (md < r)
    updRange (2*p+1, md+1, tr, l, r, valOld, valNew);

  tree[p].qnt13 = tree[2*p].qnt13 + tree[2*p+1].qnt13;
  tree[p].qnt7 = tree[2*p].qnt7 + tree[2*p+1].qnt7;
  tree[p].sum = tree[2*p].sum + tree[2*p+1].sum;
}

// Sum in range
int sumRange (int p, int tl, int tr, int l, int r) {
  //printf ("  %d %d %d\n", p, tl, tr);
  applyLazy (p, tl, tr);

  int ret = 0;
  if (l <= tl && tr <= r) {
    ret = tree[p].sum + (tree[p].qnt7 * 7) + (tree[p].qnt13 * 13);
    //printf ("  ret: %d\n", ret);
    return ret;
  }

  int md = (tl+tr)/2;
  if (l <= md)
    ret += sumRange (2*p, tl, md, l, r);
  if (md < r)
    ret += sumRange (2*p+1, md+1, tr, l, r);

  tree[p].qnt13 = tree[2*p].qnt13 + tree[2*p+1].qnt13;
  tree[p].qnt7 = tree[2*p].qnt7 + tree[2*p+1].qnt7;
  tree[p].sum = tree[2*p].sum + tree[2*p+1].sum;

  return ret;
}
