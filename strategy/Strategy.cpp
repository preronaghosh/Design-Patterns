#include <iostream>

// base algorithm interface
class PaymentStrategy {
public:
    virtual void processPayment(const float amount) const = 0;  
    virtual ~PaymentStrategy() = default;
};

// Types of payments we allow as algorithm classes
class CreditCardPayment : public PaymentStrategy {
public:
    CreditCardPayment(const std::string& cardNumber) : cardNumber{cardNumber} {}

    void processPayment(const float amount) const override {
        std::cout << "Processing Credit Card payment of amount: " << amount << std::endl; 
    }

private:
    std::string cardNumber;
};

class PayPalPayment : public PaymentStrategy {
public:
    PayPalPayment(const std::string& email) : email{email} {}

    void processPayment(const float amount) const override {
        std::cout << "Processing Paypal payment of amount: " << amount << std::endl; 
    }

private:
    std::string email;
};

// context that does the remaining common functionalities 
// supported by all kinds of payments
class PaymentProcessor {
public:
    PaymentProcessor(PaymentStrategy* strategy) : chosenStrategy{strategy} {}

    // setter to allow other kinds of payments
    void setPaymentStrategy(PaymentStrategy* newStrategy) {
        chosenStrategy = newStrategy;
    }

    void processPayment(const float amount) const {
        chosenStrategy->processPayment(amount);
    }

private:
    PaymentStrategy* chosenStrategy;
};

int main() {
    CreditCardPayment creditCardPayment("1234-5678-9012-3456");
    PayPalPayment payPalPayment("example@example.com");

    PaymentProcessor paymentProcessor(&creditCardPayment);
    paymentProcessor.processPayment(100.50);

    paymentProcessor.setPaymentStrategy(&payPalPayment);
    paymentProcessor.processPayment(50.25);
    return 0;
}