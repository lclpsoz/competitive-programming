#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

// Only save a line that
// vx and vy are coprimes
// and vx is positive!!!
typedef struct reg2 {
	int ox, oy;
	int vx, vy;
} line;

inline bool operator<(const reg2& lhs, const reg2& rhs)
{
	if (lhs.ox != rhs.ox)
		return lhs.ox < rhs.ox;
	else if (lhs.oy != rhs.oy)
		return lhs.oy < rhs.oy;
	else if (lhs.vx != rhs.vx)
		return lhs.vx < rhs.oy;
	else if (lhs.vy != rhs.vy)
		return lhs.vy < rhs.vy;
}

int mdc(int a, int b) {
    if(b == 0) return a;
    return mdc(b, a%b);
}

bool in_line (line l, int x, int y)
{
	int a, b, d;
	a = x-l.ox;
	b = y-l.oy;
	d = mdc (abs(a), abs(b));
	a /= d;
	b /= d;
	if (a < 0) {
		a *= -1;
		b *= -1;
	}
	return (a == l.vx && b == l.vy);
}

line new_line (int ox, int oy, int x, int y)
{
	line l = {ox, oy, x-ox, y-oy};
	int d = mdc (abs(l.vx), abs(l.vy));
	l.vx /= d;
	l.vy /= d;
	if (l.vx < 0) {
		l.vx *= -1;
		l.vy *= -1;
	}

	return l;
}

// if line {0,0,0,0}, there's not
// a three point line in points.
line line_3_points (vector<pii> points)
{
	set<line> new_lines;
	int N = points.size();
	line l = {0,0,0,0};
	for (int i = 0; l.vx == 0 && l.vy == 0 && i < N; i++) {
		pii o = points[i];
		for (int j = i+1; j < N; j++) {
			pii t = points[j];
			line l_n = new_line(o.first, o.second, t.first, t.second);
			if (new_lines.insert (l_n).second == 0)
				l = l_n;
		}
	}
}

/*pii line1;
pii ori1;
pii line2;
pii ori2;
bool ans = true;
bool t_ori2 = false;
pair<bool, bool> lines;
int n;

void func (int st) {
	int x, y;
	for (int i = st; i < n; i++) {
		scanf ("%d %d", &x, &y);
		if (!in_line (ori1.first, ori2.second, line1.first, line1.second, x, y)) {
			if (lines.second == false) {
				if (line2.first == 0 && line2.second == 0) {
					if (!t_ori2) {
						ori2 = {x, y};
						t_ori2 = true;
					}
					else
						line2 = new_line (ori2.first, ori2.second, x, y);
				}
			}
			else if (!in_line (ori2.first, ori2.second, line2.first, line2.second, x, y)) {
				ans = false;
				break;
			}
		}
	}
}*/

int main ()
{
	int a, b, d;
	int x, y;
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x4, y4;

	/*scanf ("%d", &n);
	if (n <= 4)
		printf ("YES\n");
	else {
		scanf ("%d %d", &x, &y); // 1º PONTO
		ori1.first = x;
		ori1.second = y;

		scanf ("%d %d", &x1, &y1); // PONTO 2
		// Supondo que sejam da mesma linha
		line1 = new_line (ori1.first, ori2.second, x1, y1);

		scanf ("%d %d", &x2, &y2); // PONTO 3
		if (in_line (ori1.first, ori1.second, line1.first, line1.second, x2, y2)) {
			// Linha confirmada!!! Primeiro ponto fora dessa linha inicia linha 2!!!
			lines.first = true;
			func (3);
		}
		else {
			pii l1_2, l2_1;
			l1_2 = new_line (ori1.first, ori2.second, x2, y2); // NOVA LINHA 1 COM PONTO 3
			l2_1 = new_line (x1, y1, x2, y2); // NOVA LINHA 2 DO PONTO 2 E 3
			scanf ("%d %d", &x3, &y3); // PONTO 4
			// LINHA 1 CORRETA, PONTOS 1, 2 E 4 NA MESMA LINHA:
			if (in_line (ori1.first, ori1.second, line1.first, line1.second, x3, y3)) {
				// printf ("-\n");
				t_ori2 = true;
				ori2 = {x2, y2};
				func (4);
			}
			// l1_2 CORRETA, PONTOS 1, 3, 4
			else if (in_line (ori1.first, ori1.second, l1_2.first, l1_2.second, x3, y3)) {
				// printf ("-\n");
				line1 = l1_2;
				t_ori2 = true;
				// PONTO 2 EM NOVA LINHA:
				ori2 = {x1, y1};
				func (4);
			}
			// l2_1 CORRETA, PONTOS 2, 3 E 4 JUNTOS
			else if (in_line (x1, y1, l2_1.first, l2_1.second, x3, y3)) {
				// printf ("-\n");
				line1 = l1_2;
				ori1 = {x1, y1};
				t_ori2 = true;
				// PONTO 1 EM NOVA LINHA:
				ori2 = {x, y};
				func (4);
			}
			// NAO OCORREM TRES PONTOS NA MESMA LINHA!
			else {
				pii l3_1 = new_line (x, y, x3, y3); // NOVA LINHA 3 DO PONTO 1 e 4
				pii l3_2 = new_line (x1, y1, x3, y3); // NOVA LINHA 3 DO PONTO 2 e 4
				pii l3_3 = new_line (x2, y2, x3, y3); // NOVA LINHA 3 DO PONTO 3 e 4
				scanf ("%d %d", &x4, &y4); // PONTO 5
				// LINHA 1 CORRETA, PONTOS 1, 2 E 5 NA MESMA LINHA:
				if (in_line (ori1.first, ori1.second, line1.first, line1.second, x4, y4)) {
					t_ori2 = true;
					ori2 = {x2, y2};
					func (5);
				}
				// l1_2 CORRETA, PONTOS 1, 3, 5
				else if (in_line (ori1.first, ori1.second, l1_2.first, l1_2.second, x4, y4)) {
					line1 = l1_2;
					t_ori2 = true;
					// PONTO 2 EM NOVA LINHA:
					ori2 = {x1, y1};
					func (5);
				}
				// l2_1 CORRETA, PONTOS 2, 3 E 4 JUNTOS
				else if (in_line (x1, y1, l2_1.first, l2_1.second, x4, y4)) {
					line1 = l2_1;
					ori1 = {x1, y1};
					t_ori2 = true;
					// PONTO 1 EM NOVA LINHA:
					ori2 = {x, y};
					func (5);
				}
				// l3_1 CORRETA
				else if (in_line (x, y, l3_1.first, l3_1.second, x4, y4)) {
					line1 = l3_1;
					ori1 = {x, y}; // PONTO 1

					ori2 = {x1, y1}; // PONTO 2
					t_ori2 = true;
					func (5);
				}
				// l3_2 CORRETA
				else if (in_line (x1, y1, l3_2.first, l3_2.second, x4, y4)) {
					line1 = l3_2;
					ori1 = {x1, y1};

					ori2 = {x, y};
					t_ori2 = true;
					func (5);
				}
				// l3_3 CORRETA
				else if (in_line (x2, y2, l3_3.first, l3_3.second, x4, y4)) {
					line1 = l3_3;
					ori1 = {x2, y2};

					ori2 = {x, y};
					t_ori2 = true;
					func (5);
				}
				else
					ans = false;
			}
		}

		if (ans)
			printf ("YES\n");
		else
			printf ("NO\n");

	}*/

	return 0;
}
