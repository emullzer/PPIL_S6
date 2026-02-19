package COR;

public abstract class Expert {
    Expert suivant;

    public Expert(Expert suivant) {
        this.suivant = suivant;
    }

    public String afficher(String text) {
        String s = this.afficher1(text);
        if (s != null) {
            return s;
        }
        else {
            return null;
        }
    }

    public String afficher1(String text) {
        String s = this.afficher2(text);
        if (s != null) {
            return s;
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

    public abstract String afficher2(String text);
}
