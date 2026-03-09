package COR;

import COR.Expert;
import Forme.Forme;
import Forme.Groupe;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

/**
 * Classe permettant de déchiffrer les requetes de type Groupe.
 */
public class ExpertGroupe extends Expert {
    /**
     * Debut de la chaine, permet d'appeler la COR à l'intérieur de la COR.
     */
     private Expert debutCOR;

    /**
     * Constructeur de l'Expertgroupe.
     * @param suivant Prochain maillon de la chaine.
     * @param debutCOR Premier Maillon de la chaine.
     */
    public ExpertGroupe( Expert suivant,Expert debutCOR) {
        super(suivant);
        this.debutCOR = debutCOR;
    }

    @Override
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