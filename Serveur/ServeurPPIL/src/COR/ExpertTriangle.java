package COR;

import Forme.Forme;
import Forme.Triangle;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

/**
 * Classe permettant de déchiffrer les requetes de type Triangle.
 */
public class ExpertTriangle extends Expert{
    /**
     * Constructeur.
     * @param suivant Prochain maillon de la chaine.
     */
    public ExpertTriangle( Expert suivant) {
        super(suivant);
    }
    @Override
    public Forme afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Triangle")) {
            return null;
        }
        String[] valeurs = getValeurs(text);
        Color color = TraducteurCouleur.getCouleur(valeurs[6]);

        return new Triangle(Double.parseDouble(valeurs[0]),Double.parseDouble(valeurs[1]),Double.parseDouble(valeurs[2]),Double.parseDouble(valeurs[3]),Double.parseDouble(valeurs[4]),Double.parseDouble(valeurs[5]),color,Integer.parseInt(valeurs[7]));
    }
}