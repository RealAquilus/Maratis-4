/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2014 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "../../SDL_internal.h"

#ifndef _SDL_cocoaopengl_h
#define _SDL_cocoaopengl_h

#if SDL_VIDEO_OPENGL_CGL

#include "SDL_atomic.h"
#import <Cocoa/Cocoa.h>

struct SDL_GLDriverData
{
    int initialized;
};

@interface SDLOpenGLContext : NSOpenGLContext {
    SDL_atomic_t dirty;
    SDL_Window *window;
}

- (id)initWithFormat:(NSOpenGLPixelFormat *)format
        shareContext:(NSOpenGLContext *)share;
- (void)scheduleUpdate;
- (void)updateIfNeeded;
- (void)setWindow:(SDL_Window *)window;

@end


/* OpenGL functions */
extern int Cocoa_GL_LoadLibrary(_THIS, const char *path);
extern void *Cocoa_GL_GetProcAddress(_THIS, const char *proc);
extern void Cocoa_GL_UnloadLibrary(_THIS);
extern SDL_GLContext Cocoa_GL_CreateContext(_THIS, SDL_Window * window);
extern int Cocoa_GL_MakeCurrent(_THIS, SDL_Window * window,
                                SDL_GLContext context);
extern void Cocoa_GL_GetDrawableSize(_THIS, SDL_Window * window,
                                     int * w, int * h);
extern int Cocoa_GL_SetSwapInterval(_THIS, int interval);
extern int Cocoa_GL_GetSwapInterval(_THIS);
extern void Cocoa_GL_SwapWindow(_THIS, SDL_Window * window);
extern void Cocoa_GL_DeleteContext(_THIS, SDL_GLContext context);

#endif /* SDL_VIDEO_OPENGL_CGL */

#endif /* _SDL_cocoaopengl_h */

/* vi: set ts=4 sw=4 expandtab: */
