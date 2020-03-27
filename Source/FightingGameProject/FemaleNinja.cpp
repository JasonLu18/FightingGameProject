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





void AFemaleNinja::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	// set up gameplay key bindings

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFemaleNinja::MoveRight);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AFemaleNinja::MoveLeft);
	PlayerInputComponent->BindAxis("Crouch", this, &AFemaleNinja::Crouch);

	PlayerInputComponent->BindAction("Attack1", IE_Pressed, this, &AFemaleNinja::StandingLP);
	PlayerInputComponent->BindAction("Attack2", IE_Pressed, this, &AFemaleNinja::StandingMP);
	PlayerInputComponent->BindAction("Attack3", IE_Pressed, this, &AFemaleNinja::StandingHP);
	PlayerInputComponent->BindAction("Attack4", IE_Pressed, this, &AFemaleNinja::StandingLK);
	PlayerInputComponent->BindAction("Attack5", IE_Pressed, this, &AFemaleNinja::StandingMK);
	PlayerInputComponent->BindAction("Attack6", IE_Pressed, this, &AFemaleNinja::StandingHK);

	
	PlayerInputComponent->BindAction("Attack1", IE_Pressed, this, &AFemaleNinja::CrouchingLP);
	PlayerInputComponent->BindAction("Attack2", IE_Pressed, this, &AFemaleNinja::CrouchingMP);
	PlayerInputComponent->BindAction("Attack3", IE_Pressed, this, &AFemaleNinja::CrouchingHP);
	PlayerInputComponent->BindAction("Attack4", IE_Pressed, this, &AFemaleNinja::CrouchingLK);
	PlayerInputComponent->BindAction("Attack5", IE_Pressed, this, &AFemaleNinja::CrouchingMK);
	PlayerInputComponent->BindAction("Attack6", IE_Pressed, this, &AFemaleNinja::CrouchingHK);

	PlayerInputComponent->BindAction("Attack1", IE_Pressed, this, &AFemaleNinja::JumpingLP);
	PlayerInputComponent->BindAction("Attack2", IE_Pressed, this, &AFemaleNinja::JumpingMP);
	PlayerInputComponent->BindAction("Attack3", IE_Pressed, this, &AFemaleNinja::JumpingHP);
	PlayerInputComponent->BindAction("Attack4", IE_Pressed, this, &AFemaleNinja::JumpingLK);
	PlayerInputComponent->BindAction("Attack5", IE_Pressed, this, &AFemaleNinja::JumpingMK);
	PlayerInputComponent->BindAction("Attack6", IE_Pressed, this, &AFemaleNinja::JumpingHK);




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
	if (IsCrouching == false && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "StLP";
		UE_LOG(LogTemp, Warning, TEXT("St. LP"));
	}
}

void AFemaleNinja::StandingMP()
{
	if (IsCrouching == false && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "StMP";
		UE_LOG(LogTemp, Warning, TEXT("St. MP"));
	}
}

void AFemaleNinja::StandingHP()
{
	if (IsCrouching == false && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "StHP";
		UE_LOG(LogTemp, Warning, TEXT("St. HP"));
	}
}

void AFemaleNinja::StandingLK()
{
	if (IsCrouching == false && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "StLK";
		UE_LOG(LogTemp, Warning, TEXT("St. LK"));
	}
}

void AFemaleNinja::StandingMK()
{
	

	if (IsCrouching == false && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "StMK";
		UE_LOG(LogTemp, Warning, TEXT("St. MK"));
	}
}

void AFemaleNinja::StandingHK()
{
	if (IsCrouching == false && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "StHK";
		UE_LOG(LogTemp, Warning, TEXT("St. HK"));
	}
}

void AFemaleNinja::CrouchingLP()
{
	if (IsCrouching == true && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "CrLP";
		UE_LOG(LogTemp, Warning, TEXT("Cr. LP"));
	}
}

void AFemaleNinja::CrouchingMP()
{
	if (IsCrouching == true && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "CrMP";
		UE_LOG(LogTemp, Warning, TEXT("Cr. MP"));
	}
}

void AFemaleNinja::CrouchingHP()
{
	if (IsCrouching == true && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "CrHP";
		UE_LOG(LogTemp, Warning, TEXT("Cr. HP"));
	}
}

void AFemaleNinja::CrouchingLK()
{
	if (IsCrouching == true && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "CrLK";
		UE_LOG(LogTemp, Warning, TEXT("Cr. LK"));
	}
}

void AFemaleNinja::CrouchingMK()
{
	if (IsCrouching == true && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "CrMK";
		UE_LOG(LogTemp, Warning, TEXT("Cr. MK"));
	}
}

void AFemaleNinja::CrouchingHK()
{
	if (IsCrouching == true && GetCharacterMovement()->IsFalling() == false) {
		CurrentAttack = "CrHK";
		UE_LOG(LogTemp, Warning, TEXT("Cr. HK"));
	}
}

void AFemaleNinja::JumpingLP()
{
	if (GetCharacterMovement()->IsFalling() == true) {
		UE_LOG(LogTemp, Warning, TEXT("Jump. LP"));
	}
}

void AFemaleNinja::JumpingMP()
{
	if (GetCharacterMovement()->IsFalling() == true) {
		UE_LOG(LogTemp, Warning, TEXT("Jump. MP"));
	}
}

void AFemaleNinja::JumpingHP()
{
	if (GetCharacterMovement()->IsFalling() == true) {
		UE_LOG(LogTemp, Warning, TEXT("Jump. HP"));
	}
}

void AFemaleNinja::JumpingLK()
{
	if (GetCharacterMovement()->IsFalling() == true) {
		UE_LOG(LogTemp, Warning, TEXT("Jump. LK"));
	}
}

void AFemaleNinja::JumpingMK()
{
	if (GetCharacterMovement()->IsFalling() == true) {
		UE_LOG(LogTemp, Warning, TEXT("Jump. MK"));
	}
}

void AFemaleNinja::JumpingHK()
{
	if (GetCharacterMovement()->IsFalling() == true) {
		UE_LOG(LogTemp, Warning, TEXT("Jump. HK"));
	}
}



void AFemaleNinja::Crouch(float Value)
{
	IsCrouching = false;

	if (Value > 0.5) {
		IsCrouching = true;
		// UE_LOG(LogTemp, Warning, TEXT("Crouch"));
	}
}




void AFemaleNinja::MoveRight(float Value)
{
	// add movement in that direction if not crouching
	if (IsCrouching == false) {
		AddMovementInput(FVector(0.f, -1.f, 0.f), Value);
	}
}

void AFemaleNinja::MoveLeft(float Value)
{
	
	// add movement in that direction
	if (IsCrouching == false) {
		AddMovementInput(FVector(0.f, 1.f, 0.f), Value);
	}
}




