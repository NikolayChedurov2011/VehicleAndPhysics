// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/VP_Ball.h"

#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AVP_Ball::AVP_Ball()
{
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	MeshComponent->SetSimulatePhysics(true);
	SetRootComponent(MeshComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 600.f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->SetupAttachment(MeshComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComponent->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;
}

void AVP_Ball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MeshComponent->AddForce(FVector{MoveLongitude, MoveLatitude, 0.f} * ControllerForce * MeshComponent->GetMass());
}

void AVP_Ball::Input_Move_Implementation(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	MoveLongitude = MovementVector.Y;
	MoveLatitude = MovementVector.X;
}

void AVP_Ball::Input_Look_Implementation(const FInputActionValue& InputActionValue)
{
	
}