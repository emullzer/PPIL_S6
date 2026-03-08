//
// Created by sanes on 06/03/2026.
//

#ifndef EXPERTCHARGER_H
#define EXPERTCHARGER_H
#include "Expert.h"


class ExpertCharger : public Expert {
    public:
        using Expert::Expert;

        Forme* charger(const std::string& ligne) const override;

    protected:

        virtual Forme* charger2(const std::string& ligne) const = 0;
};





#endif //EXPERTCHARGER_H
