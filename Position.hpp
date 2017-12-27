

#ifndef POSITION_HPP_
#define POSITION_HPP_


class Position{
	/* La classe Position nous permet de definir a la fois des points et des vecteurs*/
	public :
	Position(); // consntructeur par defaut
	Position(int x, int y, int z); // constructeur avec coordonnees
	Position(const Position& p); // constructeur de copie
	virtual ~Position(); // destructeur
	
	
	/* surcharge des operateurs de base implementes plus bas dans le fichier */

	friend Position operator +(const Position& p1, const Position& p2);	friend Position operator -(const Position& p1, const Position& p2);	friend Position operator *(const Position& p1, const Position& p2);	friend Position operator /(const Position& p1, const Position& p2);

	/* Surcharge des operateurs permettant de simplifier les 		calculs mathematiques par la suite, 
	TODO : a implementer si besoin dans le cpp*/

	
	Position& operator +=(const Position& p);
	Position& operator -=(const Position& p);
	Position& operator *=(double d);
	Position& operator /=(double d);
	Position& operator =(const Position& p);
	Position operator -() const; // permet d'obtenir l'opposé d'un point par rapport a l'origine (-x, -y, -z)

	/* Cette methode permet de calculer le carre d'une valeur*/
	friend double carre(double d);

	/*Cette methode permet de multiplier les coord de 2 positions*/
	friend double multiplie(Position p1, Position p2);

	/* Cette methode nous permet de calculer le carre de la norme euclidienne */
	double normeEuclidienneCarre();

	/* Cette methode nous permet de calculer la norme euclidienne*/
	double normeEuclidienne();


	
	/* Les coordonnees 3D correspondant a la position */
	private:
	int x, y, z;
};

Position operator +(const Position& p1, const Position& p2)
{
	return Position(p1.x + p2.x,
		p1.y + p2.y,
		p1.z + p2.z);
}

Position operator -(const Position& p1, const Position& p2)
{
	return Position(p1.x - p2.x,
		p1.y - p2.y,
		p1.z - p2.z);
}

Position operator *(const Position& p1, const Position& p2)
{
	return Position(p1.x * p2.x,
		p1.y * p2.y,
		p1.z * p2.z);
}


Position operator /(const Position& p1, const Position& p2)
{
	return Position(p1.x / p2.x,
		p1.y / p2.y,
		p1.z / p2.z);
}

#endif /* POSITION_HPP_ */
