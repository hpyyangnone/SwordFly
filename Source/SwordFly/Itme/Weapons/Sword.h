// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SwordFlyBaseWeapon.h"
#include "Sword.generated.h"

/**
 * 
 */
UCLASS()
class SWORDFLY_API ASword : public ASwordFlyBaseWeapon
{
	GENERATED_BODY()
	
	public:
	ASword();

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	class UCapsuleComponent* Collision_Capsule;

    void Attack() override;

    void AttackServer_Implementation()override;
	virtual bool AttackServer_Validate() override;
	virtual void AttackNetMulticast_Implementation() override;
	virtual EWeaponType GetWeaponType() override;
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void SwordAttackBegin();

	void SwordFly();
};
