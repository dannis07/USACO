#include <iostream>
#include <vector>

using namespace std;
vector <int> v[101000];
int visited[101000];
int N, M;
int a, b;
int sum = 0;
int count1;
int z;
void dfs(int x) {
	for(int i = 0; i < N; )
	for (int i = 0; i < v[x].size(); i++) {
		z = v[x].at(i);
		if (visited[z]==false) {
			visited[z]== true;
			dfs(z);
		}
	}	
}
int main() {
	cin >> N>>M;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
		cout << "\n";
	dfs(1);
	return 0;
}