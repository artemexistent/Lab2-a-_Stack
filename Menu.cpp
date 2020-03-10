#include "Header.h"

int menu() {
    int key = 0;
    int code;
    do {
        system( "cls" );
        key = ( key + 5 ) % 5;
        if ( key == 0 ) cout<<"-> create_empty"<<endl;
            else  cout<<"   create_empty"<<endl;
        if ( key == 1 ) cout<<"-> push"<<endl;
            else  cout<<"   push"<<endl;
        if ( key == 2 ) cout<<"-> pop"<<endl;
            else  cout<<"   pop"<<endl;
        if ( key == 3 ) cout<<"-> peek"<<endl;
            else  cout<<"   peek"<<endl;
        if ( key == 4 ) cout<<"-> is_Empty"<<endl;
            else  cout<<"   is_Empty"<<endl;
        code = _getch();
        if ( code == 224 ){
            code = _getch();
            if ( code == 80 ) key ++;
            if ( code == 72 ) key --;
        }
        if ( code == 27 ){
            system( "cls" );
            exit(0);
        }
    }while( code != 13 );
    system( "cls" );
    return key;
}



int MAXSIZE(){

    int Kol;

    cout << "VVedite max kolvo:";

    cin >> Kol;

    return Kol;

}

Point ELEMENT(){

    Point a;

    cout << "Vvedite element\nx:";

    cin >> a.x;
    cout << "y:";
    cin >> a.y;
    cout << "z:";
    cin >> a.z;


    return a;

}
