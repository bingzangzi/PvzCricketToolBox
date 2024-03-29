#ifndef PLANT_FORMATION_H
#define PLANT_FORMATION_H
#pragma once
#include <iostream>
#include <string>
#include <array>
#include <windows.h>
#include <chrono>
#include <thread>
#include <tlhelp32.h>
#include <vector>
#include <random>
#include <initializer_list>
#include <unordered_set>
#include <QMessageBox>
#include "process_op.h"
using namespace std;


//植物阵容操作
void RandInit(vector<int> allow, vector<int> gift);//设定有用和附赠植物
int RandForm(bool**);
void PlacePlant(int row, int col, int type);
void CustomForm();
void CustomSingle();
void ClearAllPlants();
void DeleteSinglePlant(int,int,int);
void AnimatedWhenPlant(int,int);
void DeleteGivenPlant(uint32_t Offset);
void DeleteGivenAddrPlant(uint32_t addr);
#endif // PLANT_FORMATION_H
