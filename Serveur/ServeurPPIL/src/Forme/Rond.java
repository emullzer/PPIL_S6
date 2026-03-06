package Forme;

import java.awt.*;
import java.awt.geom.Ellipse2D;

public class Rond extends Forme{
    double xCentre, yCentre,rayon;

    public Rond(double xCentre, double yCentre, double rayon,Color color) {
        this.xCentre = xCentre;
        this.yCentre = yCentre;
        this.rayon = rayon;
        this.color = color;
    }

    @Override
    public void dessiner(Graphics2D g) {
        g.setColor(this.color);
        g.draw(new Ellipse2D.Double(xCentre,yCentre,rayon,rayon));

    }

}
