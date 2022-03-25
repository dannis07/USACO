#include <iostream>
using namespace std;
bool isprime[10000];
int T, a, b;
int q[10000];
int dis[10000];
int impossible;
bool visited[10000];
void Eras() {
	for (int i = 2; i*i < 10000; i++) {
		for (int j = i; i * j < 10000; j++) {
			isprime[i * j] = true;
		}
	}
}
void bfs() {
	impossible = 0;
	int start = 0;
	int end = 1;
	int c;
	q[0] = a;
	visited[a] = true;
	while (start != end) {
		int x = q[start];
		for (int i = 1; i <= 1000; i *= 10) {
			// x에서 i번째 자리수를 바꿔가면서 소수인지 확인
			x = q[start] / (i * 10) * i * 10 + q[start] % i;
			for (int j = 0; j < 10; j++) {
				if (i == 1000 && j == 0) {
					continue;
				}
				if (isprime[x + j * i] == false && visited[x + j * i] != true) {
					visited[x + j * i] = true;
					dis[x + j * i] = dis[q[start]] + 1;
					q[end] = x + j * i;
					end++;
				}
			}
		}
		start++;
	}
}
int main() {
	Eras();
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		bfs();
		cout << dis[b] << "\n";
		for (int i = 0; i < 10000; i++) {
			dis[i] = 0;
			visited[i] = false;
		}
	}
}