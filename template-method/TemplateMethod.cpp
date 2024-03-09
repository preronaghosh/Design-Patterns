#include <iostream>

class BaseAlgorithm {
public:

    void runAlgorithm() {
        step1();
        step2();
        step3();
    }

    virtual void step1() const = 0;
    virtual void step2() const = 0;
    virtual void step3() const = 0;
    virtual ~BaseAlgorithm() = default;
};

class AlgorithmA : public BaseAlgorithm {
public:
    AlgorithmA() {}

    void step1() const {
        std::cout << "Algorithm A - step 1" << std::endl;
    }

    void step2() const {
        std::cout << "Algorithm A - step 2" << std::endl;
    }

    void step3() const {
        std::cout << "Algorithm A - step 3" << std::endl;
    }

    ~AlgorithmA() {}
};


class AlgorithmB : public BaseAlgorithm {
public:
    AlgorithmB() {}

    void step1() const {
        std::cout << "Algorithm B - step 1" << std::endl;
    }

    void step2() const {
        std::cout << "Algorithm B - step 2" << std::endl;
    }

    void step3() const {
        std::cout << "Algorithm B - step 3" << std::endl;
    }

    ~AlgorithmB() {}
};

int main() {
    BaseAlgorithm* algo1 = new AlgorithmA();
    algo1->runAlgorithm();
    delete algo1;

    BaseAlgorithm* algo2 = new AlgorithmB();
    algo2->runAlgorithm();
    delete algo2;
}