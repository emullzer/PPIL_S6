package COR;

import Forme.Forme;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

/**
 * Classe permettant de déchiffrer les requetes de type Nettoyage.
 * Utilisé lorsque le client veut vider l'affichage.
 */
public class ExpertNettoyage extends Expert{
    /**
     * Liste de l'interlocuteur, ici on la vide.
     */
    private ArrayList<Forme> formes;

    /**
     * Constructeur.
     * @param formes Liste des formes de l'interlocuteur.
     * @param suivant Prochain maillon.
     */
    public ExpertNettoyage(ArrayList<Forme> formes, Expert suivant) {
        super(suivant);
        this.formes = formes;
    }


    @Override
    public Forme afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Nettoyer")) {
            return null;
        }

        formes.clear();
        return null;
    }
}
