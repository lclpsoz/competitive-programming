#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n, m;
char str[11000];
vector<char> name;
vector<string> vec;
set<char> vogais, consoantes;

int main () {
    scanf (" %d", &n);
    while (n--) {
        scanf (" %d", &m); //getchar();
        char now[110];
        int p = 0;
        while (m--) {
            str[0] = '\0';
            scanf (" %[^\n]", str); //getchar();
            if (str[0] == '\0') continue;
            //printf ("%s\n", str);
            if (tolower(str[0]) >= 'a' and tolower(str[0]) <= 'z')
                now[p++] = tolower (str[0]);
        }
        now[p] = '\0';
        name.push_back (toupper (now[0]));
        vec.push_back (now);
        for (int i = 0; i < p; i++) {
            char c = now[i];
            if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
                vogais.insert (c);
            else
                consoantes.insert (c);
        }
    }
    int c = len (consoantes);
    int v = len (vogais);
    
    printf ("Nome da Linguagem: ");
    for (char c : name)
        putchar (c);
    putchar ('\n');
    
    printf ("Lista de Palavras:\n");
    for (string s : vec)
        printf ("%s\n", s.c_str());
    printf ("Numero de Vogais: %d\n", v);
    printf ("Numero de Consoantes: %d\n", c);
    printf ("Numero Total de Letras: %d\n", v + c);
    if (c > 0)
        printf ("Tempo para aprender: %.1lf horas\n", (double)(2*v+c)/c);
    else
        printf ("Linguagem Ruim\n");
    
	return 0;
}
