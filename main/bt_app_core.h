#ifndef __BT_APP_CORE_H__
#define __BT_APP_CORE_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/* log tag */
#define BT_APP_CORE_TAG    "BT_APP_CORE"

/* signal for `bt_app_work_dispatch` */
#define BT_APP_SIG_WORK_DISPATCH    (0x01)

/**
 * @brief  handler for the dispatched work
 *
 * @param [in] event  event id
 * @param [in] param  handler parameter
 */
typedef void (* bt_app_cb_t) (uint16_t event, void *param);

/* message to be sent */
typedef struct {
    uint16_t       sig;      /*!< signal to bt_app_task */
    uint16_t       event;    /*!< message event id */
    bt_app_cb_t    cb;       /*!< context switch callback */
    void           *param;   /*!< parameter area needs to be last */
} bt_app_msg_t;

/**
 * @brief  parameter deep-copy function to be customized
 *
 * @param [out] p_dest  pointer to destination data
 * @param [in]  p_src   pointer to source data
 * @param [in]  len     data length in byte
 */
typedef void (* bt_app_copy_cb_t) (void *p_dest, void *p_src, int len);

/**
 * @brief  work dispatcher for the application task
 *
 * @param [in] p_cback       callback function
 * @param [in] event         event id
 * @param [in] p_params      callback paramters
 * @param [in] param_len     parameter length in byte
 * @param [in] p_copy_cback  parameter deep-copy function
 *
 * @return  true if work dispatch successfully, false otherwise
 */
bool bt_app_work_dispatch(bt_app_cb_t p_cback, uint16_t event, void *p_params, int param_len, bt_app_copy_cb_t p_copy_cback);

/**
 * @brief  start up the application task
 */
void bt_app_task_start_up(void);

/**
 * @brief  shut down the application task
 */
void bt_app_task_shut_down(void);

/**
 * @brief  start up the is task
 */
void bt_i2s_task_start_up(void);

/**
 * @brief  shut down the I2S task
 */
void bt_i2s_task_shut_down(void);

/**
 * @brief  write data to ringbuffer
 *
 * @param [in] data  pointer to data stream
 * @param [in] size  data length in byte
 */
void write_ringbuf(const uint8_t *data, uint32_t size);

extern uint8_t s_volume;

#endif /* __BT_APP_CORE_H__ */
