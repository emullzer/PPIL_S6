package COR;

import Forme.Forme;
import Forme.Polygone;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

public class ExpertPolygone extends Expert{
    public ExpertPolygone( Expert suivant) {
        super(suivant);
    }

    public Forme afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Polygone")) {
            return null;
        }
        String[] valeurs = getValeurs(text);
        Color color = TraducteurCouleur.getCouleur(valeurs[0]);

        return new Polygone(valeurs,color, Integer.parseInt(valeurs[1]));
    }
}