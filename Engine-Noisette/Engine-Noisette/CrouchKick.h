#pragma once
#include "Combo.h"
class CrouchKick : public Combo
{
public:
	// Constructor
	CrouchKick();
	~CrouchKick();
	
	// Method
	void Execute() override;
	void Add() override;
	void Remove() override;
};

