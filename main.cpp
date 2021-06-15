#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <ctime>

#include "film.hh"
#include "sort.hh"
#include "Statystyka.hh"
using namespace std;

int main()
{
    int rozmiar=10000;
    
    film *lista_wczytanych_filmow= new film[rozmiar];
  
    string znaki_w_lini;
    int dlugosc;
    char znak ;
    char liczba[]={'0','0','0','0','0'};
    int zmienna_pomocnicza=0;
    int odczyt=0;
    int odczyt_2=0;
    char tryb;
    int liczba_filmow_z_ocenami=0;
    char sprawdzenie_liczby;
    char sprawdzenie_kropki;
    int dzialanie=0;
    ifstream baza_filmow;
    baza_filmow.open("projekt2_dane2.csv");

    
    //getline(baza_filmow,znaki_w_lini);
   // cout<<znaki_w_lini<<endl;
/*
* Poniżej znajduje sie kod odpowiedzialny za wczytywanie
* danych o filmie.
*
*/
//##########################################################################################

clock_t startd = clock();

    for(long a=0; a<rozmiar; a++)
    { 
        /*
         //getline(baza_filmow,znaki_w_lini);
         znaki_w_lini="\"Szeregowiec,,";
         dlugosc = znaki_w_lini.size(); 

        
            
            tryb=znaki_w_lini[dlugosc-1];
            sprawdzenie_liczby=znaki_w_lini[dlugosc-2];
            sprawdzenie_kropki=znaki_w_lini[dlugosc-3];

            if(tryb==','&&sprawdzenie_liczby==',')
            {



            } 
            else if(tryb=='0'&&sprawdzenie_liczby=='.')
            {
                zmienna_pomocnicza=0;
                dzialanie=0;

                while(dzialanie==0)
                {
                    zmienna_pomocnicza++;
                    znak=znaki_w_lini[dlugosc-zmienna_pomocnicza];

                    if(znak==',')
                    {
                        dzialanie=1;
                    }else{
                        liczba[5-zmienna_pomocnicza]=znak;
                        
                    }
                }
                

                
                lista_wczytanych_filmow[liczba_filmow_z_ocenami].ocena=liczba;
                znaki_w_lini.resize(dlugosc-zmienna_pomocnicza+1);
                lista_wczytanych_filmow[liczba_filmow_z_ocenami].nazwa=znaki_w_lini;
                lista_wczytanych_filmow[liczba_filmow_z_ocenami].ocena_konwersja=stoi(lista_wczytanych_filmow[a].ocena);

                liczba_filmow_z_ocenami++;
                zmienna_pomocnicza=0;
                odczyt=0;

                for(int c=0; c<5; c++)
                {
                    liczba[c]='0';
                } 
            } 
            else if(tryb==','&&sprawdzenie_liczby=='0'&&sprawdzenie_kropki=='.')
            {
                zmienna_pomocnicza=0;
                dzialanie=0;

                while(dzialanie==0)
                {
                    zmienna_pomocnicza++;
                    znak=znaki_w_lini[dlugosc-zmienna_pomocnicza-1];
                    if(znak==',')
                    {
                        dzialanie=1;
                    }else{
                        liczba[5-zmienna_pomocnicza]=znak;
                        
                    }
                }



                lista_wczytanych_filmow[liczba_filmow_z_ocenami].ocena=liczba;
                znaki_w_lini.resize(dlugosc-zmienna_pomocnicza+1);
                lista_wczytanych_filmow[liczba_filmow_z_ocenami].nazwa=znaki_w_lini;
                lista_wczytanych_filmow[liczba_filmow_z_ocenami].ocena_konwersja=stoi(lista_wczytanych_filmow[a].ocena);

                liczba_filmow_z_ocenami++;
                zmienna_pomocnicza=0;
                odczyt=0;

                for(int c=0; c<5; c++)
                {
                    liczba[c]='0';
                } 
            }
        
                 
        */
       
        
        getline(baza_filmow,znaki_w_lini);
     // znaki_w_lini="\"Szeregowiec\",,";
        dlugosc = znaki_w_lini.size(); 
        
         while(odczyt<2&&odczyt_2<1)
        {   
            znak=znaki_w_lini[dlugosc-zmienna_pomocnicza];
            tryb=znaki_w_lini[dlugosc-1];
            

            
            if(tryb==','&&zmienna_pomocnicza==0)
            {
                tryb=',';
            }
            else if(zmienna_pomocnicza==0)
            {
               tryb='0'; 
            }
            

            switch(tryb)
            {

                case ',':
                    if(znak==',')
                    {
                        odczyt++;
                    }
                    else 
                    {   
                        
                        liczba[5-zmienna_pomocnicza]=znak;
                    }

                    
                break;

                case '0':
                        
                        if(znak==',')
                        {
                            odczyt_2=1;
                        }else
                        {
                           liczba[5-zmienna_pomocnicza]=znak; 
                        }
                        
                        
                break;
            }
            zmienna_pomocnicza++; 
        }

        lista_wczytanych_filmow[a].ocena=liczba;
        znaki_w_lini.resize(dlugosc-zmienna_pomocnicza+1);
        lista_wczytanych_filmow[a].nazwa=znaki_w_lini;
        lista_wczytanych_filmow[a].ocena_konwersja=stoi(lista_wczytanych_filmow[a].ocena);
        zmienna_pomocnicza=0;
        odczyt=0;
        odczyt_2=0;
        for(int c=0; c<5; c++)
        {
            liczba[c]='0';
        } 
        
        
        
    }


    int rozmiar2=0;
   for( int i = 0; i<rozmiar; i++)
   {
       if(lista_wczytanych_filmow[i].ocena_konwersja>0)
            rozmiar2++;
   }

    film *lista_wczytanych_filmow2 = new film[rozmiar2];

    for(int a=0; a<rozmiar2; a++)
   {
       lista_wczytanych_filmow2[a]=lista_wczytanych_filmow[rozmiar-rozmiar2+a-1];
   }

    clock_t stopd = clock();
    double czas_czytania = (stopd-startd)/(double)CLOCKS_PER_SEC;
//############################################################################################
   

  
   


    
    film *lista_quick = new film[rozmiar];
    film *lista_merge = new film[rozmiar];
    film *lista_kubelkowa = new film[rozmiar];

  



    for(int index=0; index<rozmiar2; index++)
    {
        lista_quick[index]=lista_wczytanych_filmow2[index];
        lista_merge[index]=lista_wczytanych_filmow2[index];
        lista_kubelkowa[index]=lista_wczytanych_filmow2[index];
    }
    
    clock_t starta =clock();
    quickSort(lista_quick,0,rozmiar2-1);
    clock_t stopa = clock();
    double czas_quick = (stopa-starta)/(double)CLOCKS_PER_SEC;


    clock_t startb =clock();
    mergeSort(lista_merge,0,rozmiar2-1);
    clock_t stopb = clock();
    double czas_merge = (stopb-startb)/(double)CLOCKS_PER_SEC;

    clock_t startc =clock();
    sort_kubelkowe(lista_kubelkowa,rozmiar2);
    clock_t stopc = clock();
    double czas_kubelkowe = (stopc-startc)/(double)CLOCKS_PER_SEC;

    film popr_merge;
    film popr_quick;
    film popr_kub;

    popr_merge.ocena_konwersja=0;
    popr_quick.ocena_konwersja=0;
    popr_kub.ocena_konwersja=0;

    for(int a=0; a<rozmiar2; a++)
    {
        if(lista_merge[a].ocena_konwersja<popr_merge.ocena_konwersja)
        {
            cout<<"Tablica merge posortowana niepoprawnie dla elementu numer: "<<a<<endl;   
            cout<<"Film poprzedni: "<<lista_kubelkowa[a-1].nazwa<<" o rankingu: "<<lista_kubelkowa[a-1].ocena_konwersja<<".  Film obecny: "<< lista_kubelkowa[a].nazwa<<" o rankingu:"<<lista_kubelkowa[a].ocena_konwersja<<endl;
        }
        
         if(lista_quick[a].ocena_konwersja<popr_quick.ocena_konwersja)
         {
            cout<<"Tablica quick posortowana niepoprawnie dla elementu numer:"<<a<<endl; 
            cout<<"Film poprzedni: "<<lista_kubelkowa[a-1].nazwa<<" o rankingu: "<<lista_kubelkowa[a-1].ocena_konwersja<<".  Film obecny: "<< lista_kubelkowa[a].nazwa<<" o rankingu:"<<lista_kubelkowa[a].ocena_konwersja<<endl;
        }  
        
        if(lista_kubelkowa[a].ocena_konwersja<popr_kub.ocena_konwersja)
        {
            cout<<"Tablica kubelkowa posortowana niepoprawnie dla elementu numer:"<<a<<endl;  
            cout<<"Film poprzedni: "<<lista_kubelkowa[a-1].nazwa<<" o rankingu: "<<lista_kubelkowa[a-1].ocena_konwersja<<".  Film obecny: "<< lista_kubelkowa[a].nazwa<<" o rankingu:"<<lista_kubelkowa[a].ocena_konwersja<<endl;
        }
        
        popr_quick=lista_quick[a];
        popr_merge=lista_merge[a];
        popr_kub=lista_kubelkowa[a];
    }

    cout<<"##########################################################################################"<<endl;
    cout<<"#########################          ALGORYTMY SORTOWANIA          #########################"<<endl;
    cout<<"##########################################################################################"<<endl<<endl;
    cout<<"Czas odczytywania danych z pliku wyniósł:  "<<czas_czytania<<"s."<<endl<<endl;
    cout<<"Liczba filmów do postowania: "<<rozmiar<<" ."<<endl;
    cout<<"Czas dzialnia dla algorytmu quickSort (szybkie sortowanie) wyniósł:"<<czas_quick<<"s."<<endl;
    statystyka(lista_quick,rozmiar2);
    cout<<"Czas dzialnia dla algorytmu mergeSort (sortowanie przez scalanie) wyniósł:"<<czas_merge<<"s."<<endl;
    statystyka(lista_merge,rozmiar2);
    cout<<"Czas dzialnia dla algorytmu kubełkowego wyniósł:"<<czas_kubelkowe<<"s."<<endl;
    statystyka(lista_kubelkowa,rozmiar2);
   
    cout<<"##########################################################################################"<<endl;
    cout<<"##########################################################################################"<<endl;
    
   // for(int a=0; a<10;a++)
   //   cout<<"Lista kubelkowa:"<<lista_kubelkowa[a].nazwa<<lista_kubelkowa[a].ocena_konwersja<<endl;


    delete [] lista_wczytanych_filmow;
    delete [] lista_quick;
    delete [] lista_merge;
    delete [] lista_kubelkowa;
    delete [] lista_wczytanych_filmow2;
   
    return 0;
}


