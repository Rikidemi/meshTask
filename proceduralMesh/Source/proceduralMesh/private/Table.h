// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.h"
#include "Table.generated.h"

UCLASS()
class ATable : public AActor
{
	GENERATED_BODY()

private:

	TArray<FVector> vertices;
	
	
public:	
	// Sets default values for this actor's properties
	ATable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void PostActorCreated();
	void PostLoad();

	void OnConstruction(const FTransform& Transform);
	void CreateTable();

	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int size = 200;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int width = 400;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* Chairs;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
