#include <iostream>
 
using namespace std;
int N, M;
int arr[500000];
bool check[1000000];
void dfs(int a) {
	if (a == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			if (arr[a - 1] >= i) {
			}
			else {
				check[i] = true;
				arr[a] = i;
				dfs(a + 1);
				check[i] = false;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	dfs(0);
	
	return 0;
}