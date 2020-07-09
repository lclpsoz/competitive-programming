#include <stdio.h>

int i;
int n;
double den = 0, ans;

int main (void){

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		den = 1 / (6 + den);

	ans = 3 + den;

	printf("%.10lf\n", ans);

	return 0;
}
