#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<char, string>> pcs;

int n;
char arr[1000], c;
int x;
string str;
vector<pcs> vec;

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		vec.clear();
		while (n--) {
			scanf ("%s %c %d", arr, &c, &x);
			str = arr;
			vec.push_back ({x, {c, arr}});
		}
		sort (vec.begin(), vec.end());
		for (pcs p : vec)
			cout << p.second.second << '\n';
	}

	return 0;
}
