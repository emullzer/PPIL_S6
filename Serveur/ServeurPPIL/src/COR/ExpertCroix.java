package COR;

import Forme.Forme;
import Forme.Croix;

import java.util.ArrayList;

public class ExpertCroix extends Expert{
    public ExpertCroix(ArrayList<Forme> formes, Expert suivant) {
        super(formes,suivant);
    }

    public String afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Croix")) {
            return null;
        }

        try {
            String[] valeurs = getValeurs(text);
            formes.add(new Croix(Double.parseDouble(valeurs[0]), Double.parseDouble(valeurs[1]), Double.parseDouble(valeurs[2])));
            return "Croix ajoute.";
        }catch (NumberFormatException e)
        {
            return "Probleme dans les valeurs de Croix.";
        }
    }
}
