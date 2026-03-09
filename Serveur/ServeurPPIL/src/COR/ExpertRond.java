package COR;

import Forme.Forme;
import Forme.Rond;
import dessin.TraducteurCouleur;

import java.awt.*;
import java.util.ArrayList;

/**
 * Classe permettant de déchiffrer les requetes de type Rond.
 */
public class ExpertRond extends Expert{
    /**
     * Constructeur.
     * @param suivant Prochain maillon de la chaine.
     */
    public ExpertRond( Expert suivant) {
        super(suivant);
    }
    @Override
    public Forme afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Rond")) {
            return null;
        }
        try {
            String[] valeurs = getValeurs(text);
            Color color = TraducteurCouleur.getCouleur(valeurs[3]);

            return new Rond(Double.parseDouble(valeurs[0]), Double.parseDouble(valeurs[1]), Double.parseDouble(valeurs[2]),color,Integer.parseInt(valeurs[4]));
        }catch (NumberFormatException e){
            return null;
        }
    }
}
