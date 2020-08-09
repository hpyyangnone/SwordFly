// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SwordFlyCharacter.generated.h"

UCLASS()
class SWORDFLY_API ASwordFlyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASwordFlyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*
	 * Component
	 */
	//相机手臂
	class USpringArmComponent* SpringArmComp;
	//相机第三人称
	class UCameraComponent* TiredCamera;

	//设置角色基础移动
	void MoveForward(float amount);

	void MoveRight(float amount);

	void RotateCamera(float amount);

	void ChangeCameraHeight(float amount);
};
