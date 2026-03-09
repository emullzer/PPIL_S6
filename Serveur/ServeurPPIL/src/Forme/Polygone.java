package Forme;

import java.awt.*;
import java.awt.geom.Path2D;
import java.util.ArrayList;

/**
 * Classe Polygone représentant la forme du Polygone.
 */
public class Polygone extends Forme{
    /**
     * Tableau représentant l'ensemble des points du polygone ( Au moins 3).
     */
    String[] points;

    /**
     * Constructeur de Polygone.
     * @param points Liste des points du polygone.
     * @param color Couleur de la forme.
     * @param id Identifiant unique.
     */
    public Polygone(String[] points, Color color,int id) {
        this.points = points;
        this.color = color;
        this.id = id;
    }

    /**
     * Fonction qui permet de dessiner le Polygone.
     * @param g graphics du Buffer de la Frame sur laquelle on dessine.
     */
    @Override
    public void dessiner(Graphics2D g) {
        g.setColor(this.color);
        Path2D.Double polygone = new Path2D.Double();

        polygone.moveTo(Double.parseDouble(points[2]),Double.parseDouble(points[3]));
        for(int i=4;i<points.length;i=i+2) {
            polygone.lineTo(Double.parseDouble(points[i]), Double.parseDouble(points[i+1]));
        }

        polygone.closePath();

        g.fill(polygone);
    }
}
