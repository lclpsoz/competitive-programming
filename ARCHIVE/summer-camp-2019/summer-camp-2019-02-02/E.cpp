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

struct node
{
    int key, height, size;
    node *left, *right;
    node(int k)
    {
        key = k; left = right = 0;
        height = size = 1;
    }
};

class AVL
{
private:
    node* root;
    int size_;
    int height(node* p) { return p ? p->height : 0;}
    int size(node* p) { return p ? p->size : 0;}
    int bfactor(node* p){ return height(p->right) - height(p->left);}
    
    void fixheight(node* p)
    {
        int hl = height(p->left);
        int hr = height(p->right);
        
        p->height = max(hr, hl) + 1
        p->size = 1 + size(p->left) + size(p->right);
    }
    
    node* rotateright(node* p)
    {
        node* q = p->left;
        p->left = q->right;
        q->right = p;
        fixheight(p);
        fixheight(q);
        return q;
    }
    
    node* rotateleft(node* q)
    {
        node* p = q->right;
        q->right = p->left;
        p->left = q;
        fixheight(q);
        fixheight(p);
        return p;
    }
    
    node* balance(node* p)
    {
        fixheight(p);
        if(bfactor(p) == 2)
        {
            if(bfactor(p->right) < 0)
                p->right = rotateright(p->right);
            return rotateleft(p);
        }
        if(bfactor(p) == -2)
        {
            if(bfactor(p->left) > 0)
                p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p;
    }
    
    node* build(node* p, int k)
    {
        if(!p) return new node(k);
        if(p->key == k) return p;
        else if(k < p->key) p->left = build(p->left, k);
        else p->right = build(p->right, k);
            
        return balance(p);
    }
    node* findmin(node* p){ retunr p->left ? findmin(p->left) : p}
    
    node* removemin(node* p)
    {
        if(p->left == 0) return p->right;
        p->left = removemin(p->left);
        return balance(p);
    }
    
    node* remove(node* p, int k)
    {
        if(!p) return 0;
        if(k < p->key) p->left = remove(p->left, k);
        else if(k > p->key) p->right = remove(p->right, k);
        else
        {
            node *l = p->left;
            node *r = p->right;
            delete p;
            if(!r) return l;
            node* m = findmin(r);
            m->right = removemin(r);
            m->left = l;
            return balance(m);
        }
        return balance(p);
    }
    
    bool find(node* p, int k)
    {
        if(!p) return false;
        if(p->key == k) return true;
        else if(k < p->key) return find(p->left, k);
        else return find(p->right, k);
    }
    
    void del(node* p)
    {
        if(!p) return;
        del(p->left);
        del(p->right);
        delete p;
    }
    
    node* nth(node* p, int n)
    {
        if(!p) return p;
        if(size(p->left) + 1 > n) return nth(p->left, n);
        if(size(p->left) + 1 < n) return nth(p->right, n - size(p->left) - 1);
        else return p;
    }
    
public:
    AVL(){root = 0; size_ = 0;}
    
    bool empty(){return size_ == 0;}
    int size(){return size_;}
    void clear()
    {
        size_=0;
        del(root);
        root = 0;
    }
    void insert(int key)
    {
        size_++;
        root = build(root, key);
    }
    void erase(int key)
    {
        size_--;
        root = remove(root, key);
    }
    bool count(int key)
    {
        return find(root, key);
    }
    int nth_element(int n)
    {
        node* p = nth(root, n);
        if(p) return p->key;
        else return 1;
    }
};


int main () {
    int n; cin >> n;
    
    AVL tree;
    
    while(n--)
    {
        char c; cin >> c;
        if(c == 'I')
        {
            int x; cin >> x;
            if(!tree.count(x)) tree.insert(x);
        }
        else if(c == 'D')
        {
            int x; cin >> x;
            if(!tree.count(x)) tree.erase(x);            
        }
        else if(c == 'N')
        {
            int i, j; cin >> i >> j;
            
        }
        else
        {
            int i, j; cin >> i >> j;
            int ans = tree.nth_element(i) - tree.nth_element(j);
            cout << ans << endl;
        }
    }
	return 0;
}
