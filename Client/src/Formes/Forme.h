/**
 * @file Forme.h
 * @brief Définition de la classe abstraite Forme pour la gestion de figures géométriques.
 */

#ifndef FORME_H
#define FORME_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "../Calculs/Plan.h"

// Forward declarations pour éviter les inclusions cycliques
class Visiteur;
class VisiteurSauvegarde;
class Groupe;
class Vecteur2D;

/**
 * @class Forme
 * @brief Classe abstraite représentant une forme géométrique générique.
 * * Cette classe sert de base à toutes les figures (Cercle, Polygone, etc.).
 * Elle impose une interface pour le dessin, les transformations géométriques
 * et le calcul d'aire.
 */
class Forme {
protected:
    std::string color;      /**< Couleur de la forme (ex: "red", "blue"). */
    int id;                 /**< Identifiant unique de la forme. */
    Groupe* groupePt = nullptr; /**< Pointeur vers le groupe parent, null si la forme n'est pas dans un groupe. */
    static int auto_id;     /**< Compteur statique pour l'auto-incrémentation des IDs. */

public:
    /**
     * @brief Destructeur virtuel par défaut.
     */
    virtual ~Forme() = default;

    /**
     * @brief Accepte un visiteur pour dessiner la forme.
     * @param v Pointeur vers l'objet Visiteur qui s'occupe de l'affichage.
     */
    virtual void dessiner(Visiteur* v) const = 0;

    /**
     * @brief Opérateur de conversion vers std::string.
     * @return Une représentation en std::string de la forme.
     */
    virtual explicit operator std::string() const = 0;

    /**
     * @brief Calcule la surface occupée par la forme.
     * @return L'aire de la forme sous forme de double.
     */
    virtual double calculerAire() const = 0;

    /**
     * @brief Modifie la couleur de la forme.
     * @param couleur La nouvelle chaîne de caractères représentant la couleur.
     */
    void setCouleur(std::string couleur) {
        color = couleur;
    }

    /**
     * @brief Récupère la couleur actuelle.
     * @return La couleur sous forme de string.
     */
    std::string getCouleur() const { return this->color; }

    /** @name Délimitation rectangulaire
     * Méthodes permettant d'obtenir la "Bounding Box" de la forme.
     * @{ */
    virtual double getMinX() const = 0;
    virtual double getMinY() const = 0;
    virtual double getMaxX() const = 0;
    virtual double getMaxY() const = 0;
    /** @} */

    /**
     * @brief Prépare le rendu des pixels sur un plan donné en transformant des coordonnées réelles en cordonnées en pixels.
     * @param plan Référence vers le plan de travail.
     */
    virtual void preparerPixel(Plan &plan) = 0;

    /** @name Transformations Géométriques
     * @{ */
    /**
     * @brief Applique une rotation à la forme.
     * @param angle L'angle de rotation en radians.
     * @param centre Le point central autour duquel s'effectue la rotation.
     */
    virtual void rotation(double angle, const Vecteur2D& centre) = 0;

    /**
     * @brief Applique une translation.
     * @param v Le vecteur de déplacement.
     */
    virtual void translation(const Vecteur2D& v) = 0;

    /**
     * @brief Applique une homothétie (zoom).
     * @param rapport Le facteur d'échelle.
     * @param centre Le centre de l'homothétie.
     */
    virtual void homothetie(double rapport, const Vecteur2D& centre) = 0;
    /** @} */

    /**
     * @brief Transforme les coordonnées de la forme en format pour la sauvegarde de celle-ci.
     * @return Une chaîne formatée des coordonnées.
     */
    virtual std::string tranformerCoordonnees() const = 0;

    /**
     * @brief Sauvegarde la forme via un visiteur.
     * @param v Pointeur vers le visiteur de sauvegarde.
     */
    virtual void sauvegarder(VisiteurSauvegarde* v) const = 0;

    /**
     * @brief Définit le groupe parent de la forme.
     * @param nouveauParent Pointeur vers le groupe de destination.
     * @throw std::runtime_error Si la forme possède déjà un parent.
     */
    void setParent(Groupe* nouveauParent) {
        if (groupePt != nullptr && nouveauParent != nullptr) {
            throw std::runtime_error("Erreur : La forme appartient deja a un groupe !");
        }
        groupePt = nouveauParent;
    }

    /**
     * @brief Récupère le groupe parent.
     * @return Groupe* Pointeur vers le parent (peut être nullptr).
     */
    Groupe* getParent() {
        return groupePt;
    }
};

#endif //FORME_H