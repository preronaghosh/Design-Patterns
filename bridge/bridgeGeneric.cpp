#include <iostream>

// Implementer abstract
class Implementer {
public:
    virtual void operationImpl() = 0; 
    virtual ~Implementer() {}
};

// Concrete Implementer A
class ConcreteImplementerA : public Implementer {
public:
    void operationImpl() override {
        std::cout << "ConcreteImplementerA operation" << std::endl;
    }
};

// Concrete Implementer B
class ConcreteImplementerB : public Implementer {
public:
    void operationImpl() override {
        std::cout << "ConcreteImplementerB operation" << std::endl;
    }
};

// Abstract abstraction
class Abstraction {
protected:
    Implementer* implementer;

public:
    Abstraction(Implementer* implementer) : implementer(implementer) {}
    virtual void operation() = 0; 
    virtual ~Abstraction() {}
};

// Concrete abstraction A
class RefinedAbstractionA : public Abstraction {
public:
    RefinedAbstractionA(Implementer* implementer) : Abstraction(implementer) {}

    void operation() override {
        std::cout << "RefinedAbstractionA operation: ";
        implementer->operationImpl();
    }
};

// Concrete abstraction B
class RefinedAbstractionB : public Abstraction {
public:
    RefinedAbstractionB(Implementer* implementer) : Abstraction(implementer) {}

    void operation() override {
        std::cout << "RefinedAbstractionB operation: ";
        implementer->operationImpl();
    }
};

// driver
int main() {
    Implementer* implA = new ConcreteImplementerA();
    Implementer* implB = new ConcreteImplementerB();

    Abstraction* absA = new RefinedAbstractionA(implA);
    Abstraction* absB = new RefinedAbstractionB(implB);

    absA->operation(); // RefinedAbstractionA operation: ConcreteImplementerA operation
    absB->operation(); // RefinedAbstractionB operation: ConcreteImplementerB operation

    delete absA;
    delete absB;
    delete implA;
    delete implB;

    return 0;
}
