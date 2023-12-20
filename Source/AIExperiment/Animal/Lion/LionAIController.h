// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "LionAIController.generated.h"

/**
 * 
 */
UCLASS()
class AIEXPERIMENT_API ALionAIController : public AAIController
{
	GENERATED_BODY()

public:
	ALionAIController();


protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
};
