package Forme;

import java.awt.*;
import java.awt.geom.Path2D;
import java.util.ArrayList;

public class Polygone extends Forme{
    String[] points;

    public Polygone(String[] points, Color color) {
        this.points = points;
        this.color = color;
    }
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
