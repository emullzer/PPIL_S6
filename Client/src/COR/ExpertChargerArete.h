#include "ExpertCharger.h"
#include "../Formes/Segment.h"
#include <regex>

class ExpertChargerArete : public ExpertCharger {
public:
       using ExpertCharger::ExpertCharger;
       protected:
       Forme* charger2(const std::string& ligne) const override;
};