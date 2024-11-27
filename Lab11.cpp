#include <iostream>
#include <string>
#include <regex>

using namespace std;

struct Order {
    int orderNumber;    
    string date;        
    string productCode; 

    string Category() const {
        if (regex_match(productCode, regex("^E\\d{4}$"))) return "Electronics"; //^ - start line, E or C or F - start word, \d{4} - after first word 4 number, $ - end line
        if (regex_match(productCode, regex("^C\\d{4}$"))) return "Clothing";
        if (regex_match(productCode, regex("^F\\d{4}$"))) return "Food";
        return "Unknown Category";
    }
};

int main() {
    Order order;

    cout << "Enter order number: ";
    cin >> order.orderNumber;

    cout << "Enter date (YYYY-MM-DD): ";
    cin >> order.date;

    cout << "Enter product code: ";
    cin >> order.productCode;

    cout << "\nOrder Details:\n";
    cout << "Order Number: " << order.orderNumber << endl;
    cout << "Date: " << order.date << endl;
    cout << "Product Code: " << order.productCode << endl;
    cout << "Product Category: " << order.Category() << endl;

    return 0;
}

