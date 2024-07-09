#include "dllutils.h"

int main() {
    // Example usage
    auto myFunction = DllUtils::loadFunction("mymodule.dll", "MyFunction");
    if (myFunction) {
        myFunction(); // Invoke the loaded function
    }
    return 0;
}
