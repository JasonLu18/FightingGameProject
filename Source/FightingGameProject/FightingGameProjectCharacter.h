// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FightingGameProjectCharacter.generated.h"

UCLASS(config=Game)
class AFightingGameProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

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
	virtual void Crouch(float Value);
	/** Called for side to side input */
	virtual void MoveRight(float Value);

	virtual void MoveLeft(float Value);

protected:

	

	

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	virtual void TakeDamage(float damageAmount);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float PlayerHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Super")
	float PlayerSuper;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool IsCrouching = false;

public:
	AFightingGameProjectCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	

};
