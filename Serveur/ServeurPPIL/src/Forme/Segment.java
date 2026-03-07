package Forme;

import java.awt.*;
import java.awt.geom.Line2D;

public class Segment extends Forme{
    double x,y,x2,y2;

    public Segment(double x, double y,double x2, double y2,Color color,int id) {
        this.x = x;
        this.y = y;
        this.x2 = x2;
        this.y2 = y2;
        this.color = color;
        this.id = id;
    }

    @Override
    public void dessiner(Graphics2D g) {
        g.setColor(this.color);
        g.draw(new Line2D.Double(x,y,x2,y2));
        }

}
