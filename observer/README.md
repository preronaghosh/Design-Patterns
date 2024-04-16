1. Motivation: 
    - Move from polling (constanty request subject asking for current state) to push (concreteSubject notifies observer of any state changes). 

2. Implementation:
    - We can have Subject and Observer base classes, which can be derived by multiple ConcreteSubject and ConcreteObserver classes respectively.
    - One subject has relationships with many observers. When a subject's state changes, all relevant concreteObservers are notified.
    - ConcreteObservers can handle the updates in their own ways. 