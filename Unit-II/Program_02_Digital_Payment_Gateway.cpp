#include <iostream>   // Input/output
#include <memory>     // Smart pointers
#include <string>     // String data type
#include <vector>     // Vector container
using namespace std;  // Use standard namespace


// Abstract base class for payment methods
class PaymentMethod
{
protected:
    string transactionId;   // Transaction ID
    double amount;          // Payment amount

public:
    // Constructor
    PaymentMethod(string tid, double amt)
        : transactionId(tid), amount(amt) {}

    // Pure virtual payment function
    virtual bool processPayment() const = 0;

    // Virtual destructor
    virtual ~PaymentMethod() = default;
};


// Credit card payment class
class CreditCardPayment : public PaymentMethod
{
private:
    string maskedCardNumber;   // Masked card number

public:
    // Constructor
    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt), maskedCardNumber(card) {}

    // Process credit card payment
    bool processPayment() const override
    {
        cout << "Credit-card transaction "
             << transactionId
             << " for Rs. " << amount
             << " using " << maskedCardNumber
             << " completed." << endl;

        return true;
    }
};


// UPI payment class
class UPIPayment : public PaymentMethod
{
private:
    string upiId;   // UPI ID

public:
    // Constructor
    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt), upiId(upi) {}

    // Process UPI payment
    bool processPayment() const override
    {
        cout << "UPI transaction "
             << transactionId
             << " for Rs. " << amount
             << " from " << upiId
             << " completed." << endl;

        return true;
    }
};


// Net banking payment class
class NetBankingPayment : public PaymentMethod
{
private:
    string bankName;   // Bank name

public:
    // Constructor
    NetBankingPayment(string tid, double amt, string bank)
        : PaymentMethod(tid, amt), bankName(bank) {}

    // Process net banking payment
    bool processPayment() const override
    {
        cout << "Net-banking transaction "
             << transactionId
             << " for Rs. " << amount
             << " through " << bankName
             << " completed." << endl;

        return true;
    }
};


int main()
{
    // Vector storing smart pointers to payment objects
    vector<unique_ptr<PaymentMethod>> payments;

    // Add credit card payment
    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001", 2500, "XXXX-XXXX-1234"
        )
    );

    // Add UPI payment
    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002", 1200, "student@upi"
        )
    );

    // Add net banking payment
    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003", 5000, "Example Bank"
        )
    );

    cout << "=== Payment Gateway ===" << endl;

    // Process all payments
    for (const auto& payment : payments)
    {
        payment->processPayment();
    }

    return 0;   // Successful execution
}
