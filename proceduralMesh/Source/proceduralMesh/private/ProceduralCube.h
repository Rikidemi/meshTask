// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.h"
#include "ProceduralCube.generated.h"

UCLASS()
class PROCEDURALMESH_API ACube : public AActor
{
	GENERATED_BODY()
	
private:
	TArray<FVector> vertices;
public:	
	// Sets default values for this actor's properties
	ACube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() ;
	void PostActorCreated() ;
	void PostLoad() ;
	void OnConstruction(const FTransform& Transform);

	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int size = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int heigth = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int width = 100;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) ;

};
