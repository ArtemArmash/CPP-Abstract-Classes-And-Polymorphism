# C++ OOP: Abstract Classes and Polymorphism Examples

This repository contains two separate C++ projects that demonstrate the practical application of advanced Object-Oriented Programming (OOP) principles, including **abstract classes**, **pure virtual functions**, **inheritance**, and **polymorphism**.

---

## 1. Mathematical Equation Solver (`math.cpp`)

This program provides a robust, object-oriented framework for solving different types of mathematical equations. It uses an abstract base class to define a common interface for all equation types.

### About The Project

The goal is to model the relationship between different kinds of equations. A `Math` class serves as an abstract base, declaring a pure virtual function `RootEquation()`. Concrete classes, `LineEquation` and `SquadEquation` (Quadratic Equation), inherit from `Math` and provide specific implementations for finding their roots.

### Concepts Demonstrated

*   **Abstract Base Classes**: Using a class with a pure virtual function (`= 0`) as an un-instantiable interface.
*   **Polymorphism**: The `RootEquation()` method is implemented differently in each derived class to solve the specific type of equation.
*   **Inheritance**: The classes share common properties (`a`, `b`) defined in the base class.
*   **Error Handling**: Uses `throw runtime_error` to handle invalid or unsolvable equation states (e.g., no solution, infinite solutions, no real roots).
*   **Delegation**: The `SquadEquation` class correctly handles the edge case where `a=0` by delegating the problem to a `LineEquation` object.

### How to Build and Run

1.  Save the code as `math.cpp`.
2.  Compile using a C++ compiler:
    ```sh
    g++ math.cpp -o math_solver_app
    ```
3.  Run the executable:
    ```sh
    ./math_solver_app
    ```

### Expected Output
```
Result: x = 1.5
Result: x1 = 2, x2 = 1
```

---

## 2. Polymorphic Shape Editor (`shapes.cpp`)

This program demonstrates a more complex use of polymorphism to create a basic graphical shape management system. It can handle different types of shapes, display their properties, and serialize them to a file.

### About The Project

This project defines an abstract `Shape` class with pure virtual functions for `Show()`, `Save()`, and `Load()`. Several concrete shape classes (`Square`, `Rectangle`, `Circle`, `Ellipse`) inherit from `Shape` and provide their own implementations. The `main` function uses a `std::vector<Shape*>` to manage a collection of different shapes polymorphically.

### Concepts Demonstrated

*   **Polymorphism with Collections**: Storing pointers to objects of different derived classes in a single `std::vector` of base class pointers.
*   **Abstract Class as Interface**: The `Shape` class defines a contract that all derived shapes must adhere to.
*   **File I/O and Serialization**: Each shape knows how to save its state to a text file.
*   **Dynamic Memory Management**: Objects are created on the heap with `new` and must be manually freed with `delete`.
*   **Virtual Destructor**: The base class has a virtual destructor to ensure that the correct derived class destructor is called when deleting a base class pointer, preventing memory leaks.

### How to Build and Run

1.  Save the code as `shapes.cpp`.
2.  Compile using a C++ compiler:
    ```sh
    g++ shapes.cpp -o shape_editor_app
    ```
3.  Run the executable:
    ```sh
    ./shape_editor_app
    ```

### Important Note on the `Load` Functionality

The `Save` functionality in this project works correctly by appending each shape's data to `shapes.txt`. However, the **`Load` functionality in the `main` function is logically flawed and serves as a good example of a common mistake.**

*   **The Problem**: The `Load` method within each class is designed to read from a file and print what it finds. It **does not create new shape objects**. The `main` function's loading loop creates a local `Square` object and calls its `Load` method, which simply reads and prints all lines from the file without actually creating a `Square`. It does not deserialize the data back into a vector of shape objects.

*   **How to Fix It (Conceptual)**: A correct loading mechanism would involve:
    1.  Reading the file line by line.
    2.  For each line, read the first word (e.g., "Square", "Circle") to determine the type of shape to create.
    3.  Based on the type, read the corresponding data points.
    4.  Use a factory pattern or a series of `if/else if` statements to dynamically create the correct shape object (`new Square(...)`, `new Circle(...)`, etc.) and add its pointer to the `loadedShapes` vector.

### Expected Output

Running the program will create a `shapes.txt` file with the content `Square 0 0 5`. The console output will be:
```
Square: Top left corner coordinates (0, 0), Side length: 5
Loaded Square: Top left corner coordinates (0, 0), Side length: 5
```
