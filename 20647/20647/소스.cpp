#include <iostream>
#include <vector>

using namespace std;
int arr[100];
int N;
int a, b;
vector<bool> visited[100];
vector<int> v[100];
int count1 = 0;
int numb;
int sum = 0;
void dfs(int x) {
	for (int i = 1; i <= N; i++) {
		if (visited[x].at(i) == false) {
			count1++;
			visited[x].at(i) = true;
			dfs(i);
		}
	}
	for (int i = 0; i*i < count1; i++) {
		numb = i;
	}
	sum = sum + count1 + numb;
	count1 = 0;
}
int main() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	return 0;
}