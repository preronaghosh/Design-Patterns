#include <iostream>

// what we want to adapt to
class Target {
public:
    virtual void request() const = 0;
    virtual ~Target() = default;
};

// what we had previously
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "This is a specific request inside Adaptee" << std::endl;
    }

    ~Adaptee() = default;
};

// class that will act as a bridge
class Adapter : public Target {
public:
    Adapter(Adaptee* adaptee) : adaptee{adaptee} {}

    void request() const override {
        std::cout << "Target's request" << std::endl;
        adaptee->specificRequest();
    }

private:
    Adaptee* adaptee;
};

int main() {
    Target* target = new Adapter(new Adaptee());
    target->request();

    delete target;

    return 0;
}