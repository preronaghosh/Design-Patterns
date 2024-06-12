#include <string>
#include <iostream>

// Define the Product
class House {
private:
    std::string foundation;
    std::string structure;
    std::string roof;
    std::string interior;

public:
    void setFoundation(const std::string& foundation) {
        this->foundation = foundation;
    }

    void setStructure(const std::string& structure) {
        this->structure = structure;
    }

    void setRoof(const std::string& roof) {
        this->roof = roof;
    }

    void setInterior(const std::string& interior) {
        this->interior = interior;
    }

    void show() const {
        std::cout << "House built with foundation: " << foundation
                  << ", structure: " << structure
                  << ", roof: " << roof
                  << ", and interior: " << interior << std::endl;
    }
};

// Define the Builder Interface
class HouseBuilder {
public:
    virtual ~HouseBuilder() {}
    virtual void buildFoundation() = 0;
    virtual void buildStructure() = 0;
    virtual void buildRoof() = 0;
    virtual void buildInterior() = 0;
    virtual House* getHouse() = 0;
};

// Concrete Builder
class ConcreteHouseBuilder : public HouseBuilder {
private:
    House* house;

public:
    ConcreteHouseBuilder() {
        house = new House();
    }

    ~ConcreteHouseBuilder() {
        delete house;
    }

    void buildFoundation() override {
        house->setFoundation("Concrete, brick, and stone");
        std::cout << "Foundation complete." << std::endl;
    }

    void buildStructure() override {
        house->setStructure("Wooden structure");
        std::cout << "Structure complete." << std::endl;
    }

    void buildRoof() override {
        house->setRoof("Metal roofing");
        std::cout << "Roof complete." << std::endl;
    }

    void buildInterior() override {
        house->setInterior("Drywall and paint");
        std::cout << "Interior complete." << std::endl;
    }

    House* getHouse() override {
        return house;
    }
};

// Define the Director
class ConstructionDirector {
private:
    HouseBuilder* houseBuilder;

public:
    ConstructionDirector(HouseBuilder* builder) : houseBuilder(builder) {}

    void constructHouse() {
        houseBuilder->buildFoundation();
        houseBuilder->buildStructure();
        houseBuilder->buildRoof();
        houseBuilder->buildInterior();
    }
};

// Client driver code
int main() {
    HouseBuilder* builder = new ConcreteHouseBuilder();
    ConstructionDirector director(builder);

    director.constructHouse();

    House* house = builder->getHouse();
    house->show();

    delete builder;

    return 0;
}
