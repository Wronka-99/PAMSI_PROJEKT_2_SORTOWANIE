#ifndef sort_hh
#define sort_hh
#include "film.hh"
#include <iostream>

using namespace std;

//######################################################
//#############          QUICKSORT       ###############
//######################################################
void quickSort( film *tab, long l, long p )
{
	long i = l;
	long j = p;
	int x = tab[ ( i + j ) / 2 ].ocena_konwersja;

	while ( i < j )
	{
		while ( tab[ i ].ocena_konwersja < x ) i++;
		while ( tab[ j ].ocena_konwersja > x ) j--;

		if ( i <= j )
		{
			film pom = tab[ i ];
			tab[ i ] = tab[ j ];
			tab[ j ] = pom;
			i++;
			j--;
		}
	}
	if ( l < j )
		quickSort( tab, l, j );
	if ( i < p )
		quickSort( tab, i, p );
}
//#######################################################






//######################################################
//#############          MERGESORT       ###############
//######################################################

void merge(film *lista_film, int lewy_index, int srodek, int prawy_index) {
   int i, j, k;
   
   int rozm_lewa = srodek-lewy_index+1;                                     //rozmiary lewej i prawej podtablicy
   int rozm_prawa = prawy_index-srodek;

   film *lewa_tab=new film[rozm_lewa];                                      //tworzenie podtablic dynamicznych
   film *prawa_tab = new film[rozm_prawa];
   
   for(i = 0; i<rozm_lewa; i++)
      lewa_tab[i] = lista_film[lewy_index+i];                               //uzupelnianie lewej tablicy

   for(j = 0; j<rozm_prawa; j++)
      prawa_tab[j] = lista_film[srodek+1+j];                                //uzupelnianie prawej tablicy

   i = 0; j = 0; k = lewy_index;
   
   while(i < rozm_lewa && j<rozm_prawa) 
   {
      if(lewa_tab[i].ocena_konwersja <= prawa_tab[j].ocena_konwersja)       //sprawdzanie wartości 
      {
         lista_film[k] = lewa_tab[i];                                       //jesli ocena rowna badz mniejsza z lewej tablicy to ja wstawiamy do listy filmow 
         i++;
      }
      else
      {
         lista_film[k] = prawa_tab[j];                                      //jesli ocena jest wieksza z prawej tablicy to ja wstawiamy do listy filmow 
         j++;
      }
      k++;
   }


   while(i<rozm_lewa)                                                       //jesli poprzednia petla while nie wyczerpala indeksow z lewej tablicy
   {                                                                        //to przypisuje wartość do listy filmow
      lista_film[k] = lewa_tab[i];
      i++; k++;
   }


   while(j<rozm_prawa) 
   {                                                                        //jesli poprzednia petla while nie wyczerpala indeksow z prawej tablicy
      lista_film[k] = prawa_tab[j];                                         //to przypisuje wartość do listy filmow
      j++; k++;
   }

   delete [] lewa_tab;
   delete [] prawa_tab;
}



void mergeSort(film *tab_filmow, int lewy_index, int prawy_index) {
   
   if(lewy_index < prawy_index) {
      int srodek = lewy_index+(prawy_index-lewy_index)/2;  //wyznaczanie srodkowego indeksu
      mergeSort(tab_filmow, lewy_index, srodek);           //dzielenie tablicy po prawej stronie od srodka na dwie mniejsze
      mergeSort(tab_filmow, srodek+1, prawy_index);        //dzielenie tablicy po lewej stronie od srodka na dwie mniejsze
      merge(tab_filmow, lewy_index, srodek, prawy_index);  //odwołanie do funkcji sortującej wartośći
   }
}




//######################################################
//#############          MERGESORT       ###############
//######################################################

void sort_kubelkowe(film *lista_filmow, int rozmiar)
{
    
    int tablica_licznikow[11]= {0,0,0,0,0,0,0,0,0,0,0};
    film **kubelki = new film*[11];

    for(int i = 0; i < 11; ++i)                                         //tworzenie kubełków
    {
         kubelki[i] = new film[rozmiar];
    }


    for(int index=0; index<rozmiar;index++)                             //przypisywanie filmów kubełkom
    {
        for(int a=0; a<11;a++)
        {
            if(lista_filmow[index].ocena_konwersja==a)
            {
                kubelki[a][tablica_licznikow[a]]=lista_filmow[index];
                tablica_licznikow[a]++;
            }
        }  
    }

    int licznik_przypisania=0;

    for(int index=0; index<11;index++)                                   //przypisywanie wartości kubełków do listy filmów
    {
        for(int a=0; a<tablica_licznikow[index];a++)
        {
            lista_filmow[licznik_przypisania]=kubelki[index][a];
            licznik_przypisania++;
        }
    }

        delete [] kubelki;
}


