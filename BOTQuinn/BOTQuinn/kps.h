#pragma once
#include <cstdlib>
#include <string>

typedef enum { KIVI = 0, PAPERI = 1, SAKSET = 2 } KPS;

// KPS-TURNAUS
// ======================================================================
// A) Yksi ottelu koostuu 1000 kierroksesta.
// B) Kaikki botit pelaavat ottelun kaikkia muita vastaan.
// C) Ottelun voitosta saa 2 pistettä, tasapelista 1 pisteen, haviosta 0.
// D) Molemmista boteista luodaan uudet instanssit ottelua varten.
// E) Botit saavat parametrina ko. ottelun historian.
// E) rand()-funktiota voi kayttaa, ala kayta srand():ia
// F) Botin tulee toimia todella nopeasti (1000 kierroksen ottelut!)
// G) Turnaukseen osallistuu muutamia "heikkoja" botteja
//    ("pelaa aina K/P/S", "vaihda aina", "biittaa vihun edellinen")
// H) Toteuta bottisi yhdessa headerissa, tulee kaantya edunixissa!
// ======================================================================

class KPS_Bot
{
public:
        virtual KPS pelaa(              // palauta KIVI/PAPERI/SAKSET!
                int kierros,            // kierroksen numero (0..999)
                const KPS *omat,        // omat  edelliset pelatut (0..kierros-1)
                const KPS *vihun        // vihun edelliset pelatut (0..kierros-1)
                ) = 0;

        // Aseta bottisi nimi
        virtual void botin_nimi(std::string &nimi) = 0;

        KPS_Bot() {}
        virtual ~KPS_Bot() {}
};

