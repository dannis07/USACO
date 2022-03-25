#include <iostream>

using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int arr[10][10];
int arr_s[10][10];
int arr2[2][10];
int N, M;
int max1 = 0;
int count1 = 0;
void dfs1(int c, int v) {
	for (int k = 0; k < 4; k++) {
		if (c + dx[k] >= 0 && c + dx[k] < N && v + dy[k] < M && v + dy[k] >= 0) {
			if (arr_s[c + dx[k]][v + dy[k]] == 0) {
				arr_s[c + dx[k]][v + dy[k]] = 2;
				dfs1(c + dx[k], v + dy[k]);
			}
		}
	}
}
void dfs(int a) {
	for (int i = 0; i < N; i++) {
		if (a == 3) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					arr_s[i][j] = arr[i][j];
				}
			}
			for (int i = 0; i < count1; i++) {
				int x = arr2[0][i];
				int y = arr2[1][i];
				dfs1(x, y);
			}
			int d = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (arr_s[i][j] == 0) {
						d++;
					}
				}
			}
			if (d > max1) {
				max1 = d;
			}
			return;
		}
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				dfs(a + 1);
				arr[i][j] = 0;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				arr2[0][count1] = i;
				arr2[1][count1] = j;
				count1++;
			}
			
		}
	}
	dfs(0);
	cout << max1;
	return 0;
}
