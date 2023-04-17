
#include <string.h>

#include <iostream>
using namespace std;
void swapp(char *A, char *B) {
    // cout<<"hello"<<endl;
    char temp[100];
    strcpy(temp, A);
    strcpy(A, B);
    strcpy(B, temp);
}
int main() {
    int z;
    char str[6][10] = { "dog",
                        "horse",
                        "cat",
                        "elephant",
                        "goat",
                        "frog" };
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            z = strcmp(str[i], str[j]);
            // cout<<"z"<<" "<<z<<endl;
            if (z < 0)
                swapp(str[i], str[j]);
        }
    }
    for (int k = 0; k < 6; k++)
        cout << str[k] << endl;
    return 0;
}
