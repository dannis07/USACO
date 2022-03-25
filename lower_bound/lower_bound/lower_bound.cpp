#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> arr;

int main()
{
	int N, i, temp;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		// cin >> arr[i];
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	cout << lower_bound(arr.begin(), arr.end(), 6) - arr.begin() << "\n";
	cout << upper_bound(arr.begin(), arr.end(), 6) - arr.begin() << "\n";
	
}