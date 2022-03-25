#include <iostream>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int arr[5000][5000];
int visited[5000][5000];
int q[2][25000100];
int N;
int count1 = 0;
int x, y;
int end1 = 0;
void check(int a, int b) {
	visited[a][b] = true;
	for (int j = 0; j < 4; j++) {
		if (visited[a + dx[j]][b + dy[j]] == true) {
			arr[a][b] += 1;
			arr[a + dx[j]][b + dy[j]] += 1;
		}
	}
	if (arr[a][b] == 3) {
		q[0][end1] = a;
		q[1][end1] = b;
		end1++;
	}
	for (int j = 0; j < 4; j++) {
		if (arr[a + dx[j]][b + dy[j]] == 3) {
			q[0][end1] = a + dx[j];
			q[1][end1] = b + dy[j];
			end1++;
		}
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		end1 = 0;
		cin >> x >> y;
		x += 2000;
		y += 2000;
		if (visited[x][y] == true) {
			count1--;
		}
		else check(x, y);
		int start = 0;
		while (start != end1) {
			for (int z = 0; z < 4; z++) {
				int stx = q[0][start] + dx[z];
				int sty = q[1][start] + dy[z];
				if (visited[stx][sty] == false) {
					count1++;
					check(stx, sty);
					break;
				}
			}
			start++;
		}
		cout << count1<<"\n";
	}
}