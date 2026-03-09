package Forme;

import java.awt.*;
import java.awt.geom.Path2D;

/**
 *Classe Triangle représentant la forme du Triangle.
 */
public class Triangle extends Forme{
    /**
     * Valeurs des 3 points du triangle.
     */
    double x1, y1, x2, y2, x3, y3;

    /**
     *
     * @param x1 Abscisse du point 1.
     * @param y1 Ordonnée du point 1.
     * @param x2 Abscisse du point 2.
     * @param y2 Ordonnée du point 2.
     * @param x3 Abscisse du point 3.
     * @param y3 Ordonnée du point 3.
     * @param color Couleur du Triangle.
     * @param id Identifiant unique.
     */
    public Triangle(double x1, double y1, double x2, double y2, double x3, double y3, Color color,int id) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.x3 = x3;
        this.y3 = y3;
        this.color = color;
        this.id = id;
    }

    /**
     * Fonction qui permet de dessiner le Triangle.
     * @param g graphics du Buffer de la Frame sur laquelle on dessine.
     */
    @Override
    public void dessiner(Graphics2D g) {
        g.setColor(this.color);
        Path2D.Double triangle = new Path2D.Double();

        triangle.moveTo(x1,y1);
        triangle.lineTo(x2,y2);
        triangle.lineTo(x3,y3);
        triangle.closePath();

        g.fill(triangle);
    }
    
}
