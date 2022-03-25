#include <iostream>
#include <vector>

using namespace std;
vector<int> v[101000];
bool visited[101000];
int N, a, b;
int sum = 0;
int count1 = 0;
int z;
int m;
int o;
int numb(int x) {
	int count = 0;
	m = 0;
	z = 0;
	for (int i = 0; i < v[x].size(); i++) {
		o = v[x].at(i);
		if (visited[o] == false) {
			z++;
		}
	}
	for (int i = 1; i <z+1; i*=2) {
		count++;
	}
	if (z != 0) {
		return count;
	}
	return 0;
}
void dfs(int x) {
	count1 += numb(x);
	for (int j = 0; j < v[x].size(); j++) {
		o = v[x].at(j);
		if (visited[o] == false) {
			visited[o] = true;
			count1 += 1;
			dfs(o);
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[1] = true;
	dfs(1);
	cout << count1;
	return 0;
}