// Fill out your copyright notice in the Description page of Project Settings.


#include "RippleHit.h"

// Sets default values
ARippleHit::ARippleHit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RippleObject = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ripple Object"));
	RippleObject->SetupAttachment(RootComponent);
	RippleObject->SetMaterial(0, RippleMaterial);
	
}

// Called when the game starts or when spawned
void ARippleHit::BeginPlay()
{
	Super::BeginPlay();

	//Bind event to timeline's attribute
	FOnTimelineFloat ProgressUpdate;
	ProgressUpdate.BindUFunction(this, FName("RippleUpdate"));

	FOnTimelineEvent FinishEvent;
	FinishEvent.BindUFunction(this, FName("RippleFinish"));

	//Key ripple value update function
	RippleTimeline.AddInterpFloat(RippleCurve, ProgressUpdate);
	RippleTimeline.SetTimelineFinishedFunc(FinishEvent);
}

// Called every frame
void ARippleHit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RippleTimeline.TickTimeline(DeltaTime);

}

void ARippleHit::RippleEffect(FVector HitPosition)
{
	//Send hit position from bullet to ripple material
	DynamicMaterial = RippleObject->CreateDynamicMaterialInstance(0, RippleMaterial);
	DynamicMaterial->SetVectorParameterValue("Center", HitPosition);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("update material"));

	//Run custom timeline
	RippleTimeline.PlayFromStart();

	RippleObject->SetMaterial(0, DynamicMaterial);
	

}

void ARippleHit::RippleUpdate(float Alpha)
{
	DynamicMaterial->SetScalarParameterValue("Radius", Alpha);
	
}

void ARippleHit::RippleFinish()
{
}

