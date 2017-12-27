/*
 * Parser.cpp
 *
 *  Created on: 29 nov. 2017
 *      Author: Djenna
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

#include "Scene.hpp"
#include "Camera.hpp"

using namespace std;

#define NBMINELT 8

/**
 * Cette methode decoupe la ligne, en fonction d'un delimitateur, en plusieurs token.
 */
vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

/**
 * Cette methode verifie que la ligne contient bien le nombre d'arguments voulu et qu'il s'agit uniquement de nombres
 */
bool verification(const vector<string> ligne, int nbArgument)
{
	if(ligne.size()!=nbArgument)
	{
		return false;
	}
	for(string s : ligne)
	{
		for (int i= 0;i<s.size(); i++)
		{
			if(((s[i]>='a') && (s[i]<='z'))||((s[i]>='A') && (s[i]<='Z')))
			{
				return false;
			}
		}
	}
	return true;

}

/**
 * Méthode pour enlever la virgule, positionnee à la fin d'une chaine
 */
bool enleverVirgule(string& str)
{
	str[str.size()-1] = 0;
	return true;
}

bool checkLigne(string chemin)
{
	string ligne;
	int nbligne = 0;

	ifstream fichier(chemin, ios::in);
		if(fichier)
		{

			//On lit le fichier en entier
			while(getline(fichier, ligne))
			{
				//On ignore les sauts de ligne et les espaces seuls
				if((ligne!="\r\n")&&(ligne!="")&&(ligne!="\n"))
				{
					//On ignore les commentaires
					if((ligne[0]!='#')&&(ligne!=""))
					{
						//Il s'agit d'une ligne contenant des informations utiles
						nbligne++;
					}
				}
				//On ignore les sauts de ligne, espace inutile
	    		else
	    		{
	    			getline(fichier, ligne);
	    		}
			}
			//On ferme le fichier
	    	fichier.close();
		}
	    else
	    {
	    	cerr << "Impossible d'ouvrir le fichier ! \n" << endl;
	    }

		//cout << "Affichage du nombre de ligne : "<< nbligne <<endl;
		if(nbligne>=NBMINELT)
		{
			return true;
		}
		return false;
}

/**
 * Cette methode lit un fichier decrivant une scene et instancie les données correspondantes a ses element
 */
