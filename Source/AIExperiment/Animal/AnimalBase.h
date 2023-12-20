// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AnimalBase.generated.h"

UCLASS()
class AIEXPERIMENT_API AAnimalBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAnimalBase();

	//function
	UFUNCTION(BlueprintCallable)
		FORCEINLINE float GetSatietyPercentage() { return Satiety / 100.f; }

	UFUNCTION(BlueprintCallable)
		FORCEINLINE void AddToSatiety() { Satiety += SatietyToAdd; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	///Components

	//Variables
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//bool bIsInDanger{
		//false
	//};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsHungry{
		false
	};
	//We use this bool to change the maxWalkSpeed depending on whether we want the animal to run fast ro walk slowly.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bShouldWalk{
		true
	};
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		float MaxWalkSpeed{ 80.f };
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		float MaxRunSpeed{ 160.f };
	//
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Satiety)
		float MaxSatiety{ 100.f };
	//
	//Satiety will be assigned the value of MaxSatiety in the ctor.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Satiety)
		float Satiety{};
	//how much Satiety do we want to add to current satiety(Used by AddToSatiety() ).
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Satiety)
		float SatietyToAdd{ 10 };
	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Satiety)
		float SatietyReductionValue{ 5 };
	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Satiety)
		float SatietyReductionDelay{ 3 };
	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Satiety)
		bool bShouldEat{};

	FTimerHandle SatietyTimerHandle;
	//FUNCTIONS

	UFUNCTION()
		FORCEINLINE void ReduceSatiety()
	{
		Satiety = FMath::Clamp(Satiety - SatietyReductionValue, 0.f, 100.f);
		//
		//GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Green, FString::FromInt(Satiety));
		//
		//if (bIsHungry)
		//{
			//GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Green, FString("bIsHungry is true!"));
		//}
		//else
		//{
			//GEngine->AddOnScreenDebugMessage(-1, .5f, FColor::Green, FString("bIsHungry is false!"));
		//}
	}

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};