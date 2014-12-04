#pragma once
#include "kps.h"

// Keksi luokallesi uusi nimi!
class Oma_Botti : public KPS_Bot
{
public:
        // Botin toimintalogiikka pelaa-funktioon!
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        { return KIVI; }

        // Keksi botille osuva nimi!
        void botin_nimi(std::string &nimi)
        { nimi = "Oma_Botti"; }
};
