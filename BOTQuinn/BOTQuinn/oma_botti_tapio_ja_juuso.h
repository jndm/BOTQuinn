#pragma once

#include "kps.h"
#include <stdlib.h>
#include <time.h>

// Keksi luokallesi uusi nimi!
class Oma_Botti_Tapio_Ja_Juuso : public KPS_Bot
{
public:
        // Botin toimintalogiikka pelaa-funktioon! (kierrokset 0-999)
        KPS pelaa(int kierros,  const KPS *omat, const KPS *vihun)
        {

	  // ensimmäisellä kieroksella ei ole saatavilla tietoa kuitenkaan
	  if (kierros <4){ return PAPERI; } 
	  
	  // jos joku botti pelaa vain samaa, bustataan se
	  int K = 0;
	  int P = 0;
	  int S = 0;
	  int i;
	  for(i = 1 ; i < kierros; i++){
	    if(vihun[kierros-1] == KIVI){ K++;}
	    else if(vihun[kierros-1] == SAKSET){ S++;}
	    else{ P++;}
	  }
	  {  
	  if(K == 0 && P == 0){ return KIVI;}
	  if(K == 0 && S == 0){ return SAKSET;}
	  if(S == 0 && P == 0){ return PAPERI;}
	  };
	  //jos pelannut minun edellisen
	  if (kierros > 12){
	    int i=kierros;
	    int j = i - 8;
	    bool pelEde = false;
	    for (; j < i ; i--){ // katsotaan viimeiset 5 kierrosta
	      if (omat[i - 2] == KIVI && vihun[i - 1] == PAPERI){ pelEde = true; }
	      else if (omat[i - 2] == PAPERI && vihun[i - 1] == SAKSET){ pelEde = true; }
	      else if (omat[i - 2] == SAKSET && vihun[i - 1] == KIVI){ pelEde = true; }
	      else { pelEde = false; }
	    }
	    if (pelEde){ //vihu on valinnut aina oman botin edellisen => rankaistaan
	      if (omat[kierros-1] == KIVI){ return SAKSET; }
	      else if (omat[kierros-1] == PAPERI){ return KIVI; }
	      else { return PAPERI; }
	    }
	  }
	  
	  //jos botti ei valitse koskaan samaa
	  if (kierros > 12){
	    int i = kierros;
	    int j = i - 10;
	    bool vaihtaaAina = true;
	    for (; j < i ; i--){ // katsotaan viimeiset 5 kierrosta
	      if (vihun[i - 2] != vihun[i - 1]){ vaihtaaAina = false; }
	    }
	    if (vaihtaaAina){ //vihu on valinnut aina oman botin edellisen => rankaistaan
	      switch (vihun[kierros - 1])
		{
		case KIVI:
		  return SAKSET;
		case SAKSET:
		  return PAPERI;
		case PAPERI:
		  return KIVI;
		}
	    }
	  }
	  /*	  
	  //jos ei mikään näistä
	  if (kierros > 120 && kierros < 140){ return KPS(kierros % 3); }
	  if (kierros > 350 && kierros < 370){ return KPS(kierros % 3); }
	  
	  if (kierros > 600 && kierros < 620){ return SAKSET; }
	  if (kierros > 800 && kierros < 820){ return vihun[kierros - 1]; }
	  */
	  return randomValinta();
	  
	}
	
        // Keksi botille osuva nimi!
        void botin_nimi(std::string &nimi)
	{ nimi = "-=pihvib0tti=-"; }
	
 private:
	
	KPS randomValinta(){
	  
	  int rnd;
	  srand(time(NULL));
	  rnd = rand() % 3;
	  
	  return KPS(rnd);
	}
};
