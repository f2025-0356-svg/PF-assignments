#include <iostream>
using namespace std;
    
 int days =  7;
 int reading = 4 ;

void inputtemperature(int temp[7][4]) {
    for (int i = 0; i < 7; i++) {
             cout << "Day " << i + 1 << " = " <<endl; 
    for (int j = 0; j < 4; j++) {
              cout << "  Reading " << j + 1 << " = " <<endl;
            cin >> temp[i][j];
         }
     }
}


void HighLowtemperature(int temp[7][4], int &high, int &low) {
    high = temp[0][0];
    low  = temp[0][0];

    for (int i = 0; i < 7; i++) {
                    for (int j = 0; j < 4; j++) {
            if (temp[i][j] > high)
                      high = temp[i][j];
            if (temp[i][j] < low)
                      low = temp[i][j];
        }
    }
}


void Average(int temp[7][4], float avg[7]) {
    for (int i = 0; i < 7; i++) {
        float sum = 0;
        for (int j = 0; j < 4; j++) {
            sum = sum + temp[i][j];
        }
        avg[i] = sum / 4;  
    }
}


void Results(float avg[7], int high, int low) {
    cout << " Daily Average Temperatures = "<<endl;
    for (int i = 0; i < 7; i++) {
        cout << "Day " << i + 1 << " Average = " << avg[i] << endl;
    }

    cout << " Highest Temperature of Week = " << high << endl;
    cout << "Lowest Temperature of Week  = " << low << endl;
}

// Main function
int main() {
    int temperature[7][4];
    float avg[7];
    int highest, lowest;

    
    inputtemperature(temperature);
    
    HighLowtemperature(temperature, highest, lowest);

    
    Average(temperature, avg);

    
    Results(avg, highest, lowest);

    return 0;
}
