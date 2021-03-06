// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include "FightingGameProjectCharacter.h"
#include "FemaleNinja.generated.h"

using namespace std;

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

public:

	// Returns SideViewCameraComponent subobject 
	// FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	// Returns CameraBoom subobject 
	// FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	 AFemaleNinja();
	


protected: 
	void StandingLP();
	void StandingMP();
	void StandingHP();
	void StandingLK();
	void StandingMK();
	void StandingHK();
	void CrouchingLP();
	void CrouchingMP();
	void CrouchingHP();
	void CrouchingLK();
	void CrouchingMK();
	void CrouchingHK();
	void JumpingLP();
	void JumpingMP();
	void JumpingHP();
	void JumpingLK();
	void JumpingMK();
	void JumpingHK();
	void Crouch(float Value);
	void MoveRight(float Value);
	void MoveLeft(float Value);

	// APawn interface
	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	void TakeDamage(float damageAmount);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ForwardMovement")
	bool WalkingForward = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BackwardMovement")
	bool WalkingBackward = false;

	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	FString CurrentAttack = "null";
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool IsStanding = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool IsJumping = true;


};


