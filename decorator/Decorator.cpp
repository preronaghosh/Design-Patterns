#include <iostream>
#include <memory>

// Component: Abstract base class for the component
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual void brew() const = 0;
};

// ConcreteComponent: The concrete implementation of the component
class SimpleCoffee : public Coffee {
public:
    void brew() const override {
        std::cout << "Brewing simple coffee" << std::endl;
    }
};

// Decorator: Abstract base class for all kinds of decorators
class CoffeeDecorator : public Coffee {
protected:
    std::unique_ptr<Coffee> coffee;

public:
    explicit CoffeeDecorator(std::unique_ptr<Coffee> coffee)
        : coffee(std::move(coffee)) {}

    void brew() const override {
        if (coffee) {
            coffee->brew();
        }
    }
};

// ConcreteDecorator 1: Adds milk to the coffee
class MilkDecorator : public CoffeeDecorator {
public:
    explicit MilkDecorator(std::unique_ptr<Coffee> coffee)
        : CoffeeDecorator(std::move(coffee)) {}

    void brew() const override {
        CoffeeDecorator::brew();
        addMilk();
    }

private:
    void addMilk() const {
        std::cout << "Adding milk to the coffee" << std::endl;
    }
};

// ConcreteDecorator 2: Adds sugar to the coffee
class SugarDecorator : public CoffeeDecorator {
public:
    explicit SugarDecorator(std::unique_ptr<Coffee> coffee)
        : CoffeeDecorator(std::move(coffee)) {}

    void brew() const override {
        CoffeeDecorator::brew();
        addSugar();
    }

private:
    void addSugar() const {
        std::cout << "Adding sugar to the coffee" << std::endl;
    }
};

int main() {
    // Create a simple coffee
    std::cout << "Making a black coffee" << std::endl;
    std::unique_ptr<Coffee> simpleCoffee = std::make_unique<SimpleCoffee>();
    simpleCoffee->brew();
    std::cout << "--------------------------------------" << std::endl;

    // Make a coffee with just milk
    std::cout << "Making a milk coffee" << std::endl;
    std::unique_ptr<Coffee> milkCoffee = std::make_unique<MilkDecorator>(std::make_unique<SimpleCoffee>());
    milkCoffee->brew();
    std::cout << "--------------------------------------" << std::endl;

    // Make a coffee with just sugar 
    std::cout << "Making coffee with sugar" << std::endl;
    std::unique_ptr<Coffee> sugarCoffee = std::make_unique<SugarDecorator>(std::make_unique<SimpleCoffee>());
    sugarCoffee->brew();
    std::cout << "--------------------------------------" << std::endl;

    // Decorate the simple coffee with milk and sugar
    std::cout << "Making coffee with milk and sugar" << std::endl;
    std::unique_ptr<Coffee> milkAndSugarCoffee = std::make_unique<SugarDecorator>(
        std::make_unique<MilkDecorator>(std::move(simpleCoffee)));
    milkAndSugarCoffee->brew();

    return 0;
}
