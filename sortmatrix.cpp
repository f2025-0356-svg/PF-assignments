#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the size of matrix : ";
    cin >> N;

    int matrix[10][10];       
    int numbers[50];         
    int count = 0;            

    
    cout << "Enter the matrix elements: " << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
            numbers[count] = matrix[i][j];
            count++;
        }
    }


    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    
    count = 0;  
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            matrix[i][j] = numbers[count];
            count++;
        }
    }

    
    cout << " Sorted Matrix is folowing : " << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << matrix[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
