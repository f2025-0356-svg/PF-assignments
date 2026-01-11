#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


struct Order {
    int orderID;
    string customerName;
    int numItems;
    double pricePerItem;
};

int main() {
    vector<Order> orders;  
    int n;

    cout << "Enter number of orders: ";
    cin >> n;


    for(int i = 0; i < n; i++) {
        Order ord;
        cout << endl << "Order " << i + 1 << " details: " << endl;

        cout << "Order ID: ";
        cin >> ord.orderID;
        cin.ignore(); 

        cout << "Customer Name: ";
        getline(cin, ord.customerName);

        
        do {
            cout << "Number of items: ";
            cin >> ord.numItems;
        } while(ord.numItems <= 0);

        do {
            cout << "Price per item: ";
            cin >> ord.pricePerItem;
        } while(ord.pricePerItem <= 0);

        orders.push_back(ord);
    }

    
    ofstream outFile("priority_orders.txt");
    cout << "\nHigh-value orders (total > 5000):\n";
    for(int i = 0; i < orders.size(); i++) {
        double total = orders[i].numItems * orders[i].pricePerItem;
        if(total > 5000) {
            cout << "Order ID: " << orders[i].orderID 
                 << ", Customer: " << orders[i].customerName
                 << ", Total: " << total << endl;

            
            outFile << orders[i].orderID << "," 
                    << orders[i].customerName << ","
                    << orders[i].numItems << "," 
                    << orders[i].pricePerItem << "," 
                    << total << "\n";
        }
    }
    outFile.close();

    
    ifstream inFile("priority_orders.txt");
    string line;
    cout <<  endl<< "Reading priority orders from file: " << endl;
    while(getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}
