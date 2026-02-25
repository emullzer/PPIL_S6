package COR;

import Forme.Forme;
import Forme.Rond;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

public class ExpertRond extends Expert{
    public ExpertRond(ArrayList<Forme> formes, Expert suivant) {
        super(formes,suivant);
    }

    public String afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Rond")) {
            return null;
        }
        try {
            String[] valeurs = getValeurs(text);
            Color color = TraducteurCouleur.getCouleur(valeurs[3]);

            formes.add(new Rond(Double.parseDouble(valeurs[0]), Double.parseDouble(valeurs[1]), Double.parseDouble(valeurs[2]),color));
            return "Rond ajoute";
        }catch (NumberFormatException e){
            return "Probleme avec les valeurs de Rond.";
        }
    }
}
