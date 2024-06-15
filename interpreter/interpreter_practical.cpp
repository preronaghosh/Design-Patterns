#include <iostream>
#include <string>
#include <unordered_map>

// Abstract Expression
class Expression {
public:
    virtual int interpret(const std::unordered_map<std::string, int>& context) = 0;
    virtual ~Expression() {}
};

// Create terminal expressions
class Number : public Expression {
    int number;

public:
    Number(int number) : number(number) {}

    int interpret(const std::unordered_map<std::string, int>& context) override {
        return number;
    }
};

class Variable : public Expression {
    std::string name;

public:
    Variable(const std::string& name) : name(name) {}

    int interpret(const std::unordered_map<std::string, int>& context) override {
        if (context.find(name) != context.end()) {
            return context.at(name);
        }
        return 0;
    }
};

// create non-terminal expressions
class Add : public Expression {
    Expression* left;
    Expression* right;

public:
    Add(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret(const std::unordered_map<std::string, int>& context) override {
        return left->interpret(context) + right->interpret(context);
    }

    ~Add() {
        delete left;
        delete right;
    }
};

class Subtract : public Expression {
    Expression* left;
    Expression* right;

public:
    Subtract(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret(const std::unordered_map<std::string, int>& context) override {
        return left->interpret(context) - right->interpret(context);
    }

    ~Subtract() {
        delete left;
        delete right;
    }
};

// pattern main driver
int main() {
    // Context with variable values
    std::unordered_map<std::string, int> context = { {"x", 5}, {"y", 10} };

    // Expression: (x + y) - 2
    Expression* expression = new Subtract(
        new Add(new Variable("x"), new Variable("y")),
        new Number(2)
    );

    int result = expression->interpret(context);
    std::cout << "Result: " << result << std::endl; // Output: Result: 13

    delete expression;

    return 0;
}
