#include <iostream>
#include <string>

// Generic template

class Product {
public:
    virtual std::string getName() = 0;
    virtual ~Product() = default;
};

class ConcreteProductA : public Product {
public:
    ConcreteProductA() {}

    std::string getName() {
        return "Product A";
    }
};

class ConcreteProductB : public Product {
public:
    ConcreteProductB() {}

    std::string getName() {
        return "Product B";
    }
};

// Creator abstract class 
class Creator {
public:
    virtual Product* createProductA() = 0;
    virtual Product* createProductB() = 0;

    virtual void removeProduct(Product* product) = 0;

    virtual ~Creator() = default;
};

// only creators can know how to create/remove the products
// product classes will only have informational methods 
class ConcreteCreator : public Creator {
public:
    Product* createProductA() {
        return new ConcreteProductA();
    }

    Product* createProductB() {
        return new ConcreteProductB();
    }

    void removeProduct(Product* product) {
        delete product;
    }

    ~ConcreteCreator() {}
};

int main() {
    ConcreteCreator* creator = new ConcreteCreator;

    Product* prodA = creator->createProductA();
    std::cout << "Creating: " << prodA->getName() << std::endl;
    creator->removeProduct(prodA);

    Product* prodB = creator->createProductB();
    std::cout << "Creating: " << prodB->getName() << std::endl;
    creator->removeProduct(prodB);
}