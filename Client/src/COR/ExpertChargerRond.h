//
// Created by sanes on 08/03/2026.
//

#ifndef EXPERTCHARGERROND_H
#define EXPERTCHARGERROND_H
#include "ExpertCharger.h"


class ExpertChargerRond : public ExpertCharger {
public:
    using ExpertCharger::ExpertCharger;
protected:
    Forme* charger2(const std::string& ligne) const override;
};



#endif //EXPERTCHARGERROND_H
