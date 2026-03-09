#ifndef FORMESMANAGER_H
#define FORMESMANAGER_H

#include "Plan.h"
#include <iostream>
#include <optional>
#include <vector>
#include "../Formes/Forme.h"
#include "Vecteur2D.h"
#include "../Connexion/ConnexionServeur.h"

class Expert;

/**
 * @class FormesManager
 * @brief Gestionnaire principal des formes géométriques.
 * * Cette classe centralise le stockage des formes, gère leur affichage via le Plan,
 * et pilote le chargement de fichiers grâce au pattern design Chain of Responsablility.
 */
class FormesManager {
    Plan plan; /**< Gère la projection monde-écran pour l'affichage. */
    std::vector<Forme*> VectorFormes; /**< Liste de pointeurs vers toutes les formes chargées. */
    std::optional<Vecteur2D> rectangleHG, rectangleBD; /**< Bornes diagonales du rectangle englobant toutes les formes. */
    Expert* expertCharger = nullptr; /**< Premier maillon de la Chaîne de Responsabilité pour le chargement. */

    /**
     * @brief Parcourt et envoie chaque forme au serveur de dessin.
     */
    void dessinerFormes();

    /**
     * @brief Met à jour les bornes HG/BD en fonction d'une forme spécifique.
     * @param forme La forme à inclure dans le calcul du rectangle englobant.
     * @note Utilisé par updateBordsFormes, qui l'applique a toutes les formes gérées par le Manager.
     */
    void updateBordsFormes(Forme* forme);

    /**
     * @brief Recalcule globalement les valeurs minimales et maximales HG/BD parmi toutes les formes.
     */
    void updateBordsFormes();

    /**
     * @brief Adapte les paramètres du Plan en fonction du rectangle englobant actuel.
     */
    void updatePlan();


    public:
        /**
         * @brief Constructeur par défaut.
         * Initialise le plan avec une zone par défaut de (-5,-5) à (5,5).
         * @note Cette zone est arbitraire puisque changée dès l'ajout d'une forme.
         */
        FormesManager():plan(Vecteur2D(-5,-5),10,10),VectorFormes() {}

        /**
         * @brief Ajoute une forme unique au gestionnaire et l'affiche par la suite.
         * @param forme Pointeur vers la forme à ajouter.
         */
        void ajouterForme(Forme *forme);

        /**
         * @brief Ajoute une liste complète de formes au gestionnaire.
         * @param formes Vecteur de pointeurs de formes.
         */
        void ajouterVectorForme(std::vector<Forme *> formes);

        /**
         * @brief Envoie une requête au serveur pour effacer la zone de dessin.
         * @note Ceci est utilisé lorsque l'on veut redessiner les formes car la Bounding box a changé.
         */
        void nettoyer()
        {
            ConnexionServeur::getInstance().envoyerRequete("Nettoyer[]\n");
        }

        /**
         * @brief Met à jour l'état visuel : recalcule les bords, le plan et redessine.
         */
        void updateFormes();

        /**
         * @brief Charge des formes depuis un fichier texte via la COR.
         * @param nomFichier Chemin du fichier à lire.
         * @return True si le chargement a réussi, false sinon.
         */
        bool chargerFormes(const std::string& nomFichier);

        /**
         * @brief Initialise la Chaine of Responsability (COR) des Experts.
         */
        void setupCOR();

};

#endif //FORMESMANAGER_H