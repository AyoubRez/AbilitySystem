// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "CharacterBase.generated.h"


class UGameplayAbilityBase;
UCLASS()
class ABILITYSYSTEM_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category=AbilitySystem)
	void AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire);

	UFUNCTION(BlueprintCallable, Category=AbilitySystem)
	void AcquireAbilities(TArray<TSubclassOf<UGameplayAbility>> AbilitiesToAcquire);


	UFUNCTION()
	void OnHealthChange(float Health, float MaxHealth);

	UFUNCTION(BlueprintImplementableEvent, Category=Attribute, meta=(DisplayName="OnHealthChange"))
	void BP_OnHealthChange(float Health, float MaxHealth);

	UFUNCTION()
	void OnManaChange(float Mana, float MaxMana);

	UFUNCTION(BlueprintImplementableEvent, Category=Attribute, meta=(DisplayName="OnManaChange"))
	void BP_OnManaChange(float Mana, float MaxMana);


	UFUNCTION()
	void OnStrengthChange(float Strength, float MaxStrength);

	UFUNCTION(BlueprintImplementableEvent, Category=Attribute, meta=(DisplayName="OnStrengthChange"))
	void BP_OnStrengthChange(float Strength, float MaxStrength);

	UFUNCTION(BlueprintImplementableEvent, Category=Attribute, meta=(DisplayName="Die"))
	void BP_Die();

	void AutoDetermineTeamIDByControllerType();

	UFUNCTION(BlueprintCallable, Category=AbilitySystem)
	bool IsOtherHostile(ACharacterBase* Other);

	uint8 GetTeamID() const { return TeamID; }

	UFUNCTION(BlueprintCallable, Category=AbilitySystem)
	void AddGameplayTag(FGameplayTag& TagToAdd);

	UFUNCTION(BlueprintCallable, Category=AbilitySystem)
	void RemoveGameplayTag(FGameplayTag& TagToRemove);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=CharacterBase)
	FGameplayTag FullHealthTag;

	UFUNCTION(BlueprintCallable, Category=CharacterBase)
	void HitStun(float StunDuration);

private:
	/** Spring Arm Attached to Character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* CameraBoom;

	/** Camera following the character at spring arm lenght */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* FollowCamera;

	bool bDead;

	uint8 TeamID;

	FTimerHandle StunTimeHandle;

#pragma region AbilitySytem

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=AbilitySystem, meta=(AllowPrivateAccess="true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=AbilitySystem, meta=(AllowPrivateAccess="true"))
	class UAttributeSetBase* AttributeSetBase;


#pragma endregion

protected:
	void Dead();

	void DisableInputControl();

	void EnableInputControl();

	void AddAbilityToUI(TSubclassOf<UGameplayAbilityBase> AbilityToAdd);
};
