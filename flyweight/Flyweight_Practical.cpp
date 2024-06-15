#include <iostream>
#include <unordered_map>
#include <string>

// Flyweight
class Color {
public:
    virtual void applyColor() const = 0;
    virtual ~Color() {}
};


class ConcreteColor : public Color {
    std::string color;

public:
    ConcreteColor(const std::string& color) : color(color) {}

    void applyColor() const override {
        std::cout << "Applying color: " << color << std::endl;
    }
};

class ColorFactory {
    std::unordered_map<std::string, Color*> colors;

public:
    ~ColorFactory() {
        for (auto pair : colors) {
            delete pair.second;
        }
    }

    Color* getColor(const std::string& color) {
        if (colors.find(color) == colors.end()) {
            colors[color] = new ConcreteColor(color);
        }
        return colors[color];
    }
};

class Shape {
protected:
    Color* color;

public:
    Shape(Color* color) : color(color) {}
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    int x, y, radius;

public:
    Circle(int x, int y, int radius, Color* color) : Shape(color), x(x), y(y), radius(radius) {}

    void draw() const override {
        std::cout << "Drawing Circle at (" << x << ", " << y << ") with radius " << radius << ". ";
        color->applyColor();
    }
};

int main() {
    ColorFactory colorFactory;

    // Create shapes with shared colors
    Shape* redCircle1 = new Circle(10, 10, 20, colorFactory.getColor("Red"));
    Shape* redCircle2 = new Circle(30, 30, 30, colorFactory.getColor("Red")); // Reuses the same Red color object
    Shape* blueCircle = new Circle(50, 50, 40, colorFactory.getColor("Blue"));

    redCircle1->draw();   // Drawing Circle at (10, 10) with radius 20. Applying color: Red
    redCircle2->draw();   // Drawing Circle at (30, 30) with radius 30. Applying color: Red
    blueCircle->draw();   // Drawing Circle at (50, 50) with radius 40. Applying color: Blue

    delete redCircle1;
    delete redCircle2;
    delete blueCircle;

    return 0;
}
