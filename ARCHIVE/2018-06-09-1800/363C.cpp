#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 200020;

char str[MAXN];
char arr[MAXN];
int qnt[MAXN];

int main ()
{
	scanf ("%s", str);
	int j = 0;
	qnt[j] = 1;
	arr[j] = str[0];
	for (int i = 1; str[i] != '\0'; i++)
		if (str[i] == arr[j])
			qnt[j]++;
		else {
			if (qnt[j] > 2)	qnt[j] = 2;
			qnt[++j] = 1;
			arr[j] = str[i];
		}
	if (qnt[j] > 2) qnt[j] = 2;

	for (int i = 1; qnt[i]; i++)
		if (qnt[i-1] == 2 && qnt[i] == 2)
			qnt[i] = 1;
	j = 0;
	while (qnt[j]) {
		qnt[j]--;
		putchar (arr[j]);
		if (!qnt[j]) j++;
	}
	putchar ('\n');

	return 0;
}
