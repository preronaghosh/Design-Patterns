#include <iostream>
#include <vector>
#include <memory>

/* Simple example of a collection of integers where we want to iterate over the elements. */

// Iterator Interface
template <typename T>
class Iterator {
public:
    virtual T next() = 0;
    virtual bool hasNext() = 0;
    virtual ~Iterator() = default;
};

// Concrete Iterator
template <typename T>
class ConcreteIterator : public Iterator<T> {
private:
    const std::vector<T>& collection;
    size_t index;

public:
    ConcreteIterator(const std::vector<T>& collection)
        : collection(collection), index(0) {}

    T next() override {
        return collection[index++];
    }

    bool hasNext() override {
        return index < collection.size();
    }
};

// Aggregate (or Collection) Interface
template <typename T>
class Collection {
public:
    virtual std::unique_ptr<Iterator<T>> createIterator() const = 0;
    virtual ~Collection() = default;
};

// Concrete Aggregate
template <typename T>
class ConcreteCollection : public Collection<T> {
private:
    std::vector<T> items;

public:
    void addItem(const T& item) {
        items.push_back(item);
    }

    std::unique_ptr<Iterator<T>> createIterator() const override {
        return std::make_unique<ConcreteIterator<T>>(items);
    }
};

int main() {
    // Create a collection
    ConcreteCollection<int> collection;
    collection.addItem(1);
    collection.addItem(2);
    collection.addItem(3);
    collection.addItem(4);
    collection.addItem(5);

    // Create an iterator for the collection
    auto iterator = collection.createIterator();

    // Iterate through the collection
    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }

    return 0;
}