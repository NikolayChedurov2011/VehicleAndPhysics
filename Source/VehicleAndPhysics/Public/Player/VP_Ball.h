// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Interfaces/SS_InputInterface.h"
#include "VP_Ball.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class VEHICLEANDPHYSICS_API AVP_Ball : public APawn, public ISS_InputInterface
{
	GENERATED_BODY()

public:
	
	AVP_Ball();
	virtual void Tick(float DeltaTime) override;
	
	/*---- Input Interface ----*/
	virtual void Input_Move_Implementation(const FInputActionValue& InputActionValue) override;
	virtual void Input_Look_Implementation(const FInputActionValue& InputActionValue) override;
	
private:

	double MoveLongitude{0};
	double MoveLatitude{0};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true), Category="Pawn Control")
	float ControllerForce{250.f};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true), Category="Pawn Control")
	float JumpForce{50.f};
		
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true), Category="Pawn Control")
	float DashForce{150.f};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true), Category="Pawn Control")
	float MaxSpeed{4.f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true), Category="Pawn Control")
	bool Magnetized{false};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	TObjectPtr<UStaticMeshComponent> MeshComponent{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	TObjectPtr<USpringArmComponent> SpringArm{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	TObjectPtr<UCameraComponent> CameraComponent{};
};
