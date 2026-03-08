//
// Created by mulle1149u on 07/02/2026.
//


#include "../Calculs/FormesManager.h"
#include "../Formes/Segment.h"
#include "../Formes/Forme.h"
#include "../Formes/Rond.h"
#include "../Formes/Triangle.h"
#include "../Formes/Groupe.h"
#include "../Formes/Rectangle.h"


int main() {
    std::string ch;
    try {
        std::cout << "1 pour test formes + homothetie et tt pour Rond et triangle";
        std::cin >> ch;
        int val = std::stoi(ch);
        switch (val) {
            case 1:{
                Forme *f1, *f2;
                FormesManager *fm = new FormesManager();
                char c;

                f1 = new Rond(2,2,1,"red");
                fm->ajouterForme(f1);
                std::cin >> c;
                f2 = new Formes::Rectangle(8,3,6,1,"green");

                fm->ajouterForme(f2);
                std::cin >> c;
                f2 = new Triangle(4,3.1,5,5.1,6,3.1,"blue");

                fm->ajouterForme(f2);
                std::cin >> c;

                FormesManager *fm2 = new FormesManager();
                fm2->ajouterForme(f1);
                fm2->ajouterForme(f2);
                std::cin >> c;
                f2->translation(Vecteur2D(3,-3));
                f1->homothetie(2,Vecteur2D(2,2));
                f2->rotation(1.57,Vecteur2D(5,5.1));
                fm2->updateFormes();
                break;
                }

            case 2:{
                auto* fm = new FormesManager();
                Forme* f1 = new Formes::Rectangle(4,3,6,1,"green");
                Forme* f2 = new Rond(-2,0.1,1.4,"black");
                Forme* f3 = new Segment(4,3.1,5,3,"blue");
                Groupe* f4 = new Groupe("red");
                f4->ajouterForme(f1);
                f4->ajouterForme(f2);
                f4->ajouterForme(f3);
                fm->ajouterForme(f4);
                //fm->ajouterForme(f2);
                //fm->ajouterForme(f3);
                std::cin >> ch;
                f1->rotation(1.1,Vecteur2D(1,3));
                fm->updateFormes();
                break;
                }

            case 3: {
                auto* fm = new FormesManager();
                std::string chemin = R"(C:\Users\sanes\Downloads\faces.txt)";
                if (!(fm->chargerFormes(chemin))) std::cout << "erreur" << std::endl;

            }

        }

    }catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cin >> ch;
    return 0;
}