Scene ecritureScene(string const chemin)
{
	//Ligne lue dans le fichier
	string ligne;
	//On va decouper la ligne et la ranger dans ce vector qui contiendra un mot par "case"
	vector<string> res;
	//Cette variable va nous permettre de nous situer dans la lecture du fichier
	int numLigne = 0;
	//La scène qu'on va retourner
	Scene scene;
	Camera camera;
	Ecran ecran;
	Position position;
	ColorRGB couleur;
	Source source;

	//On verifie d'abord que le fichier contient le bon nombre de lignes minimum
	if(!(checkLigne(chemin)))
	{
		cerr << "Le fichier ne contient pas assez d'informations ! \n" << endl;
	}
	//On ouvre le fichier en lecture
	ifstream fichier(chemin, ios::in);
	if(fichier)
	{

		//On lit le fichier en entier
		while(getline(fichier, ligne))
		{
			//On ignore les sauts de ligne et les espaces seuls
			if((ligne!="\r\n")&&(ligne!="")&&(ligne!="\n"))
			{
				//On ignore les commentaires
				if((ligne[0]!='#')&&(ligne!=""))
				{
					//Une ligne correspond a une information
					switch (numLigne)
					{
						//Ligne 1 --> La camera
						case 0:
							//On découpe la ligne
							res = split(ligne," ");
							//Verification de la conformite des arguments
							if(verification(res,3))
							{
								//On remplit la position de la caméra
								position.x = stoi (res[0]);
								position.y = stoi (res[1]);
								position.z = stoi (res[2]);
								camera.setSaPosition(position);

							}
							else
							{
								cerr << "Les arguments sur la camera ne sont pas conformes ! \n" << endl;
							}
							numLigne++;
							break;
	        				//Ligne 2 --> Top Left Corner
	        				case 1:
	        					//On découpe la ligne
	        					res = split(ligne," ");
	        					//Verification de la conformite des arguments
	        					if(verification(res,3))
	        					{
	        						//On remplit la position de Tlc
	        						position.x = stoi (res[0]);
	        						position.y = stoi (res[1]);
	        						position.z = stoi (res[2]);
	        						ecran.setTlc(position);
	        					}
	        					else
	        					{
	        						cerr << "Les arguments sur le coin superieur gauche ne sont pas conformes ! \n" << endl;
	        					}
	        					numLigne++;
	        					break;
	        				//Ligne 3 --> Top Right Corner
	        				case 2:
	        					//On découpe la ligne
	        					res = split(ligne," ");
	        					//Verification de la conformite des arguments
	        					if(verification(res,3))
	        					{
	        						//On remplit la position de trc
	        						position.x = stoi (res[0]);
	        						position.y = stoi (res[1]);
	        						position.z = stoi (res[2]);
	        						ecran.setTrc(position);
	        					}
	        					else
	        					{
	        						cerr << "Les arguments sur le coin superieur droit ne sont pas conformes ! \n" << endl;
	        					}
	        					numLigne++;
	        					break;
	        				//Ligne 4 --> Bottom Left Corner
	        				case 3:
	          					//On découpe la ligne
								res = split(ligne," ");
								//Verification de la conformite des arguments
								if(verification(res,3))
								{
									//On remplit la position de la caméra
									position.x = stoi (res[0]);
									position.y = stoi (res[1]);
									position.z = stoi (res[2]);
									ecran.setBlc(position);
								}
								else
								{
									cerr << "Les arguments sur le coin inferieur gauche ne sont pas conformes ! \n" << endl;
								}
	        					numLigne++;
	        					break;
	        				//Ligne 5 --> Resolution Horizontale
	        				case 4:
	        					res = split(ligne," ");
	        					//Verification de la conformite des arguments
	        					if(verification(res,1))
	        					{
	        						//On remplit la resolution horizontale
	        						ecran.setHorizontaleRes(stoi (res[0]));
	        					}
	        					else
	        					{
	        						cerr << "L'argument sur la resolution horizontale n'est pas conforme ! \n" << endl;
	        					}
	        					numLigne++;
	        					break;
	        				//Ligne 6 --> Couleur de fond
	        				case 5:
	        					//On découpe la ligne
	        					res = split(ligne," ");
	        					//Verification de la conformite des arguments
	        					if(verification(res,3))
	        					{
	        						//On remplit le background
	        						couleur.setRouge(stoi (res[0]));
	        						couleur.setVert(stoi (res[1]));
	        						couleur.setBleu(stoi (res[2]));
	        						ecran.setBackground(couleur);

	        						//On ajoute a la scene
	        						scene.setSonEcran(ecran);
	        					}
	        					else
	        					{
	        						cerr << "Les arguments sur la couleur de fond ne sont pas conformes ! \n" << endl;
	        					}
	        					numLigne++;
	        					break;
	        				//Ligne 7 --> Source lumineuse et sa couleur
	           				case 6:
	        					//On découpe la ligne
	        					res = split(ligne," ");
	        					//Verification de la conformite des arguments
	        					if(verification(res,6))
	        					{
	        						//On remplit la position de la source
	        						position.x = stoi (res[0]);
	        						position.y = stoi (res[1]);
	        						position.z = stoi (res[2]);
	        						source.setPosition(position);
	        						//On remplit la couleur de la source lumineuse
	        						couleur.setRouge(stoi (res[3]));
	        						couleur.setVert(stoi (res[4]));
	        						couleur.setBleu(stoi (res[5]));
	        						source.setCouleur(couleur);

	        						//On ajoute a la scene
	        						scene.setSaSource(source);

	        					}
	        					else
	        					{
	        						cerr << "Les arguments sur la source lumineuse ne sont pas conformes ! \n" << endl;
	        					}
	           					numLigne++;
	            				break;
	            			//Autres lignes --> Objets sur la scène
	           				default:
	           					//On découpe la ligne
	           					res = split(ligne," ");
	           					//On etudie le type de la forme
	           					if(res[0] == "sphere:") //L'objet est une sphere
	           					{
	           						//On enleve les virgules
	           						for(int i(1) ; i < 8 ; i++)
	           						{
	           							enleverVirgule(res[i]);
	           						}
	           						//On prend la chaine après le type de l'objet
	           						res.erase(res.begin());
	           						//Verification de la conformite des arguments
	           						if(verification(res, 8))
	           						{
	           							//On declare une nouvelle sphere
	           							Sphere sphere;
	               						//On prend la position de son centre
	            						position.x = stoi (res[0]);
	            						position.y = stoi (res[1]);
	            						position.z = stoi (res[2]);
	               						sphere.centre = position;
	            						//On prend son rayon
	            						sphere.setRayon(stoi (res[3]));
	            						//On prend sa couleur
	            						couleur.setRouge(stoi (res[4]));
	            						couleur.setVert(stoi (res[5]));
	            						couleur.setBleu(stoi (res[6]));
	            						sphere.setC(couleur);
	            						//On prend sa reflexion
	            						sphere.setReflexion(stof (res[7]));

	            						//On ajoute la sphere à la liste des objets de la scene
	            						scene.getSesSpheres().push_back(sphere);

	           						}

	               					else
	               					{
	               						cerr <<"Les arguments sur d'un objet de la scene ne sont pas conformes ! \n"<< endl;
	               					}
	           					}
	           					else
	           					{
	           						cerr << "Le type : " << res[0] << "n'est pas accepte  ! \n" << endl;
	           					}
	        					cout<<ligne<<endl;
	        					numLigne++;
	        			}

	        		}

	    		}
				//On ignore les sauts de ligne, espace inutile
	    		else
	    		{
	    			getline(fichier, ligne);
	    		}

	    	}
			//On ferme le fichier
	    	fichier.close();
	    }
	    else
	    {
	    	cerr << "Impossible d'ouvrir le fichier ! \n" << endl;
	    }

	    return scene;
}

int main()
{
	string chemin;

	//On demande à l'utilisateur de renseigner le chemin du fichier
	cout<< "Renseigner le chemin du fichier à lire" <<endl;
	cin >> chemin;

	//On cree la scene
	checkLigne(chemin);
	Scene scene = ecritureScene(chemin);



}



