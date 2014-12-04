#pragma once
#include "kps.h"

// Keksi luokallesi uusi nimi!
// KIVI = 0, PAPERI = 1, SAKSET = 2
class DerpBot : public KPS_Bot
{
public:
        // Botin toimintalogiikka pelaa-funktioon!
    KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        {         
        if(kierros>2 && vihun[kierros-1] == vihun[kierros-2]){ // if 1
           if (vihun[kierros-1]==KIVI) //onko kivi
           { return PAPERI; }
           else if (vihun[kierros-1]==PAPERI) //onko paperi
           { return SAKSET; }
           else // tällöin on sakset
           { return KIVI; }
        }// end of if 1
        if (kierros>3 && vihun[kierros-1] == omat[kierros-3]){
			if (omat[kierros-2]==KIVI) // omalla ollut kivi, jolloin vihulla tulee kivi
            { return PAPERI; }
			else if (omat[kierros-2]==PAPERI) // omalla ollut paperi, jolloin vihulla tulee paperi
            { return SAKSET; }
            else
            { return KIVI;}
            } // end of kierros > 3
        if (kierros > 2){ // if 3
			if((vihun[kierros-1] != vihun[kierros-2]) && (vihun[kierros-1]==KIVI)){ //jos vihu on ollut kivi, oma on kivi tai sakset
				int temp;
				do{
					temp = rand() % 3;
				} while (temp != 1);
				return (KPS)(temp);
			}
			else if((vihun[kierros-1] != vihun[kierros-2]) && (vihun[kierros-1]==PAPERI)){ //vihu on ollut pap., oman pitää olla pap. tai kivi
				return (KPS)(rand() % 2);
			}
			else if((vihun[kierros-1] != vihun[kierros-2]) && (vihun[kierros-1]==SAKSET)){ //jos vihu on ollut sakset, oma on paperi tai sakset
				return (KPS)(rand() % 2 + 1);
			}
			else {
				if (kierros % 2 == 0){
					int temp;
					do{
						temp = rand() % 3;
					} while ((KPS)temp != omat[kierros-1]);
					return (KPS)(temp);
				}
				else {
					return omat[kierros-1];
				}
			}
		} // end of if 3
        else { return (KPS)(rand() % 3); }

    }

    // Keksi botille osuva nimi!
    void botin_nimi(std::string &nimi)
		{ nimi = "DerpBot"; }
};


