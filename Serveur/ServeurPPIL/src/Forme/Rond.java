package Forme;

import java.awt.*;
import java.awt.geom.Ellipse2D;

/**
 * Classe Rond répresentant la forme du Cercle.
 */
public class Rond extends Forme{
    /**
     * Valeurs de la position du centre du cercle.
     */
    double xCentre, yCentre;
    /**
     * Valeur du rayon du cercle.
     */
    double rayon;

    /**
     * Constructeur de Rond.
     * @param xCentre Abscisse du centre du cercle.
     * @param yCentre Ordonnée du centre du cercle.
     * @param rayon Rayon du cercle.
     * @param color Couleur du cercle.
     * @param id identifiant unique.
     */
    public Rond(double xCentre, double yCentre, double rayon,Color color,int id) {
        this.xCentre = xCentre;
        this.yCentre = yCentre;
        this.rayon = rayon;
        this.color = color;
        this.id = id;
    }

    /**
     * Fonction qui permet de dessiner le Rond.
     * @param g graphics du Buffer de la Frame sur laquelle on dessine.
     */
    @Override
    public void dessiner(Graphics2D g) {
        g.setColor(this.color);
        g.fill(new Ellipse2D.Double(xCentre-rayon,yCentre-rayon,rayon*2,rayon*2));

    }



    @Override
    public String toString() {
        return "Rond{" +
                "xCentre=" + xCentre +
                ", yCentre=" + yCentre +
                ", rayon=" + rayon +
                '}';
    }
}
