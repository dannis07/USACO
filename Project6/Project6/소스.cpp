#include <iostream>

using namespace std;
bool visited[1000];
int arr[100];
void dfs(int a) {
	if (a == 0) {
		return;
	}
	int count = 0;
	for (int i = 1; i < 10; i++) {
		if (!visited) {
			visited[i] = true;
			dfs(i);
			count++;
		}
		cout << count;

	}
	
}
int main() {
	dfs(1);
	return 0;
}