package COR;

import Forme.Forme;

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
        return "Triangle dessine.";
    }
}