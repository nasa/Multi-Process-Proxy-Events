/*******************************************************************************
** File: proxy_evs.h
**
*******************************************************************************/

#ifndef _proxy_evs_h_
#define _proxy_evs_h_

/*
** Required header files.
*/
#include "cfe.h"
#include "cfe_error.h"
#include "cfe_evs.h"
#include "cfe_sb.h"
#include "cfe_es.h"

/***********************************************************************/

/****************************************************************************/
/*
** Local function prototypes.
**
** Note: Except for the entry point (PROXY_EvsMain), these
**       functions are not called from any other source module.
*/
void Proxy_EvsMain(void);
void Proxy_EvsInit(void);

#endif /* _proxy_evs_h_ */
