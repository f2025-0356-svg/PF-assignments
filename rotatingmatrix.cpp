#include <iostream>
using namespace std;

int main() {
    int m = 3, n = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rotated[3][3]; 

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            rotated[j][m - 1 - i] = matrix[i][j];
        }
    }

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
