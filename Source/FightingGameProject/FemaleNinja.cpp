// Fill out your copyright notice in the Description page of Project Settings.


#include "FemaleNinja.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include <string>
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

using namespace std;

AFemaleNinja::AFemaleNinja() {

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
/*
	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera */

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// PlayerStats
	PlayerHealth = 2.00f;
	UE_LOG(LogTemp, Warning, TEXT("Female Ninja constructed"));
}




void AFemaleNinja::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void AFemaleNinja::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

void AFemaleNinja::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	// set up gameplay key bindings

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFemaleNinja::MoveRight);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AFemaleNinja::MoveLeft);

	PlayerInputComponent->BindAction("Attack1", IE_Pressed, this, &AFemaleNinja::StandingLP);
	// PlayerInputComponent->BindAction("Attack1", IE_Released, this, &AFemaleNinja::StopAttack1);

	PlayerInputComponent->BindAction("Attack2", IE_Pressed, this, &AFemaleNinja::StandingMP);
	// PlayerInputComponent->BindAction("Attack2", IE_Released, this, &AFemaleNinja::StopAttack2);

	PlayerInputComponent->BindAction("Attack3", IE_Pressed, this, &AFemaleNinja::StandingHP);
	// PlayerInputComponent->BindAction("Attack3", IE_Released, this, &AFemaleNinja::StopAttack3);

	PlayerInputComponent->BindAction("Attack4", IE_Pressed, this, &AFemaleNinja::StandingLK);
	// PlayerInputComponent->BindAction("Attack4", IE_Released, this, &AFemaleNinja::StopAttack4);

	PlayerInputComponent->BindAction("Attack5", IE_Pressed, this, &AFemaleNinja::StandingMK);
	// PlayerInputComponent->BindAction("Attack5", IE_Released, this, &AFemaleNinja::StopAttack5);

	PlayerInputComponent->BindAction("Attack6", IE_Pressed, this, &AFemaleNinja::StandingHK);
	// PlayerInputComponent->BindAction("Attack6", IE_Released, this, &AFemaleNinja::StopAttack6);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AFemaleNinja::Crouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AFemaleNinja::StopCrouch);


	PlayerInputComponent->BindTouch(IE_Pressed, this, &AFemaleNinja::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AFemaleNinja::TouchStopped);
}

void AFemaleNinja::TakeDamage(float damageAmount)
{
	PlayerHealth -= damageAmount;
	if (PlayerHealth < 0.00f) {
		PlayerHealth = 0.00f;
	}
}

void AFemaleNinja::StandingLP()
{
	CurrentAttack = "StLP";
	UE_LOG(LogTemp, Warning, TEXT("St. LP"));
}

void AFemaleNinja::StandingMP()
{
	CurrentAttack = "StMP";
	UE_LOG(LogTemp, Warning, TEXT("St. MP"));
}

void AFemaleNinja::StandingHP()
{
	CurrentAttack = "StHP";
	UE_LOG(LogTemp, Warning, TEXT("St. HP"));
}

void AFemaleNinja::StandingLK()
{
	CurrentAttack = "StLK";
	UE_LOG(LogTemp, Warning, TEXT("St. LK"));
}

void AFemaleNinja::StandingMK()
{
	CurrentAttack = "StMK";
	UE_LOG(LogTemp, Warning, TEXT("St. MK"));
}

void AFemaleNinja::StandingHK()
{
	CurrentAttack = "StHK";
	UE_LOG(LogTemp, Warning, TEXT("St. HK"));
}

void AFemaleNinja::Crouch()
{
	IsCrouching = true;
	UE_LOG(LogTemp, Warning, TEXT("Crouch"));
}

void AFemaleNinja::StopCrouch()
{
	IsCrouching = false;
	UE_LOG(LogTemp, Warning, TEXT("Stop Crouch"));
}


void AFemaleNinja::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f, -1.f, 0.f), Value);
}

void AFemaleNinja::MoveLeft(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f, 1.f, 0.f), Value);
}




