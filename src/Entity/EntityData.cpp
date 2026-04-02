#include "Entity/EntityData.h"
using namespace Entity;

EntityData::EntityData(int hp, int damage) : maxHp(hp), currentHp(hp), damage(damage) {}