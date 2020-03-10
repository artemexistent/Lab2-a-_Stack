#include "Header.h"

class List{

public:
    List();
    ~List();

    void create_empty();
    void push( Point data );
    void pop();
    Point& peek();
    bool is_Empty();

private:
    class Node{
    public:
        Node *pPrev;
        Point data;

        Node( Point data = Point(), Node *pPrev = 0 ){
            this->data = data;
            this->pPrev = pPrev;
        }

    };
    int Size;
    Node *head;
};

List::List(){
    Size = 0;
    head = 0;
};
List::~List(){
};

void List::create_empty(){
    if ( Size != 0 ){
        Node *current = this->head;
        while ( current->pPrev != 0 ){
            current = current->pPrev;
            delete head;
        }
        delete head;
    }
    Size = 0;
}


void List::push( Point data ){
    Node *current = new Node(data);
    current->pPrev = this->head;
    this->head = current;
    Size ++;
    cout << "Item added\n";
}

void List::pop(){
    Node *current = this->head;
    current = current->pPrev;
    delete head;
    head = current;
    Size --;
}

Point & List::peek(){
    return this->head->data;
}

bool List::is_Empty(){
    if ( Size == 0 )
        return true;
    else return false;
}

void StackList(){
    List n;
    while (true){
        int answer = menu();
        switch ( answer ){
            case 0: n.create_empty(); system("pause"); break;
            case 1: n.push( ELEMENT() ); system("pause"); break;
            case 2: n.pop(); system("pause"); break;
            case 3: {Point a = n.peek(); cout << "(" << a.x << ", " << a.y << ", " << a.z << ")"; system("pause");} break;
            case 4: if ( n.is_Empty() ) cout << "This stack is empty\n"; else cout << "This stack isn't empty\n"; system("pause"); break;
        }
    }
}


void DemoList(){
    srand(time(0));
    List n;
    cout << "List\n";
    cout << "create_empty() size:";
    int Size = rand()%20 + 2;
    cout << Size - 1 << "\n";
    n.create_empty();
    Sleep(3000);
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
        Point a = n.peek();
        cout << "(" << a.x << ", " << a.y << ", " << a.z << ")     ";
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


void BenchList(){

    ofstream out("BechList.txt");
    srand(time(0));
    out << "List:  \n\n";
    clock_t start, end;

    start = clock();
    end = clock();
    List n;
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
    for (int i=0;i<Size-1;i++){
        n.peek();
        n.pop();
    }
    out << "Pop and Peek:" << Size << " " << ((double) end - start) / ((double) CLOCKS_PER_SEC) << ' ' << sizeof(Point)*Size;

    out.close();
    return;

}



