#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

vector<vector<string>> vec;

bool operator < (vector<string> &v1, vector<string> &v2) {
	if (v1[0] < v2[0])
		return true;
	if (v1[0] > v2[0])
		return false;
	if (v1[1] == v2[1]) {
		if (v1[2] < v2[2])
			return true;
		if (v1[2] > v2[2])
			return false;
	}

}

// P -> A
// M -> B
// G -> C
int main ()
{
	int n;
	scanf ("%d", &n);
	char arr[150], name[150];
	while (scanf ("%d", &n), n) {
		for (int i = 0; i < n; i++) {
			getchar ();
			scanf ("%[^\n]", name);
			scanf ("%s", arr);
			vec.push_back ({arr});
		}

	}

	return 0;
}
