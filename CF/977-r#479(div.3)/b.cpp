#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n;
map<string, int> mp;
char arr[200];
char aux[3];

int main ()
{
	scanf ("%d", &n);
	scanf ("%s", arr);
	for (int i = 0; i < n-1; i++) {
		aux[0] = arr[i];
		aux[1] = arr[i+1];
		aux[2] = '\0';
		mp[aux]++;
	}

	int maxi = 0;
	string str;
	for (auto p : mp) {
		if (p.y > maxi) {
			maxi = p.y;
			str = p.x;
		}
	}

	cout << str << '\n';


	return 0;
}
