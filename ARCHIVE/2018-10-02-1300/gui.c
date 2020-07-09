#include <stdio.h>
#include <stdlib.h>
typedef struct reg {
  int chave;
  char conteudo;
  struct reg *esq;
  struct reg *dir;
}noh;

typedef noh* arvore;

int i = 0;


void imprimeBalanceado (arvore raiz, int cont) {
  if (raiz != NULL) {
    if (cont > 0) {
      int i;
      for (i = 0; i < cont; i++) printf("   ");
    }
    cont++;
    printf("%d\n", raiz->chave);
    if (raiz->esq == NULL) {
      int i;
      for (i = 0; i < cont; i++) 
	printf("   ");
      printf("-\n");
    }
    imprimeBalanceado (raiz->esq, cont);
    imprimeBalanceado (raiz->dir, cont);
    if (raiz->dir == NULL) {
      int i;
      for (i = 0; i < cont; i++)
	printf("   ");
      printf("-\n");
    }
    cont--;
  }
}

noh *insere2 ( int c) {
  noh * n = malloc (sizeof(noh));
  n->chave = c;
  n->esq = NULL;
  n->dir = NULL;
  return n;
}

arvore transforma (char string[], arvore r)
{
  printf ("%d\n", i);
  int aux = 0;
  ++i; // Pulando o '('
  if(string[i] == ')') {
    ++i; // Para o próximo estar em um '('
    return NULL;
  }
  else {
    int bol = 0;
    while(!bol){
      aux += string[i] - '0';
      if(string[i+1] != '('){
	aux *= 10;
      }
      else bol = 1;
      i++; // Isso soma mesmo quando string[i+1] == '(', logo string[i] == '('
    }
    r = insere2(aux);
    printf ("bef_l: %d\n", i);
    r->esq = transforma(string, r->esq);
    printf ("bef_r: %d\n", i);
    r->dir = transforma(string, r->dir);
    ++i;
  }
  return r;
}

int main ()
{
  char s[1000];
  scanf("%s", s);
  arvore raiz = NULL;
  i = 0;
  raiz = transforma(s, raiz);
  printf("sai\n");
	
  imprimeBalanceado(raiz, 0);
	
  return 0;
}
