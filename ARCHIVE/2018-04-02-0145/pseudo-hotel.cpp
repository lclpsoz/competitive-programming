// grafo_1: Grafo inicial com todas as cidades
// grafo_2: Grafo final apenas com cidade 1, n e todas as com hotel (e suas conexoes como arestas de peso 1)
// com_hotel: Array onde 'true' quando a cidade possui hotel

const int MAXN = 1e4+5;
typedef pair <int, int> pii;

vector <pii> grafo_1[MAXN];
vector <int> grafo_2[MAXN];
int com_hotel[MAXN];

// Aplicado primeiro para gerar o grafo_2 somente
// com os caminhos entre cidade 1, n e cidades com
// hotel.
void dijkstra ()
{
	
}
