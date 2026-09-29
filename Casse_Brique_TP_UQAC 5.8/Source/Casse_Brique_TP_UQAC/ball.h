#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ball.generated.h" 

UCLASS()
class CASSE_BRIQUE_TP_UQAC_API Aball : public AActor
{
	GENERATED_BODY()
	
public:	
	Aball();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	class UProjectileMovementComponent* ProjectileMovement;
};