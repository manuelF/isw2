#ifndef _MASTER_PLAN_INCLUDE
#define _MASTER_PLAN_INCLUDE
#include <string>
#include <vector>

struct Stage {
  Stage(int, std::string, int, double, int);
  virtual ~Stage();

  int _natural_order;
  std::string _friendly_name;
  int _humidity_required;
  double _ph_required;
  int _temperature_required;
};

class MasterPlan{
  public:
    MasterPlan(std::string);
    virtual ~MasterPlan();

  private:
    std::vector<Stage> _stages;
};

#endif
