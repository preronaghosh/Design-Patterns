#include <iostream>
#include <string>
#include <memory>

// abstract product 1
class Chair {
public:
    virtual void sit() const = 0;
    virtual ~Chair() = default;
};

// concrete product 1
class ModernChair : public Chair {
public:
    void sit() const override {
        std::cout << "Sitting on a modern chair." << std::endl;
    }
};

// concrete product 2
class VictorianChair : public Chair {
public:
    void sit() const override {
        std::cout << "Sitting on a victorian chair." << std::endl;
    }
};

// Abstract product 2
class Sofa {
public:
    virtual void lieDown() const = 0;
    virtual ~Sofa() = default;
};

// concrete products
class ModernSofa : public Sofa {
public:
    void lieDown() const override {
        std::cout << "Lying down on a modern sofa." << std::endl;
    }
};

class VictorianSofa  : public Sofa {
public:
    void lieDown() const override {
        std::cout << "Lying down on a Victorian  sofa." << std::endl;
    }
};

// Abstract factory selling both these products
class FurnitureFactory {
public:
    // generic create chair and sofa functions 
    virtual std::unique_ptr<Chair> createChair() const = 0;
    virtual std::unique_ptr<Sofa> createSofa() const = 0;
    virtual ~FurnitureFactory() = default;
};

// Concrete factory 1
class ModernFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<ModernChair>();    
    }

    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<ModernSofa>();    
    }
};

// Concrete factory 2
class VictorianFurnitureFactory : public FurnitureFactory {
public:
    std::unique_ptr<Chair> createChair() const override {
        return std::make_unique<VictorianChair>();    
    }

    std::unique_ptr<Sofa> createSofa() const override {
        return std::make_unique<VictorianSofa>();    
    }
};

void populateFactory(const FurnitureFactory& factory) {
    std::unique_ptr<Chair> chair = factory.createChair();
    std::unique_ptr<Sofa> sofa = factory.createSofa();

    chair->sit();
    sofa->lieDown();
}

int main() {

    std::cout << "Creating Modern Furniture:" << std::endl;
    ModernFurnitureFactory modernFactory;
    populateFactory(modernFactory);

    std::cout << "Creating Victorian Furniture:" << std::endl;
    VictorianFurnitureFactory victorianFactory;
    populateFactory(victorianFactory);

    
    return 0;
}



