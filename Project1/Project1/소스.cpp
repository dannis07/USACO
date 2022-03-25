#include <iostream>
#define MAX 1000000
using namespace std;
int K;
int check;
int arr[MAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 2; i * i <= MAX; i++) {
        for (int v = 2; v*i <= MAX; v++) {
            arr[v*i] = true;
        }
    }
    arr[1] = true;
    arr[2] = true;
    while (true) {
        cin >> K;
        if (K == 0) {
            break;
        }
        int sum = -1;

        for (int i = 3; i <= K / 2; i+=2) {
            if (arr[i] == false&& arr[K - i] == false) {
                sum = 0;
                check = i;
                cout << K << " = " << check << " + " << K - check << "\n";
                break;
            }
        }
        if (sum == -1) {
            cout << "Goldbach's conjecture is wrong." << "\n";
        }
        
    }
    return 0;
    
 }
