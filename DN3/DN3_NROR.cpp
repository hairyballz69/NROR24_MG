//NROR DN3
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

// Izracun arctan z uporabo Taylorjeve vrste
double calcAtan(double* x, int* N_steps) {
    double result = 0.0;
    for (int n = 0; n < *N_steps; ++n) {
        result += std::pow(-1.0, n) * std::pow(*x, 2 * n + 1) / (2 * n + 1);
    }
    return result;
}

// Funkcija za integracijo
double integral(double x) {
    double x_div_2 = x / 2.0;
    int N_steps = 10;
    return std::exp(3 * x) * calcAtan(&x_div_2, &N_steps);
}

// Trapezno pravilo za numerièno integracijo
double trapezoidalRule(double a, double b, int n) {
    double dx = (b - a) / n; // Velikost koraka
    double sum = 0.5 * (integral(a) + integral(b)); // Prispevek mejnih toèk

    for (int i = 1; i < n; ++i) {
        double x = a + i * dx;
        sum += integral(x);
    }

    return sum * dx; // Koncni rezultat
}

int main() {
    double a = 0.0, b = M_PI / 4; // Meje integracije
    int delitve = 1000;          // Število podintervalov

    double result = trapezoidalRule(a, b, delitve); // Izracun integrala

    std::cout << "Vrednost integrala: " << result << std::endl; // Izpis rezultata

    return 0;
}
