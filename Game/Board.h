#pragma once
#include "Animation.h"
class Game;
class Player;
class Animation;
class Board;
class Board :public IGameObject
{
public:
	Board();
	~Board();
	int Banmen[8][8];			//�����牡�����A�c���� 
	bool Start();
	void Update();
	void Render(CRenderContext& rc);
	prefab::CSkinModelRender* m_skinModelRender[8][8] = { { nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr },{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } ,{ nullptr,nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr } };	//�X�L�����f�������_���[�B
	CFont m_font;
	int ScoreA = 0;
	int ScoreB = 0;
	int k = 0;
	wchar_t A;
	wchar_t B;
	int Koushin = 1;//���̕ϐ���0�̏ꍇ���_���X�V�����
	int Haichi = 0;//�V�����΂�z�u���Ĕz��̍X�V���K�v�Ȏ�1�ɂȂ�
				   /*int BanX;
				   int BanY;*/
	int count = 0;
	int Animflag = 0;
	int GetBanX()
	{
		return BanX;
	}
	int GetBanY()
	{
		return BanY;
	}
	int GetstonePos()
	{
		return stonePos;
	}
	////�㉺���E�ɉ��������W��Ԃ�
	//CInt2 GetPos(int c)
	//{
	//	CInt2 re;
	//	switch (c)
	//	{
	//	case 0:
	//		re.X = BanX;
	//		re.Y = BanY - 1;
	//		break;
	//	case 1:

	//		re.X = BanX;
	//		re.Y = BanY + 1;
	//		break;
	//	case 2:

	//		re.X = BanX-1;
	//		re.Y = BanY;
	//		break;
	//	case 3:

	//		re.X = BanX+1;
	//		re.Y = BanY;
	//		break;
	//	}
	//	return re;
	//}
	//���̂��Ђ傤 t��1�̎������A�|�P�̂Ƃ����� -1�̂Ƃ���BanXBanY�̒l��
	CInt2 GetMapW(int t);
	CInt2 GetMapB(int t);

private:

	//�c��^�[�����B�c�R�}���\���̎��͂���g���B
	int turnA = 10;	//��
	int turnB = 10;	//��

					//Animation�ɂ����Ă������W
	int BanX;
	int BanY;
	int stonePos;//Animation���Ăяo�����Ƃ��z�u�����΂���݂Ăǂ̕����̃}�X���@0123�ŏ㉺���E�̏���
	Game* m_game = nullptr;
	Player* m_player = nullptr;
	Animation* m_animation = nullptr;
	void SetMapB(int a, int b, int c)
	{
		switch (Banmen[a][b])
		{
		case -1:Banmen[a][b] = 0;
			//�����ɂ��񂵂�̂��
			BanX = a;
			BanY = b;
			stonePos = c;
			NewGO<Animation>(0);
			break;
		case 0:Banmen[a][b] = 1;
			break;
		default:break;
		}
	}

	void SetMapW(int a, int b, int c)
	{
		switch (Banmen[a][b])
		{
		case 1:Banmen[a][b] = 0;
			//�����ɂ��񂵂�̂��
			BanX = a;
			BanY = b;
			stonePos = c;
			NewGO<Animation>(0);
			break;
		case 0:Banmen[a][b] = -1;
			break;
		default:break;
		}
	}
};