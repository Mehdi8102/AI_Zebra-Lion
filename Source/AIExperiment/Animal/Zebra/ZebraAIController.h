// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ZebraAIController.generated.h"

/**
 * 
 */
UCLASS()
class AIEXPERIMENT_API AZebraAIController : public AAIController
{
	GENERATED_BODY()
public:
	AZebraAIController();


protected:
	virtual void BeginPlay() override;

};
