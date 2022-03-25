#include <iostream>
#include <vector>
using namespace std;
int N;
int a;
int arr[5100][5100];
int ans[5100];
int ans1[5100];
bool answer = false;
int visited[5100];
int count1 = 0;
int max1 = 0;
void dfs(int x) {
	if (x == 4) {
		count1 = 0;
		int z, y;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] == ans[i]) {
					z = j;
				}
				if (arr[i][j] == i) {
					y = j;
				}
			}
			count1 += y - z;
			if (z > y) {
				return;
			}
		}
		if (max1 < count1) {
			for (int i = 1; i <= N; i++) {
				ans1[i] = ans[i];
			}
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[arr[x + 1][i]]) {
			visited[arr[x + 1][i]] = true;
			ans[x + 1] = arr[x + 1][i];
			dfs(x + 1);
			visited[arr[x + 1][i]] = false;
		}
	}

}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0);
	for (int i = 1; i <= N; i++) {
		cout << ans1[i] << "\n";
	}

}

