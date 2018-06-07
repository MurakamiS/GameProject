#pragma once
#include "Animation.h"
class Game;
class Player;
class Board:public IGameObject
{
public:
	Board();
	~Board();
	int Banmen[8][8];			//�����牡�����A�c���� 
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	prefab::CSkinModelRender* m_skinModelRender[8][8] = { {nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } };	//�X�L�����f�������_���[�B
	CFont m_font;
	int ScoreA = 0;
	int ScoreB = 0;
	wchar_t A;
	wchar_t B;
	int Koushin = 1;//���̕ϐ���0�̏ꍇ���_���X�V�����
	int Haichi = 0;//�V�����΂�z�u���Ĕz��̍X�V���K�v�Ȏ�1�ɂȂ�
	int BanX;
	int BanY;
private:
	//�c��^�[�����B�c�R�}���\���̎��͂���g���B
	int turnA = 10;	//��
	int turnB = 10;	//��
	////���݂̃^�[���@1���A-1����
	//int turn = 1;
	Game* m_game = nullptr;
	Player* m_player = nullptr;
	void SetMapB(int a, int b)
	{
		switch (Banmen[a][b])
		{
		case -1:Banmen[a][b] = 0;
			//�����ɂ��񂵂�̂��
			BanX = a;
			BanY = b;
			NewGO<Animation>(0);
			break;
		case 0:Banmen[a][b] = 1;
			break;
		default:break;
		}
	}

	void SetMapW(int a, int b)
	{
		switch (Banmen[a][b])
		{
		case 1:Banmen[a][b] = 0;
			//�����ɂ��񂵂�̂��
			break;
		case 0:Banmen[a][b] = -1;
			break;
		default:break;
		}
	}
};
