#pragma once
static const sf::Vector2f WINDOW_SIZE = { 800, 700 };
static const std::string WINDOW_TITLE = "Flappy Bird: Demo #1";
static const unsigned WINDOW_FRAME_LIMIT = 60;

static const std::string SPRITE_FILE = "images/FlappyBird.png";

static const sf::Vector2f BACKGROUND_SIZE = { 144, 256 };
static const sf::Vector2f BIRD_SIZE = { 25, 25 };
static const sf::Vector2f BIRD_INITIAL_POSITION = { 0.33f * (sf::Vector2f(WINDOW_SIZE).x - BIRD_SIZE.x), 0.5f * (sf::Vector2f(WINDOW_SIZE).y - BIRD_SIZE.y) };

static const float JUMP_SPEED = 2.5;