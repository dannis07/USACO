#include <iostream>
using namespace std;
int N, M;
int arr[1025][1025];
int sum[1025][1025];
int sum1;
int ans;
int main() {
	int x1, y1, x2, y2;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i][j] = arr[i][j] + sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		ans = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
		cout << ans<<"\n";
	}
}