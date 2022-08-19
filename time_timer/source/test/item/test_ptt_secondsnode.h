#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace test_ptt_secondsnode
{
	class Generate : public r2cm::iItem, public r2cm::SingleTon<Generate>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class View : public r2cm::iItem, public r2cm::SingleTon<View>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Process : public r2cm::iItem, public r2cm::SingleTon<Process>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}