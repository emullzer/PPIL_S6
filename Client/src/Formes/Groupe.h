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
        id = auto_id++;
    }
    ~Groupe() override = default;
    void ajouterForme(Forme* &forme) {
        forme->setCouleur(color);
        this->formesGroupe.push_back(forme);
    }

    explicit operator std::string() const override;
    void dessiner(Visiteur* v) const override;
    double calculerAire() const override;

    double getMaxY() const override {
        double max = formesGroupe[0]->getMaxY();
        for( auto forme: formesGroupe ) {
            max = std::max(max, forme->getMaxY());
        }
        return max;
    }

    double getMaxX() const override{
        double max = formesGroupe[0]->getMaxX();
        for( auto forme: formesGroupe ) {
            max = std::max(max, forme->getMaxX());
        }
        return max;
    }
    double getMinY() const override {
        double min = formesGroupe[0]->getMinY();
        for( auto forme: formesGroupe ) {
            min = std::min(min, forme->getMinY());
        }
        return min;
    }
    double getMinX() const override {
        double min = formesGroupe[0]->getMinX();
        for( auto forme: formesGroupe ) {
            min = std::min(min, forme->getMinX());
        }
        return min;
    }
    int getNbFormes()const {
        return formesGroupe.size();
    }
    void preparerPixel(Plan &plan) override;

    void translation(const Vecteur2D& v) override {
        for( auto forme: formesGroupe ) {
            forme->translation(v);
        }
    }

    void homothetie(double rapport, const Vecteur2D& centre) override {
        for( auto forme: formesGroupe ) {
            forme->homothetie(rapport, centre);
        }
    }

    void rotation(double angle, const Vecteur2D& pointPivot) override {
        for( auto forme: formesGroupe ) {
            forme->rotation(angle, pointPivot);
        }
    }

    virtual void sauvegarder(VisiteurSauvegarde* v) const = 0;

};



#endif //GROUPE_H