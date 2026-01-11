#include <iostream>
using namespace std;
int sales[5][7]; 
int revenue[5]; 
void inputSales(int sales[5][7]) {
    for (int i = 0; i < 5; i++) {
        cout << "Enter sales for Product " << i + 1 << endl;
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << " = ";
            cin >> sales[i][j];
        }
    }
}


void calculateRevenue(int sales[5][7], int revenue[5]) {
    for (int i = 0; i < 5; i++) {
        revenue[i] = 0;
        for (int j = 0; j < 7; j++) {
            revenue[i] = revenue[i] + sales[i][j];
        }
    }
}


int findMaxProduct(int revenue[5]) {
    int bestProduct = 1;
    int maxRevenue = revenue[0];

    for (int i = 1; i < 5; i++) {
        if (revenue[i] > maxRevenue) {
            maxRevenue = revenue[i];
            bestProduct = i + 1; 
        }
    }
    return bestProduct;
}


int findBestDay(int sales[5][7]) {
    int bestDay = 1;
    int maxSales = 0;

    for (int j = 0; j < 7; j++) {
        int dailyTotal = 0;
        for (int i = 0; i < 5; i++) {
            dailyTotal = dailyTotal + sales[i][j];
        }
        if (dailyTotal > maxSales) {
            maxSales = dailyTotal;
            bestDay = j + 1; 
        }
    }
    return bestDay;
}


void Results(int revenue[5], int bestProduct, int bestDay) {
    cout << " Weekly Revenue of Each Product:";
    for (int i = 0; i < 5; i++) {
        cout << "Product " << i + 1 << " Revenue = " << revenue[i] << endl;
    }

    cout << " Product with Maximum Revenue = Product " << bestProduct << endl;
    cout << "Best Sales Day Overall = Day " << bestDay << endl;
}


int main() {
    int sales[5][7];
    int revenue[5];
    int bestProduct, bestDay;

    inputSales(sales);

    calculateRevenue(sales, revenue);

    bestProduct = findMaxProduct(revenue);

    bestDay = findBestDay(sales);

    Results(revenue, bestProduct, bestDay);

    return 0;
}
