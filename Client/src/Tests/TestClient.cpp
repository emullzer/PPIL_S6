//
// Created by mulle1149u on 07/02/2026.
//

#include "TestClient.h"

#include "../Calculs/FormesManager.h"
#include "../Formes/Croix.h"
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

        f1 = new Rond(1.3,4,2,"red");
        fm->ajouterForme(f1);
        std::cin >> c;
        f2 = new Formes::Rectangle(-3,2,-1,1,"green");

        fm->ajouterForme(f2);

    }catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cin >> ch;
    return 0;
}
