// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeSetBase.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangeDelegate, float, Health, float, MaxHealth);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnManaChangeDelegate, float, Mana, float, MaxMana);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStrengthChangeDelegate, float, Strength, float, MaxStrength);

UCLASS()
class ABILITYSYSTEM_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()


public:
	UAttributeSetBase();

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	FOnHealthChangeDelegate OnHealthChangeDelegate;
	FOnManaChangeDelegate OnManaChangeDelegate;
	FOnStrengthChangeDelegate OnStrengthChangeDelegate;

private:
	/**
	 * Health Of Character 
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeSetBase, meta=(AllowPrivateAccess="true"))
	FGameplayAttributeData Health;

	/**
	 * Max Health of the character
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeSetBase, meta=(AllowPrivateAccess="true"))
	FGameplayAttributeData MaxHealth;

	/**
   * Mana Of Character 
   */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeSetBase, meta=(AllowPrivateAccess="true"))
	FGameplayAttributeData Mana;

	/**
	 * Max Mana of the character
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeSetBase, meta=(AllowPrivateAccess="true"))
	FGameplayAttributeData MaxMana;


	/**
    * Strength Of Character 
    */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeSetBase, meta=(AllowPrivateAccess="true"))
	FGameplayAttributeData Strength;

	/**
	 * Max Strength of the character
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AttributeSetBase, meta=(AllowPrivateAccess="true"))
	FGameplayAttributeData MaxStrength;
};
