// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"


void AMyActor::CreateSquare(TArray<FVector> vert, int index) {
	
	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(1);
	Triangles.Add(3);
	Triangles.Add(2);

	TArray<FVector> normals;
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));

	TArray<FVector2D> UV0;
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));
	UV0.Add(FVector2D(10, 10));

	TArray<FProcMeshTangent> tangents;
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));

	TArray<FLinearColor> vertexColors;
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
	vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

	mesh->CreateMeshSection_LinearColor(index, vert, Triangles, normals, UV0, vertexColors, tangents, true);	
	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}

void AMyActor::GetCircleVertices(const int r, const int heigth, TArray<FVector>& vertices, FVector centre, int direction, FRotator rotator)
{
	FTransform T(rotator, centre, FVector(1, 1, 1));
	//FRotationTranslationMatrix M(FRotator(0, 0, 90), centre);
	//int variation = 50;
	//int direction = 1;
	float angle = T_PI / stepAroundCircle;

	if (direction == 0) {
		for (int i = 0; i < stepAroundCircle; i++)
		{
			vertices.Add(T.TransformVector(FVector(centre.X, centre.Y, centre.Z + heigth)));
			vertices.Add(T.TransformVector(FVector(centre.X+(r * cos(angle * (i))), centre.Y+(r * sin(angle * (i))), centre.Z + heigth)));
			vertices.Add(T.TransformVector(FVector(centre.X + (r * cos(angle * (i + 1))), centre.Y+(r * sin(angle * (i + 1))), centre.Z + heigth)));
		}
	}
	else {
		for (int i = 0; i < stepAroundCircle; i++)
		{
			vertices.Add(T.TransformVector(FVector(centre.X, centre.Y, centre.Z)));
			vertices.Add(T.TransformVector(FVector(centre.X, centre.Y+(r * cos(angle * (i))), centre.Z+(r * sin(angle * (i))))));
			vertices.Add(T.TransformVector(FVector(centre.X, centre.Y+(r * cos(angle * (i + 1))), centre.Z + (r * sin(angle * (i + 1))))));
		}
	}
	
}


// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

