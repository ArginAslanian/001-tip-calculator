/**
 * Programmer: Argin Aslanian
 * Purpose: Calculate the tip amount given totalBill, tipRate
 *          Display tipAmount and newTotal to the user.
 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

//Function Decelerations.
double getTipAmount(double totalBill, double tipRate);
double getUserInput();
double negativeNumberValidation(double &value);

int main() {

    //Initialize variables.
    double totalBill = 0, tipRate = 0, tipAmount = 0, newTotalBill = 0;

    //Get the bill amount.
    cout << "What is the bill amount? $";
    totalBill = getUserInput();

    //Get the tip rate.
    cout << "What is the tip rate?";
    tipRate = getUserInput();

    //Calculate tip amount and new total bill.
    tipAmount = getTipAmount(totalBill, tipRate);
    newTotalBill = totalBill + tipAmount;

    //Display to the user.
    cout << fixed << setprecision(2) << endl;
    cout << "Tip amount: $" << fixed << setprecision(2) << tipAmount << endl;
    cout << "Total: $" << newTotalBill << endl;

    return 0;
}

double getTipAmount(double totalBill, double tipRate) {

    //Initialize a return value.
    double tipAmount = 0;

    //Convert tip rate entered into percentage.
    tipRate = tipRate / 100;

    //Calculate tip amount.
    tipAmount = tipRate * totalBill;

    return tipAmount;
}

double getUserInput() {
    //Initialize a return value.
    double retVal = 0;

    //Validate user input. Do not allow non-numeric values.
    while(!(cin >> retVal)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid Input - please try again... ";
    }

    //Validate that the value is not negative.
    retVal = negativeNumberValidation(retVal);

    return retVal;
}

double negativeNumberValidation(double &value) {

    //If the value was negative, keep asking the user for a positive numeric input.
    while(value < 0) {
        cout << "Invalid Input: Enter a positive number... ";
        while(!(cin >> value)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid Input - please try again... ";
        }
    }

    return value;
}
