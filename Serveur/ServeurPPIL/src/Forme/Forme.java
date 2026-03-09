package Forme;

import java.awt.*;

/**
 * Classe abstraite suivant les Formes du client, utilisée pour dessiner chacune des formes.
 */
public abstract class Forme {
    Color color;
    int id;
    /**
     * Fonction qui va être appelée par Dessin et qui trace la forme adéquate
     * sur le graphics en paramètre.
     * @param g graphics du Buffer de la Frame sur laquelle on dessine.
     */
    public abstract void dessiner(Graphics2D g);
}
