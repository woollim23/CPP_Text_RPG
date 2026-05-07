#pragma once
#include "pch.h"
#include "Monster.h"
#include "Player.h"
#include "Characters.h"

static class Battle
{
public:
	static void battleSystem(Characters* attacker, Characters* target);
};