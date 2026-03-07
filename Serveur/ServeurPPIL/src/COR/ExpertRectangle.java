package COR;

import Forme.Forme;
import Forme.Rectangle;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

public class ExpertRectangle extends Expert{
    public ExpertRectangle(ArrayList<Forme> formes, Expert suivant) {
        super(formes,suivant);
    }

    public String afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Rectangle")) {
            return null;
        }

        try {
            String[] valeurs = getValeurs(text);
            Color color = TraducteurCouleur.getCouleur(valeurs[4]);

            formes.add(new Rectangle(Double.parseDouble(valeurs[0]),Double.parseDouble(valeurs[1]),Double.parseDouble(valeurs[2]),Double.parseDouble(valeurs[3]),color,Integer.parseInt(valeurs[5])));
            return "Rectangle ajoute.";
        }catch (NumberFormatException e)
        {
            return "Probleme dans les valeurs de Rectangle.";
        }
    }
}
