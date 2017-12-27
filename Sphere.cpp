#include "Sphere.hpp"

/*Constructeur par defaut*/
Sphere::Sphere()
{
}

/* Constructeur avec parametres*/
Sphere::Sphere(const Position& centre, double rayon, const ColorRGB& color, double reflexion):centre(centre), rayon(rayon), color(color), reflexion(reflexion)
{
}

/*Destructeur*/
Sphere::~Sphere()
{
}

Position Sphere::getCentre(){
	return centre;
}

/*Methode permettant de savoir s'il y a un ou plusieurs points d'intersection entre la sphere et le rayon*/
bool Sphere::intercepte(const Rayon& rayonI)
{
	/*On utilise la methode presentee dans le sujet du projet
	en resolvant un polynome du second degre*/

	Rayon rayonE = rayonI;

	/*Pour simplifier les calculs mathematiques, on positionne le 		rayon au centre de la sphere etudiee*/
	
	rayonE.setOrigine(rayonE.getOrigine() -= centre);

	/* On calcule les coefficients du polynome obtenu */
	double a = (rayonE.getDirection()).normeEuclidienneCarre();
	double b = 2* multiplie(rayonE.getDirection(),rayonE.getOrigine()); 
	double c = (rayonE.getOrigine()).normeEuclidienneCarre() -carre(rayon);

	
	/*Calcul du discriminant correspondant */

	double delta = carre(b) - 4* a *c;
	
	/*On etudie les points d'intersections eventuels*/
	if(delta >=0.0) /*il y a un ou deux points d'intersection*/
	{
		/* On calcule les deux points d'intersection
		Sachant que x1=x2 dans le cas ou delta=0*/
		double x1 = (-b -std::sqrt(delta)) /(2*a);
		double x2 = (-b + std::sqrt(delta))/(2*a);
		/*il y a eu intersection on renvoie vrai*/
		return true;
	}


	if(delta <0.0) /*il n'y a aucun point d'intersection*/
	{
		return false;	
	}	
		
}
