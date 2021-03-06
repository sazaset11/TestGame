//TGE skeleton 
#include "stdafx.h"
#include "tge.h"
#include "tge_sprite.h"
#include "gameobject.h"

void _loadSprite(tge_sprite::S_SPRITE_OBJECT *spr, const char *szFileName)
{
	tge_sprite::Init(spr);
	tge_sprite::load(spr, szFileName);
}

int main()
{

	HANDLE hStdout = NULL;
	TGE::startTGE(&hStdout);

	//리소스 로딩
	CHAR_INFO *pMapDataBuffer = TGE::CreateScreenBuffer();
	CHAR_INFO *pBakBuffer = TGE::CreateScreenBuffer();
	TGE::loadBufferBinary(pMapDataBuffer, "../../res/1.map");

	tge_sprite::S_SPRITE_OBJECT sprMiw, sprFirep, sprKey, sprGun/*, sprdoor2, sprClaw*/;
	tge_sprite::S_SPRITE_OBJECT sprAilen, sprTrap1, sprTrap2, sprDoor1, sprFiree1, sprFiree2;
	tge_sprite::S_SPRITE_OBJECT sprPoison1, sprPoison2, sprPoison3, sprPoison4;
	_loadSprite(&sprMiw, "../../res/obj1.spr");
	_loadSprite(&sprAilen, "../../res/ailen.spr");
	//_loadSprite(&sprClaw, "../../res/claw.spr");
	_loadSprite(&sprFirep, "../../res/firey.spr");
	_loadSprite(&sprKey, "../../res/keyg.spr");
	_loadSprite(&sprDoor1, "../../res/doorg.spr");
	//_loadSprite(&sprdoor2, "../../res/doorb.spr");
	_loadSprite(&sprGun, "../../res/gun.spr");
	_loadSprite(&sprTrap1, "../../res/trapd.spr");
	_loadSprite(&sprTrap2, "../../res/trapr.spr");
	_loadSprite(&sprFiree1, "../../res/firer.spr");
	_loadSprite(&sprFiree2, "../../res/firer.spr");
	_loadSprite(&sprPoison1, "../../res/poison.spr");
	_loadSprite(&sprPoison2, "../../res/poison.spr");
	_loadSprite(&sprPoison3, "../../res/poison.spr");
	_loadSprite(&sprPoison4, "../../res/poison.spr");

	cs2018prj::objMng::S_OBJECT_MNG objMng = { 0 };
	cs2018prj::S_GAMEOBJECT *objPlayer, *objFirep, *objKey, *objGun/*, *objDoor2, *objClaw*/;
	cs2018prj::S_GAMEOBJECT *objAilen, *objTrap1, *objTrap2, *objDoor1, *objFiree1, *objFiree2;
	cs2018prj::S_GAMEOBJECT *objPoison1, *objPoison2, *objPoison3, *objPoison4;

	objPlayer = (cs2018prj::S_GAMEOBJECT *)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::playerObject::Init(objPlayer, irr::core::vector2df(2, 2), 10, &sprMiw);
	cs2018prj::playerObject::Activate(objPlayer);
	//objPlayer->m_bActive = true;
	objPlayer->m_translation = irr::core::vector2df(-1, -1);

	objFirep = (cs2018prj::S_GAMEOBJECT *)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::attackObject::fire::Init(objFirep, irr::core::vector2df(0, 0), 20, &sprFirep);
	objFirep->m_translation = irr::core::vector2df(0, 0);

	objAilen = (cs2018prj::S_GAMEOBJECT *)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::enemyObject::ailenObject::Init(objAilen, irr::core::vector2df(20, 18), 8, &sprAilen);
	objAilen->m_translation = irr::core::vector2df(-1, -1);
	cs2018prj::enemyObject::ailenObject::Activate(objAilen);
	
	//objAilen->m_nFSM = 10;
	objKey = (cs2018prj::S_GAMEOBJECT*)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::itemObject::key::Init(objKey, irr::core::vector2df(0, 0), 0, &sprKey);
	objKey->m_translation = irr::core::vector2df(0, 0);

	objDoor1 = (cs2018prj::S_GAMEOBJECT*)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::itemObject::door::Init(objDoor1, irr::core::vector2df(98, 14), 0, &sprDoor1);
	objDoor1->m_translation = irr::core::vector2df(1, -1);	
	cs2018prj::itemObject::door::Activate(objDoor1);
	//objDoor1->m_bActive = true;
	//objDoor2 = (cs2018prj::S_GAMEOBJECT*)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	//cs2018prj::itemObject::door::Init(objDoor2, irr::core::vector2df(50, 24), 0, &sprdoor2);
	//objDoor2->m_translation = irr::core::vector2df(0, 0);
	//cs2018prj::itemObject::door::Activate(objDoor2);
	objGun = (cs2018prj::S_GAMEOBJECT*)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::itemObject::gun::Init(objGun, irr::core::vector2df(85, 5), 0, &sprGun);
	objGun->m_translation = irr::core::vector2df(-1, 0);
	cs2018prj::itemObject::gun::Activate(objGun);

	objTrap1 = (cs2018prj::S_GAMEOBJECT*)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::enemyObject::trap::Init(objTrap1, irr::core::vector2df(50, 1), 0, &sprTrap1);
	objTrap1->m_translation = irr::core::vector2df(-1, 0);
	cs2018prj::enemyObject::trap::Activate(objTrap1);
	objTrap1->m_cDirection = 'd';

	objFiree1 = (cs2018prj::S_GAMEOBJECT *)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::attackObject::fire::Init(objFiree1, irr::core::vector2df(0, 0), 15, &sprFiree1);
	objFiree1->m_translation = irr::core::vector2df(0, 0);

	objTrap2 = (cs2018prj::S_GAMEOBJECT*)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::enemyObject::trap::Init(objTrap2, irr::core::vector2df(1, 15), 0, &sprTrap2);
	objTrap2->m_translation = irr::core::vector2df(0, -1);
	cs2018prj::enemyObject::trap::Activate(objTrap2);
	objTrap2->m_cDirection = 'r';

	objFiree2 = (cs2018prj::S_GAMEOBJECT *)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::attackObject::fire::Init(objFiree2, irr::core::vector2df(0, 0), 30, &sprFiree2);
	objFiree2->m_translation = irr::core::vector2df(0, 0);

	objPoison1 = (cs2018prj::S_GAMEOBJECT*)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::enemyObject::poison::Init(objPoison1, irr::core::vector2df(9, 13), 0, &sprPoison1);
	objPoison1->m_translation = irr::core::vector2df(-5, -5);
	cs2018prj::enemyObject::poison::Activate(objPoison1);

	objPoison2 = (cs2018prj::S_GAMEOBJECT*)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::enemyObject::poison::Init(objPoison2, irr::core::vector2df(75, 10), 0, &sprPoison2);
	objPoison2->m_translation = irr::core::vector2df(-5, -5);
	cs2018prj::enemyObject::poison::Activate(objPoison2);

	objPoison3 = (cs2018prj::S_GAMEOBJECT*)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::enemyObject::poison::Init(objPoison3, irr::core::vector2df(64, 10), 0, &sprPoison3);
	objPoison3->m_translation = irr::core::vector2df(-5, -5);
	cs2018prj::enemyObject::poison::Activate(objPoison3);

	objPoison4 = (cs2018prj::S_GAMEOBJECT*)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
	cs2018prj::enemyObject::poison::Init(objPoison4, irr::core::vector2df(53, 10), 0, &sprPoison4);
	objPoison4->m_translation = irr::core::vector2df(-5, -5);
	cs2018prj::enemyObject::poison::Activate(objPoison4);

	objPlayer->m_pWepon = objFirep;
	objPlayer->m_pTargetObj = objDoor1;
	objAilen->m_pTargetObj = objPlayer;
	objAilen->m_pDropObj = objKey;
	objFirep->m_pTargetObj = objAilen;
	objKey->m_pDropObj = objAilen;
	objKey->m_pTargetObj = objPlayer;
	objGun->m_pTargetObj = objPlayer;
	objTrap1->m_pWepon = objFiree1;
	objFiree1->m_pTargetObj = objPlayer;
	objTrap2->m_pWepon = objFiree2;
	objFiree2->m_pTargetObj = objPlayer;
	objPoison1->m_pTargetObj = objPlayer;
	objPoison2->m_pTargetObj = objPlayer;
	objPoison3->m_pTargetObj = objPlayer;
	objPoison4->m_pTargetObj = objPlayer;

	cs2018prj::objMng::add(&objMng, objPoison1);
	cs2018prj::objMng::add(&objMng, objPoison2);
	cs2018prj::objMng::add(&objMng, objPoison3);
	cs2018prj::objMng::add(&objMng, objPoison4);
	cs2018prj::objMng::add(&objMng, objFirep);
	cs2018prj::objMng::add(&objMng, objAilen);
	cs2018prj::objMng::add(&objMng, objKey);
	cs2018prj::objMng::add(&objMng, objDoor1);
	//cs2018prj::objMng::add(&objMng, objDoor2);
	cs2018prj::objMng::add(&objMng, objGun);
	cs2018prj::objMng::add(&objMng, objTrap1);
	cs2018prj::objMng::add(&objMng, objTrap2);
	cs2018prj::objMng::add(&objMng, objFiree1);
	cs2018prj::objMng::add(&objMng, objFiree2);
	cs2018prj::objMng::add(&objMng, objPlayer);


	bool _bLoop = true;
	static int _nFSM = 0;
	UINT64 _oldTick = TGE::util::GetTimeMs64();

	while (_bLoop)
	{
		TGE::setCursor(hStdout, 0, 25);
		UINT64 _curTick = TGE::util::GetTimeMs64();
		UINT64 _deltaTick = _curTick - _oldTick;
		_oldTick = _curTick;

		double _dbDeltaTick = (double)(_deltaTick) / 1000.0;

		//SetConsoleCursorPosition(hStdout,{ 40, 1 });

		static char szCmdBuf[128];
		//입력 처리 
		switch (_nFSM) {
		case 0:
			if (TGE::input::g_KeyTable[VK_RETURN]) {
				_nFSM = 1;
				TGE::input::setEditMode();
			}
			break;
		case 1: //동기  모드
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, 26);
			printf_s("                                                 ]");
			TGE::setCursor(hStdout, 0, 26);
			printf_s("[cmd >");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			_nFSM = 0;
			TGE::input::setNormalMode();
			TGE::input::g_KeyTable[VK_RETURN] = 0;
			_oldTick = TGE::util::GetTimeMs64();
			break;
		}
		//커멘드 처리..
		{
			char szTokenBuf[8][64];
			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0) {
				if (!strcmp(szTokenBuf[0], "quit")) {
					_bLoop = false;
				}
			}
			szCmdBuf[0] = 0x00;
		}

		//ai
		cs2018prj::objMng::applyAll(&objMng, _dbDeltaTick);

		//랜더링 전처리
		TGE::copyScreenBuffer(pBakBuffer, pMapDataBuffer);

		//오브잭트 랜더링
		cs2018prj::objMng::renderAll(&objMng, pBakBuffer);

		//랜더 (화면 갱신)
		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBakBuffer);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
		if (!objDoor1->m_bActive || !objPlayer->m_bActive) _bLoop = false;
	}

	cs2018prj::objMng::clearAll(&objMng);

	free(pBakBuffer);
	free(pMapDataBuffer);

	free(sprMiw.m_pSpriteBuf);
	free(sprAilen.m_pSpriteBuf);
	free(sprFirep.m_pSpriteBuf);
	free(sprDoor1.m_pSpriteBuf);
	free(sprKey.m_pSpriteBuf);
	free(sprGun.m_pSpriteBuf);
	free(sprTrap1.m_pSpriteBuf);
	free(sprTrap2.m_pSpriteBuf);
	free(sprFiree1.m_pSpriteBuf);
	free(sprFiree2.m_pSpriteBuf);
	free(sprPoison1.m_pSpriteBuf);
	free(sprPoison2.m_pSpriteBuf);
	free(sprPoison3.m_pSpriteBuf);
	free(sprPoison4.m_pSpriteBuf);

	TGE::endTGE();

	return 0;

}