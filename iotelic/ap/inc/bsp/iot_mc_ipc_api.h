

#ifndef IOT_MC_IPC_API_H
#define IOT_MC_IPC_API_H

/* os shim includes */
#include "os_types_api.h"

/* SW defined mail box credit number, should match with HW */
#define IOT_IPC_MAIL_SLOT_MAX  8

typedef enum {
    IOT_APPCPU_ID = 0,
    IOT_SECCPU_ID = 1,
}IOT_CPU_ID;

typedef enum {
    IOT_MC_POLL_MODE = 0,
    IOT_MC_INTERRUPT_MODE = 1,
}IOT_MC_MODE;

typedef struct _iot_mc_ipc_msg
{
    /* msg id mailed between cpus */
    uint32_t ipc_msg_id;
    /* pointer to msg args buffer */
    void*    ipc_msg_arg;
    /* mail seq, useful to debug msg loss */
    uint32_t ipc_seq;
    /* send side time stamp, used for profiling */
    uint32_t ipc_mail_sender_tick;
    /* recev side time stamp, used for profiling */
    uint32_t ipc_mail_recver_tick;
}iot_mc_ipc_msg_t;

typedef struct _iot_mc_ipc_hw_status
{
    uint32_t hw_send_free_credit    : 8;
    uint32_t hw_send_slot_full1     : 1;
    uint32_t hw_recv_slot_avail     : 8;
    uint32_t hw_recv_slot_empty     : 1;
    uint32_t reserve                : 14;
}iot_mc_ipc_hw_status_t;

typedef void (*iot_mc_ipc_recv_func_t)(uint32_t msg_id, void* msg_arg);

typedef struct _iot_mc_ipc_mailbox
{
    uint8_t  ready;
    uint8_t  cupid;
    uint8_t  mode;
    
    /* send msg by mailbox, this variable indicate how many free */
    uint32_t ipc_fifo_credit;

    /* log of send histrory */
    uint8_t  ipc_send_idx;
    iot_mc_ipc_msg_t send_mail[IOT_IPC_MAIL_SLOT_MAX];
    uint32_t ipc_send_seq;

    uint32_t ipc_fifo_recv_credit;
    /* log of recv history */
    uint8_t  ipc_recv_idx;
    iot_mc_ipc_msg_t recv_mail[IOT_IPC_MAIL_SLOT_MAX];

    /* log last time hw status */
    iot_mc_ipc_hw_status_t ipc_hw_status;

    /* rece msg handler, registerd by caller */
    iot_mc_ipc_recv_func_t recv_callback;
}iot_mc_ipc_mailbox_t;



uint32_t iot_mc_ipc_init(iot_mc_ipc_recv_func_t callback, uint8_t cpuid, uint8_t mode);

uint32_t iot_mc_ipc_deinit(void);

uint32_t iot_mc_ipc_query_mailbox_freecredit(void);

uint32_t iot_mc_ipc_query_mailbox_reccredit(void);

uint32_t iot_mc_ipc_send_msg(uint32_t msg_id, void* msg_arg);

uint32_t iot_mc_ipc_get_hw_stauts(void);


#endif //IOT_MC_IPC_API_H
