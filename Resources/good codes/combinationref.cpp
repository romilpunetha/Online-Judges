#include <iostream>
using namespace std;
int main() {
    int N[10];
    int n, temp, k;
    cout << "enter the no of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> N[i];
    for (int j = 0; j < n; j++) {
        for (k = 0; k < (n - 1); k++) {
            temp = N[k];
            N[k] = N[k + 1];
            N[k + 1] = temp;
            for (int z = 0; z < n; z++)
                cout << N[z] << " ";
            cout << endl;
        }
    }

    return 0;
}
