package Forme;

import java.awt.*;
import java.util.ArrayList;

public class Groupe extends Forme {
    private ArrayList<Forme> enfants = new ArrayList<>();

    public Groupe(ArrayList<Forme> enfants,int id) {
        this.enfants = enfants;
        this.id =id;
    }

    // void ajouter(Forme f) { enfants.add(f); }

    @Override
    public void dessiner(Graphics2D g) {
        for (Forme f : enfants) {
            f.dessiner(g);
        }
    }

}