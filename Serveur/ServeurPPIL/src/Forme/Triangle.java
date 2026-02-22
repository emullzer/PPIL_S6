package Forme;

import java.awt.*;
import java.awt.geom.Path2D;

public class Triangle extends Forme{
    double x1, y1, x2, y2, x3, y3;

    public Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.x3 = x3;
        this.y3 = y3;
    }

    @Override
    public void dessiner(Graphics2D g) {
        Path2D.Double triangle = new Path2D.Double();

        triangle.moveTo(x1,y1);
        triangle.lineTo(x2,y2);
        triangle.lineTo(x3,y3);
        triangle.closePath();

        g.fill(triangle);
    }

    @Override
    public double calculerAire() {
        return 0;
    }
}
