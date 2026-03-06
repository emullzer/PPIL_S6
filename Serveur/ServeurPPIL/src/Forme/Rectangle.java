package Forme;

import java.awt.*;
import java.awt.geom.Rectangle2D;

public class Rectangle extends Forme {

    double xHG, yHG, xBD, yBD;

    public Rectangle(double xHG, double yHG, double xBD, double yBD) {
        this.xHG = xHG;
        this.yHG = yHG;
        this.xBD = xBD;
        this.yBD = yBD;
    }

    @Override
    public void dessiner(Graphics2D g) {
        g.draw(new Rectangle2D.Double(xHG, yHG, xBD, yBD));
    }
}
