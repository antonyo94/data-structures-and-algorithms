#  Data Structures and Algorithms

## 🛠 Skills
DSA, C++, Object Oriented Programming

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
The first track of the project, relating to the implementation of the Assembly Line, allowed me to learn, in a practical way, how the resolution of an **optimization problem** can be approached, i.e. a type of problem that has several optimal solutions and with respect to which it is possible to associate a goodness index, in order to identify which is the best desired solution. Furthermore, I was able to see how to significantly reduce the **computational complexity** of an algorithm, using the right programming technique.
Similarly, I had the opportunity to approach **C++** in a practical way, with respect to which I tried to fully exploit the characteristics of an **object-oriented programming language**. In fact, there is no lack of development of the **abstraction** and **encapsulation** characteristics, defining the members of the various classes as **public** and **private** and allowing the end user to approach the entire implementation with an **interface**. Additionally, each class was given a **constructor** and a **destructor**; if it was deemed necessary, the default constructor was **overloaded**, to allow the correct initialization of the objects, using arguments defined in input. In addition, the classes have been equipped with the canonical **getter** and **setter** methods, for the valorization and recovery of information and to maintain the integrity and coherence of the data.

### Track 2 - Max Priority Queue
The second track instead allowed me to analyze the implementation of an important data structure, namely a **maximum priority queue**, developed through a **binary search tree**, in its red-black variant. The priority queue, by its definition, is a data structure that serves to maintain a set of elements to each of which is associated with a key and, based on the latter, it is possible to identify the precedence of an element in the set with respect to to another. In this case therefore, I was able to see how, by choosing the right data structure to solve the problem, it is possible to reduce the time of the required operations, down to a minimum complexity. In fact, examining the case in question, the red-black binary trees represent a hierarchical data structure that extends, in terms of operations, the binary search trees. Compared to the latter, they maintain the same properties, but limit the costs of accessing the data by maintaining additional information, that of color, in order to maintain a correctly balanced structure at the end of the modification operations.
From a purely implementation point of view, using the same C++ programming language mentioned before, I had the opportunity to learn the concept of **object pointers**, to allow for example the right child node and the left child node, within the binary tree, to point to its parent node. In correspondence with the object pointers, the **new()** and **delete()** functions were then used for dynamic **memory allocation**, in addition to the usual constructors and destructors present within the classes.

