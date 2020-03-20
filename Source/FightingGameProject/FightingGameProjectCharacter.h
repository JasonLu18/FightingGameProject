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

	virtual void StartAttack1();
	virtual void StartAttack2();
	virtual void StartAttack3();
	virtual void StartAttack4();
	virtual void StartAttack5();
	virtual void StartAttack6();
	virtual void Crouch();
	/** Called for side to side input */
	void MoveRight(float Value);

	void MoveLeft(float Value);

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
