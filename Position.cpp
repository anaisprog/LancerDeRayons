
using namespace std;
#include <cmath>
#include "Position.hpp"

using namespace std;

Position::Position(int _x, int _y, int _z): x(_x), y(_y), z(_z)
{
}

Position::Position(const Position& p): x(p.x), y(p.y), z(p.z)
{
}

// Constructeur par defaut 
Position :: Position(): x(0), y(0), z(0)
{
}

//destructeur par defaut
Position::~Position() 
{
}

/* Cette methode permet de calculer le carre d'une valeur*/
double carre(double d){
	return d*d;
}

/* Cette methode permet de realiser la multiplication de deux positions : utilise pour les resolutions polynomiales*/
double multiplie(Position p1, Position p2){
	return (p1.x * p2.x) + (p1.y * p2.y) + (p1.z * p2.z);
}


// Calcul du carre de la norme euclidienne 
double Position::normeEuclidienneCarre()
{
	return carre(x) + carre(y) + carre(z);
}
// Calcul de la norme euclidienne
double Position::normeEuclidienne()
{
	return sqrt(normeEuclidienneCarre());
}

/*Surcharge de l'operateur -=*/
Position& Position::operator -=(const Position& p)
{
	x -= p.x;
	y -= p.y;
	z -= p.z;
	return *this;
}


Position& Position::operator /=(double d)
{
	x/=d;
	y/=d;
	z/=d;
}

