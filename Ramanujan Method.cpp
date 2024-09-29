#include <bits/stdc++.h>
using namespace std;
double valueofb(vector<double> a, double b[], int current, int limit)
{
    double sum = 0;
    cout << "b(" << current << ")= ";
    for (int i = 0, j = current - 1, iteration = 0; iteration < limit; i++, j--)
    {
        sum += a[i] * b[j];
        // cout << "a(" << i << ")*b(" << j << ")= " << a[i] * b[j] << endl;
        cout << "a(" << i << ")*b(" << j << ")";
        if (iteration == limit - 1)
            cout << "= ";
        else
            cout << " + ";
        iteration++;
    }
    cout << sum << endl;
    return sum;
}
int main()
{
    int n;
    cout << "Using Ramanujan's Method To Find the Smallest Root\norder of equation: ";
    cin >> n;
    // double a[100] = {0};
    vector<double> a(100, 0);
    cout << "Enter the co-efficients in order (higher to lower): ";
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    double cont = a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] /= cont;
        a[i] *= -1;
    }
    a[n] = 0;
    reverse(a.begin(), a.begin() + 3);
    cout << "\nThe series: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "a(" << i << ")=" << a[i] << endl;
    }
    cout << endl;
    double b[100] = {0};
    b[0] = 1;
    double ratio[100] = {1};
    ratio[0] = b[0];
    int current = 1;
    bool rootfound = false;
    while (!rootfound)
    {
        cout << "\n--> Step-" << current << endl;
        b[current] = valueofb(a, b, current, n);
        // cout << "b(" << current << "): " << b[current] << endl
        //      << endl;
        double err;
        ratio[current] = b[current - 1] / b[current];
        cout << "current ratio: b(" << current - 1 << ")/b(" << current << ")= " << ratio[current] << endl;
        if (current >= 1)
            err = abs((ratio[current]) - (ratio[current - 1]));
        else
            err = 100;
        cout << "Error = " << err << endl;
        if (err < 0.0001)
        {
            rootfound = true;
            cout << fixed << setprecision(5);
            cout << "\nThe smallest root is: " << ratio[current] << endl;
        }
        else
            current++;
    }
}
