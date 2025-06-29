//
// Created by Alec Feldhaus on 6/8/25.
//

#include "InvestmentAccount.h"

InvestmentAccount::InvestmentAccount() {
    this->m_balance = 0.0;
    this->m_interestRate = 0.0;
    this->m_monthlyDeposit = 0.0;
    this->m_years = 0.0;
}

InvestmentAccount::InvestmentAccount(const double t_balance, const double t_interestRate, const double t_years, const double t_monthlyDeposit) {
    this->m_balance = t_balance;
    this->m_interestRate = t_interestRate/100.0;
    this->m_years = t_years;
    this->m_monthlyDeposit = t_monthlyDeposit;
}

double InvestmentAccount::getBalance() const {
    return this->m_balance;
}
double InvestmentAccount::getInterestRate() const {
    return this->m_interestRate;
}
void InvestmentAccount::setBalance(double t_balance) {
    this->m_balance = t_balance;
}
void InvestmentAccount::setInterestRate(double t_interestRate) {
    this->m_interestRate = t_interestRate/100.0;
}
double InvestmentAccount::deposit(const double t_amount) {
    this->m_balance += t_amount;
    return this->m_balance;
}
double InvestmentAccount::calcMonthlyInterest() const {
    return this->m_balance * (this->m_interestRate/12);
}
double InvestmentAccount::getYears() const {
    return this->m_years;
}
double InvestmentAccount::getMonthlyDeposit() const {
    return this->m_monthlyDeposit;
}
