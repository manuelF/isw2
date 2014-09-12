#ifndef _MASTER_PLAN_INCLUDE
#define _MASTER_PLAN_INCLUDE
#include <string>
#include <vector>

struct Stage {
  Stage(int, std::string, double, double, double);
  virtual ~Stage();
  std::string Serialize();

  static Stage Build(std::string);

  int _natural_order;
  std::string _friendly_name;
  double _humidity_required;
  double _ph_required;
  double _temperature_required;
};

class MasterPlan{
  public:
    virtual ~MasterPlan();

    static MasterPlan BuildFromFile(std::string);
    static MasterPlan BuildFromString(std::string);

  private:
    explicit MasterPlan(std::string);

    std::vector<Stage> _stages;
    std::string _filename;
};

#endif
