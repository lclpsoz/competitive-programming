#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

llu len, num;

int main (){

	scanf("%llu %llu", &len, &num);

	printf("%llu\n", (len-num+1)*(len-num+1)+(num-1));

	return 0;
}
