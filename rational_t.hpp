// AUTOR: Alvaro Luis Gonzalez
// FECHA: 17/02/2025
// EMAIL: alu0101575582@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6

using namespace std;

class rational_t
{
// pautas de estilos [44] y [73]: primero "public" y después "private"
public:
    rational_t(const int = 0, const int = 1);
    ~rational_t() {}

    // pauta de estilo [71]: indentación a 2 espacios
    // getters
    int get_num() const;
    int get_den() const;

    // setters
    void set_num(const int);
    void set_den(const int);

    double value(void) const;

    // FASE II
    bool is_equal(const rational_t&, const double precision = EPSILON) const;
    bool is_greater(const rational_t&, const double precision = EPSILON) const;
    bool is_less(const rational_t&, const double precision = EPSILON) const;

    // FASE III
    rational_t add(const rational_t&);
    rational_t substract(const rational_t&);
    rational_t multiply(const rational_t&);
    rational_t divide(const rational_t&);

    void write(ostream& = cout) const;
    void read(istream& = cin);

    // Nuevas funciones (comentadas)
    /*
    rational_t square_root() const;
    rational_t power(int exponent) const;
    bool is_numerator_greater() const;
    bool is_denominator_greater() const;
    */
    rational_t factorial() const; // Declaración de la función factorial

private:
    // pauta de estilo [11]: nombre de los atributos seguido de "_"
    int num_, den_;
};