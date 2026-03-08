package COR;

import COR.Expert;
import Forme.Forme;
import Forme.Groupe;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

public class ExpertGroupe extends Expert {
     private Expert debutCOR;
    public ExpertGroupe( Expert suivant,Expert debutCOR) {
        super(suivant);
        this.debutCOR = debutCOR;
    }

    public Forme afficher2(String text) {
        String type = text.split(" ")[0];
        if (!type.equals("Groupe")) {
            return null;
        }
        String[] formes = text.split(" ")[1].split(";");
        ArrayList<Forme> formesGroupe = new ArrayList<Forme>();
        for (int i = 1; i < formes.length; i++) {
            formesGroupe.add(debutCOR.afficher(formes[i]));
        }

        return new Groupe(formesGroupe,Integer.parseInt(formes[0]));
    }
}