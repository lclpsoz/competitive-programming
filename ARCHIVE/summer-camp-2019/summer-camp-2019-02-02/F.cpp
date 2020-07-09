#include "bits/stdc++.h"
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

//mt19937 rng((llu)chrono::steady_clock::now().time_since_epoch().count());

struct node
{
    char v;
    int y, size;
    bool rev;
    
    node *l, *r;
    
    node(char _v) : v(_v), y(rand()), size(1), l(NULL), r(NULL), rev(false) {}
    
};

class ImplicitTreap
{
private:
    node* root;
    int size(node* t){ return t ? t->size : 0;}
    
    node* refresh(node* t)
    {
        if(t == NULL) return t;
        t->size = 1 + size(t->l) + size(t->r);
        if(t->l != NULL)t->l->rev ^= t->rev;
        if(t->r != NULL)t->r->rev ^= t->rev;
        if(t->rev)
        {
            swap(t->l, t->r);
            t->rev = false;
        }
        
        return t;
    }
    
    void split(node* &t, int k, node* &a, node* &b)
    {
        refresh(t);
        node* aux;
        if(!t) a = b = NULL;
        else if(size(t->l) < k)
        {
            split(t->r, k-size(t->l)-1, aux, b);
            t->r = aux;
            a = refresh(t);
        }
        else
        {
            split(t->l, k, a, aux);
            t->l = aux;
            b = refresh(t);            
        }
    }
    node* merge(node* a, node* b)
    {
        refresh(a); refresh(b);
        
        if(!a || !b) return a ? a : b;
        if(a->y < b->y)
        {
            a->r = merge(a->r, b);
            return refresh(a);
        }
        else
        {
            b->l = merge(a, b->l);
            return refresh(b);   
        }
    }
    node* at(node* t, int n)
    {
        if(!t) return t;
        refresh(t);
        if(n < size(t->l)) return at(t->l, n);
        else if(n == size(t->l)) return t;
        else return at(t->r, n - size(t->l) - 1);
    }
    
public:
    ImplicitTreap() : root(NULL){}
    int size(){return size(root);}
    bool insertAt(int n, char v)
    {
        node *a, *b;
        split(root, n, a, b);
        root = merge(merge(a, new node(v)), b);
        return true;
    }
    char at(int n)
    {
        node* ans = at(root, n);
        return ans ? ans->v : '#';
    }
    void reverse(int l, int r)
    {
        if(l > r) swap(l, r);
        node *a, *b, *c, *d;
        split(root, l, a, d);
        split(d, r-l+1, b, c);
        if(b != NULL) b->rev ^= 1;
        root = merge(a, merge(b, c));
    }
    void print(int n)
    {
        for(int i = 0; i < n; i++)
            cout << at(i);
        cout << endl;
    }
};

map<char, int> dd;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, l ,r;
    cin >> n >> l >> r;
    
    l--, r--;
    
    string s; cin >> s;
    
    ImplicitTreap treap;
    
    dd['L'] = -1;
    dd['R'] = 1;
    
    for(int i = 0; i < n; i++)
        treap.insertAt(i, s[i]);
    
    int q;
    cin >> q;
    
    while(q--)
    {
        //treap.print(n);
        char t;
        cin >> t;
        
        if(t == 'R')
        {
            treap.reverse(l, r);
        }
        else if(t == 'Q')
        {
            char c; cin >> c;
           //continue;
            if(c == 'L')
                cout << treap.at(l);
            else
                cout << treap.at(r);
        }
        else
        {
            char c, d; cin >> c >> d;
            if(c == 'L') l += dd[d];
            else r += dd[d];
        }
    }
    
    cout << endl;
    
	return 0;
}
