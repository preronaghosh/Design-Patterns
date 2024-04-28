#include <iostream>
#include <memory>

/*
 * Subject Interface
 * defines the common interface for RealSubject and Proxy
 * so that a Proxy can be used anywhere a RealSubject is expected
 */
class Subject {
public:
    virtual void request() = 0;
    virtual ~Subject() {}
};

// Real Subject : defines the real object that the proxy represents
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject: Handling request" << std::endl;
    }
};

// Proxy : maintains a reference that lets the proxy access the real subject
class Proxy : public Subject {
private:
    RealSubject* subject;

public:
    Proxy() { subject = new RealSubject(); }

    void request() override {
        subject->request();
    }

    ~Proxy() { delete subject; }
};

// Client
int main() {
    Proxy* proxy = new Proxy();
    proxy->request();

    return 0;
}

