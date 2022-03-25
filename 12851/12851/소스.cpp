#include <iostream>
using namespace std;
int N, K;
int arr[100000000];
int dis[100100];
int numb;
void bfs() {
	int start = 0;
	int end = 1;
	arr[0] = N;
	for (int i = 0; i <= 100000; i++) dis[i] = 1000000000;
	dis[N] = 0;
	while (start != end) {
		if (arr[start] == K)
		{
			numb++;
			start++;
			continue;
		}
		for (int i = 0; i < 3; i++) {
			int next = -1;
			if (i == 0) next = arr[start] * 2;
			if (i == 1) next = arr[start] - 1;
			if (i == 2) next = arr[start] + 1;

			if (0 <= next && 100000 >= next) {
				if (dis[next] >= dis[arr[start]] + 1)
				{
					dis[next] = dis[arr[start]] + 1;
					arr[end] = next;
					end += 1;
				}
			}

		}
		start += 1;
	}
}
int main() {
	cin >> N >> K;
	bfs();
	cout << dis[K]<<"\n"<<numb;
}
