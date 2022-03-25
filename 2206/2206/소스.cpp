#include <iostream>

using namespace std;
int MMAX = 1000010;
int N, M;
int arr[1100][1100];
int dist[1100][1100][2];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int q[2000010][3];
int begin1, end1;
int a, b;
int c, d;
void bfs() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			dist[i][j][0] = MMAX;
			dist[i][j][1] = MMAX;
		}
	}
	dist[0][0][0] = 1;
	begin1 = 0;
	end1 = 1;
	q[0][0] = 0;
	q[0][1] = 0 ;
	q[0][2] = 0;
	while (begin1 != end1) {
		int x = q[begin1][0], y = q[begin1][1], z=q[begin1][2];
		for (int i = 0; i < 4; i++) {
			int newx = x + dx[i], newy = y + dy[i];
			if (newx >= 0 && newx < N && newx >= 0 && newy < M) {
				if (arr[newx][newy] == 0)
				{
					if (dist[x][y][z] + 1 < dist[newx][newy][z]) {
						dist[newx][newy][z] = dist[x][y][z] + 1;
						q[end1][0] = newx;
						q[end1][1] = newy;
						q[end1][2] = z;
						end1 += 1;
					}
				}
				else if(z == 0)
				{
					if (dist[x][y][0] + 1 < dist[newx][newy][1]) {
						dist[newx][newy][1] = dist[x][y][0]+1;
						q[end1][0] = newx;
						q[end1][1] = newy;
						q[end1][2] = 1;
						end1 += 1;
					}
				}
				
			}
		}
		begin1 += 1;
		if (dist[c][d][0] < MMAX || dist[c][d][1] < MMAX) break;
	}
}
int main() {
	int i, j;
	int max1 = MMAX;
	cin >> N >> M;
	c = N - 1;
	d = M - 1;
	string temp;
	for (i = 0; i < N; i++) {
		cin >> temp;
		for (j = 0; j < M; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}

	bfs();

	if (max1 > dist[c][d][0]) {
		max1 = dist[c][d][0];
	}
	else if (max1 > dist[c][d][1]) {
		max1 = dist[c][d][1];
	}

	if (max1 == MMAX) {
		cout << "-1";
	}
	else {
		cout << max1;
	}
	return 0;
}