#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> arr;
vector<long long> arr1;
vector<long long> arr_no_repeat;
long long N;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
		arr1.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	int a = arr.at(0);
	arr_no_repeat.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		if (arr[i] != a) {
			arr_no_repeat.push_back(arr[i]);
			a = arr[i];
		}
		
	}
	for (int i = 0; i < N; i++) {
		int a = lower_bound(arr_no_repeat.begin(), arr_no_repeat.end(), arr1.at(i))- arr_no_repeat.begin();
		cout << a << " ";
	}
}