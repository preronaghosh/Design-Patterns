#include <iostream>
#include <vector>
#include <string>

// Command Interface
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

// Concrete Command
class LightOnCommand : public Command {
public:
    void execute() override {
        std::cout << "Light is turned ON" << std::endl;
    }
};

// Receiver
class Light {
public:
    void turnOn() {
        std::cout << "Light is ON" << std::endl;
    }
};

// Invoker
class RemoteControl {
private:
    Command* command;
public:
    void setCommand(Command* cmd) {
        command = cmd;
    }
    
    void pressButton() {
        command->execute();
    }
};

int main() {
    RemoteControl remote;
    LightOnCommand lightOnCmd;

    remote.setCommand(&lightOnCmd);
    remote.pressButton();

    return 0;
}
