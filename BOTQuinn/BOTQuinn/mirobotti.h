#pragma once
#include "kps.h"

//Miro Vilkki
// Keksi luokallesi uusi nimi!
class mirobotti : public KPS_Bot
{
public:
        // Botin toimintalogiikka pelaa-funktioon!
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        { 
			
				//aina testataan vihua tekemällä randomia aluksi
				if(kierros < 4){
					return (KPS)(rand() % 3);
			
				}
			
				//jos vihu tekee aina samaa countteroidaan vihu helposti
				if(vihun[kierros-3]==vihun[kierros-1] && vihun[kierros-1]==vihun[kierros-2]){
					return perusbotinvoitto(kierros, vihun);
				}

				// reakoidaan vaihda aina ja randomiin samalla tavalla
				//
				if(vihun[kierros-3]!=vihun[kierros-1] && vihun[kierros-1]!=vihun[kierros-2]){
					return satunnaisenvoitto(kierros,omat,vihun);
				}
				
				//jos tilanne ei ole mikään muista oletetaan vihollisen olevan kehittynyt
				return kehittyneenvoitto(kierros, omat);
		}

		KPS perusbotinvoitto(int kierros, const KPS *vihun){
			switch (vihun[kierros-1])
			{
			case KIVI:      return PAPERI;  break;
			case PAPERI:    return SAKSET;  break;
			case SAKSET:    return KIVI;    break;	
			}
		}

		//kountteroidaan kolmanneks edellinen koska se on todnäkönen
		KPS satunnaisenvoitto(int kierros,  const KPS *omat, const KPS *vihun){
			switch (vihun[kierros-3])
			{
			case KIVI:      return PAPERI;  break;
			case PAPERI:    return SAKSET;  break;
			case SAKSET:    return KIVI;    break;	
			}
		}

		KPS kehittyneenvoitto(int kierros, const KPS *omat){
			switch (omat[kierros-1])
			{
			case KIVI:      return SAKSET;  break;
			case PAPERI:    return KIVI;  break;
			case SAKSET:    return PAPERI;    break;	
			}
		}

        // Keksi botille osuva nimi!
        void botin_nimi(std::string &nimi)
        { nimi = "Miro_Botti"; }
};