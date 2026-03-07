#ifndef EXPERT_H
#define EXPERT_H

#include <string>
#include "../Formes/Forme.h"

class Expert {
    protected:
        Expert* suivant; // Le prochain expert dans la liste

    public:
        Expert(Expert* next) : suivant(next) {}
        virtual ~Expert() = default;

        virtual Forme* charger(const std::string& ligne) const = 0;
    };

#endif