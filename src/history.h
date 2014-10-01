#ifndef _HISTORY_INCLUDE
#define _HISTORY_INCLUDE

#include <vector>
#include "action_log_item.h"
#include "external_conditions_log_item.h"
#include "plant_log_item.h"
#include "log_item.h"
#include "sensors/external_data.h"
#include "decision.h"

  class History {
    public:
      History();
      virtual ~History();

      void InsertActionLog(Decision);

      void InsertPlantLog(std::string);

      void InsertExternalConditionLog(ExternalData);

    ExternalData GetLastExternalCondition();

    void Save();

  private:
    void Load();

    std::string _actions_filename;
    std::string _plant_filename;
    std::string _external_data_filename;
    std::vector<ActionLogItem> _actions_items;
    std::vector<PlantLogItem> _plant_items;
    std::vector<ExternalConditionsLogItem> _external_condition_items;
};

#endif
