//-----------------------------------------------------------------------------------
//
// Bitfighter - A multiplayer vector graphics space game
// Based on Zap demo released for Torque Network Library by GarageGames.com
//
// Derivative work copyright (C) 2008-2009 Chris Eykamp
// Original work copyright (C) 2004 GarageGames.com, Inc.
// Other code copyright as noted
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//------------------------------------------------------------------------------------

#ifndef _SYMBOL_SHAPE_H_
#define _SYMBOL_SHAPE_H_

#include "FontContextEnum.h"
#include "InputCodeEnum.h"

#include "Point.h"
#include "tnlVector.h"
#include "tnlTypes.h"


using namespace TNL;

namespace Zap { namespace UI {


// Parent for various Shape classes below
class SymbolShape 
{
protected:
   S32 mWidth, mHeight;
public:
   virtual void render(const Point &pos, S32 fontSize, FontContext fontContext) const = 0;
   virtual void updateWidth(S32 fontSize, FontContext fontContext);

   S32 getWidth() const;
};


class SymbolRoundedRect : public SymbolShape
{
   typedef SymbolShape Parent;

private:
   S32 mRadius;

public:
   SymbolRoundedRect(S32 width, S32 height, S32 radius);   // Constructor
   void render(const Point &pos, S32 fontSize, FontContext fontContext) const;
};


class SymbolHorizEllipse : public SymbolShape
{
   typedef SymbolShape Parent;

public:
   SymbolHorizEllipse(S32 width, S32 height); // Constructor
   void render(const Point &pos, S32 fontSize, FontContext fontContext) const;
};


class SymbolRightTriangle : public SymbolShape
{
   typedef SymbolShape Parent;

public:
   SymbolRightTriangle(S32 width); // Constructor
   void render(const Point &pos, S32 fontSize, FontContext fontContext) const;
};


class SymbolCircle : public SymbolShape
{
   typedef SymbolShape Parent;

public:
   SymbolCircle(S32 radius); // Constructor
   virtual void render(const Point &pos, S32 fontSize, FontContext fontContext) const;
};


class SymbolGear : public SymbolCircle
{
   typedef SymbolCircle Parent;

private:
   F32 mSizeFactor;

public:
   SymbolGear();  // Constructor
   void updateWidth(S32 fontSize, FontContext fontContext);
   void render(const Point &pos, S32 fontSize, FontContext fontContext) const;
};


class SymbolText : public SymbolShape
{
   typedef SymbolShape Parent;

protected:
   string mText;

public:
   SymbolText(const string &text);
   virtual void updateWidth(S32 fontSize, FontContext fontContext);
   virtual void render(const Point &pos, S32 fontSize, FontContext fontContext) const;
};


class SymbolKey : public SymbolText
{
   typedef SymbolText Parent;

public:
   SymbolKey(const string &text);
   void updateWidth(S32 fontSize, FontContext fontContext);
   void render(const Point &pos, S32 fontSize, FontContext fontContext) const;
};


////////////////////////////////////////
////////////////////////////////////////


class SymbolString
{
private:
   S32 mWidth;
   S32 mFontSize;
   FontContext mFontContext;

   Vector<SymbolShape *> mSymbols;

public:
   SymbolString(const Vector<SymbolShape *> &symbols, S32 fontSize, FontContext fontContext);      // Constructor
   virtual SymbolString::~SymbolString();

   S32 getWidth() const;
   void renderCenter(const Point &center) const;

   static SymbolShape *getControlSymbol(InputCode inputCode);
   static SymbolShape *getSymbolGear();
};


} } // Nested namespace



#endif