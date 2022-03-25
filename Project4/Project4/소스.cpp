#include <iostream>

using namespace std;
bool visited[110];
int d[110][110];
int N, M;
int cnt = 0;
void dfs(int a) {
	cnt++;
	visited[a] = true;
	for (int i = 1; i <= N; i++) {
		if (d[a][i]==1 && !visited[i]) {
			dfs(i);
		}
	}
}
int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		d[a][b] = 1;
		d[b][a] = 1;
	}
	dfs(1);
	cout << cnt - 1;
	return 0;
}

