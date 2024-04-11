#ifndef PLANTSOPERATION_H
#define PLANTSOPERATION_H
#pragma once
#include <vector>
#include <QThread>
#include <QString>
#include <random>
#include <chrono>
#include <thread>
#include <QTextStream>
#include <QRegularExpression>
#include <unordered_set>
#include "game_info.h"
extern HANDLE pvzHand;
extern QTextStream out;

struct PlantInfoStruct{
    int type;
    int blood;
    int interval;
    int row;
    int col;
    uint32_t number;
    int shiningtime;
    int flashingtime;
    int towards;
    int shoottime;
    bool issleep;
    bool isinvisible;
    bool issquished;
    bool isableshine;
    uint32_t addr;
};
struct PlantEffectStruct{
    int planttype;
    int modifytype;
    vector<int>value_first;
    vector<int>value_second;
};
void ClearAllPlants();
bool JudgeifForbid(int,int,int);
bool RandPlantplace(vector<bool>,bool,int,int);
void SinglePlantPlace(int,int,int);
vector<vector<int>> StringCheck(const QString&,bool,bool,int,int);
QString FormToString(bool,bool);

void CustomPlantAffectOnGame(vector<PlantEffectStruct>plant_effect_inlist);
void CustomPlantCancelAffectOnGame();

#endif // PLANTSOPERATION_H
