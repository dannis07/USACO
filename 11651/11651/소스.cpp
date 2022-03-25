#include<iostream>
#include<algorithm>
using namespace std;
pair<int, int> x[100010];
int N;

bool compare1(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x[i].first;
		cin >> x[i].second;
	}
	sort(x, x + N, compare1);
	for (int i = 0; i < N; i++) cout << x[i].first << " " << x[i].second << "\n";
}