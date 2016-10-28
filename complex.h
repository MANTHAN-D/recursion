
#include<iostream>
#include<math.h>
using namespace std;
class Complex{
private:
    float real;
    float imaginary;
public:
    Complex();
    Complex(float, float);
    float value();
    friend bool operator== (const Complex &c1, const Complex &c2){
        return (c1.real == c2.real && c1.imaginary == c2.imaginary);
    }
    friend bool operator> (Complex &c1, Complex &c2){
        return (c1.value() > c2.value());
    }
    friend ostream &operator<<( ostream &output, const Complex *C )
    {
        if(C->imaginary > 0.0)
            output << C->real << " + " << C->imaginary << "i";
        else
            output << C->real << " " << C->imaginary << "i";
        return output;
    }
    friend istream &operator>>( istream  &input, Complex &C )
    {
        input >> C.real >> C.imaginary;
        return input;
    }
};
