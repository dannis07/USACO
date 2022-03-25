#include <iostream>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int arr[5000][5000];
int visited[5000][5000];
int N;
int x, y;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		visited[x][y] = true;
		for (int j = 0; j < 4; j++) {
			if (visited[x + dx[j]][y + dy[j]] == true) {
				arr[x][y] += 1;
			}
		}
	}
	for (int j = 0; j < 5; j++) {
		for (int z = 0; z < 5; z++) {
			if (visited[j][z]) {
				cout << arr[j][z] << " ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << endl;
	}
}