#include <iostream>


class Receiver {
public:
    Receiver() {}

    void action() {
        std::cout << "Receiver executed an action.." << std::endl;
    }
};

// Interface
class Command {
public: 
    virtual void execute() = 0;
    ~Command() {}

protected:
    Command() {}
};

// Derived Command class
class ConcreteCommand : public Command {
public:
    
    ConcreteCommand(Receiver* recvr) : receiver{recvr} {}

    void execute() override {
        receiver->action();
    }

    ~ConcreteCommand() {
        if (receiver) { delete receiver; }
    }

private:
    Receiver* receiver;
};

// asks the command to do something
class Invoker {
public:
    void setCommand(Command *command) {
        _command = command;
    }

    void executeCommand() {
        if (_command) {
        _command->execute();
        }
    }

private:
    Command* _command;
};

int main()
{
    Receiver* recv = new Receiver();
    ConcreteCommand command(recv);
    
    Invoker invoker;
    invoker.setCommand( &command );
    invoker.executeCommand();
  
    return 0;
}