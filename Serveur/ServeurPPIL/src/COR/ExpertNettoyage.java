package COR;

import Forme.Forme;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

public class ExpertNettoyage extends Expert{
    public ExpertNettoyage(ArrayList<Forme> formes, Expert suivant) {
        super(formes,suivant);
    }

    public String afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Nettoyer")) {
            return null;
        }

        formes.clear();
        return "Nettoyage effectue";
    }
}
