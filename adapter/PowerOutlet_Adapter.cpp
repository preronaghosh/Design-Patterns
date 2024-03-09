#include <iostream>
#include <string>

// Target interface for the power outlets in the destination country
class PowerOutlet {
public:
    virtual void plugIntoOutlet() const = 0;
};

// Adaptee - Electronic device with a specific power plug
class ElectronicDevice {
public:
    void connectToPower() const {
        std::cout << "ElectronicDevice - Connected to power" << std::endl;
    }
};

// Adapter class that adapts ElectronicDevice to PowerOutlet
class PowerAdapter : public PowerOutlet {
private:
    ElectronicDevice* device;

public:
    PowerAdapter(ElectronicDevice* device) : device(device) {}

    void plugIntoOutlet() const override {
        std::cout << "PowerAdapter - Plugged into outlet" << std::endl;
        device->connectToPower();
    }
};

int main() {
    // Using the PowerOutlet interface directly
    PowerOutlet* outlet = new PowerAdapter(new ElectronicDevice());
    outlet->plugIntoOutlet();

    delete outlet;

    return 0;
}
