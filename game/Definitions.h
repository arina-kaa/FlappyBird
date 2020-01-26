#pragma once

static const sf::Vector2u WINDOW_SIZE = { 768, 1024 };

static const std::string GAME_BACKGROUND_FILEPATH = "Resources/res/sky.png";
static const std::string GAME_OVER_BACKGROUND_FILEPATH = "Resources/res/sky.png";

static const std::string GAME_TITLE_FILEPATH = "Resources/res/title.png";
static const std::string PLAY_BUTTON_FILEPATH = "Resources/res/PlayButton.png";

static const std::string PIPE_UP_FILEPATH = "Resources/res/PipeUp.png";
static const std::string PIPE_DOWN_FILEPATH = "Resources/res/PipeDown.png";
static const std::string SCORING_PIPE_FILEPATH = "Resources/res/InvisibleScoringPipe.png";

static const std::string LAND_FILEPATH = "Resources/res/Land.png";

static const std::string BIRD_FRAME_1_FILEPATH = "Resources/res/bird-01.png";
static const std::string BIRD_FRAME_2_FILEPATH = "Resources/res/bird-02.png";
static const std::string BIRD_FRAME_3_FILEPATH = "Resources/res/bird-03.png";
static const std::string BIRD_FRAME_4_FILEPATH = "Resources/res/bird-04.png";

static const std::string FLAPPY_FONT_FILEPATH = "Resources/fonts/FlappyFont.ttf";

static const float PIPE_MOVEMENT_SPEED = 200.0f;
static const float PIPE_SPAWN_FREQUENCE = 2.0f;

static const float BIRD_ANIMATION_DURATION = 0.4f;

static const int BIRD_STATE_STILL = 1;
static const int BIRD_STATE_FALLING = 2;
static const int BIRD_STATE_FLYING = 3;

static const float GRAVITY = 350.5f;
static const float FLYING_SPEED = 350.5f;
static const float FLYING_DURATION = 0.25f;

static const float ROTATION_SPEED = 100.0f;

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};
