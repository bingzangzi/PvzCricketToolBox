#ifndef GAME_INFO_H
#define GAME_INFO_H
#pragma once
#include "process_op.h"
#include <QDebug>
#include <QFileInfo>
#include <QString>
#include <QTextStream>
#include <QDateTime>
#include <Psapi.h>
#pragma comment (lib,"Psapi.lib")
extern HANDLE pvzHand;
extern QTextStream out;
int GetFrameDuration();
void CodeInject(HANDLE pvzHand,CodeStruct* target);
bool IsProcessRunning();
int GetGameUI();
int GetGameMode();
int GetScene();
int GetRowCount();
bool CheckBoardOn();
bool CheckGameOn();
bool Resumemower();
bool Startmower(int);
bool Clearmower(int);
void SetGamePause();
void PlantNoLimit(bool);
void LockShovel(bool);
void PlantInvincible(bool);
void UnlockAllMode(bool);
void UnlockGoldFlower(bool);
void PassGame();
void HideShovel(bool);
void HideMenu(bool);
void SetNoSun(bool);
void AutoCollect(bool);
void ZombieInvincible(bool);
void MushroomNoSleep(bool);
void StopZombieMove(bool);
void StopSystemZombie(bool);
void NoCrater(bool);
void AllowBackRunning(bool);
void PlaceNoCD(bool);
void IgnoreSun(bool);
void PurpleSeedUnlimited(bool);
bool CompareVerinfo();
void OverlapPlant(bool);
QString GetExeFileVersion(const QString& filePath);
QString GetExeProductName(const QString &filePath);
QStringList GetPlantBook();
void ChangeBaseValue(uint32_t,uint32_t,bool);
void ResumeMaxMemory();
void UnlockMaxMemory();
void UnlockShopItems(bool);
void ClearAllBullet();
#endif // GAME_INFO_H
