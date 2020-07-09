#include<bits/stdc++.h>
using namespace std;

int n;
string str;
stack<char> pilha;
bool resposta;

int main () {
	cin >> n;
	for (int j = 0; j < n; j++) {
		resposta = true;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' or str[i] == '[' or str[i] == '{')
				pilha.push (str[i]);
			else {
				if (str[i] == ')') {
					if (pilha.size() > 0 and pilha.top() == '(')
						pilha.pop();
					else {
						resposta = false;
						break;
					}
				} else if (str[i] == ']') {
					if (pilha.size() > 0 and pilha.top() == '[')
						pilha.pop();
					else {
						resposta = false;
						break;
					}
				} else if (str[i] == '}') {
					if (pilha.size() > 0 and pilha.top() == '{')
						pilha.pop();
					else {
						resposta = false;
						break;
					}
				}
			}
		}
		if (pilha.size() > 0) {
			resposta = false;
			while (pilha.empty() == false)
				pilha.pop();
		}
		if (resposta)
			cout << "S\n";
		else
			cout << "N\n";
	}
	
    return 0;
}