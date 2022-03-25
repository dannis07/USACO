#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100
#define INF 1000000000

using namespace std;
int n=1, result;
int N, M;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector <int> a[MAX];

void maxFlow(int start, int end) {
	while (1) {
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;
					if (y == end) break;
				}
			}
		}
		if (d[end] == -1) break;
		int flow = INF;
		for (int i = end; i != start; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
}
int main() {
	cin >> N >> M;
	int x, y;
	for (int i = 1; i <= N; i++) {
		a[0].push_back(i);
		a[i].push_back(0);
		c[0][i] = 1;
	}
	for (int i = 1; i <= N; i++) {
		cin >> x>> y;
		a[i].push_back(x);
		a[x].push_back(i);
		a[i].push_back(y);
		a[y].push_back(i);
		c[i][y] = 1;
		c[i][x] = 1;
	}
	for (int i = 1; i <= M; i++) {
		a[i].push_back(M + 1);
		a[M + 1].push_back(i);
		c[i][M + 1] = 1;
	}
	maxFlow(0, M+1);
	cout << result;
}
