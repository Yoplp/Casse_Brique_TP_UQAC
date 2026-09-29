#include "ball.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

Aball::Aball()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = MeshComponent;
	
	ProjectileMovement->InitialSpeed = 1200.0f;
	ProjectileMovement->MaxSpeed = 1200.0f;
	
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.0f; 
	ProjectileMovement->Friction = 0.0f; 
	ProjectileMovement->ProjectileGravityScale = 0.0f; 

	ProjectileMovement->bConstrainToPlane = true;
	ProjectileMovement->SetPlaneConstraintNormal(FVector(1.0f, 0.0f, 0.0f));
}

void Aball::BeginPlay()
{
	Super::BeginPlay();

	FVector DirectionInitiale = FVector(0.0f, 1.0f, -1.0f);
	ProjectileMovement->Velocity = DirectionInitiale.GetSafeNormal() * ProjectileMovement->InitialSpeed;
}

void Aball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}