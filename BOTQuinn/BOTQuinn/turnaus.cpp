#include <ctime>
#include <cstdlib>
#include <iostream>
#include "kps.h"
#include "perusbotit.h"
#include "mybot.h"
#include "paviaani_botti.h"
#include "hangman.h"
#include "sorvisto.h"
#include "joku_botti.h"
#include "extremebot.h"
#include "arbalest.h"
#include "TT_Botti.h"
#include "bot_bill2.h"
#include "mirobotti.h"
#include "derpbot.h"
#include "turo.h"
#include "oma_botti_tapio_ja_juuso.h"
#include "BOTQuinn.h"

#define TURNAUSTEN_LKM 5
#define KIERROKSET_PER_OTTELU 1000
#define BOTTIEN_LKM 6

int pisteyta_kierros(KPS oma, KPS vihu);
int pisteyta_ottelu(int omat_pisteet, int vihun_pisteet);
KPS_Bot* luo_botti(int i);


// ******************************************************************************
//      KPS-TURNAUS
// ******************************************************************************
int main()
{
        srand(time(0));

        // Turnauksen tilanne
        int *turnaus_pisteet = new int[BOTTIEN_LKM];
        std::string *bottien_nimet = new std::string[BOTTIEN_LKM];
        for (int i = 0; i < BOTTIEN_LKM; ++i)
        {
                turnaus_pisteet[i] = 0;
                KPS_Bot *botti = luo_botti(i);
                botti->botin_nimi(bottien_nimet[i]);
                delete botti;
        }

	// Pelataan useita turnauksia.
	for (int turnaus = 0; turnaus < TURNAUSTEN_LKM; ++turnaus)
	{

        // Kaikki kaikkia vastaan. Botti instantioidaan uudelleen
        // jokaiseen otteluun.
        for (int i = 0; i < (BOTTIEN_LKM - 1); ++i)
        {
                for (int j = i + 1; j < BOTTIEN_LKM; ++j)
                {
                        // Alusta ottelijat.
                        KPS_Bot *eka_botti      = luo_botti(i);
                        KPS_Bot *toka_botti     = luo_botti(j);
                        KPS *ekan_pelatut       = new KPS[KIERROKSET_PER_OTTELU];
                        KPS *tokan_pelatut      = new KPS[KIERROKSET_PER_OTTELU];
                        int ekan_pisteet        = 0;
                        int tokan_pisteet       = 0;

                        // Ottelu (monta kierrosta)
                        std::cout << "\nUUSI OTTELU: " << bottien_nimet[i] << " vs. " << bottien_nimet[j] << "\n";
                        for (int k = 0; k < KIERROKSET_PER_OTTELU; ++k)
                        {
                                KPS ekan_valinta        = eka_botti ->pelaa(k, ekan_pelatut, tokan_pelatut);
                                KPS tokan_valinta       = toka_botti->pelaa(k, tokan_pelatut, ekan_pelatut);
                                ekan_pisteet            += pisteyta_kierros(ekan_valinta, tokan_valinta);
                                tokan_pisteet           += pisteyta_kierros(tokan_valinta, ekan_valinta);
                                ekan_pelatut[k]         = ekan_valinta;
                                tokan_pelatut[k]        = tokan_valinta;
                        }

                        // Ottelun tulos
                        turnaus_pisteet[i] += pisteyta_ottelu(ekan_pisteet, tokan_pisteet);
                        turnaus_pisteet[j] += pisteyta_ottelu(tokan_pisteet, ekan_pisteet);
                        std::cout << "  " << bottien_nimet[i] << " = " << ekan_pisteet  << " (" << turnaus_pisteet[i] << ")\n";
                        std::cout << "  " << bottien_nimet[j] << " = " << tokan_pisteet << " (" << turnaus_pisteet[j] << ")\n";
			//			std::cin.get();

                        // Siivoa ottelu.
                        delete eka_botti;
                        delete toka_botti;
                        delete[] ekan_pelatut;
                        delete[] tokan_pelatut;
                }
        }
	} // Turnaus

        // Lopputulokset
        std::cout << "\nLOPPUTULOKSET\n";
        for (int i = 0; i < BOTTIEN_LKM; ++i)
        {
                std::cout << bottien_nimet[i] << " = " << turnaus_pisteet[i] << "\n";
        }

        // Siivoa ja lopeta turnaus.
        delete[] turnaus_pisteet;
        delete[] bottien_nimet;
        return 0;
}


int pisteyta_kierros(KPS oma, KPS vihu)
{
        if (oma == KIVI && vihu == SAKSET)
                return 1;
        if (oma == PAPERI && vihu == KIVI)
                return 1;
        if (oma == SAKSET && vihu == PAPERI)
                return 1;
        return 0;
}


int pisteyta_ottelu(int omat_pisteet, int vihun_pisteet)
{
        if (omat_pisteet > vihun_pisteet)
                return 2;
        if (omat_pisteet == vihun_pisteet)
                return 1;
        return 0;
}


KPS_Bot* luo_botti(int i)
{
        switch(i)
        {
                case 0: return new BOTQuinn; 
                case 1: return new Bot_Aina_Kivi;
                case 2: return new Bot_Aina_Paperi;
                case 3: return new Bot_Aina_Sakset;
                case 4: return new Bot_Vaihda_Aina;
                case 5: return new Bot_Biittaa_Edellinen;
                case 6: return new Oma_Botti_Tapio_Ja_Juuso;
                case 7: return new Turo;
				case 8: return new Paviaani_Botti;
				case 9: return new hangman;
				case 10: return new Robobotti;
                case 11: return new Arbalest;
                case 12: return new TT_Botti;
				case 13: return new BOT_Bill;
                case 14: return new mirobotti;
                case 15: return new DerpBot;
				case 16: return new Joku_Botti;
				case 17: return new ExtremeBot;
                case 18: return new mybot;
        }
        return 0;
}
