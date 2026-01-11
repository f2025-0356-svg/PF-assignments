#include <iostream>
using namespace std;

int main() {
    int n = 4;

    int mat[4][4] = {
        {1 , 0, 3, 0},
        {15, 35, 35, 45},
        {27, 29, 97, 48},
        {32, 63, 39, 50}
    };

    
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) { 
            for(int j = 0; j < n; j++) {
                cout << mat[i][j] << endl ;
            }
        } else {          
            for(int j = n-1; j >= 0; j--) {
                cout << mat[i][j] << endl ;
            }
        }
    }

    cout << endl;
    return 0;
}
