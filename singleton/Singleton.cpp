#include <iostream>

template <typename T>
class Singleton {
public:
    // Define a static method to get the instance
    static T& getInstance() {
        static T instance;  
        return instance;
    }

    // Prevent explicit instantiation and copying
    Singleton(Singleton const&) = delete;
    void operator=(Singleton const&) = delete;

protected:
    // Protected constructor to allow derived classes to be created
    Singleton() {
        std::cout << "Singleton instance created." << std::endl;
    }

    // Protected destructor to allow derived classes to be destroyed
    ~Singleton() {
        std::cout << "Singleton instance destroyed." << std::endl;
    }
};


class MySingleton : public Singleton<MySingleton> {
public:
    void myFunction() {
        std::cout << "MySingleton function called." << std::endl;
    }
};

int main() {
    MySingleton& mySingleton = MySingleton::getInstance();
    mySingleton.myFunction();
    return 0;
}
