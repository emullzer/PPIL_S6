package COR;

import Forme.Forme;
import Forme.Polygone;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

public class ExpertPolygone extends Expert{
    public ExpertPolygone(ArrayList<Forme> formes, Expert suivant) {
        super(formes,suivant);
    }

    public String afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Polygone")) {
            return null;
        }
        String[] valeurs = getValeurs(text);
        Color color = TraducteurCouleur.getCouleur(valeurs[0]);

        Polygone polygone = new Polygone(valeurs,color);
        formes.add(polygone);
        return "Triangle dessine.";
    }
}