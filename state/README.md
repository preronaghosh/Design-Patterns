## State Design Pattern

The State design pattern is a *behavioral* design pattern that allows an object to alter its behavior when its internal state changes. 
In essence, the object will appear to change its class when its state changes.

#### Key Concepts:
- **Context**: This is the class that has a reference to one of the concrete state objects and delegates to it depending on its current state.
- **State Interface**: This defines the interface for encapsulating the behavior associated with a particular state of the Context.
- **Concrete State Classes**: These classes implement the behavior associated with a state of the Context.

#### When to Use:
- When an object must change its behavior at runtime depending on its internal state.
- When multiple operations on an object depend on its state and there are significant state-specific behaviors.

#### Advantages:
- **Encapsulation of State-specific Behavior**: Each state-specific behavior is encapsulated in a class, making the system easier to understand and maintain.
- **Ease of Adding New States**: New states can be added without modifying existing state classes or the context class.
- **Flexibility**: Allows an object to change its behavior without modifying the object itself.


#### Disadvantages:
- **Increased Number of Classes**: The pattern may lead to a large number of classes, making the system more complex.
- **Context-Dependent**: The pattern might increase coupling between the state and the context, as the context needs to change its state.