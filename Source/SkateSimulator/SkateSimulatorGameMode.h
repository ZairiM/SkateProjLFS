// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SkateSimulatorGameMode.generated.h"


UCLASS(minimalapi)
class ASkateSimulatorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ASkateSimulatorGameMode();

    UFUNCTION(BlueprintCallable)
    void IncrementJumpedObstaclesCounter (int32 NewValue);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void BP_IncrementJumpedObstaclesCounter(int32 NewValue);
};



