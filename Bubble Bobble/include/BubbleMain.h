#ifndef BUBBLEMAIN_H
#define BUBBLEMAIN_H

#include <stdio.h>
#include <windows.h>
#include "PathNames.h"
#include "utilities.h"
#include "MemoryManage.h"
#include "InputManage.h"
#include "BitmapFontHolder.h"

#include "BubbleLogic.h"

#include "BitmapFontHolder.h"
#include "Terrain.h"
#include "FrameRangeAnimation.h"
#include "AnimationFilmHolder.h"
#include "AnimationFilm.h"
#include "FrameRangeAnimator.h"
#include "AnimatorHolder.h"
#include "InvisibleSprites.h"
#include "TickAnimation.h"

#include "GameActionUtilities.h"
#include "AnimationsParser.h"
#include "CollisionChecker.h"
#include "BubAnimator.h"
#include "BubblesAnimator.h"
#include "ZenChanAnimator.h"
#include "MightaAnimator.h"
#include "BarronVonBlubaAnimator.h"
#include "StartScreenAnimator.h"
#include "TimerTickAnimator.h"
#include "StageStartingAttributesParser.h"

#include "ArtificialIntelligence.h"
#include "PowerUpsAnimator.h"
#include "SoundAPI.h"

#include <allegro5\allegro5.h> 
#include <allegro5\allegro.h> 
#include <allegro5\allegro_native_dialog.h> 
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

Display display = NULL;
EventQueue event_queue = NULL;
Timer timer = NULL;

ALLEGRO_EVENT ev;
KeyBoardState keyState;

const float FPS = 50;
bool redraw = true;

namespace BubbleMain{

	extern int DrawTerrain(void);

	extern bool InitAllegro(void);
	extern void InitGameEngine(void);

	extern void InitSprites(void);
	extern void InitBubblun(void);
	extern void InitZenChan(void);
	extern void InitMighta(void);

	extern void ManageGameLoop(void);

	extern void Rendering(timestamp_t nowTime);
	extern bool InputManagement(void);
	extern void AnimationProgress(timestamp_t timeNow);
	extern void ArtificialIntelligence(void);
	extern void CollisionChecking(void);
	extern void CommitDestructions(void);
	extern void FPSCalculation(void);
	extern void SystemLoopDispatching(void);
	extern void GameOver(void);
	
}

#endif