// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"

#include "CharacterBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"


UAttributeSetBase::UAttributeSetBase()
	: Health(500.0f),
	  MaxHealth(500.0f),
	  Mana(250.0f),
	  MaxMana(250.0f),
	  Strength(100.0f),
	  MaxStrength(100.0f)
{
}

void UAttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(
		UAttributeSetBase::StaticClass(),GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)))
	{
		Health.SetCurrentValue(FMath::Clamp(Health.GetCurrentValue(), 0.f, MaxHealth.GetCurrentValue()));
		Health.SetBaseValue(FMath::Clamp(Health.GetBaseValue(), 0.f, MaxHealth.GetBaseValue()));

		OnHealthChangeDelegate.Broadcast(Health.GetCurrentValue(), MaxHealth.GetCurrentValue());

		ACharacterBase* CharacterOwner = Cast<ACharacterBase>(GetOwningActor());
		if (Health.GetCurrentValue() == MaxHealth.GetCurrentValue())
		{
			if (CharacterOwner)
			{
				CharacterOwner->AddGameplayTag(CharacterOwner->FullHealthTag);
			}
		}
		else
		{
			if (CharacterOwner)
			{
				CharacterOwner->RemoveGameplayTag(CharacterOwner->FullHealthTag);
			}
		}
	}

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(
		UAttributeSetBase::StaticClass(),GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Mana)))
	{
		Mana.SetCurrentValue(FMath::Clamp(Mana.GetCurrentValue(), 0.f, MaxMana.GetCurrentValue()));
		Mana.SetBaseValue(FMath::Clamp(Mana.GetBaseValue(), 0.f, MaxMana.GetBaseValue()));

		OnManaChangeDelegate.Broadcast(Mana.GetCurrentValue(), MaxMana.GetCurrentValue());
	}


	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(
		UAttributeSetBase::StaticClass(),GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Strength)))
	{
		Strength.SetCurrentValue(FMath::Clamp(Strength.GetCurrentValue(), 0.f, MaxStrength.GetCurrentValue()));
		Strength.SetBaseValue(FMath::Clamp(Strength.GetBaseValue(), 0.f, MaxStrength.GetBaseValue()));

		OnStrengthChangeDelegate.Broadcast(Strength.GetCurrentValue(), MaxStrength.GetCurrentValue());
	}
}
