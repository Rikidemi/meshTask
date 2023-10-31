// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "MyActor.generated.h"


UCLASS()
class PROCEDURALMESH_API AMyActor : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void CreateSquare(TArray<FVector> vertices, int index);

	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
