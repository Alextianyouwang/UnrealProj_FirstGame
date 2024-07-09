// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class UNREALPROJ_FIRSTGAME_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	

	AItem();
	virtual void Tick(float DeltaTime) override;
protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Param")

	float Amplitude = 0.25f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Param")
	float TimeConstant = 5.f;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	float RunningTime = 0.f;


	UFUNCTION(BlueprintPure)
	float TransformedSin(); 

	UFUNCTION(BlueprintPure)
	float TransformedCos();

	template<typename T>
	T Avg(T First, T Second);



private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess =  "true"))
	UStaticMeshComponent* ItemMesh;


};

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return T(First + Second)/2;
}
