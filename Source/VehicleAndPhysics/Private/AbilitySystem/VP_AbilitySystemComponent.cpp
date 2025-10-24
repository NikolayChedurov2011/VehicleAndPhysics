// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/VP_AbilitySystemComponent.h"

void UVP_AbilitySystemComponent::Input_AbilityActionPressed_Implementation(const FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(1, 7.f, FColor::Blue, (TEXT("%s, OnActionPressed"), InputTag.GetTagName().ToString()));
}

void UVP_AbilitySystemComponent::Input_AbilityActionReleased_Implementation(const FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(2, 7.f, FColor::Green, (TEXT("%s, OnActionReleased"), InputTag.GetTagName().ToString()));
}

void UVP_AbilitySystemComponent::Input_AbilityActionHeld_Implementation(const FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(3, 7.f, FColor::Yellow, (TEXT("%s, OnActionHeld"), InputTag.GetTagName().ToString()));
}
