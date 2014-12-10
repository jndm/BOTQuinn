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
	vector<int> edellinen;
	ofstream file;

	int laskeTodennakoisin(vector<int> maarat)
	{
		int max = -1;
		for(int i = 0; i < 3; ++i)
			max = max < maarat.at(i) ? i : max;
		return (max + 1) % 3;
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
		ikkunakoko = 4;
		edellinen = vector<int>();
		file.open("log.txt");
		file << "-" << endl;
	}

	~BOTQuinn(){
		file.close();
	}

	// Botin toimintalogiikka pelaa-funktioon!
	KPS pelaa(int kierros, const KPS *omat, const KPS *vihun) {
		int r = rand() % 3;
		if(int(edellinen.size()) != 0) {
			paivitaMaarat(edellinen, vihun[kierros-1]);
		}
		if(kierros >= ikkunakoko) {
			vector<int> key;
			for(int i = kierros - ikkunakoko; i < kierros; i++){
				key.push_back(vihun[i]);
			}
			edellinen = key;

			auto it = hashmap.find(key);
			if ( it == hashmap.end() ) {
				//Ei löydy
				vector<int> maarat (3,0);
				hashmap.insert(make_pair(key, maarat));
			} else {
				//Löytyy
				r = laskeTodennakoisin(it->second);
			}
		}
		for(auto iterator = hashmap.begin(); iterator != hashmap.end(); iterator++){
			for(auto iterator2 = iterator->first.begin(); iterator2 != iterator->first.end(); iterator2++){
				file << *iterator2;
			}
			file << " ";
			for(auto iterator2 = iterator->second.begin(); iterator2 != iterator->second.end(); iterator2++){
				file << *iterator2 << "|";
			}
			file << endl;
		}
		return (KPS) r;
	}

	// Keksi botille osuva nimi!
	void botin_nimi(std::string &nimi)
	{ nimi = "BOT Quinn"; }
};
