#include <iostream>
using namespace std;
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };
int q[100000][2], begin1;
long long end1;
int l;
int n, a, b, c, d;
int x = 0;
int arr[300][300];
void bfs() {
	begin1 = 0;
	end1 = 1;
	q[0][0] = a;
	q[0][1] = b;
	while (begin1!=end1) {
		for (int i = 0; i < 8; i++) {
			if (q[begin1][0] + dx[i] >= 0 && q[begin1][0] + dx[i] < n && q[begin1][1] + dy[i] >= 0 && q[begin1][1] + dy[i] < n) {
				
				if (arr[q[begin1][0]][q[begin1][1]] + 1 < arr[q[begin1][0] + dx[i]][q[begin1][1] + dy[i]]) {
					q[end1][0] = q[begin1][0] + dx[i];
					q[end1][1] = q[begin1][1] + dy[i];
					arr[q[end1][0]][q[end1][1]] = arr[q[begin1][0]][q[begin1][1]] + 1;
					end1 += 1;
				}
			}
		}
		begin1 += 1;
		if (arr[c][d] < 1000000) break;
	}
}
int main()
{
	cin >> l;
	while (l--){
		cin >> n >> a >> b >> c >> d;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = 1000000;
			}
		}
		arr[a][b] = 0;
		bfs();
		cout << arr[c][d]<<"\n";
	}
}

/*
2206번은 위와 같은 방법으로 해보고 되는지 안되는지 확인
안될시 hint
int arr[1010][1010][2];
arr[x][y][0] : 0,0에서 x,y까지 오는 최단 경로의 길이(벽을 한번도 안부숨)
arr[x][y][1] : 0,0에서 x, y까지 오는 최단 경로의 길이(벽을 한번 부숨)
*/