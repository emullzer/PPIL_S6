package Forme;

import java.awt.*;
import java.awt.geom.Ellipse2D;

public class Rond extends Forme{
    double xCentre, yCentre,rayon;

    public Rond(int xCentre, int yCentre, int rayon) {
        this.xCentre = xCentre;
        this.yCentre = yCentre;
        this.rayon = rayon;
    }

    @Override
    public void dessiner(Graphics2D g) {
        //TODO Couleur
        g.fill(new Ellipse2D.Double(xCentre,yCentre,rayon,rayon));

    }

    @Override
    public double calculerAire() {
        return 0;
    }
}
