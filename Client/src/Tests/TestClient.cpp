//
// Created by mulle1149u on 07/02/2026.
//

#include "TestClient.h"

#include "../Formes/Croix.h"
#include "../Formes/Forme.h"
#include "../Formes/Rond.h"
#include "../Formes/Triangle.h"
#include "../Formes/Groupe.h"


int main() {
    char ch;
    try {
        Forme *f1, *f2, *f3;

        f1 = new Croix(200,200,50,"cyan");
        f2 = new Rond(300,50,90,"red");
        f3 = new Triangle(150,70.8,120,150.2,180,70.8,"blue");

        std::cout << "f1 = " << f1 << std::endl;
        std::cout << "f2 = " << f1 << std::endl;

        f1->dessiner();
        f2->dessiner();
        f3->dessiner();


        Groupe *g1 = new Groupe("green");
        g1->ajouterForme(f1);
        g1->ajouterForme(f2);
        g1->ajouterForme(f3);
        std::cout << "g1 = " << std::string(*g1) << std::endl;

    }catch(std::exception& e) {
        std::cerr << "prob" << std::endl;
    }

    std::cin >> ch;
    return 0;
}
