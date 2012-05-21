#pragma once
class Chipstack
{
public:
	int m_stack;

	void modifyStack(int modification_stack);
	void initStack(int modification_stack);

	Chipstack(void);
	~Chipstack(void);
};

