package dessin;

import java.awt.*;
import java.util.HashMap;

/**
 * Classe qui permet de faire la conversion d'un string en une variable de Type Color.
 */
public class TraducteurCouleur {
    /**
     * HashMap qui contient les Valeurs en String, et leur équivalence en type Color.
     */
    static HashMap<String, Color> mapCouleur = new HashMap<>();

    /**
     * Remplis statiquement la HashMap, pour qu'elle soit prête directement.
     */
    static{
        mapCouleur.put("black", Color.BLACK);
        mapCouleur.put("blue", Color.BLUE);
        mapCouleur.put("red", Color.RED);
        mapCouleur.put("green", Color.GREEN);
        mapCouleur.put("yellow", Color.YELLOW);
        mapCouleur.put("cyan", Color.CYAN);
    }

    /**
     * Permet de faire la conversion entre String jusqu'à Color.
     * @param couleur String contenant la couleur entrée par l'utilisateur.
     * @return La couleur assortie, ou "black" si la couleur n'existe pas.
     */
    public static Color getCouleur(String couleur) {
        Color color = mapCouleur.get(couleur);
        if (color == null) {
            return Color.BLACK;
        }
        return color;
    }


}
