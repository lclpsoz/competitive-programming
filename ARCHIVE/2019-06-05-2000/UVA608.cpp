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

int n;
string s;
vector<string> even, up;
bool arr[30];

pair<string, string> div (string str) {
	string l = "";
	int i = 0;
	for (; str[i] != ' '; i++)
		l += str[i];
	string r = "";
	++i;
	for (; str[i] != ' '; i++)
		r += str[i];
	
	return {l, r};
}

string inv (string str) {
	pair<string, string> p = div (str);
	
	return p.x + p.y + " up";
}


int main () {
// 	cin.tie (0);
// 	ios::sync_with_stdio (false);
	
	cin >> n;
// 	cin.ignore ();
	while (n--) {
		memset (arr, 0, sizeof arr);
		even.clear(), up.clear();
		for (int i = 0; i < 3; i++) {
			cout << "HERE\n";
			do {
				getline (cin, s);
			} while (s == "");
// 			cout << s << '\n';
			int q = 0;
			char ax;
			for (int i = 0; i < len (s); i++) {
				if (q == 2) {
					ax = s[i];
					break;
				}
				if (s[i] == ' ') ++q;
			}
			
			if (ax == 'u')
				up.push_back (s);
			else if (ax == 'd')
				up.push_back (inv (s));
			else
				even.push_back (s);
		}
  		cout << len (even) << ' ' << len (up) << '\n';
		
		assert (len (even) < 3);
		
		// Clear EVEN:
		for (string str : even)
			for (int i = 0; i < len (str); i++)
				if (str[i] >= 'A' and str[i] <= 'L')
					arr[str[i]-'A'] = true;
		
		if (len (even) == 2) {
			
			bool ans = false;
			pair<string, string> p = div (up.back());
// 			cout << p.x << " | " << p.y << '\n';
			for (char c : p.x) {
				int v = c - 'A';
				if (!arr[v]) {
					assert (!ans);
					printf ("%c is the counterfeit coin and it is heavy.\n", v+'A');
					ans = true;
				}
			}
			for (char c : p.y) {
				int v = c - 'A';
				if (!arr[v]) {
					assert (!ans);
					printf ("%c is the counterfeit coin and it is light.\n", v+'A');
					ans = true;
				}
			}
		} else if (len (even) == 1) {
			map<char, int> mp;
			vector<string> esq, dir;
			for (string str : up) {
				pair<string, string> p = div (str);
				esq.push_back (p.x);
				dir.push_back (p.y);
			}
			
			for (string str : esq)
				for (char c : str)
					mp[c]++;
			bool light, heavy;
			char ans;
			light = heavy = false;
// 			printf ("1_HERE!\n");
			for (auto p : mp)
				if (p.y == 2 and !arr[p.x-'A']) {
					assert (!light);
					light = true;
					ans = p.x;
				}

// 			printf ("HERE!\n");
			mp.clear();
			for (string str : dir)
				for (char c : str)
					mp[c]++;
			for (auto p : mp)
				if (p.y == 2 and !arr[p.x-'A']) {
					assert (!heavy and !light);
					heavy = true;
					ans = p.x;
				}
				
			printf ("%c is the counterfeit coin and it is ", ans);
			if (!light)
				printf ("light.\n");
			else
				printf ("heavy.\n");
		} else { // NO EVEN
			map<char, int> mp;
			for (string str : up)
				for (int i = 0; i < 4; i++)
					mp[str[i]]++;
				
			bool ans = false;
				
			for (auto p : mp)
				if (p.y == 3) {
// 					printf ("C: %c\n", p.x);
					assert (!ans);
					printf ("%c is the counterfeit coin and it is heavy.\n", p.x);
					ans = true;
				}
				
			mp.clear();
			for (string str : up)
				for (int i = 5; i < 9; i++) {
// 					printf ("[%c]", str[i]);
					mp[str[i]]++;
				}
				
			for (auto p : mp)
				if (p.y == 3) {
// 					printf ("-C: %c\n", p.x);
					assert (!ans);
					printf ("%c is the counterfeit coin and it is light.\n", p.x);
				}
		}
	}
	

	return 0;
}
