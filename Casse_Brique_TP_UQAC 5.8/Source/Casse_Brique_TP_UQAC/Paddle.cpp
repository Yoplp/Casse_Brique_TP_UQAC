#include "Paddle.h"
#include "Components/StaticMeshComponent.h"

APaddle::APaddle()
{
	PrimaryActorTick.bCanEverTick = true;

	// composant visuel
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    
	// physique
	MeshComponent->SetCollisionProfileName(TEXT("BlockAllDynamic")); 
    
	RootComponent = MeshComponent;

	// vitesse par défaut
	MoveSpeed = 1000.0f;
}

void APaddle::BeginPlay()
{
	Super::BeginPlay();
}

void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveRight", this, &APaddle::MoveRight);
}

// logique de déplacement
void APaddle::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// position actuelle
		FVector NewLocation = GetActorLocation();
		
		// déplace sur l'axe Y en fonction du temps et de la vitesse
		NewLocation.Y += Value * MoveSpeed * GetWorld()->GetDeltaSeconds();
		
		// applique nouvelle position
		SetActorLocation(NewLocation, true);
	}
}