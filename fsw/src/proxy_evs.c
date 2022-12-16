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

/*
**   Include Files:
*/

#include "proxy_evs.h"
#include "proxy_evs_events.h"
#include "proxy_evs_version.h"

#include "unistd.h"

/*
** global data
*/

static CFE_EVS_BinFilter_t  PROXY_EventFilters[] =
       {  /* Event ID    mask */
          {PROXY_STARTUP_INF_EID,       0x0000},
       };

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Proxy_EvsMain() -- Application entry point and main process loop          */
/*                                                                            */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * *  * * * * **/
void Proxy_EvsMain( void )
{
    uint32 RunStatus = CFE_ES_RunStatus_APP_RUN;

    Proxy_EvsInit();

    while (CFE_ES_RunLoop(&RunStatus) == true)
    {
        sleep(1);
    }

    CFE_ES_ExitApp(RunStatus);

} /* End of PROXY_EvsMain() */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */
/*                                                                            */
/* PROXY_EvsInit() --  initialization                                         */
/*                                                                            */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/
void Proxy_EvsInit(void)
{
    /*
    ** Register the events
    */ 
    CFE_EVS_Register(PROXY_EventFilters,
                     sizeof(PROXY_EventFilters)/sizeof(CFE_EVS_BinFilter_t),
                     CFE_EVS_EventFilter_BINARY);

    CFE_EVS_SendEvent (PROXY_STARTUP_INF_EID, CFE_EVS_EventType_INFORMATION,
                       "PROXY EVS Initialized. Version %d.%d.%d.%d",
                       PROXY_EVS_MAJOR_VERSION,
                       PROXY_EVS_MINOR_VERSION, 
                       PROXY_EVS_REVISION, 
                       PROXY_EVS_MISSION_REV);

} /* End of PROXY_EvsInit() */
