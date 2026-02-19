package COR;

public class ExpertCroix {
    public ExpertCroix(Expert suivant) {
        super();
    }

    public String afficher2(String text) {
        String type = text.split("\\[")[0];
        if (!type.equals("Croix")) {
            return null;
        }

        String valeurs = text.split("\\[")[1];
        valeurs = valeurs.replace("]", ""); // on remplace le dernier caractère par du vide
        String[] positions = valeurs.split(",");
        return "Croix dessinee.";
    }
}
