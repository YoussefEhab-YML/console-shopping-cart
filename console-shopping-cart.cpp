#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Product {
    string name;
    double price;
};

int main() {
    // Predefined menu items (e.g., restaurant or electronics)
    vector<Product> menu = {
        {"Burger", 5.99},
        {"Pizza", 8.99},
        {"Salad", 4.50},
        {"Soda", 1.99},
        {"Coffee", 2.50}
    };

    vector<Product> cart;
    double total = 0;
    int mainChoice;

    do {
        // Main menu
        cout << "\n===== Main Menu =====\n";
        cout << "1. View Menu\n";
        cout << "2. View Cart\n";
        cout << "3. Remove Product from Cart\n";
        cout << "4. Checkout\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            // Show product menu and allow adding items
            int menuChoice;
            do {
                cout << "\n===== Product Menu =====\n";
                for (int i = 0; i < menu.size(); i++) {
                    cout << i + 1 << ". " << menu[i].name << " - $" << fixed << setprecision(2) << menu[i].price << "\n";
                }
                cout << menu.size() + 1 << ". Back to Main Menu\n";
                cout << "Select product to add to cart: ";
                cin >> menuChoice;

                if (menuChoice >= 1 && menuChoice <= (int)menu.size()) {
                    cart.push_back(menu[menuChoice - 1]);
                    total += menu[menuChoice - 1].price;
                    cout << menu[menuChoice - 1].name << " added to cart.\n";
                }
                else if (menuChoice == (int)menu.size() + 1) {
                    // Back to main menu
                    break;
                }
                else {
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (true);
        }
        else if (mainChoice == 2) {
            // View cart
            if (cart.empty()) {
                cout << "Cart is empty.\n";
            }
            else {
                cout << "\nCart contents:\n";
                for (int i = 0; i < cart.size(); i++) {
                    cout << i + 1 << ". " << cart[i].name << " - $" << fixed << setprecision(2) << cart[i].price << "\n";
                }
                cout << "Total: $" << fixed << setprecision(2) << total << "\n";
            }
        }
        else if (mainChoice == 3) {
            // Remove product from cart
            if (cart.empty()) {
                cout << "Cart is empty. Nothing to remove.\n";
                continue;
            }
            int removeIndex;
            cout << "Enter product number to remove from cart: ";
            cin >> removeIndex;
            if (removeIndex > 0 && removeIndex <= (int)cart.size()) {
                total -= cart[removeIndex - 1].price;
                cout << cart[removeIndex - 1].name << " removed from cart.\n";
                cart.erase(cart.begin() + removeIndex - 1);
            }
            else {
                cout << "Invalid product number.\n";
            }
        }
        else if (mainChoice == 4) {
            // Checkout
            if (cart.empty()) {
                cout << "Cart is empty. Nothing to checkout.\n";
            }
            else {
                cout << "Checkout complete! Total: $" << fixed << setprecision(2) << total << "\n";
                cart.clear();
                total = 0;
            }
        }
        else if (mainChoice == 5) {
            cout << "Exiting program. Thank you!\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (mainChoice != 5);

    return 0;
}
