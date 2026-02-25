package COR;

import Forme.Forme;
import Forme.Triangle;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

public class ExpertTriangle extends Expert{
    public ExpertTriangle(ArrayList<Forme> formes, Expert suivant) {
        super(formes,suivant);
    }

    public String afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Triangle")) {
            return null;
        }
        String[] valeurs = getValeurs(text);
        Color color = TraducteurCouleur.getCouleur(valeurs[6]);

        Triangle triangle = new Triangle(Double.parseDouble(valeurs[0]),Double.parseDouble(valeurs[1]),Double.parseDouble(valeurs[2]),Double.parseDouble(valeurs[3]),Double.parseDouble(valeurs[4]),Double.parseDouble(valeurs[5]),color);
        formes.add(triangle);
        return "Triangle dessine.";
    }
}