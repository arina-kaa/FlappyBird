#pragma once
static const sf::Vector2u WINDOW_SIZE = { 600, 700 };
static const std::string WINDOW_TITLE = "Flappy Bird: Demo #1";
static const unsigned WINDOW_FRAME_LIMIT = 120;

static const std::string SPRITE_FILE = "images/FlappyBird.png";

static const sf::Vector2u BACKGROUND_POSITION_LIGHT = { 0, 0 };
static const sf::Vector2u BACKGROUND_POSITION_DARK = { 146, 0 };
static const sf::Vector2u BACKGROUND_SIZE = { 144, 256 };

static const sf::Vector2u GROUND_POSITION = { 292, 0 };
static const sf::Vector2u GROUND_SIZE = { 168, 56 };

static const sf::Vector2u PIPE_POSITION = { 84, 323 };
static const sf::Vector2u PIPE_SIZE = { 26, 160 };

static const sf::Vector2u BIRD_POSITION = { 0, 490 };
static const sf::Vector2u BIRD_SIZE = { 25, 25 };
static const sf::Vector2f BIRD_INITIAL_POSITION = { 0.33f * (sf::Vector2f(WINDOW_SIZE).x - BIRD_SIZE.x), 0.5f * (sf::Vector2f(WINDOW_SIZE).y - BIRD_SIZE.y) };
const sf::Vector2f BIRD_INITIAL_VELOCITY = { 150, 0 };

constexpr auto JUMP_SPEED = -300.f;
constexpr auto ACCELERATION = 600.f;

const auto PIPE_DISTANCE = WINDOW_SIZE.x / 2;
const auto VOID_HEIGHT = 7 * BIRD_SIZE.y;
