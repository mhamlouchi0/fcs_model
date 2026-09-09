/*
 * ***************************************************
 * types_fcs.h
 * Implementation hierarchy: Model::fcs_ops::src::types::types_fcs
 *
 *
 *
 * Copyright: LODD (c) 2026
 * ***************************************************
 */
#ifndef H_TYPES_FCS
#define H_TYPES_FCS

#include "type.h" /* Include for 'relation to classifier' 'type' */

typedef enum
{
    VOM_STATUS_INVALID = 0,
    VOM_STATUS_INIT    = 1,
    VOM_STATUS_READY   = 2,
    VOM_STATUS_TAXI    = 3,
    VOM_STATUS_PFBIT   = 4,
    VOM_STATUS_GNDOPS  = 5,
    VOM_STATUS_ZEROG   = 6,
    VOM_STATUS_STARTUP = 10,
    VOM_STATUS_TAKEOFF = 20,
    VOM_STATUS_HOVER   = 30,
    VOM_STATUS_MANUAL  = 40,
    VOM_STATUS_LAND    = 50,
    VOM_STATUS_MR_RTH  = 60,
    VOM_STATUS_UMAN    = 70,
    VOM_STATUS_F_TRANS = 80,
    VOM_STATUS_B_TRANS = 90,
    VOM_STATUS_WAYPNT  = 100,
    VOM_STATUS_FLTDIR  = 110,
    VOM_STATUS_LOITER  = 120,
    VOM_STATUS_FW_RTH  = 130
} vom_status_e;

typedef struct
{
    /* deg */
    float fcs_mr_eul_rpy_d[3];

    /* rad/s */
    float fcs_mr_yawrate_d;

    int8_t fcs_mr_yaw_hold;

    /* thrust, Mx, My, Mz */
    float fcs_ca_nu_des[4];

    /* thrust, Mx, My, Mz */
    float fcs_ca_nu_alloc[4];

    /* Mx, My, Mz */
    float fcs_ca_cerp[3];

    float fcs_mr_h_d;

    float fcs_mr_hdot_d;

    float fcs_mr_h_hold;

    /* m/s */
    float fcs_mr_vel_ne_d[2];

    /* deg */
    float fcs_fw_roll_d;

    /* deg */
    float fcs_fw_pitch_d;

    float fcs_fw_h_d;

    /* m/s */
    float fcs_fw_cas_d;

    /* crossfeed */
    float fcs_mr_pit_intg;

    /* crossfeed */
    int8_t fcs_mr_pit_intg_sat;

    /* crossfeed */
    float fcs_fw_pit_intg;

    /* crossfeed */
    int8_t fcs_fw_pit_intg_sat;
} fcs_mi_fbctrl_data_t;

typedef struct
{
    float euler_rpy[3]; // in rad
    float omg_xyz[3];   // in rad/s
    float acc_xyz[3];   // in m/s/s
    int32_t latitude;   // in degrees * 1E7
    int32_t longitude;  // in degrees * 1E7
    float alt_gps_amsl; // in meters
    float vel_ned[3];   // NED velocity in m/s
    float aspd_cas;
    float alt_radalt_agl;
} fcs_mi_cont_state_t;

typedef struct
{
    uint8_t vom_status;
    uint8_t vom_phase;
    uint8_t safety_status;
    uint8_t pic_status;
    uint8_t in_air_status;
    bool ep_loss;
    bool ip_loss;
    bool gnss_loss;
    uint16_t current_waypoint_idx;
    bool tecs_on;
    bool loiter_on;
    bool cog_track_on;
} fcs_mi_desc_state_t;

typedef struct
{
    float motor_cmd[8];  // Motor commands in RPM (PoC) or normalized [0,1] (SS)
    float servo_cmd[14]; // Servo commands in degrees, 12 control surface + 1 steering + 1 brake servo
    float pusher_cmd;    // Pusher command in RPM, PWM (SS)
} fcs_mi_act_cmd_t;

#endif /* H_TYPES_FCS */
