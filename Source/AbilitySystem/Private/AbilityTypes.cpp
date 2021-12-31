// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityTypes.h"

FGameplayAbilityInfo::FGameplayAbilityInfo():
	CooldownDuration(0.f),
	Cost(0.f),
	CostType(EAbilityCostType::Mana),
	UIMaterial(nullptr),
	AbilityClass(nullptr)
{
}

FGameplayAbilityInfo::FGameplayAbilityInfo(float InCooldownDuration, float InCost, EAbilityCostType InCostType,
                                           UMaterialInstance* InUIMaterial,
                                           const TSubclassOf<UGameplayAbilityBase>& InAbilityClass):
	CooldownDuration(InCooldownDuration),
	Cost(InCost),
	CostType(InCostType),
	UIMaterial(InUIMaterial),
	AbilityClass(InAbilityClass)
{
}
