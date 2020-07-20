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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 30100;

int trie[N][300];
vector<pii> cl;
int enTrie;

void add(char *word) {
	int p = 0;
	int pTrie = 0;
	while(word[p] != '\0') {
		if(trie[pTrie][word[p]] == 0) {
			trie[pTrie][word[p]] = enTrie++;
			cl.push_back({pTrie, word[p]});
		}
		pTrie = trie[pTrie][word[p++]];
	}
	trie[pTrie]['-'] = 1;
	cl.push_back({pTrie, '-'});
}

int main () {
	int n, m;
	char text[102], word[102];
	while(scanf("%d %d", &n, &m) != EOF) {
		for(pii p : cl)
			trie[p.x][p.y] = 0;
		cl.clear();
		enTrie = 1;
		scanf(" %s", text);
		while(m--) {
			scanf(" %s", word);
			add(word);
		}
		int ans = 0;
		for(int st = 0; st < n; st++) {
			int enSt = n; // not inclusive
			for(int i = st; i < enSt; i++) {
				int pText = i;
				int pTrie = 0;
				while(pText < enSt and trie[pTrie][text[pText]]) {
					pTrie = trie[pTrie][text[pText]];
					if(trie[pTrie]['-']) {
						enSt = pText;
						break;
					}
					pText++;
				}
			}
			// printf("st = %d, enSt = %d\n", st, enSt);
			// ans += enSt - st;
			// Check if palindrome
			for(int r = st+1; r <= enSt; r++) {
				int sz = r-st;
				bool pal = true;
				for(int i = 0; pal and i < sz/2; i++)
					if(text[st+i] != text[st+sz-1-i])
						pal = false;
				// if(pal)
				// 	printf("  [%d, %d]\n", st, r-1);
				ans += pal;
			}
		}
		printf("%d\n", ans);
	}


	return 0;
}
