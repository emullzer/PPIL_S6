package COR;

import Forme.Forme;

import java.util.ArrayList;

public abstract class Expert {
    Expert suivant;
    ArrayList<Forme> formes;

    public Expert(ArrayList<Forme> liste, Expert suivant) {
        this.suivant = suivant;
        this.formes = liste;
    }

    public String afficher(String text) {
        String s = this.afficher1(text);
        if (s != null) {
            return s;
        }
        else {
            return null;
        }
    }

    public String afficher1(String text) {
        String s = this.afficher2(text);
        if (s != null) {
            return s;
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

    public abstract String afficher2(String text);

    protected String[] getValeurs(String text){
        String valeurs = text.split("\\[")[1];
        valeurs = valeurs.replace("]", "");
        return valeurs.split(",");
    }
}
