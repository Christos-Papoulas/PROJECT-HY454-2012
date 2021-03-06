#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "MemoryManage.h"
#include "utilities.h"
#include <map>

typedef unsigned long timestamp_t;

enum animatorstate_t {
	ANIMATOR_FINISHED = 0,
	ANIMATOR_RUNNING  = 1,
	ANIMATOR_STOPPED  = 2
};

#define ANIMATORS_SIZE 64

enum animatorType_t {
	unkwownAnimator_t,
	bubStandAnimator_t,
	bubWalkAnimator_t,
	bubFallingAnimator_t,
	bubOpenMouthAnimator_t,
	bubOpenMouthFallingAnimator_t,
	bubJumpOpenMouthAnimator_t,
	bubJumpAnimator_t,
	bubDieAnimator_t,
	bubDieFallingAnimator_t,
	ponEffectAnimator_t,
	bubBubbleBlastOffAnimator_t,
	bubBubbleAnimator_t,
	bubPingBubbleAnimator_t,
	zenChanInBubble_t,
	zenChanInBubbleMediumAngry_t,
	zenChanInBubbleHighAngry_t,
	mightaInBubble_t,
	mightaInBubbleMediumAngry_t,
	mightaInBubbleHighAngry_t,
	waterSpecialBubble_t,
	zenChanStandAnimator_t,
	zenChanWalkAnimator_t,
	zenChanFallingAnimator_t,
	zenChanJumpAnimator_t,
	zenChanAngryStandAnimator_t,
	zenChanAngryWalkAnimator_t,
	zenChanAngryFallingAnimator_t,
	zenChanAngryJumpAnimator_t,
	mightaStandAnimator_t,
	mightaWalkAnimator_t,
	mightaFallingAnimator_t,
	mightaJumpAnimator_t,
	mightaAngryStandAnimator_t,
	mightaAngryWalkAnimator_t,
	mightaAngryFallingAnimator_t,
	mightaAngryJumpAnimator_t,
	mightaAngryThrowFireBallAnimator_t,
	mightaThrowFireBallAnimator_t,
	baronVonBlubaRushAnimator_t,
	baronVonBlubaStandAnimator_t,
	zenChanDieAnimator_t,
	mightaDieAnimator_t,
	zenChanDieFallingAnimator_t,
	mightaDieFallingAnimator_t,
	BananaAnimator_t,
	OrangeAnimator_t,
	PeachAnimator_t,
	WaterMelonAnimator_t,
	riverAnimator_t,
	BlueDiamondAnimator_t,
	RedShoesAnimator_t,
	YellowSweetAnimator_t,
	BlueSweetAnimator_t,
	PurpleSweetAnimator_t,
	timeTickAnimator_t,
	hurryUpAnimator_t,
	bubInBubbleAnimator_t,
	mightaMovingFireBallAnimator_t,
	mightaDestroyedFireBallAnimator_t,
	scoreLabelAnimator_t,
	startScreenStaticAnimator_t,
	startScreenSelectorAnimator_t,
	optionsScreenStaticAnimator_t,
	optionsScreenSelectorAnimator_t,
};

class Animator : public LatelyDestroyable{
public:
	typedef void (*FinishCallback)(Animator*,void*);

protected:

	timestamp_t	lastTime;
	animatorstate_t	state;
	FinishCallback	onFinish;
	void* finishClosure;
	void NotifyStopped (void);


public:
	Animator (void); 
	virtual ~Animator();
	void Stop (void);
	bool HasFinished (void) const;
	virtual void TimeShift (timestamp_t offset);
	virtual void Progress (timestamp_t currTime)=0;
	virtual void Display(Bitmap at)=0;
	void SetOnFinish (FinishCallback f, void* c); 
	virtual enum animatorType_t GetAnimatorType(void);
};

#endif