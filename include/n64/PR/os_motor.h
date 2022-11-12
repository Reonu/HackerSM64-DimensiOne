
/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo.
        
        $RCSfile: os_motor.h,v $
        $Revision: 1.1 $
        $Date: 1998/10/09 08:01:15 $
 *---------------------------------------------------------------------*/

#ifndef _OS_MOTOR_H_
#define	_OS_MOTOR_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_message.h"
#include "os_pfs.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Rumble PAK interface */

extern s32 osMotorInit(OSMesgQueue *mq, OSPfs *pfs, int controller_no);
extern s32 osMotorInitEx(OSMesgQueue *mq, OSPfs *pfs, int controller_no);
#if	1
#define MOTOR_START		1
#define MOTOR_STOP		0
#define	osMotorStart(x)		__osMotorAccessEx((x), MOTOR_START)
#define	osMotorStop(x)		__osMotorAccessEx((x), MOTOR_STOP)
extern s32 __osMotorAccess(OSPfs *pfs, s32 flag);
extern s32 __osMotorAccessEx(OSPfs *pfs, s32 flag);
#else
extern s32 osMotorStop( OSPfs *pfs);
extern s32 osMotorStart(OSPfs *pfs);
#endif


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_MOTOR_H_ */
