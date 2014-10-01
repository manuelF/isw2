#ifndef _MASTER_PLAN_INCLUDE
#define _MASTER_PLAN_INCLUDE
#include <string>
#include <vector>
#include "level.h"

struct Stage {
  Stage(int, std::string, Level, Level, Level);
  virtual ~Stage();
  std::string Serialize();
  std::string GetContentForDisplay();

  static Stage Build(std::string);

  int _natural_order;
  std::string _friendly_name;
  Level _humidity_required;
  Level _ph_required;
  Level _temperature_required;
};

class MasterPlan {
  public:
    virtual ~MasterPlan();

    static MasterPlan BuildEmpty();
    static MasterPlan BuildFromFile(std::string);
    static MasterPlan BuildFromString(std::string);
    std::string Serialize();

    std::string GetContentForDisplay();

    void AddStage(Stage);
    void ModifyStage(int, Stage);

    Stage GetActualStage();

    bool _persist;
    std::string _filename;
private:
    explicit MasterPlan(std::string);
    int _actual_stage;
    std::vector<Stage> _stages;
};

#endif
