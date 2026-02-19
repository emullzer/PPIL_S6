#ifndef VECTEUR2D_H
#define VECTEUR2D_H


#include <iostream>
#include <string>
#include <sstream>
#include <cmath>


class Vecteur2D
{
	public:
		double x,y;
		explicit Vecteur2D(const double &x=0, const double &y=0):x(x),y(y){/*rien à faire*/}
		operator std::string()const
	{
		std::ostringstream o;
		o << x << "," << this->y;
		return o.str();
	}

	const Vecteur2D operator+(const Vecteur2D& v) const
{
	return Vecteur2D(x+v.x,y+v.y);
}

	Vecteur2D operator-()
{
	return Vecteur2D(-x,-y);
}

	Vecteur2D operator-(const Vecteur2D& v1) const
{
	return Vecteur2D(x-v1.x,y-v1.y);
}

	Vecteur2D& operator+=(const Vecteur2D& v2)
{
	x+=v2.x;
	y+=v2.y;
	return *this;
}
	const Vecteur2D operator*(const double &a)const
{
	return Vecteur2D(x*a,y*a);
}

double operator*(const Vecteur2D& v)const
{
	return (x*v.x)+(y*v.y); //produit scalaire
}

double norme2()const //norme au carré
{
	return (*this)*(*this);
}
double norme()const //norme
{
	return sqrt(this->norme2());
}

};


Vecteur2D operator*(const double &a,const Vecteur2D& v);

inline std::ostream& operator<<(std::ostream &o,const Vecteur2D &v)
{
	o << (std::string)v;
	return o;
}


#endif