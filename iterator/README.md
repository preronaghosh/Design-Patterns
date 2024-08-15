### Iterator Design Pattern

The Iterator design pattern is a *behavioral* design pattern that provides a way to access the elements of an aggregate object sequentially without exposing its underlying representation. The pattern allows you to traverse a container (such as a list or a collection) and access its elements without needing to know how the container is implemented.


#### Key Concepts:
- Iterator Interface: Defines the interface for accessing and traversing elements in a collection.
- Concrete Iterator: Implements the Iterator interface for a specific collection.
- Aggregate (or Collection): The object that holds the collection of elements and provides a method to create an iterator for itself.
- Concrete Aggregate: Implements the Aggregate interface and returns an instance of the appropriate Concrete Iterator.


#### When to Use:
- When you need to access the elements of a collection without exposing its internal structure.
- When you need to provide multiple traversal strategies (e.g., forward, backward) for a collection.
- When you want to simplify the collection classes by handling traversal in a separate iterator class.
