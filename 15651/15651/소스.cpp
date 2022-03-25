#include <iostream>

using namespace std;
int N, M;
int arr[500000];
void dfs(int a) {
	if (a == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[a] = i;
		dfs(a + 1);
	}
}
int main() {
	cin >> N >> M;
	dfs(0);

	return 0;
}