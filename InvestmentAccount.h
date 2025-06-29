//
// Created by Alec Feldhaus on 6/8/25.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H



class InvestmentAccount {
    private:
        double m_balance;
        double m_interestRate;
        double m_monthlyDeposit;
        double m_years;
    public:
        InvestmentAccount();
        InvestmentAccount(double t_balance, double t_interestRate, double t_years, double t_monthlyDeposit);
        double getBalance() const;
        void setBalance(double t_balance);
        double getInterestRate() const;
        void setInterestRate(double t_interest_rate);
        double deposit(double t_amount);
        double calcMonthlyInterest() const;
        double getYears() const;
        double getMonthlyDeposit() const;
};



#endif //ACCOUNT_H
