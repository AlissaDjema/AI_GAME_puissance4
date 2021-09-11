#include <stdio.h>
#include <stdlib.h>
#include "primitives_graphiquesSDL2.h"

int main(void)
{
    initialise_fenetre("Test");
	int cont=1;
	while (cont)
	{
	    SDL_Event event;
	    while ( SDL_PollEvent(&event) )
	    {
	    	switch(event.type)
	    	{
	    		case(SDL_MOUSEBUTTONDOWN):
					printf("\tposition : %d;%d\n",event.button.x,event.button.y);
	    			break;
	    		case SDL_WINDOWEVENT:
	    	        if(event.window.event==SDL_WINDOWEVENT_CLOSE)
	    	        {
	    	        	ferme_SDL();
	    	        	cont=0;
	    	        }
	    			break;
	    	}
	    }
	    raffraichis_ecran();
	}

	return EXIT_SUCCESS;
}

