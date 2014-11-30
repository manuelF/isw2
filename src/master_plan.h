#ifndef _MASTER_PLAN_INCLUDE
#define _MASTER_PLAN_INCLUDE
#include <string>
#include <vector>
#include "level.h"
#include "stage.h"
#include "plant.h"

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

    Plant GetPlant();
    void SetPlant(Plant&);

    bool _persist;
    std::string _filename;
private:
    explicit MasterPlan(std::string);
    int _actual_stage;
    Plant _plant;
    std::vector<Stage> _stages;
};

#endif
