#include <cstdio>
#include <queue>
using namespace std;

int qnt;
char c, bef;
queue <char> fila;

int main ()
{
	c = getchar ();
	while (c != EOF) {
		qnt = 0;
		bef = 4;
		while (c != '\n') {
			if (c != bef) {
				if (qnt > 1) {
					printf ("%d%c", qnt, fila.front());
					fila.pop();
				}
				qnt = 1;
				fila.push(c);
			}
			else
				qnt++;
			if (qnt > 1 && fila.size() > 1) {
				printf ("1");
				while (fila.size() > 1) {
					printf ("%c", fila.front());
					if (fila.front() == '1')
						printf ("1");
					fila.pop();
				}
				printf ("1");
			}
			bef = c;
			if (qnt == 9) {
				printf ("%d%c", qnt, c);
				fila.pop();
				qnt = 0;
				bef = 3;
			}
			c = getchar();
		}
		if (qnt > 1) {
			printf ("%d%c", qnt, fila.front());
			fila.pop();
		}
		else if (!fila.empty()){
			printf ("1");
			while (!fila.empty()) {
				printf ("%c", fila.front());
				if (fila.front() == '1')
					printf ("1");
				fila.pop();
			}
			printf("1");
		}
		printf("\n");
		c = getchar();
	}

	return 0;
}
