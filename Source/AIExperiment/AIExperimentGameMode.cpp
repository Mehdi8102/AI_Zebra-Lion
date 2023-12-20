// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIExperimentGameMode.h"
#include "AIExperimentCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAIExperimentGameMode::AAIExperimentGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
