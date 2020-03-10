#include "Header.h"

class StackVEC{
    Point* a = new Point [20000] ;
    int Size = 0;
    int MaxSize;
    public:
    Stack(){}
    void create_empty(){ MaxSize = 2; Size = 0; delete[] a; };
    void push( Point res ){
        if ( MaxSize <= Size + 1 )
            MaxSize *= 2;
        Size ++;
        a[Size] = res;
        cout << "Item added\n";

    };
    void pop(){
        if ( Size == 0 ){
            cout << "This stack is already empty\n";
            return;
        }
        Size --;
        if ( MaxSize % 4 == 0 && MaxSize / 4 >= Size )
            MaxSize /= 4;
    };
    void peek(){
        if ( Size == 0 ){
            cout << "This stack is empty\n";
        }else cout << "(" << a[Size].x << ", " << a[Size].y << ", " << a[Size].z << ")" << "   ";
    };
    bool is_Empty(){ if ( Size > 0 ) return false; return true; };
};


void StackVec(){
    StackVEC n;
    while (true){
        int answer = menu();
        switch ( answer ){
            case 0: n.create_empty(); system("pause"); break;
            case 1: n.push( ELEMENT() ); system("pause"); break;
            case 2: n.pop(); system("pause"); break;
            case 3: n.peek(); system("pause"); break;
            case 4: if ( n.is_Empty() ) cout << "This stack is empty\n"; else cout << "This stack isn't empty\n"; system("pause"); break;
        }
    }
}
void DemoVec(){
    srand(time(0));
    StackVEC n;
    cout << "Vector\n";
    cout << "create_empty() size:";
    int Size = rand()%20;
    cout << Size - 1 << "\n";
    n.create_empty();
    Sleep(3000);
    Size += 5;
    for ( int i = 0;i < Size;i ++ ){
        cout << "push() element:";
        Point a;
        a.x = rand()%1000;
        a.y = rand()%1000;
        a.z = rand()%1000;
        cout << "(" << a.x << ", " << a.y << ", " << a.z << ")     ";
        n.push(a);
        Sleep(500);
    }
    cout << "\n\n\n";
    cout << "is_Empty()   ";
    if ( n.is_Empty() ) cout << "This stack is empty\n"; else cout << "This stack isn't empty\n";
    Sleep(3000);
    cout << "\n\n\n";
    for (int i = 0;i < Size;i ++ ){
        cout << "peek()  " ;
        n.peek();
        Sleep(500);
        cout << "pop()\n";
        n.pop();
        Sleep(500);
    }
    cout << "\n\n\n";
    cout << "is_Empty()   ";
    if ( n.is_Empty() ) cout << "This stack is empty\n"; else cout << "This stack isn't empty\n";
    system("pause");

}


void BenchVec(){

    ofstream out("BechVec.txt");
    srand(time(0));
    out << "Vector:  \n\n";
    clock_t start, end;

    start = clock();
    end = clock();
    StackVEC n;
    int Size = 20000;

    n.create_empty();
    for (int i=0;i<Size;i++){
        Point a;
        a.x = rand()%1000;
        a.y = rand()%1000;
        a.z = rand()%1000;
        n.push(a);
    }
    out << "Push:" << Size << " " << ((double) end - start) / ((double) CLOCKS_PER_SEC) << ' ' << sizeof(Point)*Size << "\n";

    start = clock();
    end = clock();
  /*  for (int i=0;i<Size-1;i++){
        n.peek();
        n.pop();
    }*/
    out << "Pop and Peek:" << Size << " " << ((double) end - start) / ((double) CLOCKS_PER_SEC) << ' ' << sizeof(Point)*Size;

    out.close();
    return;

}

