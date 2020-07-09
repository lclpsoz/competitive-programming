#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int h, m;
int n;
double arr[MAXN];
double total;
double sum;

int main ()
{
	while (scanf ("%d %d", &h, &m) != EOF) {
		n = (h*60)/m;
		total = 0.0;
		for (int i = 0; i < n; i++) {
			scanf ("%lf", &arr[i]);
			total += arr[i];
		}
		total /= n;
		sum = 0;
		for (int i = 0; i < n; i++)
			sum += (arr[i]-total)*(arr[i]-total);
		printf ("%0.5lf\n", sqrt(sum/(n-1)));
	}

	return 0;
}
