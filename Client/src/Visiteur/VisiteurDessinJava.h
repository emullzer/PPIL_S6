#ifndef VISITEURDESSINJAVA_H
#define VISITEURDESSINJAVA_H

#include "Visiteur.h"

/**
 * @class VisiteurDessinJava
 * @brief Implémentation concrète du Visiteur pour l'affichage via un serveur Java.
 * * Cette classe transforme les formes géométriques C++ en commandes protocolaires
 * envoyées au serveur de dessin Java via une connexion TCP/IP.
 * * @note Les méthodes sont virtuelles car on peut envisager d'utiliser d'autres Bibliothèques Java.
 */
class VisiteurDessinJava : public Visiteur {
    /**
     * @brief Visite un groupe pour ordonner le dessin de ses composants.
     * @param groupe Pointeur vers le groupe de formes à dessiner.
     */
    virtual void visite(const Groupe* groupe) override;

    /**
     * @brief Formate et envoie la commande de dessin pour un polygone.
     * @param polygone Pointeur vers le polygone à dessiner.
     */
    virtual void visite(const Polygone* polygone) override;

    /**
     * @brief Formate et envoie la commande de dessin pour un rectangle.
     * @param rectangle Pointeur vers le rectangle à dessiner.
     */
    virtual void visite(const Formes::Rectangle* rectangle) override;

    /**
     * @brief Formate et envoie la commande de dessin pour un rond (cercle).
     * @param rond Pointeur vers le rond à dessiner.
     */
    virtual void visite(const Rond* rond) override;

    /**
     * @brief Formate et envoie la commande de dessin pour un segment.
     * @param segment Pointeur vers le segment à dessiner.
     */
    virtual void visite(const Segment* segment) override;

    /**
     * @brief Formate et envoie la commande de dessin pour un triangle.
     * @param triangle Pointeur vers le triangle à dessiner.
     */
    virtual void visite(const Triangle * triangle) override;
};

#endif //VISITEURDESSINJAVA_H