// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ZebraWidget.generated.h"

/**
 * 
 */
UCLASS()
class AIEXPERIMENT_API UZebraWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	UZebraWidget(const FObjectInitializer& ObjectInitializer);

	protected:
	virtual bool Initialize() override;
	
};
