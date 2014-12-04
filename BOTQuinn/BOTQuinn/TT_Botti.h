#pragma once
#include "kps.h"

// Keksi luokallesi uusi nimi!
class TT_Botti : public KPS_Bot
{
public:
        // Botin toimintalogiikka pelaa-funktioon!
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        { 
			KPS vastaus = (KPS)(rand() % 3);
			if (kierros != 0)
			{
				// Tarkistetaan edelliset pelit
				int* omat_valinnat = tehdyt_valinnat(omat, kierros);
				int* vihun_valinnat = tehdyt_valinnat(vihun, kierros);

				// Aina valittu sama juttu
				if (vihun_valinnat[1] == 0 && vihun_valinnat[2] == 0) // Vihu aina valitsee kiven
					vastaus = PAPERI;
				else if (vihun_valinnat[0] == 0 && vihun_valinnat[2] == 0) // Vihu aina valitsee paperin
					vastaus = SAKSET;
				else if (vihun_valinnat[0] == 0 && vihun_valinnat[1] == 0) // Vihu aina valitsee sakset
					vastaus = KIVI;				

				// Muita vaihtoehtoja
				else 
				{
					// Bot_Biittaa_Edellinen ???
					int botti_bittaa_edellinen = tarkista_botti_bittaa_edellinen(omat, vihun, kierros);

					if (botti_bittaa_edellinen == 1) // On se
					{
						if (omat[kierros - 1] == KIVI) vastaus = PAPERI;
						else if (omat[kierros - 1] == PAPERI) vastaus = SAKSET;
						else if (omat[kierros - 1] == SAKSET) vastaus = KIVI;
					}

					else
					{
						// Muuta
						if (vihun_valinnat[0] > vihun_valinnat[1] && vihun_valinnat[0] > vihun_valinnat[2])
							// Vihulla valittu enemmän kivejä
							vastaus = PAPERI;
						else if (vihun_valinnat[1] > vihun_valinnat[0] && vihun_valinnat[1] > vihun_valinnat[2])
							// Vihulla valittu enemmän paperia
							vastaus = SAKSET;
						else if (vihun_valinnat[2] > vihun_valinnat[0] && vihun_valinnat[2] > vihun_valinnat[1])
							// Vihulla valittu enemmän saksia
							vastaus = KIVI;
					}
				}
					
			}


			return vastaus; 
		}

		int tarkista_botti_bittaa_edellinen(const KPS *omat, const KPS *vihun, int kierros)
		{
			if (kierros <= 10) return 0;

			int botti_bittaa_edellinen = 1;
			int currentPosition;
			int samat = 0;
			int erit = 0;

			for (currentPosition = kierros - 1; currentPosition > 10; currentPosition--)
			{

				if (vihun[currentPosition] == SAKSET && omat[currentPosition - 1] == PAPERI) samat++;
				else if (vihun[currentPosition] == PAPERI && omat[currentPosition - 1] == KIVI) samat++;
				else if (vihun[currentPosition] == KIVI && omat[currentPosition - 1] == SAKSET) samat++;
				else erit++;
			}

			int ero = 0;
			if (erit != 0 && samat != 0)
				ero = (erit/samat) * 10;

			if ( ero > 20 ) botti_bittaa_edellinen = 0;

			return botti_bittaa_edellinen;
		}

		int* tehdyt_valinnat(const KPS *pelaaja, int kierros) 
		{
			int* pelaajan_valinnat = new int[3]; // 0 - KIVI, 1 - PAPERI, 2 - SAKSET
			int currentPosition;

			for (currentPosition = 0; currentPosition < 3; currentPosition++) 
			{
				pelaajan_valinnat[currentPosition] = 0;
			}

			for (currentPosition = 0; currentPosition < kierros; currentPosition++)
			{
				KPS tehty_valinta = pelaaja[currentPosition];

				if (tehty_valinta == KIVI) pelaajan_valinnat[0]++;
				else if (tehty_valinta == PAPERI) pelaajan_valinnat[1]++;
				else if (tehty_valinta == SAKSET) pelaajan_valinnat[2]++;
			}

			return pelaajan_valinnat;
		}

        // Keksi botille osuva nimi!
        void botin_nimi(std::string &nimi)
        { 
			nimi = "Toomas_Botti"; 
		}
};
