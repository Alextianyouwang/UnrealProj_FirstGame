#include "Item/Item.h"
#include "DrawDebugHelpers.h"
#include "UnrealProj_FirstGame/DebugMacros.h"

#define DRAW_SPHERE(L,S,C) if (GetWorld()) DrawDebugSphere(GetWorld(),L,S, 24, C, false, -1.f,0,1.f);
#define DRAW_LINE(S,E,C) if (GetWorld()) DrawDebugLine(GetWorld(), S,E,C,false,-1.f,0,1.f);
#define DRAW_POINT(L,C) if (GetWorld()) DrawDebugPoint(GetWorld(),L,15.f,C,false,-1.f,0);

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp,Warning,TEXT("Begin Play Called!"));

	//if (GEngine) 
	//{
	//	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Item OnScreen Message"));
	//}

	//UWorld* World = GetWorld();
	//FVector Location = GetActorLocation();
	//FVector Forward = GetActorForwardVector();
	//
	//DRAW_SPHERE(GetActorLocation(),25.f,FColor::Cyan)
	//DRAW_LINE(Location,Location + Forward * 100.f,100.f,FColor::Cyan)
	//DRAW_POINT(Location + Forward * 100.f, FColor::Red);
	int32 AvgInt=	Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3: %d"), AvgInt)

		float AvgFloat = Avg<float>(3.13f, 15.3f);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 3.13 and 15.3: %f"), AvgFloat)


}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}
float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	float MovementRate = 50.f;
	//AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0, 0));
	//AddActorWorldRotation(FRotator(0.f, 100.f * DeltaTime, 0.f));

	RunningTime += DeltaTime;
	float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	FVector Location = GetActorLocation();
	DRAW_SPHERE(Location, 25.f, FColor::Cyan)
	DRAW_LINE(Location, Location + GetActorForwardVector() * 100.f, FColor::Cyan)



		FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT(AvgVector, FColor::Cyan);
}

