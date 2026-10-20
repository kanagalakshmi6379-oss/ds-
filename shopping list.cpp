#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> shoppingList;
    int choice;
    string item;

    do
    {
        cout << "\n--- SHOPPING LIST MENU ---\n";
        cout << "1. Add an item\n";
        cout << "2. Remove an item\n";
        cout << "3. Search for an item\n";
        cout << "4. Display all items\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter item to add: ";
                cin >> ws;
                getline(cin, item);
                shoppingList.push_back(item);
                cout << "Item added successfully!\n";
                break;

            case 2:
                cout << "Enter item to remove: ";
                cin >> ws;
                getline(cin, item);

                {
                    auto it = find(shoppingList.begin(),
                                   shoppingList.end(), item);

                    if (it != shoppingList.end())
                    {
                        shoppingList.erase(it);
                        cout << "Item removed successfully!\n";
                    }
                    else
                    {
                        cout << "Item not found!\n";
                    }
                }
                break;

            case 3:
                cout << "Enter item to search: ";
                cin >> ws;
                getline(cin, item);

                if (find(shoppingList.begin(),
                         shoppingList.end(), item)
                    != shoppingList.end())
                {
                    cout << "Item found in the shopping list.\n";
                }
                else
                {
                    cout << "Item not found!\n";
                }
                break;

            case 4:
                if (shoppingList.empty())
                {
                    cout << "Shopping list is empty.\n";
                }
                else
                {
                    cout << "\nShopping List:\n";
                    for (int i = 0; i < shoppingList.size(); i++)
                    {
                        cout << i + 1 << ". "
                             << shoppingList[i] << endl;
                    }
                }
                break;

            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
