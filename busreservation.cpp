#include <iostream>
using namespace std;



void displaySeats(int seats[][10], int rows, int cols) {
    cout <<endl<< "Seat Layout (0 = Empty, 1 = Reserved)"<<endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << seats[i][j] << endl ;
        }
        cout << endl;
    }
}


void reserveSeat(int seats[][10], int rows, int cols) {
    int row, col;
    cout << "Enter row (1-10): ";
    cin >> row;
    cout << "Enter column (1-10): ";
    cin >> col;

             row--; 
    col--; 

    if(row >= 0 && row < rows && col >= 0 && col < cols) {
        if(seats[row][col] == 0) {
            seats[row][col] = 1;
            cout << "Seat reserved successfully! " <<endl;
        } else {
            cout << "Seat already reserved! " <<endl;
        }
    } else {
        cout << "Invalid seat number! " <<endl;
    }
}

void cancelSeat(int seats[][10], int rows, int cols) {
    int row, col;
    cout << "Enter row (1-10): ";
    cin >> row;
    cout << "Enter column (1-10): ";
    cin >> col;

      row--; 
              col--; 

    if(row >= 0 && row < rows && col >= 0 && col < cols) {
        if(seats[row][col] == 1) {
            seats[row][col] = 0;
            cout << "Reservation cancelled! "<< endl;
        } else {
            cout << "Seat is already empty! "<< endl;
        }
    } else {
        cout << "Invalid seat number! " << endl;
    }
}


void countRows(int seats[][10], int rows, int cols) {
    int full = 0, partial = 0, empty = 0;

    for(int i = 0; i < rows; i++) {
        int count = 0;
        for(int j = 0; j < cols; j++) {
            if(seats[i][j] == 1)
                count++;
        }

        if(count == 0)
            empty++;
        else if(count == cols)
            full++;
        else
            partial++;
    }

    cout << " Row Status  " << endl;
    cout << "Fully Occupied Rows: " << full << endl;
    cout << "Partially Occupied Rows: " << partial << endl;
    cout << "Empty Rows: " << empty << endl;
}


int main() {
    int seats[10][10] = {0}; 
    int rows = 10, cols = 10;
    int choice;

    do {
        cout << endl<< "--- Bus Seat Reservation Menu --- " << endl;
        cout << "1. Display Seats" << endl;
        cout << "2. Reserve Seat" << endl;
        cout << "3. Cancel Seat" << endl;
        cout << "4. Count Rows" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1)
            displaySeats(seats, rows, cols);
        else if(choice == 2)
            reserveSeat(seats, rows, cols);
        else if(choice == 3)
            cancelSeat(seats, rows, cols);
        else if(choice == 4)
            countRows(seats, rows, cols);
        else if(choice == 5)
            cout << "Program Ended"<< endl;
        else
            cout << "Invalid choice!" << endl;

    } while(choice != 5);

    return 0;
}
