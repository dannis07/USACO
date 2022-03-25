#include <iostream>
using namespace std;
int q[2][1000000];
bool visited[310][310];
int dx[8]={1, 2, 1, 2, -1, -2, -1, -2 };
int dy[8]={ 2, 1, -2, -1, 2, 1, -2, -1 };
int dis[310][310];
int  n,l,a, b, c, d;
void bfs() {
	int start, end;
	start = 0;
	end = 1;
	q[0][0] = a;
	q[1][0] = b;
	visited[a][b] = true;
	while (start != end) {
		for (int i = 0; i < 8; i++) {
			if (q[0][start] + dx[i] >= 0 && q[0][start] + dx[i] < l && q[1][start] + dy[i] >= 0 && q[1][start] + dy[i] < l) {
				int x_1=q[0][start] + dx[i];
				int y_1 = q[1][start] + dy[i];
				if (!visited[x_1][y_1]) {
					visited[x_1][y_1] = true;
					dis[x_1][y_1] = dis[q[0][start]][q[1][start]]+1;
					q[0][end] = x_1;
					q[1][end] = y_1;
					end += 1;
				}
			}
		}
		if (visited[c][d]) {
			break;
		}
		start += 1;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> a >> b >> c >> d;
		bfs();
		cout << dis[c][d]<<"\n";
		for (int i = 0; i < 310; i++) {
			for (int j = 0; j < 310; j++) {
				visited[i][j] = false;
				dis[i][j] = 0;
			}
		}
	}
	
}