/*
    This file is part of SUPPL - the supplemental library for DOS
    Copyright (C) 1996-2000 Steffen Kaiser

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
/* $RCSfile: env_rlsg.c,v $
   $Locker:  $	$Name:  $	$State: Exp $

ob(ject): env_relocateSegment
su(bsystem): env
ty(pe): 
sh(ort description): Update relocated environment segments
lo(ng description): Updates other global variables, such as \tok{env_glbSeg}
	and \tok{env_dfltSeg}, that a segment has been changed. Deleted
	segments are called with \tok{tosegm == 0}.
pr(erequistes): segm != 0
re(lated to): 
se(condary subsystems): 
in(itialized by): 
wa(rning): 
bu(gs): 
va(lue): none
fi(le): env_del.c

*/

#include "initsupl.loc"

#ifndef _MICROC_
#include <dos.h>
#endif
#include <portable.h>
#include "environ.loc"

#include "suppldbg.h"

#ifdef RCS_Version
static char const rcsid[] = 
	"$Id: env_rlsg.c,v 1.1 2006/06/17 03:25:03 blairdude Exp $";
#endif

void env_relocateSegment(const word segm, const word tosegm)
{
	DBG_ENTER("env_relocateSegment", Suppl_env)
	DBG_ARGUMENTS( ("env=%u to=%u", segm, tosegm) )

	assert(segm);

	/* Make sure the deleted segment won't be referenced */
	if(segm == env_glbSeg) {
		env_setGlbSeg(tosegm);
		DBG_INFO(("Change global segment: %04x -> %04x", segm, tosegm))
	}
	if(segm == env_dfltSeg) {
		env_setDfltSeg(tosegm);
		DBG_INFO(("Change default segment: %04x -> %04x", segm, tosegm))
	}

	DBG_EXIT
}
