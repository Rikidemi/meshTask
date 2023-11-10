// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#define T_PI 6.28318530718
#include "MyActor.generated.h"


UCLASS()
class PROCEDURALMESH_API AMyActor : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void CreateSquare(TArray<FVector> vertices, int index);
	void GetCircleVertices(const int radius, const int heigth, TArray<FVector>& vertices, FVector centre, int direction, FRotator rotator);

	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* mesh;

	const int stepAroundCircle = 8;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int size = 100;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
