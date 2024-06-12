#include <iostream>
#include <string>

// Prototype Interface
class Prototype {
public:
    virtual ~Prototype() {}
    virtual Prototype* clone() const = 0;
    virtual void print() const = 0;
};

// Concrete prototype
class ConcretePrototype : public Prototype {
private:
    std::string name;
    int value;

public:
    ConcretePrototype(const std::string& name, int value) : name(name), value(value) {}

    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void print() const override {
        std::cout << "ConcretePrototype: " << name << ", " << value << std::endl;
    }
};

// Client 
int main() {
    Prototype* original = new ConcretePrototype("Original", 100);
    Prototype* copy = original->clone();

    original->print();
    copy->print();

    delete original;
    delete copy;

    return 0;
}
