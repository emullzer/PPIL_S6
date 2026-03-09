package COR;

import Forme.Forme;
import Forme.Segment;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

/**
 * Classe permettant de déchiffrer les requetes de type Segment.
 */
public class ExpertSegment extends Expert{
    /**
     * Constructeur.
     * @param suivant Prochain maillon de la chaine.
     */
    public ExpertSegment( Expert suivant) {
        super(suivant);
    }
    @Override
    public Forme afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Segment")) {
            return null;
        }

        try {
            String[] valeurs = getValeurs(text);
            Color color = TraducteurCouleur.getCouleur(valeurs[4]);

            return (new Segment(Double.parseDouble(valeurs[0]), Double.parseDouble(valeurs[1]), Double.parseDouble(valeurs[2]),Double.parseDouble(valeurs[3]),color, Integer.parseInt(valeurs[5])));
        }catch (NumberFormatException e)
        {
            return null;
        }
    }
}
