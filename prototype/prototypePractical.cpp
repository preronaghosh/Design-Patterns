#include <iostream>
#include <memory>
#include <string>

// Define the Prototype Interface
class Shape {
public:
    virtual ~Shape() {}
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
    virtual void setPosition(int x, int y) = 0;
    virtual void setSize(int width, int height) = 0;
};

// Concrete prototype 1
class Circle : public Shape {
private:
    int x, y, radius;

public:
    Circle(int x = 0, int y = 0, int radius = 1)
        : x(x), y(y), radius(radius) {}

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }

    void draw() const override {
        std::cout << "Drawing a Circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }

    void setPosition(int x, int y) override {
        this->x = x;
        this->y = y;
    }

    void setSize(int width, int height) override {
        this->radius = (width + height) / 2; 
    }
};

// Concrete prototype 2
class Rectangle : public Shape {
private:
    int x, y, width, height;

public:
    Rectangle(int x = 0, int y = 0, int width = 1, int height = 1)
        : x(x), y(y), width(width), height(height) {}

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }

    void draw() const override {
        std::cout << "Drawing a Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << std::endl;
    }

    void setPosition(int x, int y) override {
        this->x = x;
        this->y = y;
    }

    void setSize(int width, int height) override {
        this->width = width;
        this->height = height;
    }
};

// Client code
int main() {
    // Create original shapes
    std::unique_ptr<Shape> originalCircle = std::make_unique<Circle>(10, 20, 30);
    std::unique_ptr<Shape> originalRectangle = std::make_unique<Rectangle>(15, 25, 35, 45);

    // Clone the shapes
    std::unique_ptr<Shape> clonedCircle = originalCircle->clone();
    std::unique_ptr<Shape> clonedRectangle = originalRectangle->clone();

    // Modify cloned shapes
    clonedCircle->setPosition(50, 60);
    clonedRectangle->setPosition(70, 80);
    clonedRectangle->setSize(100, 120);

    // Draw original and cloned shapes
    std::cout << "Original Shapes:" << std::endl;
    originalCircle->draw();
    originalRectangle->draw();

    std::cout << "\nCloned Shapes:" << std::endl;
    clonedCircle->draw();
    clonedRectangle->draw();

    return 0;
}
