#ifndef VISITEURDESSIN_H
#define VISITEURDESSIN_H

/**
 * @brief Espace de nommage pour les formes géométriques.
 */
namespace Formes {
  class Rectangle;
}

class Groupe;
class Segment;
class Rond;
class Triangle;
class Polygone;

/**
 * @class Visiteur
 * @brief Interface de base pour le pattern Visitor.
 * * Cette classe abstraite définit les méthodes de visite pour chaque type de forme
 * concrète. Elle permet d'appliquer le design pattern Visitor, rendant l'ajout de Formes simple.
 */
class Visiteur {
public:
  /**
   * @brief Destructeur virtuel par défaut pour assurer une libération propre
   * des ressources dans les classes dérivées.
   */
  virtual ~Visiteur() = default;

  /**
   * @brief Méthode de visite pour un objet de type Groupe.
   * @param groupe Pointeur constant vers le groupe à visiter.
   */
  virtual void visite(const Groupe* groupe) = 0;

  /**
   * @brief Méthode de visite pour un objet de type Polygone.
   * @param polygone Pointeur constant vers le polygone à visiter.
   */
  virtual void visite(const Polygone* polygone) = 0;

  /**
   * @brief Méthode de visite pour un objet de type Rectangle.
   * @param rectangle Pointeur constant vers le rectangle à visiter.
   */
  virtual void visite(const Formes::Rectangle* rectangle) = 0;

  /**
   * @brief Méthode de visite pour un objet de type Rond (Cercle).
   * @param rond Pointeur constant vers le rond à visiter.
   */
  virtual void visite(const Rond* rond) = 0;

  /**
   * @brief Méthode de visite pour un objet de type Segment.
   * @param segment Pointeur constant vers le segment à visiter.
   */
  virtual void visite(const Segment* segment) = 0;

  /**
   * @brief Méthode de visite pour un objet de type Triangle.
   * @param triangle Pointeur constant vers le triangle à visiter.
   */
  virtual void visite(const Triangle * triangle) = 0;
};

#endif //VISITEURDESSIN_H