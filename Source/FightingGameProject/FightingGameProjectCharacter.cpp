// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FightingGameProjectCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AFightingGameProjectCharacter::AFightingGameProjectCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f,180.f,0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	PlayerHealth = 1.00f;
	PlayerSuper = 1.00f; 

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AFightingGameProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFightingGameProjectCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AFightingGameProjectCharacter::MoveLeft);

	PlayerInputComponent->BindAction("Attack1", IE_Pressed, this, &AFightingGameProjectCharacter::StartAttack1);
	// PlayerInputComponent->BindAction("Attack1", IE_Released, this, &AFightingGameProjectCharacter::StopAttack1);

	PlayerInputComponent->BindAction("Attack2", IE_Pressed, this, &AFightingGameProjectCharacter::StartAttack2);
	// PlayerInputComponent->BindAction("Attack2", IE_Released, this, &AFightingGameProjectCharacter::StopAttack2);

	PlayerInputComponent->BindAction("Attack3", IE_Pressed, this, &AFightingGameProjectCharacter::StartAttack3);
	// PlayerInputComponent->BindAction("Attack3", IE_Released, this, &AFightingGameProjectCharacter::StopAttack3);

	PlayerInputComponent->BindAction("Attack4", IE_Pressed, this, &AFightingGameProjectCharacter::StartAttack4);
	// PlayerInputComponent->BindAction("Attack4", IE_Released, this, &AFightingGameProjectCharacter::StopAttack4);

	PlayerInputComponent->BindAction("Attack5", IE_Pressed, this, &AFightingGameProjectCharacter::StartAttack5);
	// PlayerInputComponent->BindAction("Attack5", IE_Released, this, &AFightingGameProjectCharacter::StopAttack5);

	PlayerInputComponent->BindAction("Attack6", IE_Pressed, this, &AFightingGameProjectCharacter::StartAttack6);
	// PlayerInputComponent->BindAction("Attack6", IE_Released, this, &AFightingGameProjectCharacter::StopAttack6);


	PlayerInputComponent->BindTouch(IE_Pressed, this, &AFightingGameProjectCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AFightingGameProjectCharacter::TouchStopped);
}

void AFightingGameProjectCharacter::TakeDamage(float damageAmount)
{
	PlayerHealth -= damageAmount;
	if (PlayerHealth < 0.00f) {
		PlayerHealth = 0.00f;
	}
}

void AFightingGameProjectCharacter::StartAttack1()
{

}

void AFightingGameProjectCharacter::StartAttack2()
{

}

void AFightingGameProjectCharacter::StartAttack3()
{

}

void AFightingGameProjectCharacter::StartAttack4()
{
	
}

void AFightingGameProjectCharacter::StartAttack5()
{
	
}

void AFightingGameProjectCharacter::StartAttack6()
{
	
}

void AFightingGameProjectCharacter::Crouch()
{
	
}

void AFightingGameProjectCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
} 

void AFightingGameProjectCharacter::MoveLeft(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f, 1.f, 0.f), Value);
}



void AFightingGameProjectCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void AFightingGameProjectCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

