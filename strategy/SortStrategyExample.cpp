#include <iostream>
#include <vector>
#include <algorithm> 

// Strategy Interface for sorting
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) const = 0;
    virtual ~SortingStrategy() = default;
};

// Concrete Strategy 1: Bubble Sort
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) const override {
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data.size() - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

// Concrete Strategy 2: Quick Sort
class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) const override {
        std::sort(data.begin(), data.end()); 
    }
};

// Context Class
class Sorter {
private:
    std::unique_ptr<SortingStrategy> strategy;

public:
    void setStrategy(std::unique_ptr<SortingStrategy> strategy) {
        this->strategy = std::move(strategy);
    }

    void sort(std::vector<int>& data) {
        if (strategy) {
            strategy->sort(data);
        } else {
            std::cerr << "Sorting strategy not defined." << std::endl;
        }
    }
};

int main() {
    std::vector<int> data = {32, 10, 20, 5, 3};

    Sorter sorter;

    // Using Bubble Sort
    sorter.setStrategy(std::make_unique<BubbleSort>());
    sorter.sort(data);
    std::cout << "Bubble Sort: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Change to Quick Sort
    data = {32, 10, 20, 5, 3}; // reset data
    sorter.setStrategy(std::make_unique<QuickSort>());
    sorter.sort(data);
    std::cout << "Quick Sort: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
