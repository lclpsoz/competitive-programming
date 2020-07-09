#include <cstdio>

int n, bef, now, ans, aux;

int main ()
{
	ans = aux = 1;
	scanf ("%d", &n);
	scanf ("%d", &bef);
	for (int i = 1; i < n; i++) {
		scanf ("%d", &now);
		if (now == bef)
			aux++;
		else {
			if (aux > ans)
				ans = aux;
			aux = 1;
		}
		bef = now;
	}
	if (aux > ans)
		ans = aux;
	printf ("%d\n", ans);
	return 0;
}
