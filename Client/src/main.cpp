
#include <iostream>
#include <vector>
#include "Calculs/FormesManager.h"
#include "Formes/Segment.h"
#include "Formes/Rond.h"
#include "Formes/Triangle.h"
#include "Formes/Polygone.h"
#include "Formes/Groupe.h"
#include "Visiteur/VisiteurSauvegardeTexte.h"

void afficherMenu() {
    std::cout << "\nChoisissez votre fonctionnalité à tester:" << std::endl;
    std::cout << "1. Afficher des formes simples - Rond, Triangle, Polygone, Segment." << std::endl;
    std::cout << "2. Tester les Groupes " << std::endl;
    std::cout << "3. Tester les Transformations (Rotation/Homothetie/translation)" << std::endl;
    std::cout << "4. Sauvegarder dans 'saves/test.txt'" << std::endl;
    std::cout << "5. Charger des fichiers" << std::endl;
    std::cout << "0. Quitter" << std::endl;
    std::cout << "Choix : ";
}

int main() {
    FormesManager manager;
    int choix = -1;
    char ch;

    while (choix != 0) {
        afficherMenu();
        std::cin >> choix;

        try {
            switch (choix) {
                case 1: { // Formes simples
                    manager.remettreAZero();
                    Rond* c = new Rond(0,0, 5, "red");
                    Segment* s = new Segment(-6,-5, -7,2, "blue");
                    Triangle* t = new Triangle(5,5, 3,5,4,7, "green");
                    Polygone* p = new Polygone("black");
                    p->ajouterPoint(Vecteur2D(-10,7));
                    p->ajouterPoint(Vecteur2D(-10,4));
                    p->ajouterPoint(Vecteur2D(-6,4));
                    p->ajouterPoint(Vecteur2D(-6,7));
                    p->ajouterPoint(Vecteur2D(-8,10));
                    manager.ajouterForme(c);
                    manager.ajouterForme(s);
                    manager.ajouterForme(t);
                    manager.ajouterForme(p);
                    manager.updateFormes();
                    break;
                }

                case 2: { // Groupes
                    manager.remettreAZero();
                    Groupe* g = new Groupe("green");
                    Forme* rond = new Rond(2,2, 2, "green");
                    Forme* segment = new Segment(5,0,5,5, "red");
                    g->ajouterForme(rond);
                    g->ajouterForme(segment);
                    manager.ajouterForme(g);
                    break;
                }

                case 3: {
                    manager.remettreAZero();
                    Rond* c = new Rond(0,0, 5, "red");
                    Segment* s = new Segment(-15,-5, -15,0, "blue");
                    manager.ajouterForme(c);
                    manager.ajouterForme(s);
                    std::cout << "Entrez un caractère pour voir après rotation / translation" << std::endl;
                    std::cin >> ch;
                    c->translation(Vecteur2D(5,5));
                    s->rotation(1.57,Vecteur2D(-5,-2.5));
                    manager.updateFormes();
                    break;
                }

                case 4: { // Sauvegarde
                    VisiteurSauvegardeTexte* visiteur = new VisiteurSauvegardeTexte("test.txt");

                    manager.remettreAZero();
                    Groupe* g = new Groupe("green");
                    Forme* rond = new Rond(2,2, 2, "green");
                    Forme* segment = new Segment(5,0,5,5, "red");
                    g->ajouterForme(rond);
                    g->ajouterForme(segment);
                    visiteur->sauvegarder(g);
                    std::cout << "Sauvegarde effectuee avec succes." << std::endl;
                    break;
                }

                case 5: { // Chargement
                    manager.nettoyer();
                    if(manager.chargerFormes("../src/saves/g_faces.txt")) {
                        std::cout << "Chargement des aretes d'un gecko ! Entrez un caractere pour tester les faces de ce meme gecko." << std::endl;
                        manager.updateFormes();
                        std::cin >> ch;
                    }
                    /*if(manager.chargerFormes("../src/saves/g_faces.txt")) {
                        std::cout << "Chargement des Faces d'un gecko !" << std::endl;
                        manager.updateFormes();
                    }*/

                    break;
                }

                case 0:
                    break;

                default:
                    std::cout << "Bug Mauvais chiffre." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "ERREUR : " << e.what() << std::endl;
        }
    }

    return 0;
}