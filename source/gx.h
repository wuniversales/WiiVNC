/**
 *	Extra convenience functions for using the Wii Graphics Library 
 */

#ifndef GxH
#define GxH

#include <string.h>
#include <malloc.h>
#include <ogcsys.h>


/**
 * GX_Texture is a wrapper around the GXtexObj provided by Nintendo
 * It keeps track of the original texture buffer and its dimensions
 */
class GX_Texture {
public:
	int height;
	int width;
	
	//Texture buffer in the specified format
	u8* buffer;

	GX_Texture(int width, int height, u8 format=GX_TF_RGBA8, u8* buffer=NULL);
	~GX_Texture();
	void Draw(int x, int y, int width=-1, int height=-1, int opacity=255, int degrees=0);
	void Flush();
	
	static GX_Texture* LoadFromPNG(const void* png);
private:
	u8 format;
	GXTexObj texObj;
};

int GX_Initialize();
void GX_Render();

#endif