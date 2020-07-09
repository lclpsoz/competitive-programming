#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n, obj, c;
int arr[MAXN];
int total;
double ans;

int main ()
{
	while (scanf ("%d %d", &n, &obj), n || obj) {
		total = 0;
		arr[n] = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &arr[i]);
			total += arr[i];
		}
		if (total == obj)
			printf (":D\n");
		else if (total < obj)
			printf ("-.-\n");
		else {
			sort (arr, arr+n, greater<int>());
			// printf ("%d\n", arr[0]);
			ans = (double) arr[0];
			int i = 0;
			c = 1;
			while (obj > 0) {
				int dif = (arr[i]-arr[i+1]);
				//printf ("obj: %d\n", obj);
				//printf ("dif: %d\n", dif);
				if (c*dif <= obj) {
					ans -= dif;
					obj -= c*dif;
					i++;
					c++;
				}
				else {
					ans -= ((double)obj/((double)c));
					obj = 0;
				}
			}
			printf ("%0.4lf\n", ans);
		}
	}

	return 0;
}
