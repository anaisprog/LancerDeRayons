
#include "Objet3D.hpp"
#include "ColorRGB.hpp"



class Sphere : public Objet3D{

	public:
		/*Constructeur par defaut*/
		Sphere();
		/*Constructeur avec parametres*/
		Sphere(const Position& centre, double rayon, const 			ColorRGB& color,double reflexion);

		/*destructeur*/
		virtual ~Sphere();

		/*Methode permettant de savoir s'il y a un ou plusieurs points d'intersection entre la sphere et le rayon*/
		virtual bool intercepte(const Rayon& rayon);
		/*Getters*/
		Position getCentre();

	private:
		Position centre;
		double rayon;
		ColorRGB color;
		double reflexion;
		

};


