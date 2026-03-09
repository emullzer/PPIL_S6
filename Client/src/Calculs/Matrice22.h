#ifndef MATRICE22_H
#define MATRICE22_H

#include "Vecteur2D.h"

/**
 * @class Matrice22
 * @brief Classe représentant une matrice carrée de taille 2x2.
 * * Cette classe est principalement utilisée pour effectuer des transformations géométriques
 * linéaires, comme les rotations, sur des instances de Vecteur2D.
 */
class Matrice22
{
    public :
    Vecteur2D ligneHaut; /**< Premier vecteur ligne de la matrice (a11, a12). */
    Vecteur2D ligneBas;  /**< Second vecteur ligne de la matrice (a21, a22). */

    /**
     * @brief Constructeur de Matrice22 à partir de deux vecteurs lignes.
     * @param ligneHaut Vecteur représentant la ligne supérieure.
     * @param ligneBas Vecteur représentant la ligne inférieure.
     */
    Matrice22(const Vecteur2D &ligneHaut, const Vecteur2D &ligneBas)
        : ligneHaut(ligneHaut), ligneBas(ligneBas) {/*rien à faire*/}

    /**
     * @brief Constructeur de Matrice22 à partir de coefficients réels.
     * @details Utilise la délégation de constructeur. Le mot-clé explicit empêche les conversions implicites.
     * @param a11 Coefficient ligne 1, colonne 1.
     * @param a12 Coefficient ligne 1, colonne 2.
     * @param a21 Coefficient ligne 2, colonne 1.
     * @param a22 Coefficient ligne 2, colonne 2.
     */
    explicit Matrice22(const double &a11, const double &a12,
                       const double &a21, const double &a22)
        : Matrice22(Vecteur2D(a11, a12), Vecteur2D(a21, a22)) {}

    /**
     * @brief Méthode statique créant une matrice de rotation.
     * @param alfa Angle de rotation en radians.
     * @return Une instance de Matrice22 configurée pour une rotation d'angle alfa.
     */
    static const Matrice22 creeRotation(const double &alfa)
    {
        double calfa = cos(alfa);
        double salfa = sin(alfa);

        return Matrice22(calfa, -salfa, salfa, calfa);
    }

    /**
     * @brief Opérateur de conversion en chaîne de caractères.
     * @return Un std::string représentant la matrice sur deux lignes.
     */
    operator std::string() const
    {
        std::ostringstream o;

        o << ligneHaut << std::endl;
        o << ligneBas;

        return o.str();
    }

    /**
     * @brief Multiplie la matrice par un Vecteur2D (Transformation linéaire).
     * @details Calcule le produit Matrice * Vecteur en utilisant le produit scalaire
     * entre chaque ligne de la matrice et le vecteur v.
     * @param v Le vecteur à transformer.
     * @return Un nouveau Vecteur2D résultant de la transformation.
     */
    const Vecteur2D operator*(const Vecteur2D &v) const
    {
        return Vecteur2D(ligneHaut * v, ligneBas * v);
    }
};

/**
 * @brief Surcharge de l'opérateur d'injection dans un flux de sortie.
 * @param o Le flux de sortie.
 * @param mat La matrice à afficher.
 * @return Le flux de sortie modifié.
 */
inline std::ostream &operator<<(std::ostream &o, const Matrice22 &mat) {
    return o << (std::string)mat;
}

#endif