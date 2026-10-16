#include <iostream>
using namespace std;

class Account {
private:
    double balance;

    friend class Auditor;  // Auditor can access private members

public:
    explicit Account(double initialBalance) : balance(initialBalance) {}
};

class Auditor {
public:
    void inspect(const Account& account) const {
        cout << "Account Balance: " << account.balance << '\n';
    }
};

int main() {
    Account account(5000.0);
    Auditor auditor;

    auditor.inspect(account);

    return 0;
}
