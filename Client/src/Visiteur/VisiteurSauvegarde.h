#ifndef VISITEURSAUVEGARDE_H
#define VISITEURSAUVEGARDE_H
#include "Visiteur.h"

class Forme;

/**
 * @class VisiteurSauvegarde
 * @brief Classe de base abstraite pour la persistance des formes.
 * * Cette classe hérite de Visiteur et définit l'interface nécessaire pour 
 * sauvegarder une hiérarchie de formes dans un fichier.
 */
class VisiteurSauvegarde : public Visiteur {
protected:
    std::string nomFichier; /**< Chemin ou nom du fichier de destination (ex: "sauvegarde.txt"). */

public:
    /**
     * @brief Constructeur avec chemin spécifié.
     * @param chemin Chaîne de caractères représentant le chemin du fichier.
     */
    explicit VisiteurSauvegarde(const std::string& chemin) : nomFichier(chemin) {}

    /**
     * @brief Constructeur par défaut.
     * Initialise le nom du fichier à "Sauvegarde.txt" par défaut.
     */
    VisiteurSauvegarde() { nomFichier = "Sauvegarde.txt"; }

    /**
     * @brief Méthode principale pour lancer le processus de sauvegarde.
     * @details Cette méthode doit ouvrir le flux de fichier, puis realise v->accept(Forme*) pour la sauvegarder.
     * @param f Pointeur vers la forme (ou le groupe) à sauvegarder.
     */
    virtual void sauvegarder(const Forme* f) = 0;

};

#endif //VISITEURSAUVEGARDE_H