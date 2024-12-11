#include <iostream>  
#include <string>  
#include <regex>  //регулярні вирази
using namespace std;  

struct Duplo {  
    int NumOrder;  
    string date;  
    string product; 
    string category; 

    Duplo() : NumOrder(0), date("0000-00-00"), product("Unknown") {}  //конструктор дупло ініціалізує елементи структури та задає їм початковх значень, а : є обов'язковм членом цієї ініціалізації/присвоєння/запобіжник

    string Category() const {  //створюємо категорії які можна задати товару, якщо правильно ввести
        if (regex_match(product, regex("^E\\d{4}$"))) return "Electronics";  //електрика або технічні прилади 
        if (regex_match(product, regex("^C\\d{4}$"))) return "Clothing";     //одяг
        if (regex_match(product, regex("^F\\d{4}$"))) return "Food";         //їжа
        if (regex_match(product, regex("^T\\d{4}$"))) return "Toys";         //іграшки
        if (regex_match(product, regex("^A\\d{4}$"))) return "Adventures";   //пригоди, товари для пригод
        if (regex_match(product, regex("^B\\d{4}$"))) return "Build";        //товари для будівництва
        if (regex_match(product, regex("^H\\d{4}$"))) return "HandMade";     //хендмейд
        return "Unknown Category";  //Якщо при вказанні категорії була допущена помилка або користувач не захотів вказувати, буде виведено невідому категорію
    }  

    void InputCategory() {  
        cout << "Enter product category: ";  
        getline(cin, category);  
        if (category.empty()) {  
            category = Category();  
        }  
    }  
};  

int main() {  
    Duplo order; //привязуємо структуру до змінної в main

    cout << "Enter order number: ";  //напиши число замовлення
    cin >> order.NumOrder;  //посилаємося на змінну замовлень та елемент в структурі
    cin.ignore();
    cout << "Enter date (YYYY-MM-DD): ";  //вкажи дату замовлення
    getline(cin, order.date);  //посилаємося на змінну замовлень та елемент в структурі та даємо дозвіл на використання пробілів
    cout << "Enter product code: ";  //напиши код чи айді продукту
    getline(cin, order.product);  //посилаємося на змінну замовлень та елемент в структурі та даємо дозвіл на використання пробілів  

    cout << "\nOrder Details:\n";  //вивід всього
    cout << "Order Number: " << order.NumOrder << endl;  
    cout << "Date: " << order.date << endl;  
    cout << "Product Code: " << order.product << endl;  
    cout << "Product Category: " << order.Category() << endl;  

    return 0;   
}

// regex - це регулярні вирази, вони слугують як опис шаблону символів
//^ - цей елемент є початком регулярного виразу. 
//F & C & E - умова, при якій щоб вивелась потрібна категорія, треба першим символом написати букву. 
//\\d{4} - наступна умова, після написання букви, користувач може написати лише 4 символи. 
//$ - кінець регулярного виразу
