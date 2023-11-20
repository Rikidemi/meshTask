// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.h"
#include "Cilinder.generated.h"

UCLASS()
class PROCEDURALMESH_API ACilinder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACilinder();

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
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) ;

};
