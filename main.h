//
// Created by Alec Feldhaus on 6/8/25.
//

#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <iostream>
#include "InvestmentAccount.h"

void printBanner();
void getUserContinue(char& userChoice);
void getUserInput(double& initialBalance, double& interestRate, double& years, double& monthlyDeposit);
double getValidInput(const std::string& prompt);
double calcMonthlyTotalWithInterest(InvestmentAccount& account);
double calcYearlyTotalWithInterest(InvestmentAccount& account);
void printAccountInfoTable(InvestmentAccount& account, std::string title);

#endif //MAIN_H
