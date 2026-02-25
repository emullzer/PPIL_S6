package dessin;

import java.awt.*;
import java.util.HashMap;

public class TraducteurCouleur {
    static HashMap<String, Color> mapCouleur = new HashMap<>();

    static{
        mapCouleur.put("black", Color.BLACK);
        mapCouleur.put("blue", Color.BLUE);
        mapCouleur.put("red", Color.RED);
        mapCouleur.put("green", Color.GREEN);
        mapCouleur.put("yellow", Color.YELLOW);
        mapCouleur.put("cyan", Color.CYAN);
    }

    public static Color getCouleur(String couleur) {
        Color color = mapCouleur.get(couleur);
        if (color == null) {
            return Color.BLACK;
        }
        return color;
    }


}
