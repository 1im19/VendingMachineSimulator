// BITE1513Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct vendingmachine
{
    string name;
    float price;
    int quantity;
};

void MachineInfo(vendingmachine drink[])
{
    drink[0] = { "Cola\t", 1.50, 10 };
    drink[1] = { "Root Beer", 1.50, 10 };
    drink[2] = { "Lemon-Lime", 1.50, 10 };
    drink[3] = { "Strawberry", 1.50, 10 };
    drink[4] = { "Mountain Dew", 1.50, 10 };
    drink[5] = { "Mirinda Orange", 1.50, 10 };
    drink[6] = { "Pepsi\t", 1.50, 10 };
    drink[7] = { "Lemon Tea", 2.00, 10 };
    drink[8] = { "Grape Soda", 2.00, 10 };
    drink[9] = { "Ice Cream Soda", 2.00, 10 };
    drink[10] = { "Milo\t", 2.00, 10 };
    drink[11] = { "Apple Juice", 2.00, 10 };
    drink[12] = { "Orange Juice", 2.50, 10 };
    drink[13] = { "Guava Juice", 2.50, 10 };
}

void DisplayMachineInfo(vendingmachine drink[])
{
    cout << "No\tDrink Name\tCost\tQuantity" << endl << endl;
    for (int i = 0; i < 14; i++)
    {
        cout << i+1 << "\t" << drink[i].name << "\t" << drink[i].price << setprecision(2) << fixed <<  "\t" << drink[i].quantity << endl;
    }
    cout << endl;
}

void DisplayDrinkPrice(vendingmachine drink[], int drinkchoice)
{
    cout << "Drink Info: " << endl << endl;
    cout << "Drink Name: " << drink[drinkchoice - 1].name << endl;
    cout << "Drink Price: RM" << drink[drinkchoice - 1].price << setprecision(2) << fixed << endl;
}

void Pay(float &change, float totalsale, int amount, vendingmachine drink[], int drinkchoice)
{
    drink[drinkchoice - 1].quantity -= 1;
    totalsale += drink[drinkchoice - 1].price;
    change = amount - drink[drinkchoice - 1].price;
    cout << "Amount dispensed: RM" << amount << endl;
    cout << "Change: RM" << change << endl;
    cout << "\nEnjoy your drink." << endl;
}

void ExitVendingMachineProgram()
{

}

int main()
{
    int drinkchoice;
    float amount, change, totalsale = 0;
    vendingmachine drink[14];

    MachineInfo(drink);
    do
    {
        cout << "Welcome to a Soft Drink Vending Machine" << endl << endl;
        DisplayMachineInfo(drink);
        cout << "Select a drink to dispense: ";
        cin >> drinkchoice;
        if (drinkchoice >= 1 && drinkchoice <= 14)
        {
            if (drink[drinkchoice - 1].quantity > 0)
            {
                cout << endl;
                DisplayDrinkPrice(drink, drinkchoice);
                cout << endl;
                cout << "Please insert the amount of money to purchase, or press 0 to cancel (the maximum amount accepted is RM3.00): RM";
                cin >> amount;
                if (amount > 0 && amount <= 3)
                {
                    if (amount >= drink[drinkchoice].price)
                    {
                        cout << endl;
                        Pay(change, totalsale, amount, drink, drinkchoice);
                        cout << endl;
                    }
                    else
                    {
                        cout << endl;
                        cout << "Not enough amount." << endl;
                        cout << endl;
                    }
                }
                else if (amount < 0)
                {
                    cout << endl;
                    cout << "This machine doesn't accept negative amount" << endl;
                    cout << endl;
                }
                else if (amount > 3)
                {
                    cout << endl;
                    cout << "Sorry, the machine doesn't accept money amounted more than RM3" << endl;
                    cout << endl;
                }
            }
            else
            {
                cout << endl;
                cout << "Sorry, the drink you are ordering has sold out." << endl;
                cout << endl;
            }
        }
        else if (drinkchoice == 15519)
        {
            //ExitVendingMachineProgram();
        }
        else
        {
            cout << "Invalid drink selection" << endl;
        }
    } while (drinkchoice != 15519);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
