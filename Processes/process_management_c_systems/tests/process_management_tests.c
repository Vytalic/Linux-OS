#include "process_value_sharing.h"  // Include the header file
#include <assert.h>  // Standard library for assertions

void test_process_value() {
    value = 5;  // Reset the global value to its initial state
    int result = simulate_process_value_sharing();
    assert(result == 5);  // Assert that the parent's value remains 5
}

int main() {
    test_process_value();  // Run the test
    printf("All tests passed!\n");
    return 0;
}
