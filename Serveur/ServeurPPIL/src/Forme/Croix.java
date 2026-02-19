package Forme;

import java.awt.*;
import java.awt.geom.Line2D;

public class Croix extends Forme{
    double x,y,longueur;

    public Croix(double x, double y, double longueur) {
        this.x = x;
        this.y = y;
        this.longueur = longueur;
    }

    @Override
    public void dessiner(Graphics2D g) {
        //TODO Couleur
        double rayon = longueur/2;
        g.draw(new Line2D.Double(x -rayon,y-rayon,x+rayon,y+rayon));
        g.draw(new Line2D.Double(x +rayon,y-rayon,x-rayon,y+rayon));
    }

    @Override
    public double calculerAire() {
        return 0;
    }
}
