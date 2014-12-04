#pragma once
#include "kps.h"
#include <vector>

// Keksi luokallesi uusi nimi!
class Paviaani_Botti : public KPS_Bot
{
public:
        // Botin toimintalogiikka pelaa-funktioon!
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun) {
			unsigned last_diff; //kertoo eron toiseksi suureen. jos ero on pieni, kannattaa heittää hatusta
			int common_next = getMostCommonNext(kierros, omat, vihun, last_diff);
			common_next %= 3;
			//std::cout << last_diff << std::endl;
			if (common_next == -1 || (double)last_diff / kierros < 0.15) {
				return getRand();
			}
		
			return getInv((KPS) common_next);
		}
		
		KPS getRand() {
			return (KPS)(rand() % 3);
		}
		
		int getMostCommonNext(int kierros, const KPS *omat, const KPS *vihun, unsigned &last_diff) {
			last_diff = 0;
			if (kierros < 2) {
				return -1;
			}
			std::vector <int> common_next;
			common_next.push_back(0);
			common_next.push_back(0);
			common_next.push_back(0);
			common_next.push_back(0);
			common_next.push_back(0);
			common_next.push_back(0);
			
			KPS last_used = vihun[kierros - 1];
			for (int i = 0; i < kierros - 2; i++) {
				if (vihun[i] == last_used) {
					common_next[vihun[i + 1]]++;
				}
			}
			
			last_used = omat[kierros - 1];
			for (int i = 0; i < kierros - 2; i++) {
				if (omat[i] == last_used) {
					common_next[vihun[i + 1] + 3]++;
				}
			}
			
			//std::cout << common_next[0] << " " << common_next[1] << " " << common_next[2] << std::endl;
			
			int last_val = 0;
			int last_best = -1;
			for (unsigned i = 0; i < 6; i++) {
				if (common_next[i] > last_val) {
					last_diff = getDiff(common_next[i], last_val);
					last_best = i;
					last_val = common_next[i];
				}
			}
			
			return last_best;
		}
		
		unsigned getDiff(int v1, int v2) {
			int diff = v1 - v2;
			if (diff < 0) {
				diff *= -1;
			}
			return diff;
		}
		
		KPS getInv(KPS kps) {
			switch (kps)
			{
			case KIVI:              return PAPERI;  break;
			case PAPERI:    return SAKSET;  break;
			case SAKSET:    return KIVI;    break;
			}
		}

        // Keksi botille osuva nimi!
        void botin_nimi(std::string &nimi)
        { nimi = "Paviaani_Botti"; }
};
