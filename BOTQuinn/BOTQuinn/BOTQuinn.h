#pragma once
#include "kps.h"
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;

namespace std
{
    template<>
    struct hash<vector<int>>
    {
		size_t operator()(vector<int> const& vec) const{
			std::size_t seed = 0;
			for(auto& i : vec) {
				seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			}
			return seed;
		}

		bool operator()(vector<int> const& x, vector<int> const& y) const{
			return x == y;
		}
    };
}

class BOTQuinn : public KPS_Bot
{
private:
	unordered_map<vector<int>, vector<int>> hashmap;
	int ikkunakoko;
	vector<int> edellinen3, edellinen4, edellinen5;
	ofstream file;

	int laskeTodennakoisin(vector<int> maarat) {
		int ret = 0;
		float r = ((float) rand() / (RAND_MAX));
		int lkm = 0;
		for(int i = 0; i < 3; ++i) {
			lkm += maarat[i];
		}
		float kumul = 0;
		for(int i = 0; i < 3; i++) {
			kumul += maarat[i]/(float)lkm;
			if(r < kumul) {
				ret = i;
				break;
			}
		}
		return (ret + 1) % 3;
	}

	void paivitaMaarat(vector<int> key, int vihun)
	{
		auto it = hashmap.find(key);
		if( it != hashmap.end() ) {
			vector<int> maarat = it->second;
			++maarat[vihun];
			hashmap[key] = maarat;
		}
	}
public:
	BOTQuinn() {
		ikkunakoko = 3; //pienimm‰n ikkunan koko
		edellinen3 = vector<int>();
		edellinen4 = vector<int>();
		edellinen5 = vector<int>();
	}

	// Botin toimintalogiikka pelaa-funktioon!
	KPS pelaa(int kierros, const KPS *omat, const KPS *vihun) {
		int r = rand() % 3;

		//P‰ivitet‰‰n ikkunoiden arvot
		if(int(edellinen3.size()) != 0) {
			paivitaMaarat(edellinen3, vihun[kierros-1]);
		}

		if(int(edellinen4.size()) != 0) {
			paivitaMaarat(edellinen4, vihun[kierros-1]);
		}

		if(int(edellinen5.size()) != 0) {
			paivitaMaarat(edellinen5, vihun[kierros-1]);
		}

		if(kierros >= ikkunakoko) {
			vector<int> key3;
			vector<int> key4;
			vector<int> key5;
			//Haetaan aikaisempien kierrosten kombinaatioita ikkunoiksi
			for(int i = kierros - ikkunakoko - 2; i < kierros; i++){
				if(i > kierros - ikkunakoko - 1)
					key3.push_back(vihun[i]);
				if(kierros >= ikkunakoko - 1 && i > kierros - ikkunakoko)
					key4.push_back(vihun[i]);
				if(kierros >= ikkunakoko)
					key5.push_back(vihun[i]);
			}
			//Merkit‰‰n edellisell‰ kierroksella tulleeksi ikkunaksi
			edellinen3 = key3;
			edellinen4 = key4;
			edellinen5 = key5;

			auto it5 = hashmap.find(key5);
			vector<int> maarat (3,0);
			if ( it5 == hashmap.end() ) {  //Ei lˆydy 5 sarjaa
				hashmap.insert(make_pair(key5, maarat));
				auto it4 = hashmap.find(key4);
				if ( it4 == hashmap.end() ) {  //Ei lˆydy 4 sarjaa
					hashmap.insert(make_pair(key4, maarat));
					auto it3 = hashmap.find(key3);
					if ( it3 == hashmap.end() ) {  //Ei lˆydy 3 sarjaa
						hashmap.insert(make_pair(key4, maarat));
					} else {
						//Lˆytyy 3 sarja
						r = laskeTodennakoisin(it3->second);
					}
				} else {
					//Lˆytyy 4 sarja
					r = laskeTodennakoisin(it4->second);
				}
			} else {
				//Lˆytyy 5 sarja
				r = laskeTodennakoisin(it5->second);
			}
		}
		return (KPS) r;
	}

	// Keksi botille osuva nimi!
	void botin_nimi(std::string &nimi)
	{ nimi = "BOT Quinn"; }
};
