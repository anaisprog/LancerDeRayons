
#include "Position.hpp"
#include "Rayon.cpp"

class Objet3D{
	/*Objet3d correspond a une classe abstraite dont heriteront differentes formes : Spheres...*/
	
	public:
		/*TODO: Verifier si besoin de constructeurs dans une classe abstraite...*/
		Objet3D();
		Objet3D(Position p);
		virtual ~Objet3D();

		/* Q3 : Methode permettant de savoir s'il y a un point d'intersection entre le rayon et l'objet, a redefinir dans les sous-classes*/
		virtual bool intercepte(const Rayon& rayon) = 0;
		Position getCentre();
	protected:
		Position centre;
};

