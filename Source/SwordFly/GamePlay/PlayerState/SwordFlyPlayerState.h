// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SwordFly/GamePlay/Character/SwordFlyCharacter.h"

#include "SwordFlyPlayerState.generated.h"

class ABaseItem;
/**
 * 
 */
UCLASS()
class SWORDFLY_API ASwordFlyPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:

	ASwordFlyPlayerState();
	
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Player State")
	class USwordFlyInformationrComponent* InformationCompoent;
	
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Player State")
	float CurrentHealth;
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Player State")
	float MaxHealth;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Player State")
	float CurrentVitality;
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Player State")
	float MaxVitality;

	
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Player State")
	TArray<class ASwordFlyBaseWeapon*> CurrentWeaponArray;
	
	UFUNCTION(BlueprintCallable)
	void SetCurrentWeapon(class ASwordFlyBaseWeapon* NewWeapon);

	UFUNCTION(BlueprintCallable)
	void SweapWeapon(class ASwordFlyBaseWeapon* newWeapon);
	
	UFUNCTION(BlueprintCallable)
	void PackUp(ABaseItem* Itme);
	
	UFUNCTION(BlueprintCallable)
	void Equipment(ASwordFlyCharacter* Player, ASwordFlyBaseWeapon* Itme);
	
	UFUNCTION(BlueprintCallable)
	void UnEquipment();
	UFUNCTION(BlueprintCallable,Server,WithValidation,Reliable)
    void UnEquipmentServer();
	UFUNCTION(BlueprintCallable,NetMulticast,Reliable)
    void UnEquipmentNetMulticast();
public:
	UFUNCTION(BlueprintCallable, Category = "Player State")
    void CollectHeart(float var);

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Player State")
	float PlayerSpeed;

	UFUNCTION(BlueprintCallable, Category = "Player State")
	void ReceiveDamage(float var);
};
