#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
typedef pair<string, string> pa;

char arr1[MAXN], arr2[MAXN];
vector<pa> vec;
map<string, bool> mortos;

int main ()
{
	while (scanf ("%s %s", arr1, arr2) != EOF) {
		if (!mortos[arr1])
			vec.push_back ({arr1, arr2});
		mortos[arr2] = true;
	}
	sort (vec.begin(), vec.end());
	string now = "";
	int qnt = 0;
	printf ("HALL OF MURDERERS\n");
	for (pa p : vec) {
		if (qnt && p.first != now) {
			cout << now;
			printf (" %d\n", qnt);
			now = "";
			qnt = 0;
		} if (p.first == now) {
			qnt++;
		} else if (!mortos[p.first]) {
			now = p.first;
			qnt = 1;
		} else
			qnt = 0;
	}
	if (qnt) {
		cout << now;
		printf (" %d\n", qnt);
		now = "";
	}

	return 0;
}
