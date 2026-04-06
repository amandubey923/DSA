#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

// Structure to store one expense record.
// Each field maps directly to one column in expenses.txt.
struct Expense {
    string date, category, description, mode, needWant;
    float amount;
};

// Collects expense details from user input and appends
// the record to the CSV-style text file (expenses.txt).
void addExpense() {
    Expense e;

    // Input: basic expense metadata.
    cout << "\nEnter Date (DD-MM-YYYY): ";
    cin >> e.date;
    cout << "Enter Category: ";
    cin >> e.category;

    // Clear leftover newline before taking full-line description.
    cin.ignore();
    cout << "Enter Description: ";
    getline(cin, e.description);

    // Input: amount and classification details.
    cout << "Enter Amount: ";
    cin >> e.amount;
    cout << "Payment Mode (Cash/UPI/Card): ";
    cin >> e.mode;
    cout << "Need or Want: ";
    cin >> e.needWant;

    // Open file in append mode so old records remain intact.
    ofstream file("expenses.txt", ios::app);

    // Save one expense in comma-separated format:
    // date,category,description,amount,mode,needWant
    file << e.date << "," << e.category << "," << e.description << ","
         << e.amount << "," << e.mode << "," << e.needWant << "\n";

    cout << "\nExpense Added Successfully!\n";
}

// Reads all expenses from file and returns them as a vector.
// Each line in file is parsed into an Expense object.
vector<Expense> loadExpenses() {
    vector<Expense> list;

    // Read mode: if file doesn't exist yet, vector remains empty.
    ifstream file("expenses.txt");
    string line;

    // Process file line by line.
    while (getline(file, line)) {
        stringstream ss(line);
        Expense e;
        string amt;

        // Extract comma-separated fields in order.
        getline(ss, e.date, ',');
        getline(ss, e.category, ',');
        getline(ss, e.description, ',');
        getline(ss, amt, ',');
        getline(ss, e.mode, ',');
        getline(ss, e.needWant, ',');

        // Convert amount from string to float.
        e.amount = stof(amt);

        // Store parsed record.
        list.push_back(e);
    }

    // Return complete expense list to caller.
    return list;
}

// Displays every expense currently stored in the file.
void viewExpenses() {
    // Load current data from persistent storage.
    vector<Expense> list = loadExpenses();
    cout << "\n----- All Expenses -----\n\n";

    // Print each record in a readable table-like format.
    for (auto &e : list) {
        cout << e.date << " | " << e.category << " | "
             << e.description << " | ₹" << e.amount 
             << " | " << e.mode << " | " << e.needWant << endl;
    }
}

// Calculates and prints total spending across all entries.
void totalSpent() {
    vector<Expense> list = loadExpenses();
    float total = 0;

    // Accumulate amount from every expense record.
    for (auto &e : list) total += e.amount;

    cout << "\nTotal Monthly Spending: ₹" << total << "\n";
}

// Calculates spending only for a user-selected category.
void categoryTotal() {
    vector<Expense> list = loadExpenses();
    string cat;

    // Ask user which category to filter.
    cout << "Enter Category: ";
    cin >> cat;

    float total = 0;

    // Add amount only when category matches user input.
    for (auto &e : list)
        if (e.category == cat)
            total += e.amount;

    cout << "\nTotal Spent in " << cat << ": ₹" << total << endl;
}

int main() {
    int choice;

    // Infinite menu loop; exits only when user selects option 5.
    while (true) {
        // Main menu UI.
        cout << "\n===== SPENDING TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Total Monthly Spending\n";
        cout << "4. Category-wise Spending\n";
        cout << "5. Exit\n";
        cout << "Choose Option: ";
        cin >> choice;

        // Route selected option to corresponding functionality.
        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: totalSpent(); break;
            case 4: categoryTotal(); break;

            // End program gracefully.
            case 5: exit(0);

            // Handles unexpected menu input.
            default: cout << "Invalid choice!\n";
        }
    }
}
