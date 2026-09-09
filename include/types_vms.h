/*
 * ***************************************************
 * types_vms
 * Implementation hierarchy: Model::fcs_ops::src::types::types_vms
 *
 *
 *
 * Copyright: LODD (c) 2026
 * ***************************************************
 */
#ifndef H_TYPES_VMS
#define H_TYPES_VMS

#include "type.h"      /* Include for 'relation to classifier' 'type' */
#include "types_dio.h" /* Include for 'attribute of type' 'wow_status_e' */

typedef enum
{
    AMP_FLIGHT_MODE = 0,
    AMP_MAINT_MODE  = 1
} amp_mode_e;

typedef enum
{
    NOT_HOT_MODE = 0,
    HOT_MODE     = 1
} hot_mode_e;

typedef enum
{
    COLD_POWER_UP = 0,
    HOT_POWER_UP  = 1
} powerup_state_e;

typedef struct
{
    amp_mode_e amp_mode_status;
    hot_mode_e hot_mode_status;
    wow_status_e wow_status;
    powerup_state_e power_up_state;
    bool wow_discrepancy;
    bool mode_switch_discrepancy;
    bool hv_enabled;
    bool vps_enabled;
    bool hv_active;
} vms_status_data_t;

#endif /* H_TYPES_VMS */