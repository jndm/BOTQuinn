#pragma once
#include "kps.h"

// Keksi luokallesi uusi nimi!
class BOT_Bill : public KPS_Bot
{
private:
		int taktiikka;
		int taktiikanVaihe;
		int perakkaisetHaviot;
public:
		BOT_Bill() {
			taktiikka = 0;
			taktiikanVaihe = 0;
			perakkaisetHaviot = 0;
		}
		
        // Botin toimintalogiikka pelaa-funktioon!
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun) {
			if(kierros != 0 && taktiikanVaihe == 0) {
				int tulos = 0;
				switch(taktiikka) {
					case 0:
						for(int i = kierros - 3; i < kierros; ++i) {
							if((omat[i] + 1) % 3 == vihun[i]) {
								--tulos;
							} else if((omat[i] + 2) % 3 == vihun[i]) {
								++tulos;
							}
						}
						if( tulos < 0) {
							++perakkaisetHaviot;
						} else {
							perakkaisetHaviot = 0;
						}
						
						if(perakkaisetHaviot == 2) {
							perakkaisetHaviot = 0;
							taktiikka = 1;
						}
						break;
					case 1:
						for(int i = kierros - 4; i < kierros; ++i) {
							if((omat[i] + 1) % 3 == vihun[i]) {
								--tulos;
							} else if((omat[i] + 2) % 3 == vihun[i]) {
								++tulos;
							}
						}
						if( tulos < 0) {
							++perakkaisetHaviot;
						} else {
							perakkaisetHaviot = 0;
						}
						
						if(perakkaisetHaviot == 2) {
							perakkaisetHaviot = 0;
							taktiikka = 0;
						}
						break;
					default:
						break;
				}
			}
		
			
			if(kierros <= 1) {
				return (KPS)(rand() % 3);
			} else {
				int k = 2;
				if (kierros > 11) {
					k = kierros - 10;
				}
				
				bool sama = true;
				bool biittaaEdellinen = true;
				bool vaihdaAina = true;
				for (int i = k; i <= kierros; ++i) {
					if(vihun[kierros - 1] != vihun[kierros - 2]) {
						sama = false;
					}
					if((vihun[kierros - 1]) % 3 != (omat[kierros - 2] + 1) % 3) {
						biittaaEdellinen = false;
					}
					if(vihun[kierros - 1] == vihun[kierros - 2]) {
						vaihdaAina = false;
					}
				}
				if (sama) {
					return (KPS) ((vihun[kierros - 1] + 1) % 3);
				}
				if (biittaaEdellinen) {
					return (KPS) ((omat[kierros - 1] + 2) % 3);
				}
				if (vaihdaAina) {
					return (KPS) ((vihun[kierros -1] + 2) % 3);
				}
				int r;
				switch(taktiikka) {
					case 0:
						if(taktiikanVaihe == 0) {
							++taktiikanVaihe;
							r = (kierros % 3);
						} else if (taktiikanVaihe == 1) {
							++taktiikanVaihe;
							r = omat[kierros - 1];
						} else {
							++taktiikanVaihe;
							r = ((omat[kierros - 1] + 2) % 3);
							taktiikanVaihe = taktiikanVaihe % 3;
						}
						break;
					case 1:
						if(taktiikanVaihe < 3) {
							++taktiikanVaihe;
							r = ((1000 - kierros) % 3);
						} else {
							++taktiikanVaihe;
							r = omat[kierros - 1];
							taktiikanVaihe = taktiikanVaihe % 4;
						}
						break;
					default:
						break;
				}
				return (KPS) r;
			}
		}

        // Keksi botille osuva nimi!
        void botin_nimi(std::string &nimi)
        { nimi = "BOT Bill"; }
};
