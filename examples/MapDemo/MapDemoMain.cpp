/* Copyright (C) 2010 Mobile Sorcery AB

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.
*/

#include <conprint.h>

#include "AppStyleMgr.h"
#include "MapDemoAppStyle.h"
#include "MapDemoMoblet.h"

//-------------------------------------------------------------------------
extern "C" int MAMain( )
//-------------------------------------------------------------------------
{
	//
	// Init app style
	//
	AppStyleMgr::setStyle( newobject( MapDemo::MapDemoAppStyle, new MapDemo::MapDemoAppStyle( ) ) );
	MapDemo::MapDemoMoblet* moblet = newobject( MapDemo::MapDemoMoblet, new MapDemo::MapDemoMoblet( ) );
	
	Moblet::run( moblet );

	deleteobject( moblet );
	MapCache::shutdown( );
	AppStyleMgr::shutdown( );
	MessageMgr::shutdown( );

	MemoryMgr::dump( );

	return 0;
}
