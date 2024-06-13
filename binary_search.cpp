#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void q_sort( int tab[], int left, int right ){
    int i = left;
    int j = right;
    int y = tab[( left + right ) / 2 ];
    do{
        while( tab[i] < y ) i++;
        while( tab[j] > y ) j--;
        if( i <= j )  {
            swap( tab[i], tab[j] );
            i++;
            j--;
        }
    } while( i <= j );
    if( left < j ) q_sort( tab, left, j );
    if( right > i ) q_sort( tab, i, right );
}

int binary_search(int tab[], int want, int left, int right){
    int piv = round((float)(right+left)/2);
    if(tab[piv]==want) return tab[piv];
    if(right-1==left) return tab[piv];
    else if(tab[piv]>want) binary_search(tab, want, left, piv);
    else if(tab[piv]<want) binary_search(tab, want, piv, right);
    else return tab[piv];
}

int main(){
	srand(time(nullptr));
	int tablica[20];
	int wanted;

	for(int i=0; i<20; i++){
		tablica[i]=rand()%100;
		cout << tablica[i] << endl;
	}
	q_sort(tablica, 0, 19);
	cout << endl << endl;
	for(int i=0; i<20; i++){
		cout << i << ": " << tablica[i] << endl;
	}
	cout << "podaj szukany: " << endl;
	cin >> wanted;
	cout <<  binary_search(tablica, wanted, 0, 19) << endl;

    cin.clear();
	cin.ignore();
	cin.get();
	return 0;
}