/*
void sort_kubelkowe(film *lista_filmow, int rozmiar)
{
    
    int tablica_licznikow[11]= {0,0,0,0,0,0,0,0,0,0,0};
  

    film *kubelek_0= new film[rozmiar];
    film *kubelek_1= new film[rozmiar];
    film *kubelek_2= new film[rozmiar];
    film *kubelek_3= new film[rozmiar];
    film *kubelek_4= new film[rozmiar];
    film *kubelek_5= new film[rozmiar];
    film *kubelek_6= new film[rozmiar];
    film *kubelek_7= new film[rozmiar];
    film *kubelek_8= new film[rozmiar];
    film *kubelek_9= new film[rozmiar];
    film *kubelek_10= new film[rozmiar];

    for(int index=0; index<rozmiar;index++)
    {
        if(lista_filmow[index].ocena_konwersja==0)
        {
            kubelek_0[tablica_licznikow[0]]=lista_filmow[index];
            tablica_licznikow[0]++;
        }

        if(lista_filmow[index].ocena_konwersja==1)
        {
            kubelek_1[tablica_licznikow[1]]=lista_filmow[index];
            tablica_licznikow[1]++;
        }

        if(lista_filmow[index].ocena_konwersja==2)
        {
            kubelek_2[tablica_licznikow[2]]=lista_filmow[index];
            tablica_licznikow[2]++;
        }

        if(lista_filmow[index].ocena_konwersja==3)
        {
            kubelek_3[tablica_licznikow[3]]=lista_filmow[index];
            tablica_licznikow[3]++;
        }

        if(lista_filmow[index].ocena_konwersja==4)
        {
            kubelek_4[tablica_licznikow[4]]=lista_filmow[index];
            tablica_licznikow[4]++;
        }

        if(lista_filmow[index].ocena_konwersja==5)
        {
            kubelek_5[tablica_licznikow[5]]=lista_filmow[index];
            tablica_licznikow[5]++;
        }

        if(lista_filmow[index].ocena_konwersja==6)
        {
            kubelek_6[tablica_licznikow[6]]=lista_filmow[index];
            tablica_licznikow[6]++;
        }

        if(lista_filmow[index].ocena_konwersja==7)
        {
            kubelek_7[tablica_licznikow[7]]=lista_filmow[index];
            tablica_licznikow[7]++;
        }

        if(lista_filmow[index].ocena_konwersja==8)
        {
            kubelek_8[tablica_licznikow[8]]=lista_filmow[index];
            tablica_licznikow[8]++;
        }

        if(lista_filmow[index].ocena_konwersja==9)
        {
            kubelek_9[tablica_licznikow[9]]=lista_filmow[index];
            tablica_licznikow[9]++;
        }

         if(lista_filmow[index].ocena_konwersja==10)
        {
            kubelek_10[tablica_licznikow[10]]=lista_filmow[index];
            tablica_licznikow[10]++;
        }

    }

        int licznik_przypisania=0;

        

            for(int licznik=0;licznik<tablica_licznikow[0]; licznik++)
            {
                lista_filmow[licznik_przypisania]=kubelek_0[licznik];
                licznik_przypisania++;
            }

             for(int licznik=0;licznik<tablica_licznikow[1]; licznik++)
            {
                lista_filmow[licznik_przypisania]=kubelek_1[licznik];
                licznik_przypisania++;
            }

             for(int licznik=0;licznik<tablica_licznikow[2]; licznik++)
            {
                lista_filmow[licznik_przypisania]=kubelek_2[licznik];
                licznik_przypisania++;
            }

             for(int licznik=0;licznik<tablica_licznikow[3]; licznik++)
            {
                lista_filmow[licznik_przypisania]=kubelek_3[licznik];
                licznik_przypisania++;
            }

             for(int licznik=0;licznik<tablica_licznikow[4]; licznik++)
            {
                lista_filmow[licznik_przypisania]=kubelek_4[licznik];
                licznik_przypisania++;
            }

             for(int licznik=0;licznik<tablica_licznikow[5]; licznik++)
            {
                lista_filmow[licznik_przypisania]=kubelek_5[licznik];
                licznik_przypisania++;
            }

             for(int licznik=0;licznik<tablica_licznikow[6]; licznik++)
            {
                lista_filmow[licznik_przypisania]=kubelek_6[licznik];
                licznik_przypisania++;
            }

             for(int licznik=0;licznik<tablica_licznikow[7]; licznik++)
            {
                lista_filmow[licznik_przypisania]=kubelek_7[licznik];
                licznik_przypisania++;
            }

             for(int licznik=0;licznik<tablica_licznikow[8]; licznik++)
            {
                lista_filmow[licznik_przypisania]=kubelek_8[licznik];
                licznik_przypisania++;
            }

             for(int licznik=0;licznik<tablica_licznikow[9]; licznik++)
            {
                lista_filmow[licznik_przypisania]=kubelek_9[licznik];
                licznik_przypisania++;
            }

             for(int licznik=0;licznik<tablica_licznikow[10]; licznik++)
            {
                lista_filmow[licznik_przypisania]=kubelek_10[licznik];
                licznik_przypisania++;
            }
        
    
        delete [] kubelek_0;
        delete [] kubelek_1;
        delete [] kubelek_2;
        delete [] kubelek_3;
        delete [] kubelek_4;
        delete [] kubelek_5;
        delete [] kubelek_6;
        delete [] kubelek_7;
        delete [] kubelek_8;
        delete [] kubelek_9;
        delete [] kubelek_10;




}
*/



  




//######################################################

#endif