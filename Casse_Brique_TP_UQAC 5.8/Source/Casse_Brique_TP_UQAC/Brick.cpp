#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "ball.h" 

ABrick::ABrick()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

void ABrick::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	// On vérifie si "Other" est balle
	Aball* LaBalle = Cast<Aball>(Other);
	
	if (LaBalle != nullptr) 
	{
		//Destroy();
	}
}