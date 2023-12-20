// Fill out your copyright notice in the Description page of Project Settings.


#include "Zebra.h"
#include "ZebraAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
void AZebra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
	UpdateShouldEat();
	//Setting a  blackboardValue.
	AZebraAIController* AIController{ Cast<AZebraAIController>(GetController()) };
	if (IsValid(AIController))
	{
		UBlackboardComponent* BBComp{ AIController->GetBlackboardComponent() };
		if (!BBComp) return;
		BBComp->SetValueAsBool(FName("bShouldEat"), bShouldEat);
	}
}
