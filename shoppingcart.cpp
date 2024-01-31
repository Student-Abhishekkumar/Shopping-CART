#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    double price;
};

int main() {
    double balance = 100000.0;
    double totalPrice = 0.0;
    char continueShopping = 'y';
    string fullName;

    Product cart[100];  
    int cartSize = 0;

    Product categories[4][6] = {
        {{"Toothpaste"}, {"Colgate", 99}, {"Oral-B", 49}, {"Sensodyne", 99},{"pepsodent", 49},{"Closeup", 29}},
        {{"Detergent"}, {"Tide", 99}, {"Gain", 99}, {"Surf Exel", 49},{"wheel", 49},{"Areal", 29}},
        {{"Tea"}, {"Green Tea", 99}, {"Black Tea", 29}, {"Herbal Tea", 99},{"Reb Label", 99},{"Taja", 99}},
        {{"Soap"}, {"Lifeboy", 99}, {"Dettol", 49}, {"Cinthol", 79}, {"Margaret", 99},{"LUX", 29}}
    };

    cout << "Enter your name: ";
    getline(cin, fullName);

    while (continueShopping == 'y' || continueShopping == 'Y') {
        cout << "------ Available Products ------" << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << categories[i][0].name << endl;
        }
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            const Product* selectedCategory = categories[choice-1];
            int productChoice;
            cout << "Products in this category:" << endl;
            for (int i = 1; i < 6; i++) {
                cout << i << ". " << selectedCategory[i].name << " - Rs." << selectedCategory[i].price << endl;
            }
            cout << "Enter the product number you want to add to the cart: ";
            cin >> productChoice;

            if (productChoice >= 1 && productChoice <= 6) {
                int quantity;
                cout << "Enter the quantity you want to purchase: ";
                cin >> quantity;

                if (quantity > 0) {
                    Product selectedProduct = selectedCategory[productChoice - 1];
                    double productCost = selectedProduct.price * quantity;

                    if (productCost <= balance) {
                        selectedProduct.price = productCost;
                        cart[cartSize] = selectedProduct;
                        cartSize++;
                        totalPrice += productCost;
                        balance -= productCost;
                        cout << "Total Price: Rs." << totalPrice << endl;
                        cout << "Current Balance: Rs." << balance << endl;
                    } else {
                        cout << "Insufficient balance. Please choose a lower quantity." << endl;
                    }
                } else {
                    cout << "Invalid quantity. Please try again." << endl;
                }
            } else {
                cout << "Invalid product choice. Please try again." << endl;
            }
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Continue shopping? (y/n): ";
        cin >> continueShopping;
    }

    cout << "Thank you for shopping with us, " << fullName << "!" << endl;
    cout << "------ Your Purchase Summary ------" << endl;
    for (int i = 0; i < cartSize; i++) {
        cout << "Product: " << cart[i].name << " - Price: Rs." << cart[i].price << endl;
    }
    cout << "Total Price: Rs." << totalPrice << endl;
    return 0;
}