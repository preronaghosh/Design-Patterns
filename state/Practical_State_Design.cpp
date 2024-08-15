#include <iostream>
#include <memory>
/* Simple example of a vending machine that can be in different states: Idle, HasMoney, and OutOfStock. */

// State Interface
class State {
public:
    // actions
    virtual void insertMoney() = 0;
    virtual void dispenseProduct() = 0;
    // dtor
    virtual ~State() = default;
};

// Concrete Staes
class IdleState: public State {
public:
    void insertMoney() override {
        std::cout << "Money inserted, ready to dispense item.\n";
    }

    void dispenseProduct() {
        std::cout << "Please insert money first.\n";
    }
};

class HasMoneyState: public State {
public:
    void insertMoney() override {
        std::cout << "Money already inserted, ready to dispense item.\n";
    }

    void dispenseProduct() override {
        std::cout << "Item dispensed..\n";
    }
};

class OutOfStockState: public State {
public:
    void insertMoney() override {
        std::cout << "Machine is out of stock. Cannot accept money.\n";
    }

    void dispenseProduct() override {
        std::cout << "Machine is out of stock. Cannot dispense item.\n";
    }
};

// Context class
class VendingMachine {
private:
    std::unique_ptr<State> currentState;

public:
    VendingMachine(std::unique_ptr<State> state) : currentState(std::move(state)) {}

    void setState(std::unique_ptr<State> state) {
        currentState = std::move(state); 
    }

    void insertMoney() {
        currentState->insertMoney();
    }

    void dispenseProduct() { currentState->dispenseProduct(); }
};

int main() {
    // Initial state is Idle
    auto idleState = std::make_unique<IdleState>();
    VendingMachine machine(std::move(idleState));

    machine.insertMoney();  // Insert money in Idle state
    machine.dispenseProduct(); // Dispense item in Idle state
    // should not be able to do it unless we move to hasMoneyState

    // Transition to HasMoneyState
    auto hasMoneyState = std::make_unique<HasMoneyState>();
    machine.setState(std::move(hasMoneyState));

    machine.insertMoney();  // Insert money in HasMoney state
    machine.dispenseProduct(); // Dispense item in HasMoney state

    // Transition to OutOfStockState
    auto outOfStockState = std::make_unique<OutOfStockState>();
    machine.setState(std::move(outOfStockState));

    machine.insertMoney();  // Try to insert money in OutOfStock state
    machine.dispenseProduct(); // Try to dispense item in OutOfStock state

    return 0;
}