#include <iostream>

// Subsystem Class A
class SubsystemA {
public:
    void operationA1() { std::cout << "Subsystem A: operationA1\n"; }
    void operationA2() { std::cout << "Subsystem A: operationA2\n"; }
};

// Subsystem Class B
class SubsystemB {
public:
    void operationB1() { std::cout << "Subsystem B: operationB1\n"; }
    void operationB2() { std::cout << "Subsystem B: operationB2\n"; }
};

// Subsystem Class C
class SubsystemC {
public:
    void operationC1() { std::cout << "Subsystem C: operationC1\n"; }
    void operationC2() { std::cout << "Subsystem C: operationC2\n"; }
};

// Main Facade class that will be USED by client code 
class Facade {
private:
    SubsystemA* subsystemA;
    SubsystemB* subsystemB;
    SubsystemC* subsystemC;

public:
    Facade(SubsystemA* a, SubsystemB* b, SubsystemC* c)
        : subsystemA(a), subsystemB(b), subsystemC(c) {}

    void operation1() {
        std::cout << "Facade: operation1\n";
        subsystemA->operationA1();
        subsystemB->operationB1();
        subsystemC->operationC1();
    }

    void operation2() {
        std::cout << "Facade: operation2\n";
        subsystemA->operationA2();
        subsystemB->operationB2();
        subsystemC->operationC2();
    }
};

// Client code
int main() {
    SubsystemA a;
    SubsystemB b;
    SubsystemC c;

    Facade facade(&a, &b, &c);

    facade.operation1();
    facade.operation2();

    return 0;
}
