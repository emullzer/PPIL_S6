package Forme;

import java.awt.*;

public abstract class Forme {
    Color color;
    /**
     * Fonction qui va être appelée par Dessin et qui trace la forme adéquate
     * sur le graphics en paramètre.
     * @param g graphics du Buffer de la Frame sur laquelle on dessine.
     */
    public abstract void dessiner(Graphics2D g);
    public abstract double calculerAire();
}
