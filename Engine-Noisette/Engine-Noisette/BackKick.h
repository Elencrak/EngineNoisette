#pragma once
#include "Combo.h"
class BackKick : public Combo
{
public:
	// Constructor
	BackKick();
	~BackKick();

	// Method
	void Execute() override;
	void Add() override;
	void Remove() override;
};

