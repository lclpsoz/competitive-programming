#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+10;
typedef pair<pair<int, int>, pair<int, string>> par;

map<string, par> mp;
char arr[MAXN], arr1[MAXN];
vector<par> vec;

int main ()
{
	while (scanf ("%[^\n]", arr) != EOF) {
		getchar ();
		scanf ("%[^\n]", arr1);
		getchar ();
		mp[arr1];
		mp[arr1].first.first--;
		mp[arr1].second.second = arr1;
		scanf ("%[^\n]", arr1);
		getchar ();
		mp[arr1];
		mp[arr1].first.second--;
		mp[arr1].second.second = arr1;
		scanf ("%[^\n]", arr1);
		getchar ();
		mp[arr1];
		mp[arr1].second.first--;
		mp[arr1].second.second = arr1;
	}
	for (auto pp : mp)
		vec.push_back(pp.second);

	sort (vec.begin(), vec.end());
	printf ("Quadro de Medalhas\n");
	for (par p : vec) {
		cout << p.second.second;
		printf (" %d %d %d\n", -p.first.first, -p.first.second, -p.second.first);
	}

	return 0;
}
