package Forme;

import java.awt.*;
import java.awt.geom.Line2D;

/**
 * Classe Segment représentant la forme du Segment.
 */
public class Segment extends Forme{
    /**
     * Valeurs des extrémités du segment.
     */
    double x,y,x2,y2;

    /**
     * Constructeur de Segment.
     * @param x Abscisse du point 1.
     * @param y Ordonnée du point 1.
     * @param x2 Abscisse du point 2.
     * @param y2 Ordonnée du point 2.
     * @param color Couleur du Segment.
     * @param id Identifiant unique.
     */
    public Segment(double x, double y,double x2, double y2,Color color,int id) {
        this.x = x;
        this.y = y;
        this.x2 = x2;
        this.y2 = y2;
        this.color = color;
        this.id = id;
    }

    /**
     * Fonction qui permet de dessiner le Segment.
     * @param g graphics du Buffer de la Frame sur laquelle on dessine.
     */
    @Override
    public void dessiner(Graphics2D g) {
        g.setColor(this.color);
        g.draw(new Line2D.Double(x,y,x2,y2));
        }

}
