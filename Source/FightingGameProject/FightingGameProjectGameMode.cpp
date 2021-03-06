// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FightingGameProjectGameMode.h"
#include "FightingGameProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFightingGameProjectGameMode::AFightingGameProjectGameMode()
{
	// set default pawn class to our Blueprinted character
 	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/BPs/FemaleNinjaBP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
