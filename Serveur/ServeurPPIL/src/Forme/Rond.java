package Forme;

import java.awt.*;

public class Rond extends Forme{
    int xCentre, yCentre,rayon;

    public Rond(int xCentre, int yCentre, int rayon) {
        this.xCentre = xCentre;
        this.yCentre = yCentre;
        this.rayon = rayon;
    }

    @Override
    public void dessiner(Graphics g) {
        //TODO Couleur
        g.fillOval(xCentre, yCentre , rayon, rayon);

    }

    @Override
    public double calculerAire() {
        return 0;
    }
}
