#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


struct Point{
    int x,y,z;
};

void BenchVec();
void BenchList();
void BenchArr();
void Bench();
int menu();
Point ELEMENT();
int MAXSIZE();
void StackArr();
void StackVec();
void StackList();
void DemoArr();
void DemoVec();
void DemoList();
