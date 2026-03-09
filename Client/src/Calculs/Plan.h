#ifndef PLAN_H
#define PLAN_H

#include "Vecteur2D.h"
#include "Matrice22.h"

/**
 * @class Plan
 * @brief Gère la transformation entre le repère monde (mathématique) et le repère écran (pixels).
 * * Cette classe implémente les paramètres de projection nécessaires pour afficher les formes 
 * sur une fenêtre de taille fixe (800x600 par défaut) tout en conservant les proportions.
 */
class Plan {
    static Plan* instance; /**< Instance unique (Singleton potentiel ou référence) */

    double hMonde, lMonde; /**< Dimensions du monde (longueur et hauteur réelles) */

    int hPixel = 600, lPixel = 800;/**< Dimensions de la fenêtre d'affichage en pixels */

    double lambda = 1;/**< Valeur de Lambda, utilisé pour l'homothétie */

    Vecteur2D rectangleBD, rectangleHG; /**< Coordonnées des coins du rectangle englobant dans le monde */

    Matrice22 matrice = Matrice22(0, 0, 0, 0); /**< Matrice de passage utilisée pour la transformation de coordonnées */

public:

    /**
     * @brief Constructeur de la zone d'affichage (Plan).
     * @param origine Le coin inférieur gauche de la vue dans le monde.
     * @param hMonde Hauteur de la vue dans le monde.
     * @param lMonde Largeur de la vue dans le monde.
     */
    Plan(const Vecteur2D& origine, const double &hMonde, const double& lMonde)
        : hMonde(hMonde), lMonde(lMonde), 
          rectangleBD(origine.x + lMonde, origine.y),
          rectangleHG(origine.x, origine.y + hMonde) 
    {
        calculerMatrice();
    }

    /**
     * @brief Calcule la matrice de transformation basée sur les dimensions actuelles.
     * @details Cette méthode doit être appelée à chaque changement de zoom ou de dimension du monde.
     */
    void calculerMatrice();

    /** @brief Modifie la hauteur du monde visible. */
    void setHMonde(const double &hMonde) { this->hMonde = hMonde; }
    
    /** @brief Modifie la largeur du monde visible. */
    void setLMonde(const double &lMonde) { this->lMonde = lMonde; }
    
    /** @brief Récupère la matrice de transformation actuelle. */
    Matrice22 getMatrice() { return matrice; }
    
    /** @brief Récupère le facteur d'échelle actuel. */
    double getLambda() const { return lambda; }

    /** @brief Récupère la hauteur du monde. */
    [[nodiscard]] double getHMonde() const { return hMonde; }

    /** @brief Récupère la largeur du monde. */
    [[nodiscard]] double getLMonde() const { return lMonde; }

    /** @brief Récupère la hauteur de l'écran en pixels. */
    [[nodiscard]] int getHPixel() const { return hPixel; }

    /** @brief Récupère la largeur de l'écran en pixels. */
    [[nodiscard]] int getLPixel() const { return lPixel; }

    /**
     * @brief Met à jour les limites du plan et recalcule les dimensions.
     * @param bd Nouveau point Bas-Droite.
     * @param hg Nouveau point Haut-Gauche.
     */
    void updateMatrice(Vecteur2D bd, Vecteur2D hg) {
        this->rectangleBD = bd;
        this->rectangleHG = hg;
        this->hMonde = hg.y - bd.y;
        this->lMonde = bd.x - hg.x;
    }

    /**
     * @brief Calcule le vecteur de translation.
     * @return Le vecteur Vecteur2D représentant le décalage (Omega).
     */
    Vecteur2D getOmega();
};

#endif //PLAN_H