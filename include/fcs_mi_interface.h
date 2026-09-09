/*
 * ***************************************************
 * fcs_mi_interface.c
 * Implementation hierarchy: Model::fcs_ops::src::fcs_mi::fcs_mi_interface
 *
 *
 *
 * Copyright: LODD (c) 2026
 * ***************************************************
 */
#ifndef H_FCS_MI_INTERFACE
#define H_FCS_MI_INTERFACE

#include "type.h" /* Include for 'relation to classifier' 'type' */
#include "types_fcs.h"

/*
 * @name   fcs_mi_init
 *
 * @brief
 * @param
 * @return void
 */
void fcs_mi_init(void);

/*
 * @name   fcs_mi_periodic
 *
 * @brief
 * @param
 * @return void
 */
void fcs_mi_periodic(void);

/*
 * @name   fcs_mi_get_fcs_cont
 *
 * @brief
 * @param
 * @return void
 */
void fcs_mi_get_fcs_cont(fcs_mi_cont_state_t *ptr_cont);

void fcs_mi_get_fcs_dscr(fcs_mi_desc_state_t *ptr_dscr);

void fcs_mi_get_fbctrl(fcs_mi_fbctrl_data_t *fbctrl_data);

void fcs_mi_get_act_cmd(fcs_mi_act_cmd_t *ptr_act_cmd);

#endif /* H_FCS_MI_INTERFACE */
