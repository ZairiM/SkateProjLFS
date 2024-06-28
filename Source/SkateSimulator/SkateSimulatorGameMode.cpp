// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkateSimulatorGameMode.h"
#include "SkateSimulatorCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASkateSimulatorGameMode::ASkateSimulatorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ASkateSimulatorGameMode::IncrementJumpedObstaclesCounter(int32 NewValue)
{
	BP_IncrementJumpedObstaclesCounter(NewValue);
}


