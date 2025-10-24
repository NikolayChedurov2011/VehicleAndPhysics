// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Interfaces/SS_InputInterface.h"
#include "VP_AbilitySystemComponent.generated.h"

UCLASS()
class VEHICLEANDPHYSICS_API UVP_AbilitySystemComponent : public UAbilitySystemComponent, public ISS_InputInterface
{
	GENERATED_BODY()
	
public:

	/*---- Input Interface ----*/
	virtual void Input_AbilityActionPressed_Implementation(const FGameplayTag InputTag) override;
	virtual void Input_AbilityActionReleased_Implementation(const FGameplayTag InputTag) override;
	virtual void Input_AbilityActionHeld_Implementation(const FGameplayTag InputTag) override;
};
