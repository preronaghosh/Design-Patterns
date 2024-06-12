#include <iostream>
#include <string>

class Product {
private:
    std::string partA;
    std::string partB;
    std::string partC;

public:
    void setPartA(const std::string& partA) {
        this->partA = partA;
    }

    void setPartB(const std::string& partB) {
        this->partB = partB;
    }

    void setPartC(const std::string& partC) {
        this->partC = partC;
    }

    void show() const {
        std::cout << "Product with PartA: " << partA
                  << ", PartB: " << partB
                  << ", PartC: " << partC << std::endl;
    }
};


// Builder interface
template <typename T>
class Builder {
public:
    virtual ~Builder() {}
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual T* getProduct() = 0;
};

// Concrete builder
class ConcreteProductBuilder : public Builder<Product> {
private:
    Product* product;

public:
    ConcreteProductBuilder() {
        product = new Product();
    }

    ~ConcreteProductBuilder() {
        delete product;
    }

    void buildPartA() override {
        product->setPartA("Default PartA");
        std::cout << "PartA complete." << std::endl;
    }

    void buildPartB() override {
        product->setPartB("Default PartB");
        std::cout << "PartB complete." << std::endl;
    }

    void buildPartC() override {
        product->setPartC("Default PartC");
        std::cout << "PartC complete." << std::endl;
    }

    Product* getProduct() override {
        return product;
    }
};

// director (optional)
template <typename T>
class Director {
private:
    Builder<T>* builder;

public:
    Director(Builder<T>* builder) : builder(builder) {}

    void construct() {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
};

// client
int main() {
    Builder<Product>* builder = new ConcreteProductBuilder();
    Director<Product> director(builder);

    director.construct();

    Product* product = builder->getProduct();
    product->show();

    delete builder;  

    return 0;
}
