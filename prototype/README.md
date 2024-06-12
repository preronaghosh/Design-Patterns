### Prototype

*The Prototype Pattern* is a creational design pattern that allows you to create new objects by copying an existing object, known as the prototype. This pattern is particularly useful when the cost of creating a new object directly is high, and you want to create a new object by cloning an existing instance.

### Key Concepts:
- Prototype Interface: This defines a method for cloning itself. Typically, this is done through a clone method.
- Concrete Prototype: This implements the prototype interface and provides a concrete implementation of the clone method.
- Client: The client uses the prototype to create new objects by calling the clone method.

### How It Works:
- Prototype Interface: Defines a clone method.
- Concrete Prototype: Implements the clone method to return a copy of itself.
- Client: Uses the clone method of a prototype to create a new object.