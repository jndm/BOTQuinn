#pragma once
#include "kps.h"

// Keksi luokallesi uusi nimi!
class Arbalest : public KPS_Bot
{
public:
        // Botin toimintalogiikka pelaa-funktioon!
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        { 
		int testi = 123;
		
		if(kierros > 2){
		if ((vihun[kierros-1] == SAKSET) && (vihun[kierros-2] == SAKSET))
		{
		return KIVI; }
		if ((vihun[kierros-1] == KIVI) && (vihun[kierros-2] == KIVI)) {
		return PAPERI; }
		if ((vihun[kierros-1] == PAPERI) && (vihun[kierros-2] == PAPERI)) {
		return SAKSET; }
		
			/*if ((vihun[kierros-1]!=vihun[kierros-2]) && (vihun[kierros-2]!= vihun[kierros-3]) && (vihun[kierros-3]!= vihun[kierros-4])){
				do{
				testi = (rand() % 3); 
				}while((KPS)testi == vihun[kierros-1]);
			}
			return (KPS)testi;*/
		else {
		if (omat[kierros-1] == SAKSET) return PAPERI;
		if (omat[kierros-1] == KIVI) return SAKSET;
		if (omat[kierros-1] == PAPERI) return KIVI;
		}
		}
		else return (KPS)(rand() % 3); 
		}

        // Keksi botille osuva nimi!
        void botin_nimi(std::string &nimi)
        { nimi = "Arbalest"; }
};
