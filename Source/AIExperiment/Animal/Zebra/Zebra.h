// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIExperiment/Animal/AnimalBase.h"
#include "Zebra.generated.h"

/**
 * 
 */
UCLASS()
class AIEXPERIMENT_API AZebra : public AAnimalBase
{
	GENERATED_BODY()

public:
	AZebra() = default;
	

	UFUNCTION(BlueprintCallable)
		FORCEINLINE void UpdateShouldEat()
	{
			//TODO: chaneg the magic number later.
		if (Satiety > (.8 * MaxSatiety) || Predator)
		{
			bShouldEat = false;
		}
		else if (!Predator && (Satiety < (MaxSatiety / 2)))
		{
			bShouldEat = true;
		}
	}
protected:

	// TODO:gotta create a predator class later and change this var to that one.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Danger)
		class ALion* Predator{ nullptr };
	//
	virtual void Tick(float DeltaTime) override;

};
