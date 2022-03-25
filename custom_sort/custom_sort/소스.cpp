#include<iostream>
#include<algorithm>
using namespace std;
int N = 10;
int a[10] = { 9, 3, 5, 8, 1, 7, 0, 2, 4, 6 };
pair<int, int> x[1000];

bool compare(int a, int b) // a�� ���� ������ true
{
	// Ȧ������ �������, �� ���� ¦�� ���� �������
	if (a % 2 != b % 2) return a % 2 > b % 2;
	return a < b;
}

bool compare1(pair<int, int> a, pair<int, int> b)
{
	// �μ��� ���� Ŭ ����  ����, �� ���� ���� ������ �ι�° ���� �������� ����
	if(a.first + a.second != b.first + b.second) return a.first + a.second > b.first + b.second;
	return a.second < b.second;	
}

int main()
{
	int i;
	// ���� ���ϴ� ��� custom order�� sort ����
	sort(a, a + N, compare);
	for (i = 0; i < N; i++) cout << a[i] << " ";
	cout << endl;

	x[0].first = 4; x[0].second = 5;
	x[1].first = 2; x[1].second = 3;
	x[2].first = 1; x[2].second = 8;
	x[3].first = 2; x[3].second = -1;
	x[4].first = 1; x[4].second = 15;
	sort(x, x + 5);
	for (i = 0; i < 5; i++) cout << x[i].first << " " << x[i].second << "\n";
	sort(x, x + 5, compare1);
	for (i = 0; i < 5; i++) cout << x[i].first << " " << x[i].second << "\n";
}