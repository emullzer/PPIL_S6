#ifndef VECTEUR2D_H
#define VECTEUR2D_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

/**
 * @class Vecteur2D
 * @brief Classe représentant un point dans un espace bidimensionnel.
 * * Cette classe fournit les opérations nécéssaires pour l'algèbre vectorielle (addition,
 * soustraction, produit scalaire, norme).
 */
class Vecteur2D
{
public:
    /**< Coordonnée sur l'axe des abscisses */
    double x;
    /**< Coordonnée sur l'axe des ordonnées */
    double y;

    /**
     * @brief Constructeur de Vecteur2D.
     * @param x Valeur initiale de x (défaut 0).
     * @param y Valeur initiale de y (défaut 0).
     */
    explicit Vecteur2D(const double &x = 0, const double &y = 0) : x(x), y(y) {}

    /**
     * @brief Conversion en string.
     * @return Format "x,y" pour l'exportation ou l'affichage.
     */
    operator std::string() const
    {
        std::ostringstream o;
        o << x << "," << y;
        return o.str();
    }

    /** @brief Addition de deux vecteurs. */
    const Vecteur2D operator+(const Vecteur2D& v) const { return Vecteur2D(x + v.x, y + v.y); }

    /** @brief Opérateur de négation (opposé du vecteur). */
    Vecteur2D operator-() { return Vecteur2D(-x, -y); }

    /** @brief Soustraction de deux vecteurs. */
    Vecteur2D operator-(const Vecteur2D& v1) const { return Vecteur2D(x - v1.x, y - v1.y); }

    /** @brief Opérateur d'assignation avec addition. */
    Vecteur2D& operator+=(const Vecteur2D& v2)
    {
        x += v2.x;
        y += v2.y;
        return *this;
    }

    /** @brief Multiplication par un scalaire. */
    const Vecteur2D operator*(const double &a) const { return Vecteur2D(x * a, y * a); }

    /**
     * @brief Produit scalaire de deux vecteurs.
     * @param v Second vecteur.
     * @return Résultat scalaire (x*v.x + y*v.y).
     */
    double operator*(const Vecteur2D& v) const { return (x * v.x) + (y * v.y); }

    /** @brief Calcule la norme au carré (évite l'appel coûteux à sqrt). */
    double norme2() const { return (*this) * (*this); }

    /** @brief Calcule la norme (longueur) du vecteur. */
    double norme() const { return sqrt(this->norme2()); }

    /** @brief Accesseur pour la coordonnée X. */
    double getX() const { return x; }
    /** @brief Accesseur pour la coordonnée Y. */
    double getY() const { return y; }

    /**
     * @brief Calcule le déterminant formé par trois points (vecteurs AB et AC).
     * @details Utile pour déterminer la collinéarité.
     * @param a Point 1.
     * @param b Point 2.
     * @param c Point 3.
     * @return Valeur du produit en croix.
     */
    static double determinant(const Vecteur2D& a, const Vecteur2D& b, const Vecteur2D& c)
    {
        Vecteur2D u = b - a; // Rectification logique : vecteur AB
        Vecteur2D v = c - a; // Rectification logique : vecteur AC
        return (u.x * v.y) - (u.y * v.x);
    }

    /**
     * @brief Vérifie si trois points sont alignés.
     * @param a Point 1.
     * @param b Point 2.
     * @param c Point 3.
     * @return true si les points sont collinéaires.
     */
    static bool sontCollineaires(const Vecteur2D& a, const Vecteur2D& b, const Vecteur2D& c) {
        return std::abs(determinant(a, b, c)) < 1e-10; // Utilisation d'un epsilon pour les doubles
    }
};

/** @brief Multiplication scalaire * vecteur (opérateur externe). */
inline Vecteur2D operator*(const double &a, const Vecteur2D& v) { return v * a; }

/** @brief Surcharge de l'opérateur de flux. */
inline std::ostream& operator<<(std::ostream &o, const Vecteur2D &v)
{
    o << (std::string)v;
    return o;
}

#endif