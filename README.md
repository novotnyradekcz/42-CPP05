*This project has been created as part of the 42 curriculum by rnovotny.*

# C++ Module 05 - Repetition and Exceptions

## Description

This project is part of the 42 C++ modules series, focusing on **exception handling**, **inheritance**, and **polymorphism** in C++. The module implements a bureaucratic system with forms, bureaucrats, and various administrative procedures.

The project is divided into four progressive exercises:

- **Exercise 00**: Implements a `Bureaucrat` class with grade validation and custom exceptions (`GradeTooHighException`, `GradeTooLowException`)
- **Exercise 01**: Adds a `Form` class that can be signed by bureaucrats with appropriate grades
- **Exercise 02**: Introduces an abstract `AForm` base class with concrete implementations:
  - `ShrubberyCreationForm`: Creates ASCII tree files
  - `RobotomyRequestForm`: Performs robotomy with 50% success rate
  - `PresidentialPardonForm`: Grants presidential pardons
- **Exercise 03**: Implements an `Intern` class that can dynamically create forms without using if/else chains

### Key Concepts Covered

- Exception handling (`try`, `catch`, `throw`)
- Custom exception classes inheriting from `std::exception`
- Abstract base classes and pure virtual functions
- Polymorphism and dynamic dispatch
- Orthodox Canonical Form (OCF)
- File I/O operations
- Function pointers (in Intern implementation)

## Instructions

### Compilation

Each exercise can be compiled independently using the provided Makefile:

```bash
# Navigate to an exercise directory
cd ex00  # or ex01, ex02, ex03

# Compile
make

# Run
./bureaucrat  # or ./form, ./aform, ./intern
```

### Compilation Flags

All exercises compile with:
```
c++ -Wall -Wextra -Werror -std=c++98
```

### Clean Up

```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Recompile from scratch
```

## Exercise Details

### Exercise 00: Bureaucrat
- **Files**: `Bureaucrat.cpp`, `Bureaucrat.hpp`, `main.cpp`
- **Features**:
  - Grade range: 1 (highest) to 150 (lowest)
  - Grade increment/decrement with validation
  - Custom exceptions for invalid grades
  - Overloaded `<<` operator for output

### Exercise 01: Form
- **Files**: Add `Form.cpp`, `Form.hpp`
- **Features**:
  - Forms have sign and execution grade requirements
  - Forms can be signed by bureaucrats
  - Bureaucrats can attempt to sign forms
  - Validation of bureaucrat grades before signing

### Exercise 02: Abstract Forms
- **Files**: `AForm` (abstract base), three concrete form classes
- **Features**:
  - Abstract `executeAction()` method
  - `ShrubberyCreationForm`: Writes ASCII trees to `<target>_shrubbery` files
  - `RobotomyRequestForm`: Makes drilling noises, 50% success rate
  - `PresidentialPardonForm`: Pardons target by Zaphod Beeblebrox
  - Forms can only be executed if signed and executor has sufficient grade

### Exercise 03: Intern
- **Files**: Add `Intern.cpp`, `Intern.hpp`
- **Features**:
  - `makeForm()` method creates forms by name
  - Uses function pointer array to avoid if/else chains
  - Returns pointer to newly created form or NULL if invalid
  - Supports: "shrubbery creation", "robotomy request", "presidential pardon"

## Usage Examples

### Creating and Using a Bureaucrat
```cpp
try {
    Bureaucrat alice("Alice", 1);
    std::cout << alice << std::endl;  // Alice, bureaucrat grade 1
    alice.incrementGrade();  // Throws GradeTooHighException
} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
}
```

### Signing and Executing Forms
```cpp
Bureaucrat bob("Bob", 137);
ShrubberyCreationForm shrub("home");

bob.signForm(shrub);
bob.executeForm(shrub);  // Creates home_shrubbery file
```

### Using Intern to Create Forms
```cpp
Intern intern;
AForm *form = intern.makeForm("robotomy request", "Bender");

if (form) {
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;
}
```

## Project Structure

```
CPP/05/
├── README.md
├── ex00/
│   ├── Bureaucrat.cpp
│   ├── Bureaucrat.hpp
│   ├── main.cpp
│   └── Makefile
├── ex01/
│   ├── Bureaucrat.{cpp,hpp}
│   ├── Form.{cpp,hpp}
│   ├── main.cpp
│   └── Makefile
├── ex02/
│   ├── AForm.{cpp,hpp}
│   ├── Bureaucrat.{cpp,hpp}
│   ├── ShrubberyCreationForm.{cpp,hpp}
│   ├── RobotomyRequestForm.{cpp,hpp}
│   ├── PresidentialPardonForm.{cpp,hpp}
│   ├── main.cpp
│   └── Makefile
└── ex03/
    ├── (All ex02 files)
    ├── Intern.{cpp,hpp}
    ├── main.cpp
    └── Makefile
```

## Resources

### Official Documentation
- [C++ Exception Handling](https://en.cppreference.com/w/cpp/language/exceptions)
- [C++ std::exception](https://en.cppreference.com/w/cpp/error/exception)
- [C++ Virtual Functions](https://en.cppreference.com/w/cpp/language/virtual)
- [C++ Abstract Classes](https://en.cppreference.com/w/cpp/language/abstract_class)

### Tutorials and Articles
- [Exception Handling in C++](https://www.geeksforgeeks.org/exception-handling-c/)
- [Abstract Classes and Pure Virtual Functions](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)
- [Function Pointers in C++](https://www.cprogramming.com/tutorial/function-pointers.html)

### AI Usage
AI assistance was used for the following tasks in this project:

- **Initial implementation**: AI helped generate the basic structure and skeleton code for all classes
- **Exception handling patterns**: Provided guidance on proper exception class design and usage
- **Polymorphism implementation**: Assisted with abstract base class design and virtual function implementation
- **Testing**: Generated comprehensive test cases covering edge cases (grade boundaries, invalid operations, etc.)
- **Code review**: Identified potential memory leaks and suggested improvements for the Intern class implementation
- **Documentation**: Assisted in writing clear comments and this README

No AI-generated code was used without understanding and verification. All implementations were reviewed and modified to ensure they meet the 42 project requirements and coding standards.

## Notes

- All classes follow the Orthodox Canonical Form (default constructor, copy constructor, assignment operator, destructor)
- Memory management is handled carefully to avoid leaks (especially in ex03 with dynamic form creation)
- Exception safety is maintained throughout the code
- The code adheres to C++98 standard
- No external libraries are used beyond the standard library

---

*Project completed as part of the 42 Common Core curriculum.*
