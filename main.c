#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <windows.h>

/*
 PLEASE NOTE: the program will require SDL.dll which is located in
              dev-c++'s dll directory. You have to copy it to you
			  program's home directory or the path.
 */

/* The screen surface */
SDL_Surface *screen = NULL;
SDL_Surface *Background = NULL;
SDL_Surface *thePeeCompany = NULL;
SDL_Surface *Credit = NULL;
SDL_Surface *Avaya = NULL;
SDL_Surface *CCA = NULL;
SDL_Surface *Split_Line = NULL;
SDL_Surface *Customer = NULL;
SDL_Surface *Anfrage = NULL;
SDL_Surface *Ausgeloest = NULL;

int ScrnLevel=0;
int annahme = 0;
int ausloesen = 0;


/* This function draws to the screen; replace this with your own code! */
void LoadBitmaps();

void LoadBitmaps()
{
     Background = SDL_LoadBMP("bg.bmp");
     thePeeCompany = SDL_LoadBMP("thepeecompany2.bmp");
     Credit = SDL_LoadBMP("byspeedy.bmp");
     Avaya = SDL_LoadBMP("avaya.bmp");
     CCA = SDL_LoadBMP("cca.bmp");
     Split_Line = SDL_LoadBMP("split.bmp");
     Customer = SDL_LoadBMP("customer.bmp");
     Anfrage = SDL_LoadBMP ("anfrage.bmp");
     Ausgeloest = SDL_LoadBMP ("Eausgeloest.bmp");
 }
 
 void DrawIMG(SDL_Surface *img, int x, int y);
 
 void DrawIMG(SDL_Surface *img, int x, int y)
{
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  SDL_BlitSurface(img, NULL, screen, &dest);
}

int main (int argc, char *argv[])
{


    char *msg;
    int done;

    /* Initialize SDL */
    if (SDL_Init (SDL_INIT_VIDEO) < 0)
    {
        sprintf (msg, "Couldn't initialize SDL: %s\n", SDL_GetError ());
        MessageBox (0, msg, "Error", MB_ICONHAND); 
        free (msg);
        exit (1);
    }
    atexit (SDL_Quit);

    /* Set 800x600 32-bits video mode */
    screen = SDL_SetVideoMode (800, 600, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
    if (screen == NULL)
    {
        sprintf (msg, "Couldn't set 800x600x32 video mode: %s\n",
          SDL_GetError ());
        MessageBox (0, msg, "Error", MB_ICONHAND); 
        free (msg);
        exit (2);
    }
    SDL_WM_SetCaption ("Tetris Game", NULL);
        LoadBitmaps();
    done = 0;
    while (!done)
    {
        SDL_Event event;

        /* Check for events */
        while (SDL_PollEvent (&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                     if ( event.key.keysym.sym == SDLK_ESCAPE ) { done = 1; }
                 if ( event.key.keysym.sym == SDLK_RIGHT ) {  }
                 if ( event.key.keysym.sym == SDLK_LEFT ) { annahme=1;  }
                 if ( event.key.keysym.sym == SDLK_DOWN ) { ausloesen=1;  }
                 if ( event.key.keysym.sym == 32 ) { ScrnLevel=1;  }
                                  
                break;                    
            case SDL_QUIT:
                done = 1;
                break;
            default:
                break;
            }
        }
        
        if(ScrnLevel==0)
        {
        DrawIMG(thePeeCompany,200,200);
        SDL_SetColorKey(Credit, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Credit->format, 255,0,0));
        DrawIMG(Credit,520,500);
        }
        if(ScrnLevel==1)
        {
                 DrawIMG(Background,0,0);
                 SDL_SetColorKey(Avaya, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Avaya->format, 255,0,0));
                 DrawIMG(Avaya,450,350);
                 SDL_SetColorKey(CCA, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(CCA->format, 255,0,0));
                 DrawIMG(CCA, 250,350);  
                 DrawIMG(Split_Line,0,300);
                 SDL_SetColorKey(Customer, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Customer->format, 255,0,0));
                 DrawIMG(Customer,0,0);
                        }
                        if(annahme==1)
                        {
                           SDL_SetColorKey(Anfrage, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Anfrage->format, 255,0,0));           
                          DrawIMG(Anfrage,300,0);              
                                        }
                                        if(ausloesen==1)
                                        {
                                                        SDL_SetColorKey(Ausgeloest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Ausgeloest->format, 255,0,0));
                                                        DrawIMG(Ausgeloest,0,300);
                                                        }
    SDL_Flip(screen);
    }
    return 0;
}
