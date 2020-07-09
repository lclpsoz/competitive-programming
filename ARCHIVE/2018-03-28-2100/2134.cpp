#include <bits/stdc++.h>
using namespace std;

map<string, int> mapa;
std::map<string, int>::iterator it;
string nome, resposta;
int n, ponto, menor, instancia;

int main(){
	instancia = 1;
	while (scanf("%d", &n) != EOF)
	{
		cout << "Instancia " << instancia << '\n';
		for (int i = 0; i < n; ++i)
		{
			cin >> nome;
			scanf ("%d", &ponto);
			if (!mapa[nome] || (mapa[nome] && mapa[nome] > ponto))
				mapa[nome] = ponto+1;
		}
		it = mapa.begin();
		menor = it->second;
		resposta = it->first;
		for (; it != mapa.end(); ++it)
		{
			if (it->second < menor || it->second == menor){
				menor = it->second;
				resposta = it->first;
			}
		}
		mapa.clear();
		cout << resposta << '\n';
		cout << '\n';
		++instancia;
	}

	return 0;
}
