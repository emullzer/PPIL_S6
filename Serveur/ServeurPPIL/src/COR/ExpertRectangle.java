package COR;

import Forme.Forme;
import Forme.Rectangle;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

public class ExpertRectangle extends Expert{
    public ExpertRectangle( Expert suivant) {
        super(suivant);
    }

    public Forme afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Rectangle")) {
            return null;
        }

        try {
            String[] valeurs = getValeurs(text);
            Color color = TraducteurCouleur.getCouleur(valeurs[8]);

            return new Rectangle(Double.parseDouble(valeurs[0]),Double.parseDouble(valeurs[1]),Double.parseDouble(valeurs[2]),Double.parseDouble(valeurs[3]),
                    Double.parseDouble(valeurs[4]),Double.parseDouble(valeurs[5]),Double.parseDouble(valeurs[6]),Double.parseDouble(valeurs[7]),color,Integer.parseInt(valeurs[9]));
        }catch (NumberFormatException e)
        {
            return null;
        }
    }
}
