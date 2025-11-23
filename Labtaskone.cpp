#include <iostream>
using namespace std;

int main() {
    float celsius = 25;       
    float fahrenheit;

    fahrenheit = (celsius * 9/5) + 32;   

    cout << celsius<< " C = " << fahrenheit<< " F " << endl;

    return 0;
}