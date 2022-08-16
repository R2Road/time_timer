#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace test_ptt_timer
{
	class Generate : public r2cm::iItem, public r2cm::SingleTon<Generate>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Start : public r2cm::iItem, public r2cm::SingleTon<Start>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Update : public r2cm::iItem, public r2cm::SingleTon<Update>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Stop : public r2cm::iItem, public r2cm::SingleTon<Stop>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Pause : public r2cm::iItem, public r2cm::SingleTon<Pause>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}