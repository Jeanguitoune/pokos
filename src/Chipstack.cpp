#include "Chipstack.h"


Chipstack::Chipstack(void)
{
	m_stack = 0;
}


Chipstack::~Chipstack(void)
{
}

void Chipstack::modifyStack(int modification_stack)
{
	m_stack+=modification_stack;
}

void Chipstack::initStack(int modification_stack)
{
	m_stack=modification_stack;
}