#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e7;

bool adj[30][30];
bool vert[30];

int n;
char c;
char arr[105];
map<int, string> mp1;
map<int, string> mp2;
string strs[30];
char mat[30][N];

bool dfs (int v) {
	// printf ("|%d\n", v);
	if (vert[v]) return false;
	vert[v] = true;
	for (int i = 0; i < 26; i++)
		if (adj[v][i])
			if (dfs (i) == false)
				return false;
	vert[v] = false;
	return true;
}

string fill (int v) {
	if (mp2[v].length())
		return mp2[v];
	string &aux = mp1[v];
	if (aux.length() == 1 && aux.at(0) == (v+'a'))
		return mp2[v] = aux;
	mp2[v] = "";
	for (int i = 0; i < aux.length(); i++) {
		mp2[v] += fill (aux.at(i)-'a');
	}

	return mp2[v];
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < 26; i++)
		mp1[i] = 'a'+i;
	for (int i = 0; i < n; i++) {
		scanf (" %c %s ", &c, arr);
		mp1[c-'a'] = arr;
		for (int j = 0; arr[j] != '\0'; j++)
			adj[c-'a'][arr[j]-'a'] = true;
	}

	bool ans = true;
	for (int i = 0; i < 26; i++) {
		ans = dfs (i);
		if (!ans) break;
	}

	if (!ans)
		printf ("-1\n");
	else {
		for (int i = 0; i < 26; i++) {
			mp2[i] = fill (i);
			// cout << mp2[i] << '\n';
		}

		for (int i = 0; i < 26; i++) {
			strs[i] = mp2[i];
		}

		int xx;
		scanf ("%d ", &xx);
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < strs[i].length(); j++)
				mat[i][j] = strs[i][j];
		for (int ll = 0; ll < xx; ll++) {
			c = getchar ();
			c -= 'a';
			for (int i = 0; mat[c][i] != '\0'; i++)
				putchar (mat[c][i]);
			// cout << strs[c-'a'];
		}
		putchar ('\n');
	}


	return 0;
}
