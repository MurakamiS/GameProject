﻿
#ifndef	__EFFEKSEER_CRITICALSESSION_H__
#define	__EFFEKSEER_CRITICALSESSION_H__

//----------------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------------
#include "Effekseer.Base.h"

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
namespace Effekseer
{
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
/**
	@brief	クリティカルセクション
*/
class CriticalSection
{
private:
#ifdef _WIN32
	mutable CRITICAL_SECTION m_criticalSection;
#elif defined(_PSVITA) || defined(_PS4) || defined(_SWITCH) || defined(_XBOXONE)
	mutable CONSOLE_GAME_MUTEX	m_mutex;
#else
	mutable pthread_mutex_t m_mutex;
#endif

public:

	CriticalSection();

	~CriticalSection();

	void Enter() const;

	void Leave() const;
};

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
}
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
#endif	//	__EFFEKSEER_CRITICALSESSION_H__
