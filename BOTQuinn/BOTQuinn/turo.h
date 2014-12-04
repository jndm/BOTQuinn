#pragma once
#include "kps.h"

// Keksi luokallesi uusi nimi!
class Turo : public KPS_Bot
{
public:
        // Botin toimintalogiikka pelaa-funktioon!
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        {
          int valinta = 0;

          // Valitse sattumanvaraisesti
		     	if(kierros < 50)
				    {
              valinta = rand() % 3;
				    }
				  // Kivi
				  else if(kierros % 10 == 0)
				    {
				      valinta = KIVI;
				    }
				  // Paperi
				  else if(kierros % 11 == 0)
				    {
				      valinta = PAPERI;
				    }
				  // Sakset
				  else if(kierros % 12 == 0)
				    {
				      valinta = SAKSET;
				    }
				  // Yritä päätellä vastustajan käytös
				  else
				    {
				      // Valinnat
				      int kivet = 0;
				      int paperit = 0;
				      int sakset = 0;
				      
				      // Käyttäytyminen
				      int voittaaEdellisen = 0;
				      int vaihtaaAina = 0;

				      for(int i = (kierros - 40); i < kierros; i++)
				        {
				          switch(vihun[i])
				          {
				            case 0:
				              kivet++;
				              break;
				            case 1:
				              paperit++;
				              break;
				            case 2:
				              sakset++;
				              break;
				            default:
				              kivet++;
				              break;
				          }

				          // Voittaa edellisen
				          if(i > 0)
				            {
				              if((vihun[i] == SAKSET && omat[i - 1] == PAPERI) || (vihun[i] == PAPERI && omat[i - 1] == KIVI) || (vihun[i] == KIVI && omat[i - 1] == SAKSET))
				                {
				                  voittaaEdellisen++;
				                }
			              }
			            
			            // Vaihtaa aina
			            if(i > 0)
				            {
			                if(vihun[i] != vihun[i - 1])
			                  {
			                    vaihtaaAina++;
			                  }
		                }
				        }

              // Valitse
				      if(kivet >= paperit && kivet >= sakset && kivet >= voittaaEdellisen && kivet >= vaihtaaAina)
				        {
				          valinta = PAPERI;
				        }
				      else if(paperit >= kivet && paperit >= sakset && paperit >= voittaaEdellisen && paperit >= vaihtaaAina)
				        {
				          valinta = SAKSET;
				        }
				      else if(sakset >= kivet && sakset >= paperit && sakset >= voittaaEdellisen && sakset >= vaihtaaAina)
				        {
				          valinta = KIVI;
				        } 
				      else if(voittaaEdellisen >= kivet && voittaaEdellisen >= paperit && voittaaEdellisen >= sakset && voittaaEdellisen >= vaihtaaAina)
				        {
				          switch(omat[kierros - 1])
				          {
				            case KIVI:
				              valinta = SAKSET;
				              break;
				            case PAPERI:
				              valinta = KIVI;
				              break;
				            case SAKSET:
				              valinta = PAPERI;
				              break;
				            default:
				              valinta = KIVI;
				              break;
				          }
				        }
				      else if(vaihtaaAina >= kivet && vaihtaaAina >= paperit && vaihtaaAina >= sakset && vaihtaaAina >= voittaaEdellisen)
				        {
				          switch(vihun[kierros - 1])
				          {
				            case KIVI:
                      do
                      { valinta = rand() % 3; } while (valinta == PAPERI);
				              break;
				            case PAPERI:
				              do
                      { valinta = rand() % 3; } while (valinta == SAKSET);
				              break;
				            case SAKSET:
				              do
                      { valinta = rand() % 3; } while (valinta == KIVI);
				              break;
				            default:
				              valinta = KIVI;
				              break;
				          }
				        }
				    }

				  return (KPS)valinta;
		    } 

        // Keksi botille osuva nimi!
        void botin_nimi(std::string &nimi)
        { nimi = "Turo"; }
};
