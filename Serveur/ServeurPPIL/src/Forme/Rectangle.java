package Forme;

import java.awt.*;
import java.awt.geom.Path2D;

public class Rectangle extends Forme {


    double x1, y1, x2, y2, x3, y3, x4, y4;

    public Rectangle(double x1, double y1, double x2, double y2,
                     double x3, double y3, double x4, double y4,
                     Color color, int id) {
        this.x1 = x1; this.y1 = y1;
        this.x2 = x2; this.y2 = y2;
        this.x3 = x3; this.y3 = y3;
        this.x4 = x4; this.y4 = y4;
        this.color = color;
        this.id = id;
    }

    @Override
    public void dessiner(Graphics2D g) {
        g.setColor(this.color);

        Path2D.Double path = new Path2D.Double();

        path.moveTo(x1, y1);
        path.lineTo(x2, y2);
        path.lineTo(x3, y3);
        path.lineTo(x4, y4);
        path.closePath();

        g.fill(path);
    }
}