//
// Created by sanes on 08/03/2026.
//

#ifndef EXPERTCHARGERFACES_H
#define EXPERTCHARGERFACES_H
#include "ExpertCharger.h"


class ExpertChargerFaces : public ExpertCharger {
public:
    using ExpertCharger::ExpertCharger;
    protected:
        Forme* charger2(const std::string& ligne) const override;
};



#endif //EXPERTCHARGERFACES_H
