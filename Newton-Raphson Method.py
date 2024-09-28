import sympy as sp

def magicfunction(in_val, equation, first_derivative, n):
    fx = equation.subs(x, in_val)
    fxd = first_derivative.subs(x, in_val)
    new_value = in_val - (fx/fxd)
    err = abs(new_value - in_val)
    if n != 1:
        print(f"{n}\t{round(in_val, 5)}\t{round(new_value, 5)}\t{round(err, 5)}")
    else:
        print(f"{n}\t{round(in_val, 5)}\t{round(new_value, 5)}")

    n+=1
    if err <= 0.0001:
        return new_value
    else:
        return magicfunction(new_value, equation, first_derivative, n)


x = sp.symbols('x')

equation_input = input("Enter an equation in terms of x: ")

equation = sp.sympify(equation_input)

initial_value = float(input("Enter initial value: "))

first_derivative = sp.diff(equation, x)

print("n\tXn-1\tXn\terror")
print(f"Approximate root = {round(magicfunction(initial_value, equation, first_derivative, 1), 4)}")


