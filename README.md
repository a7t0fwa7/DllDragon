# DllDragon 🐉

This project provides a utility for dynamically loading functions from Windows DLLs (Dynamic Link Libraries) at runtime. It improves upon the original code from [mayossi/Dynamic-Windows-API-Resolver](https://github.com/mayossi/Dynamic-Windows-API-Resolver/blob/main/resolver.hpp) by introducing several enhancements and additional features.

## Improvements and Features

1. **Resource Management with RAII**: The `DllWrapper` class automatically unloads the DLL when it goes out of scope, ensuring proper resource cleanup and preventing resource leaks.

2. **Error Logging**: Instead of throwing exceptions, the code now logs errors using a custom `Logger` class, providing better control over error handling and debugging.

3. **Thread Safety**: The `DllWrapper` class is now thread-safe, with each thread having its own instance, avoiding potential race conditions and synchronization issues.

4. **Caching Mechanism**: A caching mechanism has been implemented to store loaded DLL modules and resolved function addresses, improving performance by avoiding redundant module loading and function resolution.

5. **Modularity and Separation of Concerns**: The dynamic library loading and function resolution logic has been separated into a dedicated `DllUtils` class, improving code organization and maintainability.

6. **Improved API**: The `resolveApi` function now returns a `std::function` object instead of a raw function pointer, providing more flexibility and type safety.

## Usage

To use the dynamic library loading and function resolution utility, follow these steps:

1. Include the necessary header files:

```cpp
#include "dllutils.h"
```

2. Load a function from a DLL:

```cpp
auto myFunction = DllUtils::loadFunction("mymodule.dll", "MyFunction");
if (myFunction) {
    myFunction(); // Invoke the loaded function
}
```

The `loadFunction` method takes two arguments:
- `moduleName`: The name of the DLL module to load (e.g., "mymodule.dll").
- `procName`: The name of the function to retrieve from the loaded module (e.g., "MyFunction").

If the function is successfully loaded, the `loadFunction` method returns a `std::function<void()>` object representing the loaded function. You can then invoke the function by calling the returned object.

## Building and Running

To build and run the project, follow these steps:

1. Clone the repository:

```
git clone https://github.com/a7t0fwa7/DllDragon.git
```

2. Navigate to the project directory:

```
cd DllDragon
```

3. Compile the source files:

```
g++ -o resolver main.cpp dllutils.cpp
```

4. Run the compiled executable:

```
./resolver
```

## Contributing

Contributions to this project are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
