package Forme;

import java.awt.*;
import java.awt.geom.Rectangle2D;

public class Rectangle extends Forme {

    double xHG, yHG, xBD, yBD;

    public Rectangle(double xHG, double yHG, double xBD, double yBD,Color color, int id) {
        this.xHG = xHG;
        this.yHG = yHG;
        this.xBD = xBD;
        this.yBD = yBD;
        this.color = color;
        this.id = id;
    }

    @Override
    public void dessiner(Graphics2D g)
    {
        g.setColor(this.color);
        double longueur = Math.abs(xHG - xBD);
        double hauteur = Math.abs(yHG - yBD);
        double xmin = Math.min(xHG, xBD);
        double ymin = Math.min(yHG, yBD);
        g.fill(new Rectangle2D.Double(xmin,ymin, longueur, hauteur));
    }
}
