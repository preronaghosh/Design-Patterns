#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Base class for an observer
class Observer {
public:
    virtual void update(const std::string& msg) const = 0;
    virtual ~Observer() = default;
};

// ConcreteObserver of one type; there can be more types of ConcreteObservers
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const int id) : observerId{id} {}

    void update(const std::string& msg) const override {
        std::cout << "Observer " << observerId << " received an update: " << msg << std::endl;
    }

private:
    int observerId; // extra private parameter identifying each observer
};

// Base class for a subject that has observers
class Subject {
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void updateAllObservers(const std::string& msg) {
        for(const auto& observer: observers) {
            observer->update(msg);
        }
    } 

private:
    std::vector<Observer*> observers;
};


int main() {
    Subject subject; 

    ConcreteObserver observer1{1};
    ConcreteObserver observer2{2};
    ConcreteObserver observer3{3};

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);
    subject.addObserver(&observer3);

    // notify everyone
    subject.updateAllObservers("Something happened!");

    // remove an observer
    subject.removeObserver(&observer3);

    // notify remaining observers
    subject.updateAllObservers("Something happened again!");

    return 0;
}