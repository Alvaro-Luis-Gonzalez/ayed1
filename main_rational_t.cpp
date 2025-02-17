// AUTOR: Alvaro Luis Gonzalez
// FECHA: 17/02/2025
// EMAIL: alu0101575582@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <iostream>
#include <cmath>
#include <stdexcept> // Necesario para std::runtime_error

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "rational_t.hpp"

using namespace std;

int main()
{
    rational_t a(1, 2), b(3), c;

    cout << "a.value()= " << a.value() << endl;
    cout << "b.value()= " << b.value() << endl;
    cout << "c.value()= " << c.value() << endl;

    cout << "a: ";
    a.write();
    cout << "b: ";
    b.write();

    c.read();
    cout << "c: ";
    c.write();

    // FASE II y ejemplos de las nuevas funciones con x e y
    try {
        rational_t x, y; // Ya no se inicializan aquí

        cout << "Introduce el primer racional (x):\n";
        x.read();
        cout << "Introduce el segundo racional (y):\n";
        y.read();

        x.write();
        y.write();
        cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl;
        cout << "x < y? " << (x.is_less(y) ? "true" : "false") << endl;
        cout << "x > y? " << (x.is_greater(y) ? "true" : "false") << endl;

        // FASE III
        cout << "a + b: ";
        a.add(b).write();

        cout << "b - a: ";
        b.substract(a).write();

        cout << "a * b: ";
        a.multiply(b).write();

        cout << "a / b: ";
        a.divide(b).write();


        // Nuevas funciones (ejemplos de uso, comentados)
        /*
        cout << "Raiz cuadrada de x: ";
        x.square_root().write();

        int exponent;
        cout << "Introduce el exponente para elevar x: ";
        cin >> exponent;
        cout << "x elevado a " << exponent << ": ";
        x.power(exponent).write();

        cout << "El numerador de x es mayor que el denominador? "
             << (x.is_numerator_greater() ? "true" : "false") << endl;
        cout << "El denominador de x es mayor que el numerador? "
             << (x.is_denominator_greater() ? "true" : "false") << endl;

         cout << "Raiz cuadrada de y: ";
        y.square_root().write();

        cout << "Introduce el exponente para elevar y: ";
        cin >> exponent;
        cout << "x elevado a " << exponent << ": ";
        y.power(exponent).write();

        cout << "El numerador de y es mayor que el denominador? "
             << (y.is_numerator_greater() ? "true" : "false") << endl;
        cout << "El denominador de y es mayor que el numerador? "
             << (y.is_denominator_greater() ? "true" : "false") << endl;
        */

        //Ejemplos de factorial
        
        cout << "Factorial de x: ";
        try {
            x.factorial().write();
        } catch (const std::runtime_error& e) {
            cerr << e.what() << endl;
        }

        cout << "Factorial de y: ";
        try {
            y.factorial().write();
        } catch (const std::runtime_error& e) {
            cerr << e.what() << endl;
        }
        

    } catch (const std::runtime_error& error) {
        cerr << "Error: " << error.what() << endl;
    }

    return 0;
}
