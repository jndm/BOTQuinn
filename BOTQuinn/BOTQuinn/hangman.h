#pragma once
#include "kps.h"

// Keksi luokallesi uusi nimi!
class hangman : public KPS_Bot
{
public:
        // Botin toimintalogiikka pelaa-funktioon!
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        { 
		int i;
		int j;
		int samat = 0;
			if (kierros == 0) return (KPS)(rand() % 3);
			for(i = 0; i < kierros;i++)
				if(vihun[i] == vihun[i-1])
					samat++;
					
                switch (vihun[kierros - 1])
                {
					case KIVI:
						if(kierros > 1)	
							if(omat[kierros-2] == SAKSET)
							{
								switch(omat[kierros-1])
								{
									case KIVI:
										return SAKSET;
										break;
									case PAPERI:
										return KIVI;
										break;
									case SAKSET:
										return PAPERI;
										break;
								}
							}
							else if(samat < 1)
							{
								switch(vihun[kierros-1])
								{
									case KIVI:      
										return SAKSET;
										break;
									case PAPERI:    
										return KIVI;
										break;										
										
									case SAKSET:    
										return PAPERI;   
										break;
								}
							}
							else if(vihun[kierros-2] == KIVI)
							{
								return PAPERI;
								break;
							}
								
						else return (KPS)(rand() % 3);
					case PAPERI:
						if(kierros > 1)
			
							if(omat[kierros-2] == KIVI)
							{
								switch(omat[kierros-1])
								{
									case KIVI:
										return SAKSET;
										break;
									case PAPERI:
										return KIVI;
										break;
									case SAKSET:
										return PAPERI;
										break;
								}
							}
							else if(samat < 1)
							{
								switch(vihun[kierros-1])
								{
									case KIVI:      
										return SAKSET;
										break;
									case PAPERI:    
										return KIVI;
										break;										
										
									case SAKSET:    
										return PAPERI;   
										break;
								}
							}
							else if(vihun[kierros-2] == PAPERI)
							{
								return SAKSET;
								break;
							}
						else return (KPS)(rand() % 3);
					case SAKSET:
						if(kierros > 1)
							
							if(omat[kierros-2] == PAPERI)
							{
								switch(omat[kierros-1])
								{
									case KIVI:
										return SAKSET;
										break;
									case PAPERI:
										return KIVI;
										break;
									case SAKSET:
										return PAPERI;
										break;
								}
							}
							else if(samat < 1)
							{
								switch(vihun[kierros-1])
								{
									case KIVI:      
										return SAKSET;
										break;
									case PAPERI:    
										return KIVI;
										break;										
										
									case SAKSET:    
										return PAPERI;   
										break;
								}
							}
							else if(vihun[kierros-2] == SAKSET)
							{
								return KIVI;
								break;
							}
						else return (KPS)(rand() % 3);							
								
					}
				
		 }

        // Keksi botille osuva nimi!
        void botin_nimi(std::string &nimi)
        { nimi = "HANGMAN"; }
};
