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
    char ch;
    try {
        Forme *f1, *f2;
        FormesManager *fm = new FormesManager();
        char c;

        f1 = new Rond(2,2,1,"red");
        fm->ajouterForme(f1);
        std::cin >> c;
        f2 = new Formes::Rectangle(4,3,6,1,"green");

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

    }catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cin >> ch;
    return 0;
}
