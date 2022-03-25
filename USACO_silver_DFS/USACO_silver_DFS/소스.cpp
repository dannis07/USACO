#include <iostream>
#include <vector>
using namespace std;
int N, M;
int a, b;
bool visited[10000];
int check[10000];
int arr1[10000];
int arr2[10000];
int addition = 0;
void dfs(int x, int y) {
	cout << y << endl;
	for (int i = 1; i <= N; i++) {
		if (x == N + 1) {
			return;
		}
		if (!visited[arr1[x]]) {
			visited[arr1[x]] = true;
			dfs(x + 1, y + 1);
		}
		else if (!visited[arr2[x]]) {
			visited[arr2[x]] = true;
			dfs(x + 1, y + 1);
		}
		else dfs(x + 1, y);
	}
	
}
int main() {
	int count = 100000;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		arr1[i] = a;
		arr2[i] = b;
		if (a < count) {
			count = a;
		}
	}
	
	dfs(1, 0);
}