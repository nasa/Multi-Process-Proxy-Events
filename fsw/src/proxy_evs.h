/*
** GSC-18364-1, "Proxy Core Flight System Application and Client for External Process"
**
** Copyright © 2019 United States Government as represented by
** the Administrator of the National Aeronautics and Space Administration.
** No copyright is claimed in the United States under Title 17, U.S. Code.
** All Other Rights Reserved.
**
** Licensed under the NASA Open Source Agreement version 1.3
** See "NOSA GSC-18364-1.pdf"
*/

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
