//
// Created by sanes on 25/02/2026.
//

#ifndef GROUPE_H
#define GROUPE_H
#include <iostream>
#include <vector>
#include "Forme.h"



class Groupe : public Forme {
private:
    std::vector<Forme*> formesGroupe;

public:
    explicit Groupe(const std::string &couleur){
        this->color = couleur;
    }
    ~Groupe() override = default;
    void ajouterForme(Forme* &forme) {
        this->formesGroupe.push_back(forme);
    }

    explicit operator std::string() const override;
    void dessiner() const override;

};



#endif //GROUPE_H
