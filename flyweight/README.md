### Flyweight Pattern

*The Flyweight Pattern* is a structural design pattern that focuses on minimizing memory usage by sharing as much data as possible with other similar objects. It is particularly useful when dealing with a large number of objects that share common data.

#### Key Concepts:

- Flyweight: An interface that declares methods which the flyweight objects can use.
- Concrete Flyweight: A class that implements the Flyweight interface and adds storage for intrinsic state.
- Flyweight Factory: A factory that creates and manages Flyweight objects and ensures that flyweights are shared properly.
- Intrinsic State: The state that is shared between many objects and is stored in the flyweight.
- Extrinsic State: The state that is unique to each object and is passed to the flyweight methods.

#### Advantages of the Flyweight Pattern:

- Reduced Memory Usage: Color objects are shared among many shapes, reducing the number of color objects created.
- Improved Performance: By sharing color objects, the application uses less memory, which can improve performance.

#### When to use:
- When you have a large number of objects that share common data.
- When the storage cost of the objects is high, and many objects can share the same data.
- When you want to improve memory efficiency and performance by sharing as much data as possible.