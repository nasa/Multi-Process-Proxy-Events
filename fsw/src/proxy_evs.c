/*******************************************************************************
** File: proxy_evs.c
**
** Purpose:
**   This file contains the source code for the Proxy Evs.
**
*******************************************************************************/

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
    uint32 RunStatus = CFE_ES_APP_RUN;

    Proxy_EvsInit();

    while (CFE_ES_RunLoop(&RunStatus) == TRUE)
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
    ** Register the app with Executive services
    */
    CFE_ES_RegisterApp() ;

    /*
    ** Register the events
    */ 
    CFE_EVS_Register(PROXY_EventFilters,
                     sizeof(PROXY_EventFilters)/sizeof(CFE_EVS_BinFilter_t),
                     CFE_EVS_BINARY_FILTER);

    CFE_EVS_SendEvent (PROXY_STARTUP_INF_EID, CFE_EVS_INFORMATION,
                       "PROXY EVS Initialized. Version %d.%d.%d.%d",
                       PROXY_EVS_MAJOR_VERSION,
                       PROXY_EVS_MINOR_VERSION, 
                       PROXY_EVS_REVISION, 
                       PROXY_EVS_MISSION_REV);

} /* End of PROXY_EvsInit() */
