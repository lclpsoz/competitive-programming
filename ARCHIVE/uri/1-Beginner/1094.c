#include <stdio.h>

struct animal{
	int val;
	float per;
};

int main(){

	int i;
	char id;
	struct animal c = {0, 0}, r = {0, 0}, s = {0, 0};
	int qnt, temp, total;
	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d %c", &temp, &id);
		switch (id){
			case 'C':
				c.val += temp;
				break;
			case 'R':
				r.val += temp;
				break;
			case 'S':
				s.val += temp;
				break;
		}
	}
	
	total = c.val + r.val + s.val;
	c.per = (float)c.val * 100 / (float)total;
	r.per = (float)r.val * 100 / (float)total;
	s.per = (float)s.val * 100 / (float)total;

	printf("Total: %d cobaias\n", total);
	printf("Total de coelhos: %d\n", c.val);
	printf("Total de ratos: %d\n", r.val);
	printf("Total de sapos: %d\n", s.val);
	printf("Percentual de coelhos: %0.2f %\n", c.per);
	printf("Percentual de ratos: %0.2f %\n", r.per);
	printf("Percentual de sapos: %0.2f %\n", s.per);

	return 0;
}
