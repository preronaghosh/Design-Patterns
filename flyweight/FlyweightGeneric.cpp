#include <iostream>
#include <unordered_map>
#include <string>

// Flyweight
class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) = 0;
    virtual ~Flyweight() {}
};

class ConcreteFlyweight : public Flyweight {
    std::string intrinsicState;

public:
    ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState(intrinsicState) {}

    void operation(const std::string& extrinsicState) override {
        std::cout << "Intrinsic State: " << intrinsicState << ", Extrinsic State: " << extrinsicState << std::endl;
    }
};

class FlyweightFactory {
    std::unordered_map<std::string, Flyweight*> flyweights;

public:
    ~FlyweightFactory() {
        for (auto pair : flyweights) {
            delete pair.second;
        }
    }

    Flyweight* getFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];
    }
};

int main() {
    FlyweightFactory factory;

    Flyweight* flyweight1 = factory.getFlyweight("A");
    Flyweight* flyweight2 = factory.getFlyweight("B");
    Flyweight* flyweight3 = factory.getFlyweight("A"); // Reuses the same instance as flyweight1

    flyweight1->operation("First Call");
    flyweight2->operation("Second Call");
    flyweight3->operation("Third Call"); // Should print same intrinsic state as flyweight1

    return 0;
}
