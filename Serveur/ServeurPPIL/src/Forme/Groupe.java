package Forme;

import java.awt.*;
import java.util.ArrayList;

/**
 * Classe Groupe représentant un groupe de formes.
 */
public class Groupe extends Forme {
    /**
     * Liste contenant les formes du groupe.
     */
    private ArrayList<Forme> enfants = new ArrayList<>();

    /**
     * Constructeur de la classe Groupe.
     * Notez qu'il n'y a pas de couleur dans le constructeur, car ses enfants possèdent
     * tous la même couleur définie en C++.
     * @param enfants Liste des formes composant ce groupe.
     * @param id Identifiant unique de la forme.
     */
    public Groupe(ArrayList<Forme> enfants,int id) {
        this.enfants = enfants;
        this.id =id;
    }

    /**
     * Dessine chacune des formes composant le groupe.
     * @param g graphics du Buffer de la Frame sur laquelle on dessine.
     */
    @Override
    public void dessiner(Graphics2D g) {
        for (Forme f : enfants) {
            f.dessiner(g);
        }
    }

}