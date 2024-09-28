#include <bits/stdc++.h>
using namespace std;
int main();
double eqn(double n)
{
    return pow(n, 3) - (2 * n) - 5;
}
double modified_eqn(double n)
{
    return pow(5 + 2 * n, 0.3333);
    // return (5 / (pow(n, 2) - 2));
    // return (pow(n, 3) - 5) / 2;
}
void return_to_main()
{
    cout << "Do you want to find root again?(y/n): ";
    char st;
    cin >> st;
    if (st == 'y')
    {
        system("cls");
        main();
    }
    else
    {
        system("cls");
    }
}
void iteration()
{
    double initial_value;
    cout << "Enter the initial value of x: ";
    cin >> initial_value;
    bool root_found = false;
    int j = 0;
    cout << "n\tXn-1\tXn\terr" << endl;

    while (!root_found)
    {
        double new_value = modified_eqn(initial_value);
        double err = 100;
        double tolerance = 0.0001;
        if (j != 0)
        {
            err = abs(new_value - initial_value);
        }
        if (j == 0)
            cout << j + 1 << "\t" << initial_value << "\t" << new_value << "\t" << endl;
        else
            cout << j + 1 << "\t" << initial_value << "\t" << new_value << "\t" << err << endl;

        if (abs(modified_eqn(new_value)) <= tolerance || err <= tolerance)
        {
            root_found = true;
            cout << "Root: " << new_value << " (approx.) with error: " << err << endl;
        }
        initial_value = new_value;
        j++;
    }
    return_to_main();
}

void bisection(double a, double b)
{
    cout << "Bisection Method" << endl;

    bool root_found = false;
    double arr[100];
    int j = 0;
    double tolerance = 0.0001;
    cout << "n\ta\tb\tx\terr" << endl;
    while (!root_found)
    {
        double x = (a + b) / 2;
        arr[j] = x;
        double err = 100;

        if (j != 0)
        {
            err = abs(arr[j] - arr[j - 1]);
        }

        if (j == 0)
            cout << j + 1 << "\t" << a << "\t" << b << "\t" << x << endl;
        else
            cout << j + 1 << "\t" << a << "\t" << b << "\t" << x << "\t" << err << endl;

        if (abs(eqn(x)) <= tolerance || err <= tolerance)
        {
            root_found = true;
            cout << "Root: " << x << " (approx.) with error: " << err << endl;
        }
        else
        {

            if (eqn(x) < 0)
            {
                a = x;
            }
            else
            {
                b = x;
            }
        }

        j++;
    }
    cout << endl;

    return_to_main();
}
void falsePosition(double a, double b)
{
    cout << "False Position" << endl;

    bool root_found = false;
    double arr[100];
    int j = 0;
    double tolerance = 0.0001;
    cout << "n\ta\tb\tx\terr" << endl;
    while (!root_found)
    {
        double x = (a * eqn(b) - b * eqn(a)) / (eqn(b) - eqn(a));
        arr[j] = x;
        double err = 100;

        if (j != 0)
        {
            err = abs(arr[j] - arr[j - 1]);
        }

        if (j == 0)
            cout << j + 1 << "\t" << a << "\t" << b << "\t" << x << endl;
        else
            cout << j + 1 << "\t" << a << "\t" << b << "\t" << x << "\t" << err << endl;

        if (abs(eqn(x)) <= tolerance || err <= tolerance)
        {
            root_found = true;
            cout << "Root: " << x << " (approx.) with error: " << err << endl;
        }
        else
        {

            if (eqn(x) < 0)
            {
                a = x;
            }
            else
            {
                b = x;
            }
        }

        j++;
    }
    cout << endl;

    return_to_main();
}
void interval(int menuChoiche)
{
    double a = 0, b;
    int i = 1;
    bool flag = false;
    if (eqn(a) == 0)
        cout << a << endl;
    else
    {
        while (!flag)
        {
            if (eqn(a + i) * eqn(a) < 0)
            {
                b = a + i;
                a = a + i - 1;
                flag = true;
            }
            else if (eqn(a - i) * eqn(a) < 0)
            {
                b = a - i;
                a = a - i - 1;
                flag = true;
            }
            i++;
        }
        if (eqn(a) > 0)
        {
            swap(a, b);
        }

        if (menuChoiche == 1)
            bisection(a, b);
        else if (menuChoiche == 2)
            falsePosition(a, b);
    }
}
int main()
{
    cout << "Finding Root of x^3-2x-5=0" << endl
         << "\tMenu: " << endl
         << "\t1. Bisection Method" << endl
         << "\t2. False Position Method" << endl
         << "\t3. Iteration Method" << endl
         << "Your choice: ";
    int menu_choice;
    cin >> menu_choice;
    switch (menu_choice)
    {
    case 1:
        interval(menu_choice);
        break;
    case 2:
        interval(menu_choice);
        break;
    case 3:
        iteration();
        break;
    default:
        break;
    }
}
