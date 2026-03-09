#ifndef VISITEURSAUVEGARDETEXTE_H
#define VISITEURSAUVEGARDETEXTE_H

#include <fstream>
#include "VisiteurSauvegarde.h"

/**
 * @class VisiteurSauvegardeTexte
 * @brief Visiteur concret chargé de l'écriture des formes dans un fichier texte.
 * * Cette classe implémente la logique d'exportation pour chaque type de forme géométrique.
 * Elle utilise un flux de sortie (std::ofstream) pour sauvegarder les données au format décryptable par la COR.
 */
class VisiteurSauvegardeTexte : public VisiteurSauvegarde {
    std::ofstream* texte; /**< Permet d'écrire de manière persistante dans le fichier cible. */

public:
    /** * @brief Récupère les constructeurs de la classe parente VisiteurSauvegarde.
     */
    using VisiteurSauvegarde::VisiteurSauvegarde;

    /**
     * @brief Initialise le fichier et lance le processus de sauvegarde.
     * @details Ouvre le fichier spécifié par nomFichier, assigne le flux à l'attribut 'texte',
     * puis appelle la méthode accepte() sur la forme racine.
     * @param forme Pointeur vers la forme (ou le groupe) à sauvegarder.
     */
    void sauvegarder(const Forme* forme);

    /** @brief Sauvegarde un objet Groupe, c'est-a-dire tous ses composants. @param groupe */
    void visite(const Groupe* groupe) override;
    
    /** @brief Sauvegarde les points d'un Polygone. @param polygone */
    void visite(const Polygone* polygone) override;
    
    /** @brief Sauvegarde les dimensions et l'origine d'un Rectangle. @param rectangle */
    void visite(const Formes::Rectangle* rectangle) override;
    
    /** @brief Sauvegarde le centre et le rayon d'un Rond. @param rond */
    void visite(const Rond* rond) override;
    
    /** @brief Sauvegarde les deux points d'un Segment. @param segment */
    void visite(const Segment* segment) override;
    
    /** @brief Sauvegarde les trois sommets d'un Triangle. @param triangle */
    void visite(const Triangle * triangle) override;
};

#endif //VISITEURSAUVEGARDETEXTE_H