#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.generated.h"

UCLASS()
class CASSE_BRIQUE_TP_UQAC_API APaddle : public APawn
{
	GENERATED_BODY()

public:
	// Constructeur par défaut
	APaddle();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// visu raquette
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* MeshComponent;

	// vitesse déplacement raquette (modifiable dans Unreal)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed;

	// fonction touche déplacement
	void MoveRight(float Value);
};