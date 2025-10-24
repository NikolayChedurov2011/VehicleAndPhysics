// Fill out your copyright notice in the Description page of Project Settings.


#include "VP_PlayerState.h"

#include "AbilitySystem/VP_AbilitySystemComponent.h"

AVP_PlayerState::AVP_PlayerState()
{
	SetNetUpdateFrequency(100.f);

	VP_AbilitySystemComponent = CreateDefaultSubobject<UVP_AbilitySystemComponent>(TEXT("VP Ability System Component"));
	VP_AbilitySystemComponent->SetIsReplicated(true);
	VP_AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* AVP_PlayerState::GetAbilitySystemComponent() const
{
	return VP_AbilitySystemComponent;
}
