#include "Player.h"


Player::Player(string name, string stack_cave)
{
	m_name = name;
	m_chipstack.m_stack = atoi(stack_cave.c_str());
}


Player::~Player(void)
{
}
