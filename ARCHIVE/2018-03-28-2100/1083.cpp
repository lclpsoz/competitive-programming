#include <bits/stdc++.h>
using namespace std;

int is_opr (char c)
{
	switch (c) {
		case '^': return 6;
		case '*':
		case '/': return 5;
		case '+':
		case '-': return 4;
		case '>':
		case '<':
		case '=':
		case '#': return 3;
		case '.': return 2;
		case '|': return 1;
	}

	return 0;
}

int is_var (char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return 1;
	return 0;
}

int is_valid (char c)
{
	if (c == '(' || c == ')' || is_var (c) || is_opr (c))
		return 1;
	return 0;
}

void operat (stack<char> &opr, char *str, char *pol, int i, int *j)
{
	//printf ("%c\n", str[i]);
	while (!opr.empty () && (opr.top () != '(' && (is_opr (opr.top ()) >= is_opr (str[i]) || is_opr (opr.top ()) == 0 || is_var (opr.top ())))) {
		  pol[*j] = opr.top ();
		  opr.pop ();
		  *j += 1;
	}
	opr.push (str[i]);
	//printf ("%c\n", str[i]);
}

// Return 0 if Syntax is Wrong
int parsing (char *str, int *i, int brackets)
{
	int err = 1; // No error
	char next = 's'; // Next have to be a var (s from start)
	for (; str[*i] != '\0' && (!brackets || str[*i] != ')'); *i += 1) {
		//printf ("%d\n", *i);
		if (next == 'v' || next == 's') {
			if (str[*i] == '(') {
				*i += 1;
				err = parsing (str, i, 1);
				if (err != 1)
					return err;
			}
			else if (!is_var (str[*i]))
				return 0; // Error
			next = 'o';
		}
		else {
			if (!is_opr (str[*i]))
				return 0; // Error
			next = 'v';
		}
	}
	if (next == 's')
		return 0;
	if (brackets && str[*i] == ')')
		return 1;
	else if (brackets)
		return 0;
	if (next == 'v')
		return 0;
	return 1;
}

int lex (char *str, char *pol)
{
	stack<char> opr;
	int parent = 0;
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		//printf ("%c\n", str[i]);
		switch (str[i]) {
			case '(': if (opr.empty () || is_opr (opr.top ()) || opr.top () == '(')
						  opr.push (str[i]);
					  parent++;
					  break;
			case ')': while (!opr.empty () && opr.top () != '(') {
						  pol[j++] = opr.top ();
						  opr.pop ();
					  }
					  opr.pop ();
					  parent--;
					  break;
			case '^':
			case '*':
			case '/':
			case '+':
			case '-':
			case '>':
			case '<':
			case '=':
			case '#':
			case '.':
			case '|': operat (opr, str, pol, i, &j);
					  break;
			default: opr.push (str[i]);
		}
	}
	while (!opr.empty ()) {
		pol[j++] = opr.top ();
		opr.pop ();
	}
	if (parent)
		return 1;
	pol[j] = '\0';
	return 0;
}

int main ()
{
	char *str = (char*) malloc (sizeof (char) * 1e7);
	char *pol = (char*) malloc (sizeof (char) * 1e7);

	int err = 0;
	char c = getchar ();
	int i = 0;
	int j = 0;
	while (c != EOF) {
		j = 0;
		i = 0;
		err = 0;
		while (c != '\n' && c != EOF) {
			str[i++] = c;
			if (!is_valid (c))
				err = 1;
			c = getchar ();
		}
		str[i] = '\0';
		if (err == 1)
			printf ("Lexical Error!\n");
		else {
			err = parsing (str, &j, 0);
			if (err == 1) {
				lex (str, pol);
				printf ("%s\n", pol);
			}
			else if (err == 0)
				printf ("Syntax Error!\n");
		}
		c = getchar ();
	}

	return 0;
}
