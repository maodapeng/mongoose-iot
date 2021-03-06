/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_FW_SRC_SJ_V7_EXT_H_
#define CS_FW_SRC_SJ_V7_EXT_H_

#ifdef SJ_ENABLE_JS

#include "fw/src/sj_hal_js.h"

struct v7;

/* Initialize objects and functions provided by v7_ext, incl. Sys.* */
void sj_v7_ext_api_setup(struct v7 *v7);

/* Initialize `Sys.*` */
void sj_sys_js_init(struct v7 *v7);

/*
 * Invokes a callback and prints a stack trace in case of exception.
 *
 * This function is meant to be invoked by HAL implementations of sj_invoke_cb
 */
void _sj_invoke_cb(struct v7 *, v7_val_t func, v7_val_t this_obj,
                   v7_val_t args);

/* Helper, invokes a callback calls in the context of v7 interpreter */
void sj_invoke_cb0(struct v7 *v7, v7_val_t cb);
void sj_invoke_cb1(struct v7 *v7, v7_val_t cb, v7_val_t arg);
void sj_invoke_cb2(struct v7 *v7, v7_val_t cb, v7_val_t arg1, v7_val_t arg2);

void sj_invoke_cb0_this(struct v7 *v7, v7_val_t cb, v7_val_t this_obj);
void sj_invoke_cb1_this(struct v7 *v7, v7_val_t, v7_val_t, v7_val_t);
void sj_invoke_cb2_this(struct v7 *v7, v7_val_t, v7_val_t, v7_val_t, v7_val_t);

/* Prints an exception to stdout or stderr depending on debug mode */
void sj_print_exception(struct v7 *v7, v7_val_t exc, const char *msg);

#endif /* SJ_ENABLE_JS */

#endif /* CS_FW_SRC_SJ_V7_EXT_H_ */
