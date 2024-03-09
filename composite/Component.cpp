#include <iostream>
#include <vector>

/**
 * Common interface for both children and leaf types of components
*/

class Component {
public:
    virtual ~Component() {}    

    virtual Component* getChild() {
        return 0;
    }

    virtual void add(Component*) { } // for composite nodes only
    virtual void remove(int index) { } // for composite nodes only
    virtual void operation() = 0; // has to be implemented by derived classes
};


/**
 * Component with children that can be of types composite or leaf
*/

class Composite : public Component {
public:
    Component* getChild(const int index)
    {
        return children[index];
    }

    void add(Component* component) {
        children.push_back(component);
    }

    void remove(const int index) {
        children.erase(children.begin() + index);
    }

    void operation() override {
        std::cout << "Composite operation" << std::endl;

        for (const auto& child: children) {
            child->operation();
        }
    }

    ~Composite() override {
        // clean up memory
        for (const auto& child : children) {
            delete child;
        }
    }

private:
    std::vector<Component*> children;
};

/**
 * Has no children, end of tree structure
*/
class Leaf : public Component {
public:
    Leaf(const int i) : id(i) {}

    void operation() override {
        std::cout << "Leaf "<< id <<" operation" << std::endl;
    }
    
    ~Leaf() {}
private:
    int id;
};

int main() {
    // Create leaf objects
    Leaf* leaf1 = new Leaf(0);
    Leaf* leaf2 = new Leaf(1);

    // Create composite object and add leaf objects to it
    Composite* composite = new Composite();
    composite->add(leaf1);
    composite->add(leaf2);

    // Use the composite, treating it like a leaf
    composite->operation();

    delete composite;

    return 0;
}
