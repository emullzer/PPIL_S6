package COR;

import Forme.Forme;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

public class ExpertNettoyage extends Expert{
    private ArrayList<Forme> formes;
    public ExpertNettoyage(ArrayList<Forme> formes, Expert suivant) {
        super(suivant);
        this.formes = formes;
    }

    public Forme afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Nettoyer")) {
            return null;
        }

        formes.clear();
        return null;
    }
}
