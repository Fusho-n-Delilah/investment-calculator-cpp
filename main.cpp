#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "main.h"

int main() {
    char userContinueChoice = 'y';
    InvestmentAccount accountWithMonthlyDeposit, accountNoDeposits;
    double initialBalance, interestRate, years, monthlyDeposit;

    while (userContinueChoice == 'y') {
        //print the data input banner and get user input
        printBanner();
        getUserInput(initialBalance, interestRate, years, monthlyDeposit);

        //instantiate the Investment accounts with the appropriate date.
        std::cout << initialBalance << " " << interestRate << " " << years << " " << monthlyDeposit <<  std::endl;
        accountWithMonthlyDeposit = InvestmentAccount(initialBalance, interestRate, years, monthlyDeposit);
        accountNoDeposits = InvestmentAccount(initialBalance, interestRate, years, 0.0);

        //print account information tables
        printAccountInfoTable(accountNoDeposits, "Balance and Interest Without Additional Monthly Deposits");
        printAccountInfoTable(accountWithMonthlyDeposit, "Balance and Interest With Additional Monthly Deposits");
        //check if user wants to continue
        getUserContinue(userContinueChoice);
    }

    return 0;
}

void printBanner() {
    //create banner to display
    std::string banner(36, '*');
    std::string padding(12, '*');
    std::string title = " Data Input ";
    title.insert(title.begin(), padding.begin(), padding.end());
    title.insert(title.end(), padding.begin(), padding.end());

    std::cout << banner << std::endl;
    std::cout << title << std::endl;
}

void getUserInput(double& initialBalance, double& interestRate, double& years, double& monthlyDeposit) {

    initialBalance = getValidInput("Initial Investment Amount: $");
    monthlyDeposit = getValidInput("Monthly Deposit: $");
    interestRate = getValidInput("Annual Interest: %");
    years = getValidInput("Number of Years: ");

    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get();
}

double getValidInput(const std::string& prompt) {
    double input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;

        if (std::cin.good()) break;
        else {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return input;
}

/*
 * Function takes in an account by reference, and calls the accounts calcMonthlyInterest function
 * returns that value after adding the deposit and calculating interest.
 *
 */
double calcMonthlyTotalWithInterest(InvestmentAccount& account) {
    account.deposit(account.getMonthlyDeposit());

    return account.calcMonthlyInterest();
}

/*
 * Function takes in an account by reference, and calls the calcMonthlyTotalWithInterest 12 times
 * taking in the interest earned value returned to create a sum of interest earned.
 *
 */
double calcYearlyTotalWithInterest(InvestmentAccount& account) {
    double yearlyInterest = 0.0;

    for (int i = 1; i <= 12; i++) {
        yearlyInterest += calcMonthlyTotalWithInterest(account);
        account.deposit(account.calcMonthlyInterest());
    }

    return yearlyInterest;
}

void printAccountInfoTable(InvestmentAccount& account, const std::string title) {
    const std::string divider(65, '=');
    const std::string divder2(65, '-');

    std::cout << std::setw(61) << std::right << std::endl << title << std::endl;
    std::cout << divider << std::endl;
    std::cout << std::setw(6) << "Year" << std::setw(24) << "Year End Balance" << std::setw(31) << "Year End Earned Interest" << std::endl;
    std::cout << divder2 << std::endl;

    for (int i = 1; i <= account.getYears(); i++) {
        double yearlyInterest = calcYearlyTotalWithInterest(account);
        std::stringstream interestStream;
        std::stringstream balanceStream;

        balanceStream << std::fixed << std::setprecision(2) << "$" << account.getBalance();
        interestStream << std::fixed << std::setprecision(2) << "$" << yearlyInterest;

        std::cout << std::setw(6) << i << std::setw(24) << balanceStream.str() << std::setw(31) << interestStream.str() << std::endl;
    }
    std::cout << std::endl;
}
void getUserContinue(char& userChoice){
    std::string input;
    while (true) {
        std::cin.clear();

        std::cout << std::endl << "Would you like to try new values? [y/n]: ";
        std::getline(std::cin, input);

        if (!std::cin.fail()
            && (input[0] == 'n' || input[0] == 'N' || input[0] == 'y' || input[0] == 'Y')) {
            userChoice = input[0];
            break;
        } else if (input.length() > 1){
            std::cout << std::endl << "Invalid input. Please only enter a single character.";
        } else if (!isalpha(input[0])) {
            std::cout << std::endl << "Invalid input. Please enter a single character.";
        }
    }
}
