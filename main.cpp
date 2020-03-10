#include "Header.h"

int Menu(){
    int key = 0;
    int code;
    do {
        system( "cls" );
        cout << "Choose:\n";
        key = ( key + 3 ) % 3;
        if ( key == 0 ) cout<<"-> Interactive"<<endl;
            else  cout<<"   Interactive"<<endl;
        if ( key == 1 ) cout<<"-> Demonstration"<<endl;
            else  cout<<"   Demonstration"<<endl;
        if ( key == 2 ) cout<<"-> Benchmark"<<endl;
            else  cout<<"   Benchmark"<<endl;
        code =  _getch();
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


int StartMenu() {
    int key = 0;
    int code;
    do {
        system( "cls" );
        cout << "Choose:\n";
        key = ( key + 3 ) % 3;
        if ( key == 0 ) cout<<"-> Array"<<endl;
            else  cout<<"   Array"<<endl;
        if ( key == 1 ) cout<<"-> Vector"<<endl;
            else  cout<<"   Vector"<<endl;
        if ( key == 2 ) cout<<"-> List"<<endl;
            else  cout<<"   List"<<endl;
        code =  _getch();
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

int Body(){
    int answer = StartMenu();
    switch ( answer ){
        case 0: StackArr(); break;
        case 1: StackVec(); break;
        case 2: StackList(); break;
    }
}


int main(){
    int answer = Menu();
    switch ( answer ){
        case 0: Body(); break;
        case 1: DemoArr(); system("cls"); DemoVec(); system("cls"); DemoList(); break;
        case 2: Bench(); break;
    }
}
