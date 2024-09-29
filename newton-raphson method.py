import sympy as sp

# Define the variable
x = sp.symbols('x')

# Get the equation input from the user (as a string)
equation_input = input("Enter an equation in terms of x: ")

# Convert the string input into a sympy expression
equation = sp.sympify(equation_input)

# Differentiate the equation with respect to x
derivative = sp.diff(equation, x)

# Print the derivative
print(f"The derivative of {equation} is: {derivative}")
