#include <iostream>

// Implementer
class Color {
public:
    virtual void applyColor() = 0; 
    virtual ~Color() {}
};

class RedColor : public Color {
public:
    void applyColor() override {
        std::cout << "Applying red color" << std::endl;
    }
};

class BlueColor : public Color {
public:
    void applyColor() override {
        std::cout << "Applying blue color" << std::endl;
    }
};

// Abstraction
class Shape {
protected:
    Color* color;

public:
    Shape(Color* color) : color(color) {}
    virtual void draw() = 0; 
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    Circle(Color* color) : Shape(color) {}

    void draw() override {
        std::cout << "Drawing Circle ";
        color->applyColor();
    }
};

class Square : public Shape {
public:
    Square(Color* color) : Shape(color) {}

    void draw() override {
        std::cout << "Drawing Square ";
        color->applyColor();
    }
};

int main() {
    Color* red = new RedColor();
    Color* blue = new BlueColor();

    Shape* redCircle = new Circle(red);
    Shape* blueSquare = new Square(blue);

    /* Drawing Circle Applying red color */
    redCircle->draw();   

    /* Drawing Square Applying blue color */
    blueSquare->draw();  

    delete redCircle;
    delete blueSquare;
    delete red;
    delete blue;

    return 0;
}
