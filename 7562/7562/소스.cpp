#include <iostream>

using namespace std;
int dx[8] = { 1, 2, 1, 2, -1, -2, -1, -2 };
int dy[8] = { 2, 1,-2, -1, 2, 1, -2, -1 };
int I;
int n;
int a, b, c, d;
int arr[300][300];
int count1 = 0;
void dfs(int x, int y) {
	if (x == c && y == d) {
		return;
	}
	for (int k = 0; k < 8; k++) {
		if (x + dx[k] >= 0 && x + dx[k] < n && y + dy[k] >= 0 && y + dy[k] < n) {
			if (arr[x][y] + 1 < arr[x + dx[k]][y + dy[k]]) {
				arr[x + dx[k]][y + dy[k]] = arr[x][y] + 1;
				dfs(x + dx[k], y + dy[k]);
			}
		}
	}
}
int main() {
	cin >> I;
	for (int i = 0; i < I; i++) {
		cin >> n >> a >> b >> c >> d;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = 1000000;
			}
		}
		arr[a][b] = 0;
		dfs(a, b);
		cout << arr[c][d];
	}
	return 0;
}