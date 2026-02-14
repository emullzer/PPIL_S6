package Forme;

import java.awt.*;

public class Croix extends Forme{
    int gauche,haut,droite,bas;

    public Croix(int gauche, int haut, int droite, int bas) {
        this.gauche = gauche;
        this.haut = haut;
        this.droite = droite;
        this.bas = bas;
    }

    @Override
    public void dessiner(Graphics g) {
        //TODO Couleur
        g.drawLine(gauche,haut, droite, bas);
        g.drawLine(gauche, bas, droite, haut);
    }

    @Override
    public double calculerAire() {
        return 0;
    }
}
