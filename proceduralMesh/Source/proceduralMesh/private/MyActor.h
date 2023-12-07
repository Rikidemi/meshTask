// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ProceduralMeshComponent.h"
#include "GameFramework/Actor.h"
#define T_PI 6.28318530718
#define stepAroundCircle 20
#define chairSize 100

//void CreateTriang(TArray<FVector>& vertices, FVector centre, FTransform T, const int size);
//square
void GetSquareVertices(TArray<FVector>& vertices, FVector centre, FTransform T,const int size);
void CreateSquare(TArray<FVector>& vertices, UProceduralMeshComponent*& mesh,const int index);
//circle
void GetCircleVertices(const int radius, const int heigth, TArray<FVector>& vertices, FVector centre, FTransform T);
void CreateCircle(TArray<FVector> vertices, UProceduralMeshComponent*& mesh, int& index);
//box
void GetBoxVertices(TArray<FVector>& vertices, int length, int heigth, int width, FVector centre);
void CreateBox(TArray<FVector>& vertices, UProceduralMeshComponent*& mesh, int& index);
//cilinder
void CreateCilinder(const int radius, const int heigth, UProceduralMeshComponent*& mesh, FVector centre, int& index);
