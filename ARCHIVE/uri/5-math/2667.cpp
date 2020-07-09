#include <bits/stdc++.h>
using namespace std;

int i;
int sum;
char str[1000];

int main (){

	scanf("%s", str);

	i = 0;
	while (str[i++] != '\0')
		sum += str[i-1] - '0';

	printf("%d\n", sum%3);

	return 0;
}
