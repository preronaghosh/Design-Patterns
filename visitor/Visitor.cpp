#include<iostream>

// Forward declarations
class ConcreteElementOne;
class ConcreteElementTwo;

// Visitor interface 
class Visitor {
public:
    virtual void visit(ConcreteElementOne& element) = 0;
    virtual void visit(ConcreteElementTwo& element) = 0;
};

// Concrete visitor
class ConcreteVisitor : public Visitor {
public:
    void visit(ConcreteElementOne& element) override {
        std::cout << "ConcreteVisitor: Visiting ConcreteElementOne" << std::endl;
    }

    void visit(ConcreteElementTwo& element) override {
        std::cout << "ConcreteVisitor: Visiting ConcreteElementTwo" << std::endl;
    }
};

// Element interface
class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
};

class ConcreteElementOne : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    };
};

class ConcreteElementTwo : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    };
};


int main() {
    ConcreteVisitor visitor;

    ConcreteElementOne element1;
    ConcreteElementTwo element2;

    element1.accept(visitor);
    element2.accept(visitor);
    return 0;
}