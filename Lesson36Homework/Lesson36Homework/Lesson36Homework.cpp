
#include <iostream>
#include <string>

using namespace std;

/*
 * GLOBAL VARIABLES
 * Variables declared outside any function have global scope.
 * They can be accessed from anywhere in the program using the scope resolution operator (::)
 */
int x = 300;                          // Global variable x
const int SECOND_IN_MINUTE = 60;      // Global constant (cannot be modified)

/*
 * FUNCTION 1: Local Variable Shadowing
 * Demonstrates how a local variable can "shadow" (hide) a global variable with the same name.
 * The local x (500) takes precedence over the global x (300) within this function.
 */
void myFunction1() {
	int x = 500;  // Local variable x shadows the global x

	cout << "The value of x inside funcion is: " << x << "\nAddress: " << &x << "\n\n";
	// Output: 500 and a NEW memory address (different from global x and main's x)
}

/*
 * FUNCTION 2: Pass by Const Reference
 * Parameters: const int& x - reference that cannot modify the original value
 *            const string& prompt - reference to avoid string copying
 *
 * Key Points:
 * - The '&' makes it a reference (alias to the original variable)
 * - 'const' prevents modification of the referenced value
 * - No copy is made, so the address is the SAME as the original variable
 * - More efficient than pass-by-value for large objects
 * - Can accept both variables AND constants
 */
void myFunction2(const int& x, const string& prompt = "x") {
	// x = 20;  // ERROR: Cannot modify const reference

	cout << "The value of " << prompt << " inside funcion Passed By Const Reference is: " << x << "\nAddress: " << &x << "\n\n";
	// Address will be SAME as the argument passed in
}

/*
 * FUNCTION 3: Pass by Reference
 * Parameters: int& x - reference that CAN modify the original value
 *
 * Key Points:
 * - The '&' makes it a reference (alias to the original variable)
 * - Can modify the original variable
 * - No copy is made, so the address is the SAME as the original variable
 * - CANNOT accept constants (like SECOND_IN_MINUTE) because it could modify them
 * - Use when you need to modify the original variable
 */
void myFunction3(int& x, const string& prompt = "x") {
	// x = 20;  // ALLOWED: Can modify the original variable

	cout << "The value of " << prompt << " inside funcion Passed By Reference is: " << x << "\nAddress: " << &x << "\n\n";
	// Address will be SAME as the argument passed in
}

/*
 * FUNCTION 4: Pass by Value
 * Parameters: int x - a COPY of the original value
 *
 * Key Points:
 * - Creates a NEW copy of the argument
 * - Modifications don't affect the original variable
 * - Address is DIFFERENT from the original variable
 * - Less efficient for large objects due to copying
 * - Use when you don't need to modify the original and the type is small
 */
void myFunction4(int x, const string& prompt = "x") {
	// x = 20;  // ALLOWED but only modifies the local copy

	cout << "The value of " << prompt << " inside funcion Passed By Value is: " << x << "\nAddress: " << &x << "\n\n";
	// Address will be DIFFERENT (new memory location)
}

/*
 * MAIN FUNCTION
 * Demonstrates three key concepts:
 * 1. Variable Scope (local vs global)
 * 2. Scope Resolution Operator (::)
 * 3. Parameter Passing Methods (by value, by reference, by const reference)
 */
int main()
{
	// ==========================================
	// SECTION 1: Variable Scope Demonstration
	// ==========================================

	int x = 10;  // Local variable x in main (shadows global x)

	// Local x takes precedence in this scope
	cout << "The local value of x inside Main is: " << x << "\nAddress: " << &x << "\n\n";
	// Output: 10 and its unique address

	// Use :: (scope resolution operator) to access global x
	cout << "The global value of x is: " << ::x << "\nAddress: " << &::x << "\n\n";
	// Output: 300 and a DIFFERENT address than local x

	// ==========================================
	// SECTION 2: Passing Local Variable
	// ==========================================

	myFunction1();
	// Creates its own local x = 500 with NEW address

	myFunction2(x, "local x");
	// Pass by const ref: shows 10, SAME address as main's x

	myFunction3(x, "local x");
	// Pass by ref: shows 10, SAME address as main's x

	myFunction4(x, "local x");
	// Pass by value: shows 10, NEW address (copy created)

	cout << string(30, '_') << endl;

	// ==========================================
	// SECTION 3: Passing Global Variable
	// ==========================================

	myFunction2(::x, "global x");
	// Pass by const ref: shows 300, SAME address as global x

	myFunction3(::x, "global x");
	// Pass by ref: shows 300, SAME address as global x

	myFunction4(::x, "global x");
	// Pass by value: shows 300, NEW address (copy created)

	cout << string(30, '_') << endl;

	// ==========================================
	// SECTION 4: Passing Constants
	// ==========================================

	myFunction2(SECOND_IN_MINUTE, "SECOND_IN_MINUTE");
	// Pass by const ref: WORKS - shows 60, SAME address
	// Const ref can accept constants

	// myFunction3(SECOND_IN_MINUTE); 
	// ERROR: Cannot pass const to non-const reference
	// Non-const reference could modify the value, but constants cannot be modified

	myFunction4(SECOND_IN_MINUTE, "SECOND_IN_MINUTE");
	// Pass by value: WORKS - shows 60, NEW address (copy created)
	// Copy is allowed because it doesn't modify the original

	// Display the constant's value and address
	cout << "The global value of SECOND_IN_MINUTE is: " << SECOND_IN_MINUTE << "\nAddress: " << &SECOND_IN_MINUTE << "\n\n";

	return 0;
}

/*
 * KEY TAKEAWAYS:
 *
 * 1. SCOPE RESOLUTION (::)
 *    - Use :: to access global variables when shadowed by local variables
 *    - Example: ::x accesses global x instead of local x
 *
 * 2. PASS BY VALUE (int x)
 *    - Creates a copy (different address)
 *    - Safe: cannot modify original
 *    - Less efficient for large objects
 *
 * 3. PASS BY REFERENCE (int& x)
 *    - No copy (same address)
 *    - Can modify original
 *    - Cannot accept constants
 *    - Efficient for large objects
 *
 * 4. PASS BY CONST REFERENCE (const int& x)
 *    - No copy (same address)
 *    - Cannot modify original
 *    - Can accept constants
 *    - Best practice for passing large objects you don't need to modify
 *
 * 5. MEMORY ADDRESSES
 *    - References share the same address as the original variable
 *    - Pass-by-value creates new memory addresses
 *    - Use & operator to get the address of a variable
 *
 * BEST PRACTICES:
 * - Use const reference for large objects you won't modify
 * - Use reference when you need to modify the original
 * - Use pass-by-value for small types (int, char, bool) when you don't need to modify
 * - Always use const for parameters you don't intend to modify
 */