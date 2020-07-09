#include <bits/stdc++.h>
using namespace std;

int size, m, space, plate, tam, ans, aux, first, lst;
int arr[1010];
char opt;

int main ()
{
	while (scanf ("%d %d", &size, &m) != EOF) {
		space = size;
		ans = 0;
		for (int i = 0; i < m; i++) {
			scanf (" %c %d ", &opt, &plate);
			if (opt == 'C') {
				scanf (" %d", &tam);
				if (tam <= space) {
					int j;
					for (j = 0, aux = 0; j < size && aux < tam; j++) {
						if (!arr[j]) {
							if (!aux)
								first = j;
							aux++;
						}
						if (arr[j])
							aux = 0;
					}
					if (aux == tam) {
						lst = j;
						for (j = first; j < lst; j++)
							arr[j] = plate;
						space -= tam;
						ans += 10;
					}
				}
			}
			else {
				tam = 0;
				for (int j = 0; j < size; j++)
					if (arr[j] == plate) {
						arr[j] = 0;
						tam++;
					}
				space += tam;
			}
			//printf (" %d\n", space);
			//printf (" %d %c %d %d\n", ans, opt, plate, tam);
		}
		printf ("%d\n", ans);
		for (int i = 0; i <= size; i++)
			arr[i] = 0;
	}

	return 0;
}
