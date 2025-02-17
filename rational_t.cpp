// AUTOR: Alvaro Luis Gonzalez
// FECHA: 17/02/2025
// EMAIL: alu0101575582@ull.edu.es 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"
#include <stdexcept>

rational_t::rational_t(const int n, const int d)
{
    assert(d != 0);
    num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
int
rational_t::get_num() const
{
    return num_;
}



int
rational_t::get_den() const
{
    return den_;
}




void
rational_t::set_num(const int n)
{
    num_ = n;
}


void
rational_t::set_den(const int d)
{
    assert(d != 0);
    den_ = d;
}



double
rational_t::value() const
{
    return double(get_num()) / get_den();
}


// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{
    double diff = fabs(value() - r.value());
    return (diff < precision) || (diff / (fabs(value()) + fabs(r.value())) < precision);
}

bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
    double diff = value() - r.value();
    return (diff > precision) && (diff / (fabs(value()) + fabs(r.value())) > precision);
}

bool
rational_t::is_less(const rational_t& r, const double precision) const
{
    double diff = r.value() - value();
    return (diff > precision) && (diff / (fabs(value()) + fabs(r.value())) > precision);
}


// operaciones
rational_t
rational_t::add(const rational_t& r)
{
    int n = (num_ * r.den_) + (den_ * r.num_);
    int d = den_ * r.den_;
    return rational_t(n, d);
}



rational_t
rational_t::substract(const rational_t& r)
{
    int n = (num_ * r.den_) - (den_ * r.num_);
    int d = den_ * r.den_;
    return rational_t(n, d);
}



rational_t
rational_t::multiply(const rational_t& r)
{
    int n = num_ * r.num_;
    int d = den_ * r.den_;
    return rational_t(n, d);
}



rational_t
rational_t::divide(const rational_t& r)
{
    int n = num_ * r.den_;
    int d = den_ * r.num_;
    assert(d != 0);
    return rational_t(n, d);
}



// E/S
void
rational_t::write(ostream& os) const
{
    os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void
rational_t::read(istream& is)
{
    cout << "Numerador? ";
    is >> num_;
    cout << "Denominador? ";
    is >> den_;
    assert(den_ != 0);
}


// practicado en casa

/*
rational_t rational_t::square_root() const {
    if (num_ < 0 || den_ < 0) {
        throw std::runtime_error("No se puede calcular la raíz cuadrada de un número racional negativo.");
    }
    return rational_t(static_cast<int>(sqrt(num_)), static_cast<int>(sqrt(den_)));
}

rational_t rational_t::power(int exponent) const {
    if (exponent < 0)
    {
        if (num_ == 0){
             throw std::runtime_error("No se puede elevar a un exponente negativo si el numerador es 0");
        }
        return rational_t(pow(den_, abs(exponent)), pow(num_,abs(exponent)));
    }
    return rational_t(pow(num_, exponent), pow(den_, exponent));
}

bool rational_t::is_numerator_greater() const {
    return num_ > den_;
}

bool rational_t::is_denominator_greater() const {
    return den_ > num_;
}
*/