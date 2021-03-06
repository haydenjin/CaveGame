#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "MapSize.h"
#include "Shape.h"
#include "Cavern.h"
#include "Map.h"
#include "CavernManager.h"
using namespace std;

void rawMapLoad(char raw[][MAP_SIZE_EAST], const string& filename);
void rawMapPrint(const char raw[][MAP_SIZE_EAST]);
bool rawMapIsOpen(const char raw[][MAP_SIZE_EAST], int south, int east);
Shape rawMapCalculateShape(const char raw[][MAP_SIZE_EAST], int south, int east);
bool rawMapIsCavern(const char raw[][MAP_SIZE_EAST], int south, int east);
int rawMapGetCavernSouthSize(const char raw[][MAP_SIZE_EAST], int south, int east);
int rawMapGetCavernEastSize(const char raw[][MAP_SIZE_EAST], int south, int east);
int rawMapFindExitToSouth(const char raw[][MAP_SIZE_EAST], int south, int east, int max_distance);
int rawMapFindExitToEast(const char raw[][MAP_SIZE_EAST], int south, int east, int max_distance);
Cavern rawMapCalculateCavern(const char raw[][MAP_SIZE_EAST], int south, int east);
Position rawMapGetPlayerStart(const char raw[][MAP_SIZE_EAST]);
bool animalOrNot(const char raw[][MAP_SIZE_EAST], int s,int e);
int getAnimalValue(const char raw[][MAP_SIZE_EAST], int s, int e);