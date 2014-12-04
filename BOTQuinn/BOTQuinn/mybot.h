#pragma once
#include "kps.h"

class mybot : public KPS_Bot
{


// ******************************************************************************
//      Viljami Turtiainen, Pelitekoälyt-kurssi, 8/2014
// ******************************************************************************


        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        {
                if (kierros == 0) return (KPS)(rand() % 3);
               
                else if(vihun[kierros - 1]==KIVI) {
				
				// Jos vihun edellinen on kivi, palauta satunnaisesti
				// paperi tai sakset
				
				return (KPS)((rand() % 2) + 1); 
				
				}
				
				else if(vihun[kierros - 1]==SAKSET) {
				
				// Jos vihun edellinen on sakset, palauta satunnaisesti
				// kivi tai paperi
				
				return (KPS)((rand() % 2));
				
				}
				
				else {
				
				// Muuten palauta satunnaisesti mikä tahansa
				
				return (KPS)((rand() % 3));
				
				}
				
				
        }

		
		
        void botin_nimi(std::string &nimi)
        { nimi = "MyBot"; }
};
