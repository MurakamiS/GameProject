#pragma once
#include "Fade.h"
#include "tkEngine/graphics/effect/tkEffect.h"
#include "Title.h"
#include "Board.h"
class Board;
class Stone;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	void OnDestroy();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[�B 
	int TurnB = 10; 
 	int turnW = 10; //�c��̃^�[����
	int turn = 1;	//�ǂ���̃^�[�����@1����-1����
	int win; //�ǂ��炪���������𔻒�@1���̏����@-1�����̏��� 0����������
	CVector3 m_position = CVector3::Zero;
private:
	Fade * m_fade = nullptr;
	Board* m_board = nullptr;
	Stone* m_stone = nullptr;
	enum EnState
	{
		enState_FadeIn,		//�t�F�[�h�C����
		enState_InGame,		//�C���Q�[����
	};
	bool m_DeleteFlag = false;	//���̃N���X�̃f���[�g���J�n���Ă��邩�ǂ���
};

