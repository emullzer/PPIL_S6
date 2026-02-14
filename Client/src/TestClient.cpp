//
// Created by mulle1149u on 07/02/2026.
//

#include "TestClient.h"

#include "Croix.h"
#include "Forme.h"
#include "Rond.h"

int main() {
    char ch;
    try {
        Forme *f1, *f2;

        f1 = new Croix(40,40,100,100);
        f2 = new Rond(300,300,30);

        std::cout << "f1 = " << f1 << std::endl;
        std::cout << "f2 = " << f1 << std::endl;

        f1->dessiner();
        std::cin >> ch;
        f2->dessiner();

    }catch(std::exception& e) {
        std::cerr << "prob" << std::endl;
    }

    std::cin >> ch;
    return 0;
}
