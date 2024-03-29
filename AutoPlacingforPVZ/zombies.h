#ifndef ZOMBIES_H
#define ZOMBIES_H
#pragma once
#include <iostream>
#include <string>
#include <array>
#include <windows.h>
#include <chrono>
#include <tlhelp32.h>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <initializer_list>
#include <unordered_set>
#include <conio.h>
#include "gameinfo.h"
using namespace std;
void PlaceZombie(int row, int col, int type);
void ZombieColumPlace(int,int);
void KillAllZombies();
#endif // ZOMBIES_H
