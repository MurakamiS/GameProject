﻿

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
#include "Effekseer.Vector2D.h"

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
namespace Effekseer { 
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
Vector2D::Vector2D()
	: X		( 0.0f )
	, Y		( 0.0f )
{

}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
Vector2D::Vector2D( float x, float y )
	: X		( x )
	, Y		( y )
{

}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
Vector2D& Vector2D::operator+=( const Vector2D& value )
{
	X += value.X;
	Y += value.Y;
	return *this;
}

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
 } 
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------