#include <iostream>

using namespace std;
int N, M;
int arr[110000];
int arr1[110000];
int arr2[110000];
int arr_sum[110000];
int a, b;
int initial, final;
int sum;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr_sum[i] = arr_sum[i - 1] + arr[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr1[i] = a;
		arr2[i] = b;
		
	}
	for (int i = 0; i < M; i++) {
		initial = arr1[i]-1;
		final = arr2[i];
		cout << arr_sum[final] - arr_sum[initial]<<"\n";
	}

	return 0;
}