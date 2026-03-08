package COR;

import Forme.Forme;

import java.util.ArrayList;

public abstract class Expert {
    Expert suivant;

    public Expert(Expert suivant) {
        this.suivant = suivant;
    }

    public Forme afficher(String text) {
        Forme f = this.afficher1(text);
        if (f != null) {
            return f;
        }
        else {
            return null;
        }
    }

    public Forme afficher1(String text) {
        Forme f = this.afficher2(text);
        if (f != null) {
            return f;
        }
        else {
            if (this.suivant != null) {
                return this.suivant.afficher1(text);
            }
            else {
                return null;
            }
        }
    }

    public abstract Forme afficher2(String text);

    protected String[] getValeurs(String text){
        String valeurs = text.split("\\[")[1];
        valeurs = valeurs.replace("]", "");
        return valeurs.split(",");
    }
}
