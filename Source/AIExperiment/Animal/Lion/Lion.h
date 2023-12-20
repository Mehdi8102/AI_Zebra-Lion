// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIExperiment/Animal/AnimalBase.h"
#include "Lion.generated.h"

/**
 * 
 */
UCLASS()
class AIEXPERIMENT_API ALion : public AAnimalBase
{
	GENERATED_BODY()

public:

	ALion();

protected:

	//variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite )
		bool bFoundPrey{ false };

	//functions
	virtual void Tick(float DeltaSeconds) override;
	
};
