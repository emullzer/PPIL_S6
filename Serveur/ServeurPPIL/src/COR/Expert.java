package COR;

import Forme.Forme;

import java.util.ArrayList;

/**
 * Classe abstraite permettant d'implémenter les Experts pour la Chain of responsability.
 */
public abstract class Expert {
    /**
     * Prochain maillon de la chaîne.
     */
    Expert suivant;

    /**
     * Constructeur de la classe expert.
     * @param suivant Prochain maillon de la chaîne.
     */
    public Expert(Expert suivant) {
        this.suivant = suivant;
    }

    /**
     * Fonction appelée par le premier maillon de la chaîne.
     * Permet de lancer la chaine et de récuperer la Forme si elle existe.
     * @param text Requete envoyée par le client.
     * @return Forme si le message a été compris par un maillon, ou null si personne n'a su le déchiffer.
     */
    public Forme afficher(String text) {
        Forme f = this.afficher1(text);
        if (f != null) {
            return f;
        }
        else {
            return null;
        }
    }

    /**
     * Permet d'appeler sa fonction de détection de Forme. Si jamais elle échoue.
     * @param text Requete envoyée par le Client.
     * @return Forme si message Compris, null sinon.
     */
    public Forme afficher1(String text) {
        Forme f = this.afficher2(text);
        if (f != null) {
            return f;
        }
        else {
            if (this.suivant != null) {
                return this.suivant.afficher1(text);
            }
            else {
                return null;
            }
        }
    }

    /**
     * Fonction unique à chaque maillon, essaye de déchiffrer le message.
     * @param text Requete du Client.
     * @return Forme trouvée ou null sinon.
     */
    public abstract Forme afficher2(String text);

    /**
     * Fonction qui découpe dans un tableau les valeurs du message. Utilisé par la majorité des formes.
     * @param text requete du Client.
     * @return Tableau de String avec les valeurs du message.
     */
    protected String[] getValeurs(String text){
        String valeurs = text.split("\\[")[1];
        valeurs = valeurs.replace("]", "");
        return valeurs.split(",");
    }
}
