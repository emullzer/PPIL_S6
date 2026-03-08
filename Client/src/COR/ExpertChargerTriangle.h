//
// Created by sanes on 08/03/2026.
//

#ifndef EXPERTCHARGERTRIANGLE_H
#define EXPERTCHARGERTRIANGLE_H
#include "ExpertCharger.h"


class ExpertChargerTriangle : public ExpertCharger {
public:
    using ExpertCharger::ExpertCharger;
protected:
    Forme* charger2(const std::string& ligne) const override;
};



#endif //EXPERTCHARGERTRIANGLE_H
