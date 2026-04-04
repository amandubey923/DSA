#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

struct Expense {
    string date, category, description, mode, needWant;
    float amount;
};

void addExpense() {
    Expense e;
    cout << "\nEnter Date (DD-MM-YYYY): ";
    cin >> e.date;
    cout << "Enter Category: ";
    cin >> e.category;
    cin.ignore();
    cout << "Enter Description: ";
    getline(cin, e.description);
    cout << "Enter Amount: ";
    cin >> e.amount;
    cout << "Payment Mode (Cash/UPI/Card): ";
    cin >> e.mode;
    cout << "Need or Want: ";
    cin >> e.needWant;

    ofstream file("expenses.txt", ios::app);
    file << e.date << "," << e.category << "," << e.description << ","
         << e.amount << "," << e.mode << "," << e.needWant << "\n";

    cout << "\nExpense Added Successfully!\n";
}

vector<Expense> loadExpenses() {
    vector<Expense> list;
    ifstream file("expenses.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Expense e;
        string amt;

        getline(ss, e.date, ',');
        getline(ss, e.category, ',');
        getline(ss, e.description, ',');
        getline(ss, amt, ',');
        getline(ss, e.mode, ',');
        getline(ss, e.needWant, ',');

        e.amount = stof(amt);
        list.push_back(e);
    }
    return list;
}

void viewExpenses() {
    vector<Expense> list = loadExpenses();
    cout << "\n----- All Expenses -----\n\n";

    for (auto &e : list) {
        cout << e.date << " | " << e.category << " | "
             << e.description << " | ₹" << e.amount 
             << " | " << e.mode << " | " << e.needWant << endl;
    }
}

void totalSpent() {
    vector<Expense> list = loadExpenses();
    float total = 0;

    for (auto &e : list) total += e.amount;

    cout << "\nTotal Monthly Spending: ₹" << total << "\n";
}

void categoryTotal() {
    vector<Expense> list = loadExpenses();
    string cat;
    cout << "Enter Category: ";
    cin >> cat;

    float total = 0;
    for (auto &e : list)
        if (e.category == cat)
            total += e.amount;

    cout << "\nTotal Spent in " << cat << ": ₹" << total << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== SPENDING TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Total Monthly Spending\n";
        cout << "4. Category-wise Spending\n";
        cout << "5. Exit\n";
        cout << "Choose Option: ";
        cin >> choice;

        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: totalSpent(); break;
            case 4: categoryTotal(); break;
            case 5: exit(0);
            default: cout << "Invalid choice!\n";
        }
    }
}
