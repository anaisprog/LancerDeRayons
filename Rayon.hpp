#define RAYON_HPP_

#include "Position.cpp"

class Rayon{
	public :
	/*Constructeur par defaut */
	Rayon(); 

	/*Constructeur avec parametres*/
	Rayon(const Position& origine, const Position& direction);

	/*Constructeur de copie*/
	Rayon(const Rayon& r); 

	/* Le destructeur par defaut*/
	virtual ~Rayon();

	/*Getters*/
	Position getOrigine();
	Position getDirection();
	
	/*Setters*/
	void setOrigine(Position origine);
	
	private : 
	/* Un rayon est défini par un point d'origine et un vecteur 		direction*/
	Position origine;
	Position direction;
	
};
