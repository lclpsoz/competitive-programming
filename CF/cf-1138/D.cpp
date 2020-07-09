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


int longestPrefixSuffix(string s) 
{ 
    int n = s.length(); 
  
    int lps[n]; 
    lps[0] = 0;
    int len = 0; 
  
    int i = 1; 
    while (i < n) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else
        { 
            if (len != 0) 
            { 
                len = lps[len-1]; 
            } 
            else
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1]; 

    return res; 
} 

int main () {
string s, t;
	ios::sync_with_stdio (false); // DON'T FORGET!
	cin >> s >> t;
	if (len (t) > len (s))
		cout << s << '\n';
	else {
		int qnt = 0, qnt0 = 0;
		int qT = 0, qT0 = 0;
		for (int i = 0; i < len (s); i++)
			if(s[i] == '1') ++qnt;
			else qnt0++;
		for (int i = 0; i < len (t); i++)
			qT += t[i] == '1', qT0 += t[i] == '0';
		int lS = len (s);
		if (qnt >= qT and qnt0 >= qT0) {
			cout << t;
			lS -= len (t);
			qnt -= qT;
			qnt0 -= qT0;
		}
		qT = qT0 = 0;
		int over = longestPrefixSuffix (t);
		for (int i = over; i < len (t); i++)
			qT += t[i] == '1', qT0 += t[i] == '0';
		while (qnt >= qT and qnt0 >= qT0) {
			cout << t.substr (over, len (t) - over);
			lS -= len (t)-over;
			qnt -= qT;
			qnt0 -= qT0;
		}	
		while (qnt--) {cout << '1', --lS; }
		while (lS--) cout << '0';
		cout << '\n';
	}

	return 0;
}
