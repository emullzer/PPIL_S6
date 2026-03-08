//
// Created by sanes on 08/03/2026.
//

#ifndef EXPERTCHARGERRECTANGLE_H
#define EXPERTCHARGERRECTANGLE_H
#include "ExpertCharger.h"


class ExpertChargerRectangle : public ExpertCharger {
public:
    using ExpertCharger::ExpertCharger;
protected:
    Forme* charger2(const std::string& ligne) const override;
};





#endif //EXPERTCHARGERRECTANGLE_H
