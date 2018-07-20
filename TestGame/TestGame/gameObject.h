#pragma once
namespace cs2018prj {

	struct S_GAMEOBJECT {
		double m_dbSpeed;
		//double m_posx, m_posy;
		irr::core::vector2df m_vPos;
		double m_dbAngle;
		double m_dbWorkTick;
		void *m_pWepon;
		tge_sprite::S_SPRITE_OBJECT *m_pSprite;
		irr::core::vector2df m_translation;
		int m_nFSM;
		bool m_bActive;
		cs2018prj::S_GAMEOBJECT *m_pTargetObj;
		cs2018prj::S_GAMEOBJECT *m_pDropObj;
		void(*m_fpApply)(S_GAMEOBJECT *, double);
		void(*m_fpRender)(S_GAMEOBJECT *, CHAR_INFO *);
		void(*m_fpClone)(S_GAMEOBJECT *pObj);
		bool m_bOnWepon;
		bool m_bOnKey;
		char m_cDirection;
	};

	namespace playerObject {
		struct S_SUBOBJECT {

		};

		void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed,
			tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
		void Activate(S_GAMEOBJECT *pObj);
	}
	namespace enemyObject {
		namespace ailenObject {
			struct S_SUBOBJECT {};
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed,
				tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
			void Activate(S_GAMEOBJECT *pObj);
			void Activate2(S_GAMEOBJECT *pObj);
		}
		namespace trap {
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed,
				tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
			void Activate(S_GAMEOBJECT *pObj);
		}
		namespace poison {
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed,
				tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
			void Activate(S_GAMEOBJECT *pObj);
		}
	}
	namespace attackObject {
		namespace claw {

		}
		namespace fire {
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed,
				tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);

			void Activate(S_GAMEOBJECT *pObj);
		}

	}

	namespace itemObject {
		namespace key {
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed,
				tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
			void Activate(S_GAMEOBJECT *pObj);
		}
		namespace door {
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed,
				tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
			void Activate(S_GAMEOBJECT *pObj);
		}
		namespace gun {
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed,
				tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
			void Activate(S_GAMEOBJECT *pObj);
		}
	}


	namespace objMng {
		struct S_OBJECT_MNG {
			S_GAMEOBJECT *m_pListObject[1024];
			int m_nIndex;
		};
		void add(S_OBJECT_MNG *pObj, S_GAMEOBJECT *pGameObj);
		void applyAll(S_OBJECT_MNG *pObj, double _deltaTick);
		void renderAll(S_OBJECT_MNG *pObj, CHAR_INFO *pBuf);
		void clearAll(S_OBJECT_MNG *pObj);
	}

}