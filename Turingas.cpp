#include "stdafx.h"




#include <iostream>
#include <fstream> // failam
#include <string> // stringai
#include <chrono> // laikui
#include <thread> // pausint procesa
using namespace std;

struct tiuringas {
	string ebus;
	char esimb;
	char nsimb;
	char kryptis;
	string nbus;};
int main()
{
	int headeris, i(0);
	string juosta;
	tiuringas A[100];
	ifstream fd("2.txt"); // txt failas
	fd >> headeris; // headerio vieta
	fd >> juosta; // visa juosta nuskaito
	while (!fd.eof()) // skaitys po viena kol nesibaigs failas
	{
		fd >> A[i].ebus >> A[i].esimb >> A[i].nsimb >> A[i].kryptis >> A[i].nbus; // visos tiuringo instrukcijos
		i++;
	}
	i--;

	int ilg1 = juosta.length();        // juostos eilutes ilgis baitais
	string k = "0";                // laikinas kintamasis pozicijai
	while (headeris != juosta[ilg1 - 1] || k != "X")        // kol nesibaigs eilutes tol nebaigs darbo nebent bus X.
	{
		for (int g = 0; g < i; g++) {
			if (A[g].ebus == k)     // ar dabartine busena sutampa su laikina
			{
				if (A[g].esimb == juosta[headeris]) // jeigu esamas simbolis sutampa su hederio pozicijoj esamu skaiciu vykdo toliau
				{
					juosta[headeris] = A[g].nsimb;          // pakeicia skaiciu juostoje
					k = A[g].nbus;                // nauja busena
					if (A[g].kryptis == 'R')           // jei R juda i desine
						headeris++;
					else if (A[g].kryptis == 'L') // jei L juda i kaire
						headeris--;
				}
			}

		}
		using namespace std::this_thread;
		using namespace std::chrono;
		sleep_for(nanoseconds(2500000));// Suletina eilutes keitima
		cout << juosta << '\r' << flush; //	keicia eilute

	}
	return 0;
}