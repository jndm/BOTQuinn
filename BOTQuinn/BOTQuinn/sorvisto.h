#pragma once
#include "kps.h"

// Keksi luokallesi uusi nimi!
class Robobotti : public KPS_Bot
{
public:
        // Botin toimintalogiikka pelaa-funktioon!
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        {
		if(kierros<4){//ekaa ei voi päätellä
			return (KPS)(rand() % 3);
			}
		if(vihun[kierros-1]==vihun[kierros-1]&&vihun[kierros-2]==vihun[kierros-1]&&vihun[kierros-3]==vihun[kierros-1]){
			//jos aina sama
			switch (vihun[kierros - 1])
                {
                case KIVI:      return PAPERI;  break;
                case PAPERI:    return SAKSET;  break;
                case SAKSET:    return KIVI;    break;
                }
		}
		if(vihun[kierros-1]!=vihun[kierros-2]&&vihun[kierros-2]!=vihun[kierros-3]&&vihun[kierros-3]!=vihun[kierros-4]){
			if(omat[kierros-2]==SAKSET&&vihun[kierros-1]==KIVI||omat[kierros-2]==PAPERI&&vihun[kierros-1]==SAKSET||omat[kierros-2]==KIVI&&vihun[kierros-1]==PAPERI)
				if(omat[kierros-3]==SAKSET&&vihun[kierros-2]==KIVI||omat[kierros-3]==PAPERI&&vihun[kierros-2]==SAKSET||omat[kierros-3]==KIVI&&vihun[kierros-2]==PAPERI){
					//vihu pelaa aina aiemman voittavan
					switch (omat[kierros-1])
					{
						case KIVI:      return SAKSET;  break;
						case PAPERI:    return KIVI;  break;
						case SAKSET:    return PAPERI;    break;
					}
				}
			if(omat[kierros-2]==SAKSET&&vihun[kierros-1]==SAKSET||omat[kierros-2]==PAPERI&&vihun[kierros-1]==PAPERI||omat[kierros-2]==KIVI&&vihun[kierros-1]==KIVI)
				if(omat[kierros-3]==SAKSET&&vihun[kierros-2]==SAKSET||omat[kierros-3]==PAPERI&&vihun[kierros-2]==PAPERI||omat[kierros-3]==KIVI&&vihun[kierros-2]==KIVI){
					//vihu pelaa aina aiemman saman
					switch (omat[kierros-1])
					{
						case KIVI:      return PAPERI;  break;
						case PAPERI:    return SAKSET;  break;
						case SAKSET:    return KIVI;    break;
					}
				}
			if(omat[kierros-2]==SAKSET&&vihun[kierros-1]==PAPERI||omat[kierros-2]==PAPERI&&vihun[kierros-1]==KIVI||omat[kierros-2]==KIVI&&vihun[kierros-1]==PAPERI)
				if(omat[kierros-3]==SAKSET&&vihun[kierros-2]==PAPERI||omat[kierros-3]==PAPERI&&vihun[kierros-2]==KIVI||omat[kierros-3]==KIVI&&vihun[kierros-2]==PAPERI){
					//vihu pelaa aina edelliselle häviävän
					switch (omat[kierros-1])
					{
						case KIVI:      return KIVI;  break;
						case PAPERI:    return PAPERI;  break;
						case SAKSET:    return SAKSET;    break;
					}
				}
			//jos vaihtaa aina ota ainakin tasapeli
			switch (vihun[kierros - 1])
                {
                case KIVI:      return SAKSET;  break;
                case PAPERI:    return KIVI;  break;
                case SAKSET:    return PAPERI;    break;
                }
		}
		int strat=rand() % 3;
		if(strat==0)
			return (KPS)(rand() % 3);
		else if(strat==1)
			switch (omat[kierros-1])
					{
						case KIVI:      return KIVI;  break;
						case PAPERI:    return PAPERI;  break;
						case SAKSET:    return SAKSET;    break;
					}
		else if(strat==2)
				{
                if (kierros == 0) return (KPS)(rand() % 3);
                int r;
                do
                { r = rand() % 3; } while (r == omat[kierros - 1]);
                return (KPS)r;
        }
		}

        // Keksi botille osuva nimi!
        void botin_nimi(std::string &nimi)
        { nimi = "Robobotti"; }
};
