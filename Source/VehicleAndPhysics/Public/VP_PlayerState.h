// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "VP_PlayerState.generated.h"

class UVP_AbilitySystemComponent;

UCLASS()
class VEHICLEANDPHYSICS_API AVP_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	AVP_PlayerState();

	/*---- Ability System Interface ----*/
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:

	UPROPERTY()
	TObjectPtr<UVP_AbilitySystemComponent> VP_AbilitySystemComponent{};
};
