### Builder Design Pattern

The *Builder Pattern* is a creational design pattern that allows for the step-by-step creation of complex objects. It separates the construction of an object from its representation, enabling the same construction process to create various representations. This pattern is particularly useful when an object requires multiple steps to be instantiated or when an object can have different representations.

#### Explanation:
- Product Class: Represents the product being built, which in this case is a generic product with three parts (partA, partB, and partC).
- Builder Interface: A templated interface that declares methods for creating parts of a product.
- ConcreteProductBuilder Class: Implements the Builder interface to construct and assemble parts of the Product. It manages the lifecycle of the Product.
- Director Class: A templated class that constructs an object using the Builder interface. It knows the sequence in which the construction steps should be executed.
- Client Code: Uses the Director to construct a Product object via the ConcreteProductBuilder.