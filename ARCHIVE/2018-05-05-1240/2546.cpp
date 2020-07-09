#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e6;

int n, q;
int tree[MAXN];
int lazy[MAXN];

// queremos saber a soma de todos os valores de índice no intervalo [A, B]
int consulta(int no, int i, int j, int a, int b){

	int esquerda = 2*no;     // índice do filho da esquerda
	int direita  = 2*no + 1; // índice do filho da direita
	int meio = (i + j)/2;

	if(lazy[no]){ // se existirem operações atrasadas a serem feitas, temos que fazê-las agora

		tree[no] += lazy[no]*(j - i + 1); // já que somamos lazy[no] a cada valor de i a j, fazemos isso (j-i+1) vezes

		if(i != j){ // se i != j, o nó possui descendentes e temos que atualizar o valor de lazy deles
			lazy[direita]  += lazy[no];
			lazy[esquerda] += lazy[no];
		}

		lazy[no] = 0; // agora que realizamos as operações devidas, zeramos novamente o valor de lazy[no]
	}

	if(i > j || i > b || a > j) return 0; // [i, j] e [a, b] são disjuntos, retornamos 0

	if(a <= i && j <= b) // se [i, j] está contido em [a, b], retornamos o valor do nó inteiro
		return tree[no];

	else{ // retornamos então a soma da função chamada nos dois descendentes

		int soma_esquerda = consulta(esquerda,      i, meio, a, b);
		int soma_direita  = consulta( direita, meio+1,    j, a, b);

		return soma_esquerda + soma_direita;
	}
}

// tree[i] representa o valor contido no nó i da árvore.
// Ou seja, se o nó i representa o intervalo [X, Y],
// tree[i] representa a soma das caixas de X a Y

// lazy[i] representa a soma de todas as operações
// atrasadas que devemos fazer ao nó i

// (no) representa o nó que estamos na função recursiva
// o nó que estamos representa o segmento [i, j]

// vamos somar (valor) a cada um dos índices no intervalo [a, b]

void atualiza(int no, int i, int j, int a, int b, int valor){

	int esquerda = 2*no;     // índice do filho da esquerda
	int direita  = 2*no + 1; // índice do filho da direita
	int meio = (i + j)/2;

	if(lazy[no]){ // se existirem operações atrasadas a serem feitas, temos que fazê-las agora

		tree[no] += lazy[no]*(j - i + 1); // já que somamos lazy[no] a cada valor de i a j, fazemos isso (j-i+1) vezes

		if(i != j){ // se i != j, o nó possui descendentes e temos que atualizar o valor de lazy deles
			lazy[direita]  += lazy[no];
			lazy[esquerda] += lazy[no];
		}

		lazy[no] = 0; // agora que realizamos as operações devidas, zeramos novamente o valor de lazy[no]
	}

	if(i > j || i > b || a > j) return; // se a atualização que vamos fazer não afeta esse nó, encerramos a função

	if(a <= i && j <= b){ // se a operação cobre o nó inteiro

		tree[no] += valor*(j-i+1); // atualizamos o valor do nó

		// se o nó possui descendentes, atualizamos o valor de lazy de cada um deles
		// em vez de chamar a função recursiva. Isso é o que otimiza nosso tempo de execução
		if(i != j){
			lazy[direita] += valor;
			lazy[esquerda] += valor;
		}
	}

	else{ // caso a operação atualize apenas alguns valores do nó, chamamos a função nos dois filhos

		atualiza(esquerda,      i, meio, a, b, valor); // atualizamos o filho da esquerda
		atualiza( direita, meio+1,    j, a, b, valor); // atualizamos o filho da direita

		tree[no] = tree[esquerda] + tree[direita]; // atualizamos o nó que estamos
	}

}

void add(int k, int x) {
	k += n;
	tree[k] += x;
	for (k /= 2; k >= 1; k /= 2) {
		tree[k] = tree[2*k]+tree[2*k+1];
	}
}

void modify(int p, int value) {  // set value at position p
  for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += tree[l++];
    if (r&1) res += tree[--r];
  }
  return res;
}

int main ()
{
	int x;
	while (scanf ("%d %d", &n, &q) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &x);
			modify (i, x);
			for (int i = 1; i <= 17; i++)
				printf ("%4d ", tree[i]);
			putchar ('\n');
		}
		for (int i = 1; i <= 17; i++)
			printf ("%4d ", tree[i]);
		putchar ('\n');

		int y, opt;
		for (int i = 1; i <= q; i++) {
			scanf ("%d %d %d", &opt, &x, &y);
			if (opt == 1) {
				printf ("%d %d : %d\n", x, y, consulta (1, 1, n, x, y));
				printf ("%d %d : %d\n", x, y, query (x, y+1));
			}
			else {
			}
		}

	}

	return 0;
}
