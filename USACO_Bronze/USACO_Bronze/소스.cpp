#include <iostream>
using namespace std;
int N, K;
string arr[110];
int arr1[110];
int sum;
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr1[i] = arr[i].size();
	}
	sum = arr1[0];
	cout << arr[0];
	for (int i = 1; i < N; i++) {
		sum += arr1[i];
		if (sum > K) {
			cout << "\n" << arr[i];
			sum = arr1[i];
		}
		else {
			cout << " "<<arr[i];
		}
	}

	return 0;
}