# C++ Module 01: Memory, References, Pointers, and Control Flow

[![C++ Programming](https://img.shields.io/badge/Language-C++-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Makefile](https://img.shields.io/badge/Build-Make-brightgreen.svg)](https://www.gnu.org/software/make/)

This repository contains the solutions for C++ Module 01 of the 42 core curriculum. This module serves as an essential introduction to fundamental C++ concepts beyond basic syntax, focusing on memory management, the nuances of pointers and references, pointers to members, file streams, and advanced control flow with switch statements.

## Core Concepts Covered

Throughout these exercises, the following key C++ concepts are explored and applied:

*   **Memory Allocation:** Understanding the difference between stack and heap allocation. Using `new` and `delete` for single objects, and `new[]` and `delete[]` for arrays of objects. Handling potential allocation failures (`std::bad_alloc`).
*   **Pointers:** Declaring, initializing, and dereferencing pointers. Understanding their relationship to memory addresses.
*   **References:** Declaring and using references as aliases for existing variables. Understanding their differences from pointers (non-nullability, non-reassignability after initialization).
*   **Pointers vs. References:** Choosing the appropriate tool (pointer or reference) based on requirements like optionality (nullable) or mandatory association. Using reference members and pointer members in classes.
*   **Pointers to Member Functions:** Declaring and using pointers that specifically point to member functions of a class. Syntax for calling member functions via pointers.
*   **File I/O Streams:** Reading from files using `std::ifstream` and writing to files using `std::ofstream`. Handling file operations and basic error checking.
*   **String Manipulation:** Using `std::string` methods like `find`, `erase`, `insert`, and `append`.
*   **Switch Statements:** Using `switch` for multi-way branching based on integer or enum values.
*   **Enum Classes:** Defining strongly-typed enumerations (`enum class`) for improved type safety.
*   **Control Flow Attributes:** Using `[[fallthrough]]` (C++17) to explicitly indicate intentional fallthrough in `switch` cases.
*   **Makefile Basics:** Creating simple Makefiles to automate the compilation process (`all`, `clean`, `fclean`, `re` rules).

---

## Exercises

### Exercise 00: BraiiiiiiinnnzzzZ

*   **Task:** Create a `Zombie` class. Implement functions to create a zombie on the heap (`newZombie`) and another function (`randomChump`) that creates a zombie on the heap, makes it announce itself, and then destroys it.
*   **Implementation:**
    *   A `Zombie` class with a `name` (std::string) and an `announce()` method.
    *   A constructor `Zombie(std::string name)` to initialize the zombie's name.
    *   A destructor `~Zombie()` to print a message upon destruction.
    *   `newZombie(std::string name)`: Allocates a `Zombie` object on the heap using `new` and returns a pointer to it.
    *   `randomChump(std::string name)`: Calls `newZombie` to create a zombie, calls its `announce()` method, and then uses `delete` to free the allocated memory. Basic `try-catch` for `std::bad_alloc` is included.
    *   `main.cpp`: Demonstrates the usage of `randomChump`.
*   **Concepts Learned:**
    *   Heap allocation using `new`.
    *   Object lifetime management using `delete`.
    *   Distinction between stack (automatic storage duration) and heap (dynamic storage duration) objects.
    *   Basic class definition, constructors, destructors, and member functions.

### Exercise 01: Moar brainz!

*   **Task:** Create a function `zombieHorde` that allocates an array (a "horde") of `N` zombies on the heap in a single allocation. Each zombie in the horde should have the same given name.
*   **Implementation:**
    *   `zombieHorde(int N, std::string name)`:
        *   Checks if `N` is valid (greater than 0). Throws an exception if not.
        *   Allocates an array of `N` `Zombie` objects using `new Zombie[N]`. This calls the default constructor for each zombie.
        *   Iterates through the allocated array, setting the name of each `Zombie` using a `setName` method (added to the `Zombie` class).
        *   Returns the pointer to the first element of the allocated array.
    *   `main.cpp`: Calls `zombieHorde`, makes each zombie announce itself, and then uses `delete[]` to deallocate the entire array. Includes `try-catch` for allocation errors and the custom input error.
*   **Concepts Learned:**
    *   Dynamic array allocation using `new[]`.
    *   Dynamic array deallocation using `delete[]`.
    *   Importance of matching `new[]` with `delete[]` (and `new` with `delete`).
    *   Accessing array elements using pointer arithmetic (implicitly via `[]`).
    *   Basic exception handling (`throw`, `try`, `catch`).

### Exercise 02: HI THIS IS BRAIN

*   **Task:** Demonstrate the relationship between a variable, a pointer to that variable, and a reference to that variable.
*   **Implementation:**
    *   A simple `main` function that:
        *   Declares a `std::string` variable (`str`).
        *   Declares a pointer (`stringPTR`) initialized with the address of `str`.
        *   Declares a reference (`stringREF`) initialized to `str`.
        *   Prints the memory address *of* the original variable (`&str`).
        *   Prints the memory address *stored in* the pointer (`stringPTR`).
        *   Prints the memory address *of* the reference (`&stringREF`). (Note: This shows the address of the original variable, as the reference is an alias).
        *   Prints the value *of* the original variable (`str`).
        *   Prints the value *pointed to* by the pointer (`*stringPTR`).
        *   Prints the value *referred to* by the reference (`stringREF`).
*   **Concepts Learned:**
    *   Pointer syntax (`*`, `&` for address-of).
    *   Reference syntax (`&` in declaration).
    *   Dereferencing pointers (`*`).
    *   Understanding that a reference is an alias for an existing variable and shares the same memory address.
    *   Distinguishing between the address stored *in* a pointer and the address *of* the pointer variable itself (though the latter isn't explicitly shown here).

### Exercise 03: Unnecessary violence

*   **Task:** Illustrate a scenario where using a reference is appropriate and another where a pointer is more suitable, specifically for class member variables.
*   **Implementation:**
    *   `Weapon` class: Represents a weapon with a type (string).
    *   `HumanA` class:
        *   Has a `name` (string) and a `weapon` (a `Weapon&` reference).
        *   The constructor `HumanA(std::string name, Weapon& weapon)` takes a `Weapon` by reference and initializes the member reference in the initializer list. This enforces that a `HumanA` *must* be created with a `Weapon` and cannot exist without one. The weapon cannot be changed later.
        *   `attack()` method uses the `weapon` reference.
    *   `HumanB` class:
        *   Has a `name` (string) and a `weapon` (a `Weapon*` pointer), initialized to `nullptr`.
        *   The constructor `HumanB(std::string name)` only takes the name.
        *   A `setWeapon(Weapon& newWeapon)` method allows assigning or changing the weapon *after* the `HumanB` object is created.
        *   `attack()` method checks if the `weapon` pointer is not null before attempting to use it (implicitly done by the example `main`, but good practice would require an explicit check).
    *   `main.cpp`: Demonstrates creating `HumanA` (which requires a weapon immediately) and `HumanB` (which can be given a weapon later).
*   **Concepts Learned:**
    *   Reference members: Must be initialized in the constructor's initializer list, cannot be null, cannot be reseated to refer to a different object. Use when an object *must* be associated with another object for its entire lifetime.
    *   Pointer members: Can be initialized to `nullptr`, can be reassigned later. Use when an association with another object is optional or can change over time.
    *   Constructor initializer lists.

### Exercise 04: Sed is for losers

*   **Task:** Create a program that takes a filename and two strings, `s1` and `s2`, as arguments. It should read the content of the file, replace every occurrence of `s1` with `s2`, and write the result to a new file named `<filename>.replace`.
*   **Implementation:**
    *   Checks for the correct number of command-line arguments (`argc == 4`).
    *   Opens the input file using `std::ifstream`. Includes error handling if the file cannot be opened.
    *   Reads the entire file content into a `std::string` (`infileContent`), preserving line breaks.
    *   Checks if `s1` is empty, exiting if it is (as replacing nothing causes issues).
    *   Uses a `while` loop with `std::string::find` to locate occurrences of `s1`.
    *   Inside the loop, uses `std::string::erase` to remove `s1` and `std::string::insert` to insert `s2` at the same position.
    *   Updates the search position to continue finding subsequent occurrences.
    *   Creates the output filename by appending ".replace" to the original filename.
    *   Opens the output file using `std::ofstream`. Includes error handling.
    *   Writes the modified `infileContent` to the output file.
    *   Closes both file streams implicitly by RAII (Resource Acquisition Is Initialization) when `infileStream` and `outfileStream` go out of scope, although explicit `close()` is also shown.
*   **Concepts Learned:**
    *   File input streams (`std::ifstream`).
    *   File output streams (`std::ofstream`).
    *   Reading from files (`std::getline`).
    *   Writing to files (`<<` operator).
    *   Command-line argument parsing (`argc`, `argv`).
    *   String searching (`std::string::find`).
    *   String modification (`std::string::erase`, `std::string::insert`, `std::string::append`).
    *   Basic file system interaction (opening/creating files).
    *   Error handling for file operations.

### Exercise 05: Harl 2.0

*   **Task:** Implement a `Harl` class with four private member functions representing different complaint levels (DEBUG, INFO, WARNING, ERROR). Create a public member function `complain(std::string level)` that calls the appropriate private function based on the input string `level`.
*   **Implementation:**
    *   `Harl` class with private methods: `debug()`, `info()`, `warning()`, `error()`.
    *   A `typedef` within the class `typedef void (Harl::*fcnPtr)()` defines a type alias for a pointer to a member function of `Harl` that takes no arguments and returns `void`.
    *   The `complain(std::string level)` method:
        *   Creates an array of strings holding the valid level names (`"DEBUG"`, `"INFO"`, etc.).
        *   Creates a parallel array of pointers to the corresponding member functions (`&Harl::debug`, `&Harl::info`, etc.).
        *   Iterates through the level strings. If a match is found with the input `level`:
            *   It calls the member function using the pointer-to-member syntax: `(this->*functions[i])()`.
            *   The loop breaks after finding and executing the function.
    *   `main.cpp`: Creates a `Harl` object and calls `complain` with different levels, including invalid ones (which do nothing).
*   **Concepts Learned:**
    *   Pointers to member functions: Syntax for declaration (`ReturnType (ClassName::*PointerName)(Args)`) and getting the address (`&ClassName::FunctionName`).
    *   Using `typedef` to simplify complex type declarations.
    *   Syntax for calling member functions via pointers: `(object.*pointerToMemberFunction)(args)` or `(objectPointer->*pointerToMemberFunction)(args)`.
    *   Implementing a dispatch mechanism using arrays of strings and function pointers.

### Exercise 06: Harl Filter

*   **Task:** Modify the Harl program so that it filters messages based on a minimum level provided as a command-line argument. When a level is provided, Harl should display messages of that level and all levels above it (DEBUG < INFO < WARNING < ERROR). Invalid levels should trigger a default message.
*   **Implementation:**
    *   An `enum class ComplainLevel` is defined to represent the different levels plus an 'Other' state, providing type safety.
    *   A helper function `getComplainLevel(std::string level)` converts the input string to the corresponding `ComplainLevel` enum value.
    *   The `Harl` class now has a `filter(std::string level)` method instead of `complain`.
    *   The `filter` method uses a `switch` statement based on the `ComplainLevel` returned by `getComplainLevel`.
    *   Crucially, it uses the `[[fallthrough]]` attribute (C++17) after each case (except ERROR and default) to achieve the desired filtering behavior. For example, if the input level is "INFO", the `case ComplainLevel::eInfo:` will execute, then fall through to `case ComplainLevel::eWarning:`, and finally fall through to `case ComplainLevel::eError:`.
    *   The `default` case handles unrecognized levels.
    *   `main.cpp`: Takes exactly one command-line argument, creates a `Harl` object, and calls `filter` with the provided argument.
*   **Concepts Learned:**
    *   `switch` statement for multi-way branching.
    *   `enum class` for strongly-typed enumerations, improving code clarity and safety compared to plain enums.
    *   Intentional fallthrough in `switch` statements and using the `[[fallthrough]]` attribute (C++17 standard) to clearly signal this intent and suppress potential compiler warnings.
    *   Combining enums and switch statements for state management or level-based logic.
    *   Handling command-line arguments (`argc`, `argv`).

---

## How to Compile and Run

Each exercise is contained within its own subdirectory (e.g., `ex00/`, `ex01/`, etc.) and includes its own `Makefile`.

1.  Navigate to the directory of the exercise you want to compile:
    ```bash
    cd ex<XX>/
    ```
    (Replace `<XX>` with the exercise number, e.g., `00`, `01`, `02`...)

2.  Compile the code using the `make` command:
    ```bash
    make
    ```
    This will create an executable file (e.g., `zombie`, `zombieHorde`, `hiThisIsBrain`, `unnecessaryViolence`, `sedIsForLosers`, `harl`, `harlFilter`).

3.  Run the executable:
    ```bash
    ./<executable_name> [arguments...]
    ```
    (Replace `<executable_name>` with the actual name. Some exercises like `ex04` and `ex06` require command-line arguments).

    *   **Example (ex04):** `./sedIsForLosers myInputFile.txt "old text" "new text"`
    *   **Example (ex06):** `./harlFilter WARNING`

4.  Use the other Makefile rules as needed:
    *   `make clean`: Removes object files (`.o`).
    *   `make fclean`: Removes object files and the executable.
    *   `make re`: Runs `fclean` followed by `all` (recompiles everything).
