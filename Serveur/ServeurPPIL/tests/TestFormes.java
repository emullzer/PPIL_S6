import Forme.Croix;
import Forme.Forme;
import Forme.Rond;
import dessin.Dessin;
import org.junit.Test;

import java.util.ArrayList;

public class TestFormes {
    @Test
    public void TestDessiner() throws InterruptedException {
        Dessin dessin = new Dessin();
        Croix croix = new Croix(70,90,50);
        Rond rond = new Rond(100,200,150);
        ArrayList<Forme> formes = new ArrayList<Forme>();
        formes.add(croix);
        formes.add(rond);
        dessin.afficherDessin(formes);
    }
}
