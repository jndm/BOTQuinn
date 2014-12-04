#pragma once
#include "kps.h"

// Keksi luokallesi uusi nimi!
class ExtremeBot : public KPS_Bot
{
	
	int kivi;
	int sakset;
	int paperi;
	int error;

public:

	ExtremeBot()
	{
		kivi = 0;
		sakset = 0;
		paperi = 0;
	}

        // Botin toimintalogiikka pelaa-funktioon!
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        {


			// Lis‰‰ vastustajan vallinnat muistiin
			switch (vihun[kierros - 1])
                {
                case KIVI:      kivi++;  break;
                case PAPERI:    sakset++;  break;
                case SAKSET:    paperi++;    break;
                }

			// Kaksi ensimm‰ist‰ kierrosta randomilla.
			 if (kierros < 2){
				 return (KPS)(rand() % 3);
			 }


			// Jos vastustaja valitsee kaksi kertaa per‰kk‰in
			 if(vihun[kierros - 1] == vihun[kierros-2] && vihun[kierros - 1] == vihun[kierros-3])
			 {
				  switch (vihun[kierros - 1])
                {
                case KIVI:      return PAPERI;  break;
                case PAPERI:    return SAKSET;  break;
                case SAKSET:    return KIVI;    break;
                }
			 }
			

			// Mit‰ vastustaja on eniten k‰ytt‰nyt
			 if(kivi > sakset && kivi > paperi)
			 {
				 return PAPERI;
			 }
			 if(paperi > sakset && paperi > kivi)
			 {
				 return SAKSET;
			 }
			 if(sakset > kivi && sakset > paperi)
			 {
				 return KIVI;
			 }



			// Logic goes here 
			
			return KIVI; }


        void botin_nimi(std::string &nimi)
        { nimi = "King of Hello World"; }
};
