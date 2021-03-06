//------------------------------------------------------------------------------
// Copyright Chris Eykamp
// See LICENSE.txt for full copyright information
//------------------------------------------------------------------------------

#include "tnlTypes.h"

using namespace TNL;

struct PictureLoader
{
   U32 x;
   U32 y;
   U32 *data;
   PictureLoader() {x=0; y=0; data=NULL;}
   virtual ~PictureLoader() {if(data) delete data;}
};

PictureLoader *LoadPicture(const char* path);
GLuint loadGLTex(PictureLoader picture);


extern bool LoadWAVFile(const char *filename, char &format, char **data, int &size, int &freq);
