/*
 * ***************************************************
 * vms_interface
 * Implementation hierarchy: Model::fcs_ops::src::vms::vms_interface
 *
 *
 *
 * Copyright: LODD (c) 2026
 * ***************************************************
 */
#ifndef H_VMS_INTERFACE
#define H_VMS_INTERFACE

#include "type.h"            /* Include for 'relation to classifier' 'type' */
#include "types_vms.h"       /* Include for 'attribute of type' 'amp_mode_e' 'hot_mode_e' */
#include "vms_model_types.h" /* Generated types needed for std_sensor_t */

/*
 * @name   vms_init
 *
 * @brief
 * @param
 * @return void
 */
void vms_init(void);

/*
 * @name   vms_periodic
 *
 * @brief
 * @param
 * @return void
 */
void vms_periodic(void);

/*
 * @name   vms_do_mgr_init
 *
 * @brief
 * @param
 * @return void
 */
void vms_do_mgr_init(void);

/*
 * @name   vms_do_mgr_periodic
 *
 * @brief
 * @param
 * @return void
 */
void vms_do_mgr_periodic(void);

/*
 * @name   vms_get_hven_fail_status
 *
 * @brief  Retrieves the operational failure status of the propulsion battery high voltage fail status for the given BMS
 * ID. Returns True if BMS ID is correct and High Voltage output enable operation for that PB has failed, false
 * otherwise.
 * @param  bms_id (uint8_t) -
 * @return bool
 */
bool vms_get_hven_fail_status(uint8_t bms_id);

/*
 * @name   vms_get_bms_failure
 *
 * @brief
 * @param  bms_id (uint8_t) -
 * @return bool
 */
bool vms_get_bms_failure(uint8_t bms_id);

/*
 * @name   vms_get_hv_discharge_in_progress
 *
 * @brief
 * @param
 * @return bool
 */
bool vms_get_hv_discharge_in_progress(void);

/*
 * @name   vms_get_vps_enabled_status
 *
 * @brief
 * @param
 * @return bool
 */
bool vms_get_vps_enabled_status(void);

/*
 * @name   vms_get_vms_data
 *
 * @brief
 * @param
 * @return bool
 */
bool vms_get_vms_data(vms_status_data_t *ptr_vms_data);

/*
 * @name   vms_get_voted_ins_data
 *
 * @brief
 * @param  ptr_voted_ins_data (std_sensor_t*) -
 * @return void
 */
void vms_get_voted_ins_data(std_sensor_t *ptr_voted_ins_data);

/*
 * @name   vms_get_vms_mi_wca
 *
 * @brief
 * @param  ptr_vms_wca (vms_wca_t*) -
 * @return void
 */
void vms_get_vms_mi_wca(vms_wca_t *ptr_vms_wca);

/*
 * @name   vms_mode_mgr_set_hv_active
 *
 * @brief
 * @param state - true to set HV active, false to set HV inactive
 * @return void
 */
void vms_mode_mgr_set_hv_active(bool state);

#endif /* H_VMS_INTERFACE */
