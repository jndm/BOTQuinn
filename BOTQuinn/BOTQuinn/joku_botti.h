#pragma once
#include "kps.h"
#include <stdlib.h>

// Markus Mäkinen
// Keksi luokallesi uusi nimi!
class Joku_Botti : public KPS_Bot
{

private:

		int samat;
		int vaihtelu;
		int moodi;

public:
        // Botin toimintalogiikka pelaa-funktioon!
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        {
			//KPS bottia vastaan
			if(moodi==1){
					//printf("Moodi 1 käynnissä");
					if(vaihtelu==0){
						vaihtelu+=1;
						return PAPERI;
					}
					if(vaihtelu==1){
						vaihtelu+=1;
						return SAKSET;
					}
					if(vaihtelu==2){
						vaihtelu=0;
						return KIVI;
					}
			}
			//Sama aina bottia vastaan
			if(moodi==2){
				//printf("moodi 2 käynnissä");
					if(vihun[1] == SAKSET){
						return KIVI;
					}
					if(vihun[1] == KIVI){
						return PAPERI;
					}
					if(vihun[1] == PAPERI){
						return SAKSET;
					}

			}
			//Vaihda aina bottia vastaan
			if(moodi==3){
				int randomi = rand() % 3;
				if(randomi == 0){
					return KIVI;
				}
				if(randomi == 1){
					return SAKSET;
				}
				if(randomi == 2){
					return PAPERI;
				}
			}
			//Biittaaja bottia vastaan
			if(moodi==4){
					if(omat[kierros-1]==KIVI){
						return SAKSET;
					}
					if(omat[kierros-1]==PAPERI){
						return KIVI;
					}
					if(omat[kierros-1]==SAKSET){
						return PAPERI;
					}
			}

			//katsotaan kierroksella 6 mikä botti voi olla vastassa
			if(kierros == 6){
					//onko KPS
					if(vihun[0] == KIVI && vihun[1] == PAPERI && vihun[2] == SAKSET && vihun[3] == KIVI && vihun[4] == PAPERI && vihun[5] == SAKSET){
						moodi = 1;
					}
					//onko sama aina
					else if(vihun[0]==vihun[1] && vihun[0]==vihun[2] && vihun[0] == vihun[3] && vihun[0] == vihun[4]){
						moodi = 2;
					}
					//onko biittaaja
					else if(vihun[1]==SAKSET && vihun[2]==PAPERI && vihun[3]==PAPERI && vihun[4]==PAPERI && vihun[5]==PAPERI){
						moodi = 4;
					}
					else{
						moodi = 3;
					}
			}
			if(kierros>=0 && kierros<=6){
				if(kierros==0){
					return PAPERI;
				}
				return KIVI;
			}
			int randomi = rand() % 3;
			if(randomi == 0){
				return KIVI;
			}
			if(randomi == 1){
				return SAKSET;
			}
			if(randomi == 2){
				return PAPERI;
			}
		}

        // Keksi botille osuva nimi!
        void botin_nimi(std::string &nimi)
        { nimi = "Joku_Botti"; }
};
