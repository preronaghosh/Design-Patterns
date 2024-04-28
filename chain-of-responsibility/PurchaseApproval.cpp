#include <iostream>

// Handler interface
class Approver {
public:
    virtual void setNext(Approver* next) = 0;
    virtual void processRequest(double amount) = 0;
};

// Concrete handler : Team Lead
class TeamLead : public Approver {
public:
    TeamLead() {}

    void setNext(Approver* nextApprover) override {
        _nextApprover = nextApprover;
    }

    void processRequest(double amount) override {
        if (amount <= 1000) {
            std::cout << "Team Lead approved the purchase" << std::endl;
        } else if (_nextApprover != nullptr) {
            _nextApprover->processRequest(amount);
        } else {
            std::cout << "No one can approve the purchase" << std::endl;
        }
    }

private:
    Approver* _nextApprover;
};

// Concrete handler: Manager
class Manager : public Approver {
public:
    void setNext(Approver* nextApprover) override {
        _nextApprover = nextApprover;
    }

    void processRequest(double amount) override {
        if (amount <= 5000) {
            std::cout << "Manager approved the purchase" << std::endl;
        } else if (_nextApprover != nullptr) {
            _nextApprover->processRequest(amount);
        } else {
            std::cout << "No one can approve the purchase" << std::endl;
        }
    }

private: 
    Approver* _nextApprover;
};

// Concrete handler: Director
class Director : public Approver {
public:
    void setNext(Approver* nextApprover) override {
        // Director is the last in the chain, so no next handler
    }

    void processRequest(double amount) override {
        if (amount <= 10000) {
            std::cout << "Director approved the purchase" << std::endl;
        } else {
            std::cout << "No one can approve the purchase" << std::endl;
        }
    }
};

int main() {
    TeamLead teamLead;
    Manager manager;
    Director director;

    teamLead.setNext(&manager);
    manager.setNext(&director);

    // Test with different purchase amounts
    teamLead.processRequest(800);     // Team Lead approves
    teamLead.processRequest(3500);    // Manager approves
    teamLead.processRequest(12000);   // No one can approve

    return 0;
}