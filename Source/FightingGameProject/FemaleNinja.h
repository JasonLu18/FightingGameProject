// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FightingGameProjectCharacter.h"
#include "FemaleNinja.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAMEPROJECT_API AFemaleNinja : public AFightingGameProjectCharacter
{
	GENERATED_BODY()
	
	/** Side view camera */
    //UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class UCameraComponent* SideViewCameraComponent;
	
	/** Camera boom positioning the camera beside the character */
	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	// class USpringArmComponent* CameraBoom;

	void StartAttack1();
	void StartAttack2();
	void StartAttack3();
	void StartAttack4();
	void StartAttack5();
	void StartAttack6();

public:

	// Returns SideViewCameraComponent subobject 
	// FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	// Returns CameraBoom subobject 
	// FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	 AFemaleNinja();
	


protected: 
	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	virtual void TakeDamage(float damageAmount);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attacks")
	bool WasCrouchHPused = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool WalkingForward = false;
};


