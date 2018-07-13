#pragma once
#include "Fade.h"

#include "Title.h"
#include "Board.h"

#include "tkEngine/graphics/font/tkFont.h"

class Board;
class Stone;
class Player;
//class victory;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	void PostRender(CRenderContext& rc);
	void OnDestroy();
	void ResetTimer()
	{
		m_timer = 3.0f;
	}
	//prefab::CEffect* m_effect = nullptr;					//�G�t�F�N�g

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B 
	int TurnB = 10; 
 	int turnW = 10; //�c��̃^�[����
	int turn = 1;	//�ǂ���̃^�[�����@1����-1����
	int win; //�ǂ��炪���������𔻒�@1���̏����@-1�����̏��� 0����������
	
	CVector3 m_position = CVector3::Zero;
	int count0flag = 0;
private:
	Fade * m_fade = nullptr;
	Board* m_board = nullptr;
	Stone* m_stone = nullptr;
	Player* m_player = nullptr;
	

	Animation* m_animation = nullptr;
	
	CFont m_fontTest;
	float m_timer = 3.0f;								//!<�^�C�}�[
	//std::unique_ptr<DirectX::SpriteFont> m_timerFont;	//!<�^�C�}�[�p�̃t�H���g�B
	enum EnState
	{
		enState_FadeIn,		//�t�F�[�h�C����
		enState_InGame,		//�C���Q�[����
	};
	bool m_DeleteFlag = false;	//���̃N���X�̃f���[�g���J�n���Ă��邩�ǂ���
	int count = 0;
	int count2 = 0;
};

