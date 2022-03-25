#include <iostream>
#include <algorithm>
using namespace std;
int N, C;
int arr[200100];
int a;
int b;
int answer;
void bin(int x, int y) {    
    if (y <= x + 3) {
        for (int i = y; i >= x; i--) {
            int count = 1;
            int add = arr[1];
            for (int j = 2; j <= N; j++) {
                if (add + i <= arr[j]) {
                    add = arr[j];
                    count++;
                }
            }
            if (count >= C) {
                answer = i;
                return;
            }
        }
    }
    int count = 1;
    int add = arr[1];
    for (int i = 2; i <= N; i++) {
        if (add + (x + y) / 2 <= arr[i]) {
            add = arr[i];
            count++;
        }
    }
    if (count >= C) {
        bin((x + y) / 2, y);
    }
    else {
        bin(x, (x + y) / 2 - 1);
    }
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(0);
    cin >> N >> C;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + N + 1);
    bin(1, arr[N] - arr[1]); 
    cout << answer;
    return 0;
}