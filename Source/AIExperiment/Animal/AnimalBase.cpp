// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
// Sets default values
AAnimalBase::AAnimalBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Satiety = MaxSatiety;
}
// Called when the game starts or when spawned
void AAnimalBase::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SatietyTimerHandle, this, &ThisClass::ReduceSatiety, SatietyReductionDelay, true);
}

// Called every frame
void AAnimalBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//maybe can move this to a timer instead(perfromance improvement).
	
	//GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString("AnimalBase Ticking"));
}
// Called to bind functionality to input
void AAnimalBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}