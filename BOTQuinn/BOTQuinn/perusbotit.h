#pragma once
#include "kps.h"

class Bot_Aina_Kivi : public KPS_Bot
{
public:
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        { return KIVI; }

        void botin_nimi(std::string &nimi)
        { nimi = "Open Kivi-Botti"; }
};


class Bot_Aina_Paperi : public KPS_Bot
{
public:
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        { return PAPERI; }

        void botin_nimi(std::string &nimi)
        { nimi = "Open Paperi-Botti"; }
};


class Bot_Aina_Sakset : public KPS_Bot
{
public:
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        { return SAKSET; }

        void botin_nimi(std::string &nimi)
        { nimi = "Open Sakset-Botti"; }
};


class Bot_GTO : public KPS_Bot
{
public:
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        { return (KPS)(rand() % 3); }

        void botin_nimi(std::string &nimi)
        { nimi = "Open GTO-Botti"; }
};


class Bot_Vaihda_Aina : public KPS_Bot
{
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        {
                if (kierros == 0) return (KPS)(rand() % 3);
                int r;
                do
                { r = rand() % 3; } while (r == omat[kierros - 1]);
                return (KPS)r;
        }

        void botin_nimi(std::string &nimi)
        { nimi = "Open Vaihda-Aina-Botti"; }
};


class Bot_Biittaa_Edellinen : public KPS_Bot
{
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        {
                if (kierros == 0) return (KPS)(rand() % 3);
                switch (vihun[kierros - 1])
                {
                case KIVI:              return PAPERI;  break;
                case PAPERI:    return SAKSET;  break;
                case SAKSET:    return KIVI;    break;
                }
        }

        void botin_nimi(std::string &nimi)
        { nimi = "Open Biittaa-Edellinen-Botti"; }
};
