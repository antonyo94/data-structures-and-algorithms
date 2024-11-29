#  Data Structures and Algorithms

## 🛠 Skills
- DSA
- C++
- Object Oriented Programming

## 📝 Requirements

1.**Assembly Line**
*For the production of the New Panda, Fiat has installed K assembly lines in the Pomigliano d'Arco plant, with K > 1. Each assembly line has L work stations. Each workstation has a different processing time T. Furthermore, the New Panda chassis takes an initial time I to enter the assembly line and a different time U for each assembly line to exit. Assume that the migration time ε ; between two successive stations within the same chain is not negligible. Finally, to provide the system with maximum flexibility, consider the possibility that the New Panda can migrate from one assembly line to another and this operation takes a time, different for each chain, equal to S. This is resolved by dynamic programming, the problem of identifying the fastest route for each car, writing the related recurrence equations. Subsequently, a program is implemented, using the aforementioned approach, which identifies the fastest route for each car. Check the correctness of the implementation on a series of possible system configurations.*

2.**Max Priority Queue**
*Construct, using a Red-Black tree, a max priority queue. Please remember that the public interface of the priority queue must contain the following methods (extract-max, insert, maximum, increase-key) plus any constructors and destructor.*

## 📖 Lessons Learned
The project allowed me to put into practice the key concepts of Algorithms and Data Structures, addressing two key problems of this topic, namely:
- Dynamic programming, through the resolution of track 1 Assembly Line;
- Max Priority Queue, through the implementation of a Red-Black Binary Tree of track 2.

### Track 1 - Assembly Line
The first track of the project, relating to the implementation of the Assembly Line, allowed me to:
  - Learn, in a practical way, how the resolution of an optimization problem can be approached. 
    - These problems have several optimal solutions, each associated with a goodness index, to identify the best desired solution.
  - Understand how to significantly reduce the computational complexity of an algorithm by using the right programming technique.

Moreover, I had the opportunity to approach C++ in a practical way, fully exploiting the characteristics of an object-oriented programming language:
  - Developed abstraction and encapsulation characteristics by:
    - Defining members of various classes as public and private.
    - Allowing the end user to interact with the implementation through an interface.
  - Implemented constructors and destructors for each class:
    - Overloaded the default constructor, when necessary, to allow correct object initialization using input-defined arguments.
  - Equipped classes with canonical getter and setter methods:
    - Facilitated the valorization and recovery of information.
    - Maintained data integrity and coherence.



### Track 2 - Max Priority Queue
The second track of the project allowed me to analyze the implementation of an important data structure, namely a **maximum priority queue**, developed through a **binary search tree** in its red-black variant:
  - A priority queue is a data structure that maintains a set of elements, each associated with a key, allowing the precedence of one element over another to be determined based on the key.
  - I learned how choosing the right data structure for a problem can reduce the time complexity of required operations to a minimum.

Key insights from analyzing red-black binary trees:
  - They represent a hierarchical data structure that extends binary search trees in terms of operations.
  - While maintaining the properties of binary search trees, they reduce data access costs by maintaining additional information (the color) to ensure a balanced structure after modification operations.

About C++ programming language:
  - I learned the concept of **object pointers**, enabling:
    - The right and left child nodes within the binary tree to point to their parent node.
  - I applied the **new()** and **delete()** functions for dynamic **memory allocation**, alongside the usual constructors and destructors within classes.

